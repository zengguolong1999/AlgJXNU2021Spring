// The problem comes from book page 13.
#include <stdio.h>

typedef struct t_stack {
    int printStack[100];
    int st; // st indicates the index where data will push into.
} stack;

void init(stack *s) {
    (*s).st = 0;
}

void push(stack *s, int data) {
    (*s).printStack[(*s).st++] = data;
}

int pop(stack *s) {
    return (*s).printStack[(*s).st--];
}

int intPermutationCount(int sum, int bound);
void pArr(int *arr, int len);
void pIntPerm(int sum, int first, stack *s);

int main() {
    //int res = intPermutationCount(6, 6);
    stack s;
    init(&s);
    pIntPerm(8, 8, &s);
    return 0;
}

void pIntPerm(int sum, int first, stack *s) {
    if (sum == 0) {
        pArr((*s).printStack, (*s).st);
        pop(s);
        return;
    }
    if (sum < first) {
        first = sum;
    }
    for (int i=first; i>=1; i--) {
        push(s, i);
        pIntPerm(sum-i, i, s);
    }
    pop(s);
}

int intPermutationCount(int sum, int bound) {
    if (sum == 1 || bound == 1) {
        return 1;
    }
    if (sum == bound) {
        return 1 + intPermutationCount(sum, bound-1);
    }
    if (sum < bound) {
        return intPermutationCount(sum, sum);
    }
    return intPermutationCount(sum-bound, bound) + intPermutationCount(sum, bound-1);
}

// pArr will print array "arr" of int type with length indicated by "len". If "len" is greater than the real length of given array, the result is unpredictable.
void pArr(int *arr, int len) {
    for (int i=0; i<len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
