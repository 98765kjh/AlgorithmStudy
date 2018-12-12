#include <stdio.h>

int main()
{
	int size;
	char num[128];
	
	scanf("%d", &size);
	scanf("%s", num);

	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum += (num[i] - '0');
	}

	printf("%d\n", sum);
}