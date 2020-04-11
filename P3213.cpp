#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
int getNum(char* s) {
	char pizza[3][4] = { "1/4", "1/2", "3/4" };
	if (strcmp(s, pizza[0])==0) {
		return 1;
	}
	else if (strcmp(s, pizza[1]) == 0) {
		return 2;
	}
	else if (strcmp(s, pizza[2]) == 0) {
		return 3;
	}
	return -1;
}
int main() {
	vector<int> half, quarter, quarter3;
	int N, pizzaNum = 0;
	scanf("%d",&N);
	for (int i = 0; i < N; i++) {
		char pizza[4] = { 0 };
		scanf("%s", pizza);
		
		int num = getNum(pizza);
		if (num == 2) {
			if (!half.empty()) {
				half.pop_back();
				pizzaNum++;
			}
			else {
				half.push_back(num);

			}
		}
		else {
			if (num == 1) {
				quarter.push_back(num);
			}
			else {
				quarter3.push_back(num);
			}
			if (!quarter.empty() && !quarter3.empty()) {
				quarter.pop_back();
				quarter3.pop_back();
				pizzaNum++;
			}
		}
	}
	if (!half.empty()&&!quarter.empty()) {
		half.pop_back();
		quarter.pop_back();
		pizzaNum++;
	}
	int a = 0;
	while (!quarter.empty()) {
		quarter.pop_back();
		a++;
	}
	if (!half.empty()) {
		pizzaNum++;
	}
	while (!quarter3.empty()) {
		quarter3.pop_back();
		pizzaNum++;
	}
	pizzaNum += a / 4;
	a %= 4;
	if (a != 0)
		pizzaNum++;
	printf("%d\n",pizzaNum);
}//