# pragma warning(disable:4996)
#include<stdio.h>

int main(void) {

    int data[7];
    int z;
    int z1, z2, z3;

    int i;

    printf("\nEnter 4 bits((7,4) Hamming Decoder)\n");
    for (i = 0; i < 7; i++)
        scanf("%1d", &data[i]);

    z1 = data[4] ^ data[2] ^ data[1] ^ data[0];
    z2 = data[5] ^ data[3] ^ data[2] ^ data[1];
    z3 = data[6] ^ data[3] ^ data[2] ^ data[0];

    //printf("%d\n%d\n%d\n", z1, z2, z3);

    z = z1 * 4 + z2 * 2 + z3 * 1;

    //printf("\n%d", z);

    if (z == 1) {
        data[6] = !data[6];
    }
    if (z == 2) {
        data[5] = !data[5];
    }
    if (z == 3) {
        data[3] = !data[3];
    }
    if (z == 4) {
        data[4] = !data[4];
    }
    if (z == 5) {
        data[0] = !data[0];
    }
    if (z == 6) {
        data[1] = !data[1];
    }
    if (z == 7) {
        data[2] = !data[2];
    }

    printf("\nThe result of Hamming Decoder is\n");

    for (i = 0; i < 4; i++) {
        printf("%d", data[i]);
    }

    return 0;
}