/*  
gcc -c gccItest.cc -o gccItest.o -I ./include/
gcc -c myfun.cc -o myfun.o -I ./include/
gcc -o test gccItest.o myfun.o -I ./include
*/

#include <stdio.h>

#include "myfun.h"
#include "myfun_i.h"

int main()
{
    class_myfun2 my2;
    class_myfun1 my1;
    my2.myfun2();
    my2.print_hello();
    my1.myfun1();
    return 0;
}