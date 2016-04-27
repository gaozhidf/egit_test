#include "so_test.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 

int test_what(int *num)
{
    test_a();
    int alen = strlen("nihao");
    printf("%s\n", "hello c");
    int nihao = open("/dev/pts/3", O_RDWR);
    printf("%d\n", alen);
    printf("%d\n", alen);
    *num++;
    printf("%d\n", num);

    return 0;
}

void mytest(const unsigned char* in, const unsigned int inlen, unsigned char* out)
{

int i;

for (i = 0;i < inlen;i++)
{

        *out++ = *in++;
}

}