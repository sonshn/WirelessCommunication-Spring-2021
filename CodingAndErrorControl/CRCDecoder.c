#pragma warning(disable:4996)
#include<stdio.h>

void main(void) {
    int divisor[9] = { 1,0,0,0,0,0,1,1,1 };
    int data[24] = { 0, };//Encoder의 출력, 여기서는 따로 구현했기 때문에 1비트씩 입력받음
    //twoLayerChannel.c에서는 따로 입력받는 부분 없이 바로 hamming decoder의 출력을 입력으로 받음
    int result[24] = { 0, };//CRC decoder의 결과를 저장하기 위한 배열

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

    /*나머지가 0이면, 즉 result의 모든 비트가 0이면 no error, 아니면 ERROR!! 출력*/
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