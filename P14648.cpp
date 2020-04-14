#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define FOR(i, n) for(int i = 0 ; i < n ; i++)

void SWAP(int *x, int *y) {
	int t = *x;
	*x = *y;
	*y = t;
	return;
}

long long SUM(int *arr, int i, int j) {
	long long sum = 0;
	for (int a = i; a <= j; a++)
		sum += arr[a];
	return sum;
}

int main() {
	int n, q;
	int arr[1001];
	scanf("%d %d", &n, &q);
	FOR(i, n)
		scanf("%d", arr + i);
	for (int i = 0; i < q; i++) {
		long long ret = 0;
		int nQ;
		scanf("%d", &nQ);
		if (nQ == 1) {
			int tmpArr[2];
			for (int j = 0; j < 2; j++) {//
				scanf("%d", tmpArr + j);
			}
			ret = SUM(arr, tmpArr[0] - 1, tmpArr[1] - 1);
			SWAP(&arr[tmpArr[0] - 1], &arr[tmpArr[1] - 1]);
		}
		else {
			int tmpArr[4];;
			for (int j = 0; j < 4; j++) {
				scanf("%d", tmpArr + j);
			}
			ret = SUM(arr, tmpArr[0] - 1, tmpArr[1] - 1) - SUM(arr, tmpArr[2] - 1, tmpArr[3] - 1);
		}
		printf("%lld\n", ret);
	}

	return 0;
}