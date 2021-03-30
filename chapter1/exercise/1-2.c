#include <string.h>
#include <stdio.h>

int getPos(char *str);

int main() {
    char testStrs[10][7] = {
        "a", "ab", "ac", "bd", "abc", "abd", "bek", "axyz", "cdexz", "fghijk"
    };
    for (int i=0; i<10; i++) {
        printf("%s: %d\n", testStrs[i], getPos(testStrs[i]));
    }
    return -1;
}

int getPos(char *str) {
    int matchMax[6][26];
    int bitHideNum[6];
    int sumRow;
    for (int i=0; i<26; i++) {
        matchMax[0][i] = 1;
    }
    bitHideNum[0] = 26;
    for (int i=1; i<6; i++) {
        sumRow = 0;
        for (int j=0; j<26; j++) {
            if (j == 0) {
                matchMax[i][j] = bitHideNum[i-1] - matchMax[i-1][j];
            } else {
                matchMax[i][j] = matchMax[i][j-1] - matchMax[i-1][j];
            }
            sumRow += matchMax[i][j];
        }
        bitHideNum[i] = sumRow;
    }
    int len = strlen(str);
    int bitPos = len-1;
    int val = 0;
    for (int i=0; i<bitPos; i++) {
        val += bitHideNum[i];
    }
    int letterPos;
    for (int i='a'; i<str[0]; i++) {
        letterPos = i - 'a';
        val += matchMax[bitPos][letterPos];
    }
    bitPos -= 1;
    for (int i=1; i<len; i++) {
        for (int j=str[i-1]+1; j<str[i]; j++) {
            letterPos = j - 'a';
            val += matchMax[bitPos][letterPos];
        }
        bitPos -= 1;
    }
    val += 1;
    return val;
}
