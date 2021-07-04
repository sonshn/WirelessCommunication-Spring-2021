# pragma warning(disable:4996)
#include<stdio.h>

void main() {
    int data[7];
    int i;

    printf("\nEnter 4 bits((7,4) Hamming Encoder)\n");
    scanf("%1d", &data[0]);
    scanf("%1d", &data[1]);
    scanf("%1d", &data[2]);
    scanf("%1d", &data[3]);

    data[6] = data[0] ^ data[2] ^ data[3];
    data[5] = data[1] ^ data[2] ^ data[3];
    data[4] = data[0] ^ data[1] ^ data[2];

    printf("\nThe result of Hamming Encoder is\n");

    for (i = 0; i < 7; i++)
        printf("%d", data[i]);

}