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
    // int temp = 0;
    // while (temp < 2) {
    //   temp++;
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

    // printf("ipHeaderLength: %d\n", ipHeaderLength);

    currByteInPacket += 2;

    uint16_t currPacketSize =
        (buf[currByteInPacket] << 8) | (buf[currByteInPacket + 1]);
    // printf("currPacketSize hex: %02X%02X\t currPacketSize: %u\n",
    //        buf[currByteInPacket], buf[currByteInPacket + 1], currPacketSize);

    currByteInPacket += 7;
    int protocol = buf[currByteInPacket];
    // printf("protocol: %d\n", protocol);

    currByteInPacket += 3;
    uint32_t srcIpAddress = (buf[currByte] << 24) | (buf[currByte + 1] << 16) |
                            (buf[currByte + 2] << 8) | (buf[currByte + 3]);
    // printf("srcIpAddress: %d.%d.%d.%d\n", buf[currByteInPacket],
    //        buf[currByteInPacket + 1], buf[currByteInPacket + 2],
    //        buf[currByteInPacket + 3]);
    // printf("srcIpAddress raw: %u\n", srcIpAddress);

    currByteInPacket += 4;
    uint32_t destIpAddress = (buf[currByte] << 24) | (buf[currByte + 1] << 16) |
                             (buf[currByte + 2] << 8) | (buf[currByte + 3]);
    // printf("destIpAddress: %d.%d.%d.%d\n", buf[currByteInPacket],
    //        buf[currByteInPacket + 1], buf[currByteInPacket + 2],
    //        buf[currByteInPacket + 3]);

    currByteInPacket += (4 + currPacketSize);
    // int currByteInTCP = currByteInPacket; // wrong value calculated here
    int currByteInTCP = currByteInFrame + ipHeaderLength;

    uint16_t srcPort = (buf[currByteInTCP] << 8) | (buf[currByteInTCP + 1]);

    printf("srcPort hex: %02X%02X\t srcPort: %u\n", buf[currByteInTCP],
           buf[currByteInTCP + 1], srcPort);

    currByteInTCP += 2;
    uint16_t destPort = (buf[currByteInTCP] << 8) | (buf[currByteInTCP + 1]);

    printf("destPort hex: %02X%02X\t destPort: %u\n", buf[currByteInTCP],
           buf[currByteInTCP + 1], destPort);

    currByteInTCP += 2;
    uint32_t seqNum = (buf[currByteInTCP] << 24) |
                      (buf[currByteInTCP + 1] << 16) |
                      (buf[currByteInTCP + 2] << 8) | (buf[currByteInTCP + 3]);
    printf("seqNum: %02X%02X%02X%02X\t%u\n", buf[currByteInPacket],
           buf[currByteInPacket + 1], buf[currByteInPacket + 2],
           buf[currByteInPacket + 3], seqNum);
    currByteInTCP += 4;

    uint32_t ackNum = (buf[currByteInTCP] << 24) |
                      (buf[currByteInTCP + 1] << 16) |
                      (buf[currByteInTCP + 2] << 8) | (buf[currByteInTCP + 3]);
    printf("ackNum: %02X%02X%02X%02X\t%u\n", buf[currByteInPacket],
           buf[currByteInPacket + 1], buf[currByteInPacket + 2],
           buf[currByteInPacket + 3], ackNum);
    currByteInTCP += 4;

    int tcpHeaderLength = (buf[currByteInTCP] / 16) * 4;

    printf("tcpHeaderLength: %d\n", tcpHeaderLength);

    if (srcIpAddress == 2757648607 && srcPort == 80) {
      printf("Payload coming back.\n");
    }

    currByte += nextPacketInc;
  }
  printf("total packets: %d\n", totalPackets);
}
// https://stackoverflow.com/questions/21973387/casting-8-bit-int-to-32-bit