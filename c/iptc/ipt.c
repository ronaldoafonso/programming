
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <libiptc/libiptc.h>


int main(int argc, char *argv[])
{
    struct xtc_handle *handle;
    const struct ipt_entry *entry = NULL;
    struct ipt_counters *cnt;
    int i = 0;

    handle = iptc_init("filter");
    if (!handle) {
        printf("Error: %s.\n", iptc_strerror(errno));
        exit(EXIT_FAILURE);
    }

    entry = iptc_first_rule("OUTPUT", handle);
    if (entry) {
        do {
            i += 1;
            cnt = iptc_read_counter("OUTPUT", i, handle);
            printf("Entry: %d (packets: %llu, bytes: %llu).\n",
                                                             i,
                                                             cnt->pcnt,
                                                             cnt->bcnt);
            entry = iptc_next_rule(entry, handle);
        } while (entry);
    }

    exit(EXIT_SUCCESS);
}
