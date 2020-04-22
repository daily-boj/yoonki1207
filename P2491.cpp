#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main() {
	int N; scanf("%d", &N);
	int increasingLenth = 1, decreasingLenth = 1;
	int maxLenth = 1;
	int before, now;
	scanf("%d", &before);
	for (int i = 1; i < N; i++) {
		scanf("%d", &now);
		if (before > now) {
			increasingLenth = 1;
			decreasingLenth++;
		}
		else if (before < now) {
			decreasingLenth = 1;
			increasingLenth++;
		}
		else {
			decreasingLenth++;
			increasingLenth++;
		}
		before = now;
		maxLenth = max(maxLenth, max(increasingLenth, decreasingLenth));
	}
	printf("%d\n", maxLenth);
}