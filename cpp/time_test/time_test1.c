#include <stdio.h>
#include <sys/timeb.h>
#include <time.h>

long long getSystemTime() {
    struct timeb t;
    ftime(&t);
    return 1000 * t.time + t.millitm;
}
 
int main() {
    long long start=getSystemTime();
    sleep(3);
    long long end=getSystemTime();
	
    printf("time: %lld ms\n", end-start);
    
	time_t t = time(0); 
    char tmp[64];
	start = getSystemTime();
    strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A ",localtime(&t) ); 
    puts( tmp ); 
	printf("time start: %lld\n", start);
	
	return 0;

}
