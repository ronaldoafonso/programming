
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pcap.h>


int main(int argc, char *argv[])
{
    char device[] = "wlan0";
    char error[64];
    pcap_t *handle;
    struct bpf_program fp;
    char filter[64];
    struct pcap_pkthdr header;
    const u_char *packet;

    memset(error, '\0', 64);
    memset(&fp, 0, sizeof(struct bpf_program));
    memset(filter, '\0', 64);
    strncpy(filter, "wlan type mgt subtype probe-req", 31);
    memset(&header, 0, sizeof(struct pcap_pkthdr));
    packet = NULL;

    handle = pcap_open_live(device, BUFSIZ, 1, 0, error);
    if (!handle) {
        fprintf(stderr, "Couldn't open device %s: %s.\n", device, error);
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

    packet = pcap_next(handle, &header);
    if (packet) {
        int i;
        fprintf(stdout, "Header length: %d.\n", header.len);
        for (i = 0; i < header.len; i++) {
            fprintf(stdout, "[0x%x]", packet[i]);
        }
        fprintf(stdout, "\n");
    }

    pcap_close(handle);
    exit(EXIT_SUCCESS);
}
