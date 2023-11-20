#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char *argv[]) {
  // args

  // printf("\nNumber of args: %d\n", argc);
  // for (int i = 0; i < argc; i++) {
  //   printf("Arg %d: %s\n", i, argv[i]);
  // }

  // ip 8.8.8.8 to uint32

  // struct sockaddr_in sa;
  // char str[INET_ADDRSTRLEN];

  // // store this IP address in sa:
  // inet_pton(AF_INET, "8.8.8.8", &(sa.sin_addr));
  // printf("%u\n", sa.sin_addr); // prints 134744072

  // // now get it back and print it
  // inet_ntop(AF_INET, &(sa.sin_addr), str, INET_ADDRSTRLEN);

  // printf("%s\n", str); // prints "8.8.8.8"

  // version 1

  // char domain[14] = "google.com";
  // int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

  // struct sockaddr *addr;
  // (*addr).sa_family = AF_INET;
  // // (*addr).sa_data = domain;

  // int bindResult = bind(sockfd, addr, sizeof(&addr));

  // version 2

  char domain[14] = "google.com";
  int sockfd = socket(PF_INET, SOCK_DGRAM, 0);

  if (sockfd == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in *addr;
  (*addr).sin_family = AF_INET;
  (*addr).sin_port = PORT;
  inet_pton(AF_INET, "8.8.8.8", &((*addr).sin_addr));
  // printf("%u\n", (*addr).sin_addr); // prints 134744072

  int bindResult = bind(sockfd, (struct sockaddr *)addr, sizeof(&addr));

  if (bindResult < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // char *buf = "Test";

  // int bytesSent = send(sockfd, buf, 3, 0);

  // if (bytesSent < 0) {
  //   perror("send failed");
  //   exit(EXIT_FAILURE);
  // }

  printf("\nReached end of file\n");
}

/*
Current goal
*/

/*
DNS A record returns ip address
DNS NS record returns a name server record


ubuntu@ubuntu-Inspiron-7773:~$ nslookup google.com
Server:		127.0.0.53
Address:	127.0.0.53#53

Non-authoritative answer:
Name:	google.com
Address: 142.250.80.46
Name:	google.com
Address: 2607:f8b0:4006:823::200e

ubuntu@ubuntu-Inspiron-7773:~$ nslookup 8.8.8.8
8.8.8.8.in-addr.arpa	name = dns.google.

Authoritative answers can be found from:

ubuntu@ubuntu-Inspiron-7773:~$



ubuntu@ubuntu-Inspiron-7773:~$ host 8.8.8.8
8.8.8.8.in-addr.arpa domain name pointer dns.google.
ubuntu@ubuntu-Inspiron-7773:~$ dig google.com

; <<>> DiG 9.18.12-0ubuntu0.22.04.3-Ubuntu <<>> google.com
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 30777
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;google.com.			IN	A

;; ANSWER SECTION:
google.com.		72	IN	A	142.250.72.110

;; Query time: 12 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Tue Sep 26 03:13:37 EDT 2023
;; MSG SIZE  rcvd: 55

ubuntu@ubuntu-Inspiron-7773:~$

ubuntu@ubuntu-Inspiron-7773:~$ host 142.250.72.110
110.72.250.142.in-addr.arpa domain name pointer lga34s32-in-f14.1e100.net.
ubuntu@ubuntu-Inspiron-7773:~$

*/