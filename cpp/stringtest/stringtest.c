#include <stdio.h>
#include <string.h>

int main()
{
	printf("helloworld\n");
	char *str = "MMOKY";
	char str0[8] = "MMOKYL";
	int i;
	i = strncmp("MMOKY", str0, 3);
	printf("%d", i);
	return 0;
}
