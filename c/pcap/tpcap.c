
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pcap.h>


void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    static unsigned int count = 0;
    int i;

    if (packet) {
        fprintf(stdout, "%u: Header length: %d.\n", count++, header->len);
        for (i = 0; i < header->len; i++) {
            fprintf(stdout, "[0x%x]", packet[i]);
        }
        fprintf(stdout, "\n");
    }
}


int main(int argc, char *argv[])
{
    char device[] = "wlan0";
    char error[64];
    pcap_t *handle;
    struct bpf_program fp;
    char filter[64];

    memset(error, '\0', 64);
    memset(&fp, 0, sizeof(struct bpf_program));
    memset(filter, '\0', 64);
    strncpy(filter, "wlan type mgt subtype probe-req", 31);

    handle = pcap_open_live(device, BUFSIZ, 1, 0, error);
    if (!handle) {
        fprintf(stderr, "Couldn't open device %s: %s.\n", device, error);
        exit(EXIT_FAILURE);
    }

    if (pcap_datalink(handle)!= DLT_IEEE802_11_RADIO) {
        fprintf(stderr, "Device %s doesn't provide 802.11 headers - not supported.\n", device);
        exit(EXIT_FAILURE);
    }

    if (pcap_compile(handle, &fp, filter, 1, 0) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s.\n", filter, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s.\n", filter, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    pcap_loop(handle, -1, got_packet, NULL);

    pcap_close(handle);
    exit(EXIT_SUCCESS);
}
