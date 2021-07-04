#pragma warning(disable:4996)
#include<stdio.h>

void main(void) {
    int divisor[9] = { 1,0,0,0,0,0,1,1,1 };
    int data[24] = { 0, };//Encoder�� ���, ���⼭�� ���� �����߱� ������ 1��Ʈ�� �Է¹���
    //twoLayerChannel.c������ ���� �Է¹޴� �κ� ���� �ٷ� hamming decoder�� ����� �Է����� ����
    int result[24] = { 0, };//CRC decoder�� ����� �����ϱ� ���� �迭

    int i, j;

    printf("Enter the data in 24bits\n: ");

    for (int i = 0; i < 23; i++) {
        scanf("%1d", &data[i]);
    }

    int div = 0;

    for (int i = 0; i < 16; i++) {
        div = 0;

        if (data[i] == 0)
            continue;
        for (int j = i; j < i + 9; j++) {
            data[j] = divisor[div] ^ data[j];
            div++;
        }
    }

    /*Print the result of CRC encoder*/
    printf("\nresult: \n");

    /*�������� 0�̸�, �� result�� ��� ��Ʈ�� 0�̸� no error, �ƴϸ� ERROR!! ���*/
    for (int i = 0; i < 23; i++) {
        //printf("%d", data[i]);

        if (data[i] == 0 && i == 22) {
            printf("\nNo error\n");
        }

        if (data[i] != 0) {
            printf("\nERROR!!\n");
            break;
        }
    }
}