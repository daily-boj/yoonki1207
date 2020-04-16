#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#define MAXX 987654321

int N, K; // 1<=N <=8
int arr_[8];
int cnt = 0;

int hell(int *arr, int day, int weight) { // day에 arr[day]를 이용해서 운동을 하면
	for (int i = 0; i < day ; i++) // 중복 체크
		for (int j = i+1; j < day +1; j++)
			if (arr[i] == arr[j])
				return 0;
	int now = weight - K + arr_[arr[day]];
	if (now < 500)
		return 0;

	if (day == N - 1) {
		return 1;
	}

	int ret = 0;
	for (int i = 0; i < N; i++) {
		arr[day + 1] = i;
		ret += hell(arr, day + 1, now);
	}
	return ret;
}

int main(){
	int arr[9] = { 0 };
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr_[i]);
	int ret = 0;
	for (int i = 0; i < N; i++) {
		arr[0] = i;
		ret += hell(arr, 0, 500);
	}
	printf("%d\n", ret);
	
	return 0;
}