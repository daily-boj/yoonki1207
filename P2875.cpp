#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#define MAXX 987654321

int main() {
	int N, M, K, left, maxTeam = -1;
	scanf("%d %d %d", &N, &M, &K);
	left = M + N;
	for (int i = 0; i <= K; i++) {
		if (N - i < 0 || M - K + i < 0)
			continue;
		int m = min((N - i) / 2, (M - K + i));
		maxTeam = max(maxTeam, m);
		//printf("%d %d / %d %d / %d\n", N - 1, M - K + i, (N - i) / 2, M - K + i, m);
	}
	printf("%d\n", maxTeam);
}