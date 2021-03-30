#include <stdio.h>

int divideSearch(int *arr, int left, int right, int want);
int seqSearch(int *arr, int len, int want);

int main() {
    int arr[10] = {
        1, 7, 78, 91, 92, 99, 101, 198, 234, 235,
    };
    int res = divideSearch(arr, 0, 9, 91);
    printf("%d\n", res);
    return -1;
}

// The efficiency is the same as seqSearch.
int divideSearch(int *arr, int left, int right, int want) {
    if (left == right) {
        if (arr[left] == want) {
            return left;
        } else {
            return -1;
        }
    }
    int mid = (left + right)/2;
    int lVal = divideSearch(arr, left, mid, want);
    if (lVal != -1) {
        return lVal;
    }
    return divideSearch(arr, mid+1, right, want);
}

int seqSearch(int *arr, int len, int want) {
    for (int i=0; i<len; i++) {
        if (arr[i] == want) {
            return i;
        }
    }
    return -1;
}
