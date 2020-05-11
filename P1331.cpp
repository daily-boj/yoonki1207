#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

#define MAX_N 6

int chess[MAX_N][MAX_N] = { 0, };

int main() {
	bool isValid = true;
	int tmpX, tmpY, x, y, initX, initY;
	char str[4] = { 0 };
	scanf("%s", str);
	tmpX = initX = str[0] - 'A';
	tmpY = initY = str[1] - '0' - 1;
	chess[initY][initX] = 1;

	for (int i = 1; i < MAX_N*MAX_N; i++) {
		scanf("%s", str);
		x = str[0] - 'A';
		y = str[1] - '0' - 1;
		//printf("    %s (%d %d)\n", str,x,y);
		if (chess[y][x]==1) {
			isValid = false;
			//printf("%d %d\n", x, y);
		}
		else
			chess[y][x] = 1;
		if (i != 0 && isValid) {
			int dx = (int)abs(tmpX - x);
			int dy = (int)abs(tmpY - y);
			if (dx + dy != 3 || !dx || !dy) {
				//printf("%d %d : dx : %d, dy : %d\n", x, y,dx,dy);
				isValid = false;
			}
		}
		tmpX = x;
		tmpY = y;
	}
	int dx = (int)abs(tmpX - initX);
	int dy = (int)abs(tmpY - initY);
	if (dx + dy != 3 || !dx || !dy) {
		//printf("%d %d : dx : %d, dy : %d\n", x, y,dx,dy);
		isValid = false;
	}
	if (isValid)
		printf("Valid\n");
	else
		printf("Invalid\n");
}