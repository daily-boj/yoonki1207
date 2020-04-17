#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#define MAXX 987654321

int partyCome[50][50];
int knowTruth[50];
queue<int> vTruth;
int trueParty[50];
int N, M;
int maxLie = 0;

void solve() {
	while(!vTruth.empty()){
		//printf("%d, ", vTruth.front());
		//printf("\n");
		if (1) {
			int k = vTruth.front();
			knowTruth[k] = -1;
			vTruth.pop();
			for (int m = 0; m < M; m++) {
				if (partyCome[m][k]!=0) {
					partyCome[m][k] = -1;
					trueParty[m] = 1;
					for (int n = 0; n < N; n++) {
						if (partyCome[m][n]!=0) {
							partyCome[m][n] = -1;
							if (knowTruth[n] != 1 && knowTruth[n] != -1)
								vTruth.push(n);
							knowTruth[n] = 1;
						}
					}
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	int kT;
	scanf("%d", &kT);
	FOR(i, kT) {
		int n;
		scanf("%d", &n);
		knowTruth[n - 1] = 1;
		vTruth.push(n - 1);
	}
	for (int i = 0; i < M; i++) {
		int numP;
		scanf("%d", &numP);
		if (numP == 0)
			maxLie--;
		for (int j = 0; j < numP; j++) {
			int n;
			scanf("%d", &n);
			partyCome[i][n - 1] = 1;
		}
	}
	/*printf("BEFORE\n");
	for (int i = 0; i < M; i++, printf("\n"))
		for (int j = 0; j < N; j++)
			printf("%d ", partyCome[i][j]);*/
	solve();
	/*printf("AFTER\n");
	for (int i = 0; i < M; i++, printf("\n"))
		for (int j = 0; j < N; j++)
			printf("%d ", partyCome[i][j]);
	printf("TRUE PARTY\n");*/
	for (int i = 0; i < M; i++)
		if (trueParty[i] == 0)
			maxLie++;
	printf("%d\n", maxLie);
}