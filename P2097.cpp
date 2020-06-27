#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	int N;
	int a[1000000] = { 0 };
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	vector<int> v;
	for (int i = 0; i < N; i++) {
		if (v.empty() || v.back() < a[i]) 
			v.push_back(a[i]);		
		else {
			vector<int>::iterator iter = lower_bound(v.begin(), v.end(), a[i]);
			*iter = a[i];
		}
	}
	int len = v.size();
	printf("%d", len);
}