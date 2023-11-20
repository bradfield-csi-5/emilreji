#include <fcntl.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFSIZE 74536
#define PCAP_FILE_HEADER_LEN 24

int main() {
  const char *pathname = "net.cap";
  int flags = 0;

  int fileDescriptor = open(pathname, flags);

  unsigned char buf[BUFSIZE];

  int readBytesNum = read(fileDescriptor, buf, BUFSIZE);

  int currByte = PCAP_FILE_HEADER_LEN;
  int totalPackets = 0;

  while (currByte < BUFSIZE) {
    totalPackets += 1;
    currByte += 8;
    uint32_t currPacketSize = (buf[currByte + 3] << 24) |
                              (buf[currByte + 2] << 16) |
                              (buf[currByte + 1] << 8) | (buf[currByte]);
    currByte += 8;
    printf("%d: ", totalPackets);
    int currByteInFrame = currByte;

    printf("Destination MAC Address Hex: %02X%02X%02X%02X%02X%02X\t",
           buf[currByteInFrame + 5], buf[currByteInFrame + 4],
           buf[currByteInFrame + 3], buf[currByteInFrame + 2],
           buf[currByteInFrame + 1], buf[currByteInFrame]);
    currByteInFrame += 6;
    printf("Source MAC Address Hex: %02X%02X%02X%02X%02X%02X\t",
           buf[currByteInFrame + 5], buf[currByteInFrame + 4],
           buf[currByteInFrame + 3], buf[currByteInFrame + 2],
           buf[currByteInFrame + 1], buf[currByteInFrame]);
    currByteInFrame += 6;
    printf("Ethertype: %02X%02X\n", buf[currByteInFrame + 1],
           buf[currByteInFrame]);
    // printf("Size of packet %u\n", currPacketSize);
    currByte += currPacketSize;
  }
  printf("total packets: %d\n", totalPackets);
}
