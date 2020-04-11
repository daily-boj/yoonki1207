#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
void printOct(int x) {
	int ret = 0;
	ret += x % 10 * 1;
	x /= 10;
	ret += x % 10 * 2;
	x /= 10;
	ret += x % 10 * 4;
	printf("%d",ret);
}
int main() {
	bool arr[1000000] = { 0 };
	char c;
	int i = 0;
	while ((c = getchar()) != '\n') {
		arr[i] = (c == '1');
		i++;
	}
	int ret = 0, j = 0;
	if (i % 3 == 1) {
		//00
		j = 2;
	}
	else if (i % 3 == 2) {
		//0
		j = 1;
	}
	for(int k = j+1 ; k <= i+j ; k++) {
		ret = ret * 10 + (int)(arr[k-j-1]);
		if (k % 3 == 0) {
			printOct(ret);
			ret = 0;
		}
	}
}//