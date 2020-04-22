#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

char A[] = { "1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./ " };
char B[] = { "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,. " };

int main() {
	char c;
	while ((c = getchar()) != EOF) {
		for (int i = 0; i < 45; i++) {
			if (c == A[i]) {
				printf("%c",B[i]);
				break;
			}
		}
		if (c == '\n')
			printf("\n");
	}
}