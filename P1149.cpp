#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FOR(i, n) for(int i = 0 ; i < n ; i++)

int house[1000][3];
int cache[1000][3];
int N;

int solution(const int _n, const int _color) {
	int n = _n;
	int color = _color % 3;
	if (n == N) {
		return 0;
	}
	int&ret = cache[n][color];
	if (ret != 0) {
		return ret;
	}
	ret = house[n][color];
	ret = min(solution(n + 1, color + 1), solution(n + 1, color + 2)) + ret;
	return ret;
}

int main(){
	cin >> N;
	FOR(i, N)
		FOR(c, 3)
		scanf("%d",&house[i][c]);
	int ret = solution(0, 0);
	for (int i = 1; i < 3; i++) {
		ret = min(ret, solution(0, i));
	}
	printf("%d\n",ret);
	return 0;
}
