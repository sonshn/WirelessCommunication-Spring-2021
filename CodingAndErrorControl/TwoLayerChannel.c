# pragma warning(disable:4996)
# include<stdio.h>

void main() {
    int divisor[9] = { 1,0,0,0,0,0,1,1,1 };

    int data[24] = { 0, };//CRC encoder의 결과를 저장하는 배열: hamming encoder의 입력으로 이동

    int originaldata[16] = { 0, };//2 layer의 최종 결과를 저장하는 배열이자  최초로 입력하는 16비트를 저장하는 배열

    int hammingData[42] = { 0, };//hamming encoder의 결과를 저장하는 배열

    int z1[6], z2[6], z3[6];

    int z[6];

    int i, j;

    int div = 0;

    /*2 layer channel encoder*/
    printf("\nEnter the 16bits input of 2 layer Encoder\n: ");

    for (int i = 0; i < 16; i++) {
        scanf("%1d", &originaldata[i]);
        data[i] = originaldata[i];
    }

    for (int i = 0; i < 16; i++) {
        div = 0;

        if (data[i] == 0)
            continue;
        for (int j = i; j < i + 9; j++) {
            data[j] = divisor[div] ^ data[j];
            div++;
        }
    }

    for (int i = 0; i < 16; i++)
        data[i] = originaldata[i];

    /*Check code for 2 layer channel encoder*/
    //printf("\nresult: ");

    //for (int i = 0; i < 24; i++)
    //    printf("%d", data[i]);

    /*output of CRC-8 encoder to input of hamming encoder*/
    for (int i = 0; i < 6; i++) {
        hammingData[i * 7] = data[i * 4];
        hammingData[i * 7 + 1] = data[i * 4 + 1];
        hammingData[i * 7 + 2] = data[i * 4 + 2];
        hammingData[i * 7 + 3] = data[i * 4 + 3];
        hammingData[i * 7 + 4] = data[i * 4] ^ data[i * 4 + 1] ^ data[i * 4 + 2];
        hammingData[i * 7 + 5] = data[i * 4 + 1] ^ data[i * 4 + 2] ^ data[i * 4 + 3];
        hammingData[i * 7 + 6] = data[i * 4] ^ data[i * 4 + 2] ^ data[i * 4 + 3];
    }

    printf("\n");

    /*Check code for 2 layer channel hamming encoder*/
    //for (int i = 0; i < 42; i++)
    //    printf("%d", hammingData[i]);

    /////2 layer channel decoder/////
    for (int i = 0; i < 6; i++) {
        z1[i] = hammingData[i * 7 + 4] ^ hammingData[i * 7 + 2] ^ hammingData[i * 7 + 1] ^ hammingData[i * 7 + 0];
        z2[i] = hammingData[i * 7 + 5] ^ hammingData[i * 7 + 3] ^ hammingData[i * 7 + 2] ^ hammingData[i * 7 + 1];
        z3[i] = hammingData[i * 7 + 6] ^ hammingData[i * 7 + 3] ^ hammingData[i * 7 + 2] ^ hammingData[i * 7 + 0];
        z[i] = z1[i] * 4 + z2[i] * 2 + z3[i];

        if (z[i] == 1) {
            hammingData[i * 7 + 6] = !hammingData[i * 7 + 6];
        }
        if (z[i] == 2) {
            hammingData[i * 7 + 5] = !hammingData[i * 7 + 5];
        }
        if (z[i] == 3) {
            hammingData[i * 7 + 3] = !hammingData[i * 7 + 3];
        }
        if (z[i] == 4) {
            hammingData[i * 7 + 4] = !hammingData[i * 7 + 4];
        }
        if (z[i] == 5) {
            hammingData[i * 7 + 0] = !hammingData[i * 7 + 0];
        }
        if (z[i] == 6) {
            hammingData[i * 7 + 1] = !hammingData[i * 7 + 1];
        }
        if (z[i] == 7) {
            hammingData[i * 7 + 2] = !hammingData[i * 7 + 2];
        }
    }

    for (int i = 0; i < 6; i++) {
        data[i * 4] = hammingData[i * 7];
        data[i * 4 + 1] = hammingData[i * 7 + 1];
        data[i * 4 + 2] = hammingData[i * 7 + 2];
        data[i * 4 + 3] = hammingData[i * 7 + 3];
    }

    /*Check code for 2 layer channel hamming decoder*/
    //printf("\nThe result of 2 channel layer hamming decoder is\n");

    //for (int i = 0; i < 24; i++) {
    //   printf("%d", data[i]);
    //}

    for (int i = 0; i < 16; i++) {
        originaldata[i] = data[i];
    }

    for (int i = 0; i < 16; i++) {
        div = 0;

        if (data[i] == 0)
            continue;
        for (int j = i; j < i + 9; j++) {
            data[j] = divisor[div] ^ data[j];
            div++;
        }
    }

    printf("\nThe result of 2 layer Decoder is\n");

    for (int i = 0; i < 23; i++) {
        if (data[i] == 0 && i == 22) {
            for (int j = 0; j < 16; j++) {
                printf("%d", originaldata[j]);
            }
        }

        if (data[i] != 0) {
            printf("\nERROR!!\n");
            break;
        }
    }
}