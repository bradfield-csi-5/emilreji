#include <fcntl.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFSIZE 74536 // how to determine this?
#define PCAP_FILE_HEADER_LEN 24

void printhex(unsigned char buf[]) {
  for (int i = 0; i < BUFSIZE; i++) {
    if (i % 2 == 0)
      printf(" ");
    if (i % 16 == 0)
      printf("\n");
    printf("%02X", buf[i]);
  }
  printf("\n");
}

int main() {
  const char *pathname = "net.cap";
  int flags = 0;

  int fileDescriptor = open(pathname, flags);

  unsigned char buf[BUFSIZE];

  int readBytesNum = read(fileDescriptor, buf, BUFSIZE);
  // need to figure out better way to pull this in when needed (ex. read only
  // specific byte needed instead of all)

  //   printhex(buf);
  //   printf("%d\n", readBytesNum);

  int currByte = PCAP_FILE_HEADER_LEN;
  int totalPackets = 0;

  while (currByte < BUFSIZE) {
    // int temp = 0;
    // while (temp < 16) {
    //   temp++;
    uint32_t timestamp = ((int)buf[currByte + 3] << 24) |
                         ((int)buf[currByte + 2] << 16) |
                         ((int)buf[currByte + 1] << 8) | ((int)buf[currByte]);
    printf("%d: ", totalPackets + 1);
    printf("Timestamp address: %02X%02X%02X%02X\ttimestamp val: %u\n",
           buf[currByte + 3], buf[currByte + 2], buf[currByte + 1],
           buf[currByte], timestamp);
    currByte += 4;
    uint32_t timestampSmall =
        ((int)buf[currByte + 3] << 24) | ((int)buf[currByte + 2] << 16) |
        ((int)buf[currByte + 1] << 8) | ((int)buf[currByte]);
    printf("%d: ", totalPackets + 1);
    printf(
        "Timestamp Small address: %02X%02X%02X%02X\ttimestamp small val: %u\n",
        buf[currByte + 3], buf[currByte + 2], buf[currByte + 1], buf[currByte],
        timestampSmall);
    currByte += 4;
    uint32_t currPacketSize =
        ((int)buf[currByte + 3] << 24) | ((int)buf[currByte + 2] << 16) |
        ((int)buf[currByte + 1] << 8) | ((int)buf[currByte]);
    // printf("%d: ", totalPackets + 1);
    // printf("currPacketSize address: %02X%02X%02X%02X\tcurrPacketSize val:
    // %u\n",
    //  buf[currByte + 3], buf[currByte + 2], buf[currByte + 1],
    //  buf[currByte], currPacketSize);
    // printf("%02X\t%d\n", buf[currByte + 3], ((int)buf[currByte + 3] << 24));
    // printf("%02X\t%d\n", buf[currByte + 2], ((int)buf[currByte + 2] << 16));
    // printf("%02X\t%d\n", buf[currByte + 1], ((int)buf[currByte + 1] << 8));
    // printf("%02X\t%d\n", buf[currByte], ((int)buf[currByte]));
    currByte += 4;
    uint32_t truncPacketSize =
        ((int)buf[currByte + 3] << 24) | ((int)buf[currByte + 2] << 16) |
        ((int)buf[currByte + 1] << 8) | ((int)buf[currByte]);
    printf("%d: ", totalPackets + 1);
    printf(
        "truncPacketSize address: %02X%02X%02X%02X\ttruncPacketSize val: %u\n",
        buf[currByte + 3], buf[currByte + 2], buf[currByte + 1], buf[currByte],
        truncPacketSize);
    currByte += 4;
    printf("%d: timestamp: "
           "%" PRIu32 "  timestampSmall: "
           "%" PRIu32 "  currByte: %d  currPacketSize: "
           "%" PRIu32 "  truncPacketSize: "
           "%" PRIu32 "\n",
           (totalPackets + 1), timestamp, timestampSmall, currByte,
           currPacketSize, truncPacketSize);
    currByte += currPacketSize;
    // 627 without this case and 109 with this case
    totalPackets += 1;
    // if (currPacketSize == truncPacketSize) {
    //   totalPackets += 1;
    // }
    printf("%d: next currByte: %d\n", totalPackets, currByte);
  }
  printf("total packets: %d\n", totalPackets);
}

/*
If curr and trunc are equal, means current packet is standalone
If curr is less than trunc, then


Read to size of first packet
First 24 bytes are header of pcap file
Next 16 bytes are header of 1st packet
Length of that 1st package is on bytes 32 to 35 inclusive
Un truncated length of that 1st package is on bytes 36 to 39 inclusive
Set current byte to 32 to start
Run a loop that pulls data from current byte and next 3 bytes into uint32
    Then convert it to a number to figure out how long the next packet is
    Then add 8 to current byte to reach start of current packet
    Then add the packet size to the current byte to reach end of current
packet Then add 8 to current byte to get to next packet's size Repeat Exit
loop

https://stackoverflow.com/questions/21973387/casting-8-bit-int-to-32-bit
Converting 4 8 bit values into one 32 bit value
*/

//   const char *pathname = "net.cap";
//   const char *flags = "r";

//   FILE *file = fopen(pathname, flags);
//   unsigned char buf[BUFSIZE];

//   size_t readBytesNum = fread(buf, 1, BUFSIZE, file);

//   printhex(buf);
//   printf("%lu\n", readBytesNum);

// uint32_t timestamp = ((int)buf[currByte - 5] << 24) |
//                      ((int)buf[currByte - 6] << 16) |
//                      ((int)buf[currByte - 7] << 8) | ((int)buf[currByte -
//                      8]);
// uint32_t timestampSmall =
//     ((int)buf[currByte - 1] << 24) | ((int)buf[currByte - 2] << 16) |
//     ((int)buf[currByte - 3] << 8) | ((int)buf[currByte - 4]);
// uint32_t currPacketSize =
//     ((int)buf[currByte + 3] << 24) | ((int)buf[currByte + 2] << 16) |
//     ((int)buf[currByte + 1] << 8) | ((int)buf[currByte]);
// uint32_t truncPacketSize =
//     ((int)buf[currByte + 7] << 24) | ((int)buf[currByte + 6] << 16) |
//     ((int)buf[currByte + 5] << 8) | ((int)buf[currByte + 4]);