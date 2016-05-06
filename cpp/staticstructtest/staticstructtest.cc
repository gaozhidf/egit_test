#include <stdio.h>

struct A {
    int a;
    int b;
};

struct B {
    struct A a;
    int b;
};

static struct B a = {{5,3}, 2};


struct something
{
     int a;
     int b;
};

class Myclass
{
public:
     static something c1;
};

//it needed to define c1
something Myclass::c1;

int main(int argc, char **argv) {


    printf("A.a: %d\n", a.a.a);


    Myclass::c1.a = 0;
    Myclass::c1.b = 0;
    printf("%d %d\n", Myclass::c1.a, Myclass::c1.b);
    return 0;
}