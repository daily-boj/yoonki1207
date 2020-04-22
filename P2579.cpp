#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int dp[301];
int sc[301];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", sc + i);
	dp[0] = sc[0];
	dp[1] = dp[0] + sc[1];
	dp[2] = max(sc[0], sc[1]) + sc[2];
	for (int i = 3; i < n; i++)
		dp[i] = max(sc[i - 1] + dp[i - 3], dp[i - 2]) + sc[i];
	printf("%d\n", dp[n-1]);
}