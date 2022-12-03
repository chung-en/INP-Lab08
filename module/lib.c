#include "../include/lib.h"

void printpkt(pkt_t *pkt) {
    printf("name: %06d\tseq: %d\teof: %d\n%s\n", pkt->file_no, pkt->seq_no, pkt->eof, pkt->data);
}

void printack(ack_t *ack) {
    printf("name: %06d\tseq: %d\n", ack->file_no, ack->seq_no);
}