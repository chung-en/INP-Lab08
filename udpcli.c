/*
 * Lab problem set for INP course
 * by Chun-Ying Huang <chuang@cs.nctu.edu.tw>
 * License: GPLv2
 */
#include "include/lib.h"

static int file_no = 0, seq_no = 0;
static int s = -1;
static struct sockaddr_in sin;
static int nfiles = INT_MAX;
static ack_t ack;

void recv_ack(int sig) {
	struct sockaddr_in csin;
	socklen_t csinlen = sizeof(csin);
	int rlen;

	usleep(256);

	static int recordfn = 0, recordsn = 0;
	while ((rlen = recvfrom(s, (void*) &ack, sizeof(ack), MSG_DONTWAIT, (struct sockaddr*) &csin, &csinlen)) > 0) {
		if (recordfn != ack.file_no || recordsn != ack.seq_no) {
			recordfn = ack.file_no;
			recordsn = ack.seq_no;
			printf("Receive ACK ");
			printack(&ack);
		}

		file_no = ack.file_no;
		seq_no = 0;

		if (file_no == nfiles) {
			exit(0);
		}

		memset(&ack, 0, sizeof(ack));
	}
}

int main(int argc, char *argv[]) {
	if(argc < 5) {
		return -fprintf(stderr, "usage: %s <path-to-read-files> <total-number-of-files> <port> <server-ip-address>\n", argv[0]);
	}

	char 	*path = argv[1];
	char 	filepath[30];
	int 	fr;

	nfiles = atoi(argv[2]);

	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(strtol(argv[argc-2], NULL, 0));
	if(inet_pton(AF_INET, argv[argc-1], &sin.sin_addr) != 1) {
		return -fprintf(stderr, "** cannot convert IPv4 address for %s\n", argv[argc-1]);
	}

	if((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
		err_quit("socket");

	signal(SIGALRM, recv_ack);
	ualarm( (useconds_t)( 1024 ), (useconds_t) 1024 );

	for (file_no = 0, seq_no = 0; file_no <= nfiles; ) {
		if (file_no == nfiles) continue;
		
		sprintf(filepath, "%s/%06d", path, file_no);
		
		fr = open(filepath, O_RDONLY);
		pkt_t pkt = {.file_no = file_no, .seq_no = seq_no, .eof = 0};
		
		if (fr == -1)
		{	
			err_quit("No such file");
		}
		else
		{
			/* Read file */
			seq_no = 0;
			while (read(fr, pkt.data, sizeof(pkt.data)) > 0) {
				if (file_no == ack.file_no && seq_no < ack.seq_no) {
					memset(&pkt.data, 0, sizeof(pkt.data));
					continue;
				}

				// printpkt(&pkt);

				/* Send packet */
				for (int i = 0; i < 32; i++) {
					if(sendto(s, (void*) &pkt, sizeof(pkt), 0, (struct sockaddr*) &sin, sizeof(sin)) < 0)
						perror("sendto");
					usleep(1);
				}
				
				pkt.seq_no++;
				seq_no++;

				memset(&pkt.data, 0, sizeof(pkt.data));
			}

			/* Send eof packet */
			pkt.eof = 1;
			for (int i = 0; i < 32; i++) {
				if(sendto(s, (void*) &pkt, sizeof(pkt), 0, (struct sockaddr*) &sin, sizeof(sin)) < 0)
					perror("sendto");
				usleep(1);
			}

			close(fr);

			file_no++;
		}

		memset(filepath, 0, sizeof(filepath));
	}

	close(s);
}
