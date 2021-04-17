#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int longestIncSubSeq(int *data, int len, int *maxRightPos);
void pArr(int *arr, int len);
int maxSumSubSeq(int *data, int len, int *left, int *right);
void maxSumSubSeq_getData(int *data, int len, int *maxSum, int *rights);

int main() {
    int LENARR = 10;
    int arr[LENARR];
    srand(time(0));
    for (int i=0; i<LENARR; i++) {
        arr[i] = rand()%100+1 - 55;
    }
    pArr(arr, LENARR);
    int maxRightPos;
    int maxLen = longestIncSubSeq(arr, LENARR, &maxRightPos);
    int maxLeftPos = maxRightPos - maxLen + 1;
    printf("longestIncSubSeq-> leftBound: %d; rightBound: %d;\n", maxLeftPos, maxRightPos);
    int left, right;
    int max = maxSumSubSeq(arr, LENARR, &left, &right);
    printf("maxSumSubSeq-> max: %d; leftBound: %d; rightBound: %d;\n", max, left, right);
}

// longestIncSubSeq will return the length of longest increased sub sequence of array "data". Parameter maxRightPos is the position of right bound index of the sub sequence.
int longestIncSubSeq(int *data, int len, int *maxRightPos) {
    int maxSeqLen = 1, maxSeqLenNow = 1;
    *maxRightPos = 0;
    for (int i=1; i<len; i++) {
        if (data[i-1] < data[i]) {
            maxSeqLenNow += 1;
            if (maxSeqLen < maxSeqLenNow) { //(max <= now) will make sub sequence that closer to right more preferable.
                maxSeqLen = maxSeqLenNow;
                *maxRightPos = i;
            }
        } else {
            maxSeqLenNow = 1;
        }
    }
    return maxSeqLen;
}

// maxSumSubSeq_bug is not a completely correct program.
int maxSumSubSeq_bug(int *data, int len, int *left, int *right) {
    int sum = data[0], reserve = 0;
    *left = 0;
    *right = 0;
    for (int i=1; i<len; i++) {
        reserve += data[i];
        if (reserve > 0) {
            sum += reserve;
            reserve = 0;
            *right = i;
        }
    }
    reserve = 0;
    for (int i=0; i<*right; i++) {
        reserve += data[i];
        if (reserve <= 0) {
            sum -= reserve;
            reserve = 0;
            *left = i+1;
        }
    }
    return sum;
}

// maxSumSubSeq will return the max sum of sub sequence of "data". Parameter "left" and "right" are left index and right index of the sub sequence.
int maxSumSubSeq(int *data, int len, int *left, int *right) {
    int maxSum[len];
    int rights[len];
    maxSumSubSeq_getData(data, len, maxSum, rights);
    int max = maxSum[0], maxIndex = 0;
    for (int i=1; i<len; i++) {
        if (max < maxSum[i]) {
            max = maxSum[i];
            maxIndex = i;
        }
    }
    *left = maxIndex;
    *right = rights[maxIndex];
    return max;
}

// maxSumSubSeq_getData will assign data to parameters "maxSum" and "rights". maxSum[i] is the max sum of sub sequence whose index starts from i and rights[i] indicates the right bound of that sub sequence.
void maxSumSubSeq_getData(int *data, int len, int *maxSum, int *rights) {
    maxSum[len-1] = data[len-1];
    rights[len-1] = len-1;
    for (int i=len-2; i>=0; i--) {
        if (maxSum[i+1] <= 0) {
            maxSum[i] = data[i];
            rights[i] = i;
        } else {
            maxSum[i] = data[i] + maxSum[i+1];
            rights[i] = rights[i+1];
        }
    }
}

// pArr will print array "arr" of int type with length indicated by "len". If "len" is greater than the real length of given array, the result is unpredictable.
void pArr(int *arr, int len) {
    for (int i=0; i<len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
