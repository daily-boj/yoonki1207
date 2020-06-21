#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, k;
	vector<int> v;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	int i = 0;
	long long int sum = 0LL;
	sort(v.begin(), v.end());
	for (int j = 0; j < n; j++) {
		sum += (long long int)v.at(j) * (long long int)i;
		if (i < k)
			i++;
	}
	printf("%lld\n", sum);
}