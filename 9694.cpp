#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

#define INF 987654321

int N, M;
int gp[20][20];
bool vis[20];
int d[20];
vector<int> route[20];

void initMat() {
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if(i==j)
				gp[i][j] = 0;
			else
				gp[i][j] = INF;
	for (int i = 0; i < 20; i++) {
		vis[i] = false;
		route[i].clear();
	}
}

int getSmallIndex() {
	int min = INF;
	int index = 0;
	for (int i = 0; i < M; i++) {
		if (!vis[i] && d[i] < min) {
			min = d[i];
			index = i;
		}
	}
	//printf("returned index : %d\n", index);
	return index;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; t++) {
		initMat();
		scanf("%d %d", &N, &M);
		for (int n = 0; n < N; n++) {
			int x, y, r;
			scanf("%d %d %d", &x, &y, &r);
			gp[x][y] = gp[y][x] = r;
		}
		for (int i = 0; i < M; i++) {
			d[i] = gp[0][i];
			route[i].clear();
			route[i].push_back(i);
			//printf("%d, ", route[i].at(0));
		}
		// 0-1, 0-2, 0-3, 1-4, 1-5, 2-5
		vis[0] = true;
		for (int j = 0; j < M - 1; j++) {
			int index = getSmallIndex();
			vis[index] = true;
			// update
			for (int i = 0; i < M; i++) {
				if (!vis[i]) {
					if (d[i] > d[index] + gp[index][i]) {
						d[i] = d[index] + gp[index][i];
						route[i].clear();
						vector<int>::iterator iter;
						//printf("pushed! : ");
						for (iter = route[index].begin(); iter != route[index].end(); ++iter) {
							route[i].push_back(*iter);
							//printf("%d->", *iter);
						}
						route[i].push_back(i);
						//printf("%d\n",i);
					}
				}
			}
		}
		if (d[M - 1] == INF)
			printf("Case #%d: -1\n", t + 1);
		else {
			printf("Case #%d: 0",t+1);
			vector<int>::iterator iter;
			for (iter = route[M - 1].begin(); iter != route[M - 1].end(); iter++)
				printf(" %d", *iter);
			printf("\n");
		}
	}
}