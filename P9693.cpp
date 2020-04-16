#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#define MAXX 987654321

int p(int n, int i) {
	if (i == 0)
		return 1;
	return n * p(n, i - 1);
}

int main(){
	int t = 1;
	for (;;){
		int N, ret = 0;
		scanf("%d", &N);
		if (N == 0)
			break;
		for (int i = 1; i <= 12; i++) {
			ret += (N / p(5, i));
			if (N < p(5, i))
				break;
		}
		printf("Case #%d: %d\n", t++, ret);
	}
	return 0;
}