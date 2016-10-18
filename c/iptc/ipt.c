
#include "ipt.h"


static
int add_ipt_entry(const char *table, const char *chain,
                  const char *ipaddr, const char *target)
{
    struct xtc_handle *handle = NULL;
    Entry entry;
    unsigned int ip4addr;

    handle = iptc_init(table);
    if (!handle) {
        goto aerror;
    }

    memset(&entry, 0, sizeof(Entry));
    entry.target.target.u.user.target_size = XT_ALIGN(sizeof(struct xt_standard_target));
    strncpy(entry.target.target.u.user.name, target, sizeof(entry.target.target.u.user.name));
    entry.entry.target_offset = sizeof(struct ipt_entry);
    entry.entry.next_offset = entry.entry.target_offset + entry.target.target.u.user.target_size;
    inet_pton(AF_INET, ipaddr, &ip4addr);
    entry.entry.ip.dst.s_addr = ip4addr;
    entry.entry.ip.dmsk.s_addr = 0xFFFFFFFF;
    if (!iptc_append_entry(chain, (struct ipt_entry *) &entry, handle)) {
        goto aerror;
    }

    memset(&entry, 0, sizeof(Entry));
    entry.target.target.u.user.target_size = XT_ALIGN(sizeof(struct xt_standard_target));
    strncpy(entry.target.target.u.user.name, target, sizeof(entry.target.target.u.user.name));
    entry.entry.target_offset = sizeof(struct ipt_entry);
    entry.entry.next_offset = entry.entry.target_offset + entry.target.target.u.user.target_size;
    inet_pton(AF_INET, ipaddr, &ip4addr);
    entry.entry.ip.src.s_addr = ip4addr;
    entry.entry.ip.smsk.s_addr = 0xFFFFFFFF;
    if (!iptc_append_entry(chain, (struct ipt_entry *) &entry, handle)) {
        goto aerror;
    }

    if (!iptc_commit(handle)) {
        goto aerror;
    }

    printf("Add rule: (%s).\n", ipaddr);
    iptc_free(handle);
    return 0;

aerror:
    printf("Error (add_ipt): %s.\n", iptc_strerror(errno));
    if (handle) iptc_free(handle);
    return 1;
}

static
int del_ipt_entry(const char *table, const char *chain,
                  const char *ipaddr, const char *target)
{
    struct xtc_handle *handle = NULL;
    const struct ipt_entry *pentry;
    unsigned int ip4addr;
    int i;

    handle = iptc_init(table);
    if (!handle) {
        goto derror;
    }

    inet_pton(AF_INET, ipaddr, &ip4addr);

    for (i = 0, pentry = iptc_first_rule(chain, handle);
         pentry;
         pentry = iptc_next_rule(pentry, handle), i++) {
        if (pentry->ip.src.s_addr == ip4addr) {
            if (!iptc_delete_num_entry("OUTPUT", i, handle)) {
                goto derror;
            } else {
                break;
            }
        }
    }

    for (i = 0, pentry = iptc_first_rule(chain, handle);
         pentry;
         pentry = iptc_next_rule(pentry, handle), i++) {
        if (pentry->ip.dst.s_addr == ip4addr) {
            if (!iptc_delete_num_entry("OUTPUT", i, handle)) {
                goto derror;
            } else {
                break;
            }
        }
    }

    if (!iptc_commit(handle)) {
        goto derror;
    }

    printf("Del rule: (%s).\n", ipaddr);
    iptc_free(handle);
    return 0;

derror:
    printf("Error (del_ipt): %s.\n", iptc_strerror(errno));
    if (handle) iptc_free(handle);
    return 1;
}


int main(int argc, char *argv[])
{
    if (add_ipt_entry("filter", "OUTPUT", "1.1.1.1", "ACCEPT"))
        goto error;
    if (add_ipt_entry("filter", "OUTPUT", "2.2.2.2", "ACCEPT"))
        goto error;
    if (add_ipt_entry("filter", "OUTPUT", "3.3.3.3", "ACCEPT"))
        goto error;

    if (del_ipt_entry("filter", "OUTPUT", "1.1.1.1", "ACCEPT"))
        goto error;
    if (del_ipt_entry("filter", "OUTPUT", "2.2.2.2", "ACCEPT"))
        goto error;
    if (del_ipt_entry("filter", "OUTPUT", "3.3.3.3", "ACCEPT"))
        goto error;

    exit(EXIT_SUCCESS);
error:
    exit(EXIT_FAILURE);
}
