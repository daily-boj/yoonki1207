#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>
#define FOR(i, n) for(int i = 0 ; i < n ; i++)
using namespace std;

int main() {
	int N, K, num = 0;
	int a[10];
	scanf("%d %d", &N, &K);
	FOR(i, N)
		scanf("%d", a + i);
	for (int i = N - 1; i >= 0; i--) {
		if (a[i] <= K) {
			num += K / a[i];
			K = K % a[i];
		}
	}
	printf("%d\n", num);
}
