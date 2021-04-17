#include <stdio.h>

void getPageNum(int num, int *sum0To9);

int
main() {
    int num = 11;
    int sum0To9[10];
    getPageNum(num, sum0To9);
    for (int i=0; i<10; i++) {
        printf("%d ", sum0To9[i]);
    }
}

// Length of sum0To9 must be greater than 10.
void
getPageNum(int num, int *sum0To9) {
    int thisNum = num;
    int sum0To9Val[10] = {
        0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000,
    };
    int zeroSub[10] = {
        1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111,
    };
    for (int i=0; i<10; i++) {
        sum0To9[i] = 0;
    }
    int valNow, count0To9 = 0, bitPos = 0, bitVal = 1;
    do {
        valNow = thisNum % 10;
        count0To9 += valNow * sum0To9Val[bitPos];
        for (int i=0; i<valNow; i++) {
            sum0To9[i] += bitVal;
        }
        sum0To9[valNow] += ((num % bitVal) + 1);
        bitPos += 1;
        bitVal *= 10;
        thisNum /= 10;
    } while(thisNum != 0);
    for (int i=0; i<10; i++) {
        sum0To9[i] += count0To9;
    }
    sum0To9[0] -= zeroSub[bitPos-1];
}
