typedef struct intArr {
    int data[100];
    int len;
} intArr;

int getMaxVal(int i, int affordNow, intArr *weight, intArr *val);

int
main() {
    return -1;
}

int
getMaxVal(int i, int affordNow, intArr *weight, intArr *val) {
    int endIndex = ((*weight).len)-1;
    if (i == endIndex) {
        if (affordNow < (*weight).data[i]) {
            return 0;
        } else {
            return (*val).data[i];
        }
    }
    if (affordNow < (*weight).data[i]) {
        return getMaxVal(i+1, affordNow, weight, val);
    } else {
        return max(getMaxVal(i+1, affordNow, weight, val), getMaxVal(i+1, affordNow - (*weight).data[i], weight, val)) + (*val).data[i];
    }
}

int
max(int a, int b) {
    if (a < b) {
        return b;
    } else {
        return a;
    }
}
