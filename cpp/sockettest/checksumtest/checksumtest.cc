/*
    Raw UDP sockets
    Silver Moon (m00n.silv3r@gmail.com)
*/
#include <stdio.h> //for printf
#include <string.h> //memset
#include <sys/socket.h>    //for socket ofcourse
#include <stdlib.h> //for exit(0);
#include <errno.h> //For errno - the error number
#include <netinet/udp.h>   //Provides declarations for udp header
#include <netinet/ip.h>    //Provides declarations for ip header
 
/* 
    96 bit (12 bytes) pseudo header needed for udp header checksum calculation 
*/

struct Position
{
        uint16_t x;
        uint16_t y;
        uint16_t z;
};

struct UdpHeader
{
    uint16_t srcport;
    uint16_t dstport;
    uint16_t length;
    uint16_t checksum;
};

struct pseudo_header
{
    Position op;
    Position tp;
    UdpHeader udpheader;
    uint16_t payload;
};
 
/*
    Generic checksum calculation function
*/
uint16_t csum(uint16_t *ptr, int nbytes) 
{
    uint16_t sum = 0;
    while(nbytes > 1) {
        sum += *ptr++;
        nbytes -= 2;
    }

    if(nbytes == 1) {
        // note: sizeof(uint8_t) = sizeof(unsigned char *) = 1,  
        sum += *(uint8_t *)ptr; 
    }
 
    sum = (sum >> 16) + (sum & 0xffff);
    sum = sum + (sum >> 16);
    
    return ~sum;
}
 
int main (void)
{   
    pseudo_header header;
    Position op, tp;
    UdpHeader udpheader;
    uint16_t check_sum;

    op.x = 1;
    op.y = 1;
    op.z = 1;
    tp.x = 1;
    tp.y = 1;
    tp.z = 1;
    udpheader.srcport = 0;
    udpheader.dstport = 0;
    udpheader.length = 0;
    udpheader.checksum = 0;


    header.op = op;
    header.tp = tp;
    header.udpheader = udpheader;
    header.payload = 3;

    // printf("%s\n", (char *)header );
    printf("%d\n", header.payload);

    check_sum = csum((uint16_t *) &header, sizeof(header));
    printf("%d\n", check_sum);

    header.udpheader.checksum = check_sum;
    check_sum = csum((uint16_t *) &header, sizeof(header));
    printf("%d\n", check_sum);


    return 0;
}
 
//Complete 