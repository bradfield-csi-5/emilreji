#include <fcntl.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFSIZE 74536
#define PCAP_FILE_HEADER_LEN 24
#define ETHERNET_HEADER_LEN 14

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
    uint32_t nextPacketInc = (buf[currByte + 3] << 24) |
                             (buf[currByte + 2] << 16) |
                             (buf[currByte + 1] << 8) | (buf[currByte]);
    currByte += 8;
    printf("%d:\n", totalPackets);
    int currByteInFrame = currByte;

    currByteInFrame += ETHERNET_HEADER_LEN;

    int currByteInPacket = currByteInFrame;

    int ipHeaderLength = (buf[currByteInPacket] & 0b1111) * 4;

    printf("ipHeaderLength: %d\n", ipHeaderLength);

    currByteInPacket += 2;

    uint16_t currPacketSize =
        (buf[currByteInPacket] << 8) | (buf[currByteInPacket + 1]);
    printf("currPacketSize hex: %02X%02X\t currPacketSize: %u\n",
           buf[currByteInPacket], buf[currByteInPacket + 1], currPacketSize);

    currByteInPacket += 7;
    int protocol = buf[currByteInPacket];
    printf("protocol: %d\n", protocol);

    currByteInPacket += 3;
    uint32_t srcIpAddress = (buf[currByte] << 24) | (buf[currByte + 1] << 16) |
                            (buf[currByte + 2] << 8) | (buf[currByte + 3]);
    printf("srcIpAddress: %d.%d.%d.%d\n", buf[currByteInPacket],
           buf[currByteInPacket + 1], buf[currByteInPacket + 2],
           buf[currByteInPacket + 3]);
    printf("srcIpAddress raw: %u\n", srcIpAddress);

    currByteInPacket += 4;
    uint32_t destIpAddress = (buf[currByte] << 24) | (buf[currByte + 1] << 16) |
                             (buf[currByte + 2] << 8) | (buf[currByte + 3]);
    printf("destIpAddress: %d.%d.%d.%d\n", buf[currByteInPacket],
           buf[currByteInPacket + 1], buf[currByteInPacket + 2],
           buf[currByteInPacket + 3]);
    currByte += nextPacketInc;

    if (srcIpAddress == 2757648607) {
      printf("Payload coming back.\n");
    }
  }
  printf("total packets: %d\n", totalPackets);
}
