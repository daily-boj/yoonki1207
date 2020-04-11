#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

int main() {
	int T, N;
	long long dp[101] = { 0,1,1,1,2,2 };
	scanf("%d",&T);
	while (T-- > 0) {
		scanf("%d",&N);
		for (int i = 5; i <= N; i++) {
			dp[i] = dp[i - 1] + dp[i - 5];
		}
		printf("%lld\n",dp[N]);
	}
}