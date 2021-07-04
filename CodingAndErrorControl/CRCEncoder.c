#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

void main(void) {
    int divisor[9] = { 1,0,0,0,0,0,1,1,1 };//G = X^8 + X^2 + X + 1
    int data[24] = { 0, };//encoding 된 결과를 저장하는 배열
    int originaldata[16] = { 0, };//입력을 저장하는 배열

    int i, j;

    printf("Enter the data in 16bits\n: ");

    for (int i = 0; i < 16; i++) {
        scanf("%1d", &originaldata[i]);
        data[i] = originaldata[i];
    }

    int div = 0;//나눗셈을 할 때 divisor의 각 자리를 사용하기 위한 변수

    for (int i = 0; i < 16; i++) {
        div = 0;

        if (data[i] == 0)//앞자리가 0이면 1자리 shift
            continue;
        for (int j = i; j < i + 9; j++) {//앞자리가 1이면 위치에 맞추어 XOR 연산
            data[j] = divisor[div] ^ data[j];
            div++;
        }
    }

    for (int i = 0; i < 16; i++)
        data[i] = originaldata[i];

    /*CRC encoder의 결과 출력*/
    printf("\nThe result of CRC encoding is\n: ");

    for (int i = 0; i < 24; i++)
        printf("%d", data[i]);

}