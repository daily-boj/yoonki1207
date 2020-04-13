#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
char mat[401][401];
int T, r, c;

bool checkIsCandy(int y, int x) {
	if (mat[y][x] != 'o')
		return false;
	if ((mat[y][x-1] == '>'&&mat[y][x+1] == '<' && (x - 1 >= 0 && x + 1 < c)) ||
		(mat[y-1][x] == 'v'&&mat[y+1][x] == '^' && (y - 1 >= 0 && y + 1 < r)))
		return true;
	return false;
}


int main() {
	scanf("%d", &T);
	int sum = 0;
	while (T--) {
		sum = 0;
		scanf("%d %d", &r, &c);
		for (int i = 0; i < r; i++) {
			char tmp[401];
			scanf("%s", tmp);
			for (int j = 0; j < c; j++)
				mat[i][j] = tmp[j];
		}
		for (int y = 0; y < r; y++)
			for (int x = 0; x < c; x++)
				if (checkIsCandy(y, x))
					sum++;
		printf("%d\n", sum);
	}
	return 0;
}