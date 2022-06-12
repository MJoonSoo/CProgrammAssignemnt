
//202201278 문준수 컴프 과제 : COVID-19 Information

#include <stdio.h> //stdio.h 헤더
#define _CRT_SECURE_NO_WARNINGS //Printf 관련 보안 이슈 제거
#include "neededfunction.h"
#include <iostream>
int main(void)
{
    FILE* fp;
    fp = fopen("lon.bin", "a+");

    if (fp == NULL)
    {
        fprintf(stderr, "파일 실행 불가. \n");
            exit(1);
    }
    while (1)
    {

        int input = listnumber();

        switch (input) {
        case 1:
            func1(fp);
            break;
        case 2:
            search(fp);
            break;
        case 3:
            goto exit;
        default:
            printf("잘못된 입력값.\n");
            break;
        }
    }
exit:
    fclose(fp);
    return 0;
}
