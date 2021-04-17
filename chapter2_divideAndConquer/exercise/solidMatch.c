#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

char menName[5][20] = {
    "吕布", "刘备", "孔明", "周瑜", "曹操",
};
char womenName[5][20] = {
    "貂蝉", "大桥", "小桥", "上香", "阿丑",
};

int
main() {
    int men[5][5] = {
        0, 1, 2, 4, 3,
        0, 2, 1, 3, 4,
        4, 0, 2, 1, 3,
        2, 1, 3, 0, 4,
        2, 0, 1, 3, 4,
    };
    int women[5][5] = {
        4, 0, 1, 3, 2,
        3, 1, 2, 0, 4,
        3, 2, 1, 4, 0,
        0, 1, 3, 2, 4,
        2, 3, 4, 1, 0,
    };
    int matched[5] = {
        -1, -1, -1, -1, -1,
    };
    bool isWomenMatched[5] = {
        false, false, false, false, false,
    };
    int matchCount = 0;
    while (matchCount < 5) {
        for (int manIndex=0; manIndex<5; manIndex++) {
            if (matched[manIndex] < 0) {
                for (int j=0; j<5; j++) {
                    int womanIndex = men[manIndex][j];
                    if (isWomenMatched[womanIndex]) {
                        int theThree; // theThree means the other man who likes the woman.
                        for (theThree = 0; theThree < 5; theThree++) {
                            if (matched[theThree] == womanIndex) {
                                break;
                            }
                        }
                        bool newCompetitorWin = false;
                        for (int k=0; k<5; k++) {
                            if (women[womanIndex][k] == theThree) {
                                break;
                            }
                            if (women[womanIndex][k] == manIndex) {
                                newCompetitorWin = true;
                                break;
                            }
                        }
                        if (newCompetitorWin) {
                            matched[manIndex] = womanIndex;
                            matched[theThree] = -1;
                            break;
                        }
                    } else {
                        matched[manIndex] = womanIndex;
                        isWomenMatched[womanIndex] = true;
                        matchCount += 1;
                        break;
                    }
                }
            }
        }
    }
    //output
    for (int i=0; i<5; i++) {
        printf("%s ", menName[i]);
    }
    printf("\n");
    for (int i=0; i<5; i++) {
        printf("%s ", womenName[matched[i]]);
    }
}
