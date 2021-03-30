#include <stdio.h>

int divideSearch(int *arr, int left, int right, int want);
void cover(int *arr, int posX, int posY, int errX, int errY, int *id);
void chessCover(int *arr, int posX, int posY, int len, int errX, int errY, int *id);

int
main() {
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

// a bad case for long code.
//void chessCover(int *arr, int posX, int posY, int len, int errX, int errY, int *id) {
    //if (len == 2) {
        //for (int i=posX; i<len; i++) {
            //for (int j=posY; j<len; j++) {
                //if (i != errX || j != errY) {
                    //arr[i][j] = *id;
                //}
            //}
        //}
        //*id += 1;
        //return;
    //}
    //int midX = posX + len/2;
    //int midY = posY + len/2;
    //if (errX < midX && errY < midY) {
        //arr[midX][midY-1] = *id;
        //arr[midX-1][midY] = *id;
        //arr[midX][midY] = *id;
        //*id += 1;
    //} else if (errX < midX && errY < midY) {
        ////something
    //} else if (errX < midX && errY < midY) {
        ////something
    //} else {
        ////something
    //}
//}

void chessCover(int *arr, int posX, int posY, int len, int errX, int errY, int *id) {
    if (len == 2) {
        cover(arr, posX, posY, errX, errY, id);
    }
    int midX = posX + len/2;
    int midY = posY + len/2;
    if (errX < midX && errY < midY) {
        cover(arr, midX-1, midY-1, midX-1, midY-1, id);
        chessCover(arr, posX, posY, len/2, errX, errY, id);
        chessCover(arr, posX, midY, len/2, midX-1, midY, id);
        chessCover(arr, midX, posY, len/2, midX, midY-1, id);
        chessCover(arr, midX, midY, len/2, midX, midY, id);
    } else if (errX < midX && errY >= midY) {
        cover(arr, midX-1, midY-1, midX-1, midY, id);
        chessCover(arr, posX, posY, len/2, midX-1, midY-1, id);
        chessCover(arr, posX, midY, len/2, errX, errY, id);
        chessCover(arr, midX, posY, len/2, midX, midY-1, id);
        chessCover(arr, midX, midY, len/2, midX, midY, id);
    } else if (errX >= midX && errY < midY) {
        cover(arr, midX-1, midY-1, midX, midY-1, id);
        chessCover(arr, posX, posY, len/2, midX-1, midY-1, id);
        chessCover(arr, posX, midY, len/2, midX-1, midY, id);
        chessCover(arr, midX, posY, len/2, errX, errY, id);
        chessCover(arr, midX, midY, len/2, midX, midY, id);
    } else {
        cover(arr, midX-1, midY-1, midX, midY, id);
        chessCover(arr, posX, posY, len/2, midX-1, midY-1, id);
        chessCover(arr, posX, midY, len/2, midX-1, midY, id);
        chessCover(arr, midX, posY, len/2, midX, midY-1, id);
        chessCover(arr, midX, midY, len/2, errX, errY, id);
    }
}

void cover(int *arr, int posX, int posY, int errX, int errY, int *id) {
    for (int i=posX; i<posX+2; i++) {
        for (int j=posY; j<posY+2; j++) {
            if (i != errX || j != errY) {
                arr[i][j] = *id;
            }
        }
    }
    *id += 1;
}
