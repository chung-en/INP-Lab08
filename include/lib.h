#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define err_quit(m) { perror(m); exit(-1); }

#define MAXLINE 80

typedef struct {
    int     file_no;
    int     seq_no;
    int     eof;
    char    data[MAXLINE];
} pkt_t;

typedef struct {
    int file_no;
    int seq_no;
} ack_t;

void printpkt(pkt_t*);
void printack(ack_t*);