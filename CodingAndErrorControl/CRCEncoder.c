#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

void main(void) {
    int divisor[9] = { 1,0,0,0,0,0,1,1,1 };//G = X^8 + X^2 + X + 1
    int data[24] = { 0, };//encoding �� ����� �����ϴ� �迭
    int originaldata[16] = { 0, };//�Է��� �����ϴ� �迭

    int i, j;

    printf("Enter the data in 16bits\n: ");

    for (int i = 0; i < 16; i++) {
        scanf("%1d", &originaldata[i]);
        data[i] = originaldata[i];
    }

    int div = 0;//�������� �� �� divisor�� �� �ڸ��� ����ϱ� ���� ����

    for (int i = 0; i < 16; i++) {
        div = 0;

        if (data[i] == 0)//���ڸ��� 0�̸� 1�ڸ� shift
            continue;
        for (int j = i; j < i + 9; j++) {//���ڸ��� 1�̸� ��ġ�� ���߾� XOR ����
            data[j] = divisor[div] ^ data[j];
            div++;
        }
    }

    for (int i = 0; i < 16; i++)
        data[i] = originaldata[i];

    /*CRC encoder�� ��� ���*/
    printf("\nThe result of CRC encoding is\n: ");

    for (int i = 0; i < 24; i++)
        printf("%d", data[i]);

}