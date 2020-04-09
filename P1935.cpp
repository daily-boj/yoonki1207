#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

int N;
int nums[100] = { 0 };
vector<string> v;



bool isCalc(string s) {
	char c = s[0];
	return c == '*' || c == '/' || c == '+' || c == '-';
}
double calculate(double x, double y, char calc) {
	char switch_on = calc;
	switch (switch_on)
	{
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		return x / y;
	default:
		break;
	}
	return 0;
}

string processData(char* s) {
	int i = 0;
	while (s[i] != '\0' || s[i] != NULL || s[i] != 0) {
		if (s[i] >= 'A'&&s[i] <= 'Z') {
			v.push_back(to_string(nums[s[i] - 'A']));
		}
		else {
			v.push_back(to_string(s[i]));
			if (isCalc(v.back())) {
				char calc = v.back()[0];
				v.pop_back();
				double B = stod(v.back()); v.pop_back();
				double A = stod(v.back()); v.pop_back();
				double RET = calculate(A, B, calc);
				v.push_back(to_string(RET));
			}
			else {
				printf("%f, ", stod(v.back()));
			}
		}

		i++;
	}
	return v.back();
}
// 1 2 3 *+4 5 /-
// 1 6 +4 5 /-
// "2 3 *"->"6"
int main() {
	char syntax[101];
	scanf("%d", &N);
	scanf("%s",syntax);
	for (int i = 0; i < N; i++)
		scanf("%d",nums+i);
	string s = processData(syntax);
	cout << s;
	return 0;
}