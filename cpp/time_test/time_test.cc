#include <time.h> 
#include <stdio.h> 
int main( void ) 
{ 
    time_t t = time(0); 
    char tmp[64]; 
    strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A 本年第%j天 %z",localtime(&t) ); 
    puts( tmp );

    strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A %S",localtime(&t) ); 
    puts( tmp ); 
    return 0; 
}
