#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

bool isBug(char *start, int i) {
	if (i+2 >= 100)
		return false;
	return start[i] == 'B' &&
		start[i+1] == 'U' &&
		start[i+2] == 'G';
}

void catchBug(char *s, int i) {
	for (int k = i; s[k] != 0 || k < 98; k++) {
		if (s[k + 3] == 0) {
			s[k] = 0;
			return;
		}
		s[k] = s[k+3];
	}
}
//1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
//BUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGB
int main() {
	char c;
	int i = 0;
	while (1) {
		char s[101] = { 0 };
		i = 0;
		while((c=getchar())!='\n' && c!=EOF && i<100){
			s[i++] = c;
		}s[i] = 0;
		if (c == EOF)break;
		string str(s); 
		string bug("BUG");
		size_t found = str.find(bug);
		while (found!=string::npos) {
			str.replace(found, 3, "");
			found = str.find(bug, 0);
		}
		const char *p;
		p = str.c_str();
		printf("%s\n",p);
	}
}