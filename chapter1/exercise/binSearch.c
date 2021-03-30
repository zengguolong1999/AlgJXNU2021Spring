#include <stdio.h>

int binSearch(int *sortedArr, int left, int right, int want);

int
main() {
    int sortedArr[10] = {
        1, 7, 78, 91, 92, 99, 101, 198, 234, 235,
    };
    int res = binSearch(sortedArr, 0, 9, 91);
    printf("%d\n", res);
    return -1;
}

int
binSearch(int *sortedArr, int left, int right, int want) {
    if (left > right) {
        return -1;
    }
    int mid = (left + right)/2;
    if (want == sortedArr[mid]) {
        return mid;
    } else if (want < sortedArr[mid]) {
        return binSearch(sortedArr, left, mid-1, want);
    } else {
        return binSearch(sortedArr, mid+1, right, want);
    }
}

// This is really a stupid program, because the index of wanted number belongs to sub array.
//int
//binSearch(int *sortedArr, int len, int want) {
//    if (len == 0) {
//        return -1;
//    }
//    int mid = len/2;
//    if (want == sortedArr[mid]) {
//        return mid;
//    } else if (want < sortedArr[mid]) {
//        return binSearch(sortedArr, len/2, want);
//    } else {
//        if (len % 2 == 0) {
//            return binSearch(&sortedArr[mid+1], len/2 -1, want);
//        } else {
//            return binSearch(&sortedArr[mid+1], len/2, want);
//        }
//    }
//}
