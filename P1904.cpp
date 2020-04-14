#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>
#define FOR(i, n) for(int i = 0 ; i < n ; i++)
using namespace std;

int main() {
	int now, a, b;
	a = 1;
	b = 1;
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {

		now = (a + b)%15746;
		a = b % 15746;
		b = now % 15746;
	}
	printf("%d",b);
}