#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#define MAXX 9876543987654321LL

int N, M;
char board[101][101];
char milk[101][101];
char B_[9] = { "|-\\/<v>^" };

int main() {
	//char c = '|';
	//printf("%c",c);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", board[i]);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			milk[i][j] = board[j][M-i-1];
		}
	}
	//printf("%d\n", '\\');
	for (int i = 0; i < M; i++, printf("\n"))
		for (int j = 0; j < N; j++) {
			char& t = milk[i][j];
			switch (t) {
			case '-':
				t = '|';
				break;
			case '|':
				t = '-';
				break;
			case '/':
				t = '\\';
				break;
			case '\\':
				t = '/';
				break;
			case '^':
				t = '<';
				break;
			case '<':
				t = 'v';
				break;
			case 'v':
				t = '>';
				break;
			case '>':
				t = '^';
				break;
			}
			printf("%c", t);
		}
}