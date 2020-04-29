#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printDouble(double x);

int main() {
	int A, B, C;
	int a, b, c;
	double x, y, z;
	double k;
	scanf("%d %d %d", &A, &B, &C);
	scanf("%d %d %d", &a, &b, &c);
	x = (double)A / a; y = (double)B / b; z = (double)C / c;
	k = min(x, min(y, z));
	double Al = A - k * a;
	double Bl = B - k * b;
	double Cl = C - k * c;
	printDouble(Al);
	printDouble(Bl);
	printDouble(Cl);

	return 0;
}

void printDouble(double x) {
	if (x == (int)x)
		printf("%d ", (int)x);
	else
		printf("%lf ", x);
	return;
}