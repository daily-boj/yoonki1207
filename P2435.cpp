#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

int N, K, arr[100];

int main() {
	scanf("%d %d",&N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);
	int max_value = -2000000000;
	for (int i = 0; i + K - 1 < N; i++) {
		int tmp = 0;
		for (int j = i; j < K+i; j++) {
			tmp += arr[j];
		}
		max_value = max(max_value, tmp);
	}
	printf("%d\n",max_value);
}