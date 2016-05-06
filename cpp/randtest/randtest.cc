/* 产生介于1 到10 间的随机数值，此范例未设随机数种子，完整的随机数产生请参考
srand（）*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM 10000

int main()
{
    int i,j;

    for(i=0;i<10;i++)
    {
        j=1+(int)(10.0*rand()/(RAND_MAX+1.0));
        printf("%d ",j);
    }

    srand((int)time(0));
    for(i=0;i<10;i++)
    {
        j=(int)rand()%10000;
        printf("%d ",j);
    }


    char str[6];
    sprintf(str, "%d", NUM);

    printf("%s\n", str);
    printf("%d\n", (int)time(0));
    printf("%d\n", (int)(unsigned) time(NULL));
    return 0;
}