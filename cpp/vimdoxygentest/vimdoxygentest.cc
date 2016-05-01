/**
 * @file vimdoxygentest.cc
 * @brief test for vimdoxygentest 
 * @author gaozhidf
 * @version 1.0
 * @date 2016-05-01
 */
#include <stdio.h>

/**
 * @brief youknowwhat is it
 *
 * @param i
 *
 * @return 
 */
int myfun(int i)
{
    return i + 1;
}

/**
 * @brief 
 *
 * @return 
 */
int main()
{   
    int i = myfun(1);
    printf("helloworld: %d\n", i);
    return 0;
}
