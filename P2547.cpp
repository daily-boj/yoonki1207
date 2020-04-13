#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

int main() {
	int T, R;
	long long int num, sum = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &R);
		sum = 0;
		for (int i = 0; i < R; i++) {
			scanf("%lld", &num);
			sum += num;
			sum %= R;
		}
		if (sum == (long long)0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}