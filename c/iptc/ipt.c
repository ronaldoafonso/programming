
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <libiptc/libiptc.h>


typedef struct _Entry {
    struct ipt_entry entry;
    struct xt_standard_target target;
} Entry;

int main(int argc, char *argv[])
{
    struct xtc_handle *handle;
    unsigned int dst_ip;
    Entry entry;
    int rc;
    const struct ipt_entry *pentry = NULL;
    struct ipt_counters *cnt;
    int i = 0;

    handle = iptc_init("filter");
    if (!handle) {
        printf("Error: %s.\n", iptc_strerror(errno));
        exit(EXIT_FAILURE);
    }

    memset(&entry, 0, sizeof(Entry));

    entry.target.target.u.user.target_size = XT_ALIGN(sizeof(struct xt_standard_target));
    strncpy(entry.target.target.u.user.name, "ACCEPT", sizeof(entry.target.target.u.user.name));

    entry.entry.target_offset = sizeof(struct ipt_entry);
    entry.entry.next_offset = entry.entry.target_offset + entry.target.target.u.user.target_size;

    inet_pton(AF_INET, "1.1.1.1", &dst_ip);
    entry.entry.ip.dst.s_addr = dst_ip;
    entry.entry.ip.dmsk.s_addr = 0xFFFFFFFF;

    rc = iptc_append_entry("OUTPUT", (struct ipt_entry *) &entry, handle);
    if (!rc) {
        printf("Error: %s.\n", iptc_strerror(errno));
        iptc_free(handle);
        exit(EXIT_FAILURE);
    }

    rc = iptc_commit(handle);
    if (!rc) {
        printf("Error: %s.\n", iptc_strerror(errno));
        iptc_free(handle);
        exit(EXIT_FAILURE);
    }

    printf("Appended rule to: %d.\n", rc);

    pentry = iptc_first_rule("OUTPUT", handle);
    if (pentry) {
        do {
            i += 1;
            cnt = iptc_read_counter("OUTPUT", i, handle);
            printf("Entry: %d (packets: %llu, bytes: %llu).\n",
                                                             i,
                                                             cnt->pcnt,
                                                             cnt->bcnt);
            pentry = iptc_next_rule(pentry, handle);
        } while (pentry);
    }

    exit(EXIT_SUCCESS);
}
