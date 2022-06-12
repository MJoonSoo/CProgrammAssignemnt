#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include "neededfunction.h"

#define size 400



typedef struct information
{
	char nation[size];
	char vaccined[size];
	char pos[size];
}
VAC;


int listnumber()
{
	int number;

	printf("1. input\n");
	printf("2. search\n");
	printf("3. 999\n");

	printf("input:");
	scanf("%d", &number);
	return number;
}

void func1(FILE* fp)
{
	getchar();

	VAC data;

	printf("국가명: ");
	gets_s(data.nation, size);
	printf("확진자 수: ");
	gets_s(data.pos, size);
	printf("백신 접종자수: ");
	gets_s(data.vaccined, size);

	fwrite(&data, sizeof(data), 1, fp);
}

void search(FILE* fp)
{
	VAC data;
	char word[size];

	getchar();
	printf("Nations :");
	gets_s(word, size);

	fseek(fp, 0, SEEK_SET);
	while (!feof(fp))
	{
		fread(&data.nation, sizeof(data), 1, fp);
		if (strcmp(data.nation,word) == 0)
		{
			printf("확진자 수 : %s\n", data.pos);
			printf("백신 접종자 수 : %s\n", data.vaccined);
				return;
		}
	}
	printf("일치하는 국가 없음.\n");
}

