#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
#define MAX_N 200
#define MAX_M 10000
int comb[MAX_M][2];
int board[201][201] = { 0 };
int N, M;
int num = 0;

int main() {
	scanf("%d %d",&N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &comb[i][0], &comb[i][1]);
		board[comb[i][0]][comb[i][1]] = board[comb[i][1]][comb[i][0]] = 1;
	}
	
	for (int i = 3; i <= N; i++) {
		for (int j = 2; j < i; j++) {
			if (board[j][i]==1) {
				continue;
			}
			for (int k = 1; k < j; k++) {
				if (board[k][i]==1 || board[k][j]==1) {
					continue;
				}
				else
					num++;
			}
		}
	}
	printf("%d\n",num);
}