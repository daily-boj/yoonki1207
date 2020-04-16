#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#define MAXX 987654321
int N, M, B, _B;
int blocks[250000];

int main() {
	int timeMin = MAXX;
	int heightMax = 0;
	scanf("%d %d %d", &N, &M, &_B);
	for (int i = 0; i < M*N; i++)
		scanf("%d", &blocks[i]);

	for (int h = 0; h <= 256; h++) {
		B = _B;
		int nBlanks = 0, nUp = 0;
		long long stackedTime = 0;
		for (int i = 0; i < M*N; i++) {
			if (blocks[i] < h)
				nBlanks += h - blocks[i];
			else if (blocks[i] > h)
				nUp += blocks[i] - h;
		}
		if ((B + nUp) < nBlanks) // 0 3 3 3 일때 nBlanks만 3 nUp은 0
			break;

		stackedTime += nUp * 2;
		stackedTime += nBlanks * 1;
		
		if (timeMin == stackedTime) {
			heightMax = max(heightMax, h);
		}
		else if (timeMin > stackedTime) {
			timeMin = stackedTime;
			heightMax = h;
		}
	}
	printf("%d %d\n", timeMin, heightMax);
	return 0;
}