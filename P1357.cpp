#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

int Rev(int x);

int main()
{
	int X, Y;
	scanf("%d %d", &X, &Y);
	printf("%d\n",Rev(Rev(X) + Rev(Y)));
	return 0;
}

int Rev(int x) {
	int ret = 0;
	int n = x;
	while (n != 0) {
		ret = (n % 10) + ret*10;
		n /= 10;
	}
	return ret;
}