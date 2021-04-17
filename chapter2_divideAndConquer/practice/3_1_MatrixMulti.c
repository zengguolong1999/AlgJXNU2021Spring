int main() {
    int len = 6;
    int matrixes[len][2] = {
        { 30, 35 }, { 35, 15 }, { 15, 5 }, { 5, 10 }, { 10, 20 }, { 20, 25 },
    };
    return -1;
}

void MatrixChain(int *matrixes[2], int len, int **cost, int **split) {
    for (int i=0; i<len; i++) {
        cost[i][i] = 0;
    }
    for (int botBound=len-1, off=1; botBound>1; botBound--, off++) {
        for (int row=0; row<botBound; row++) { //now: [row, row+off]
            int min = 0;
            for (int sepe=row; sepe<row+off; sepe++) { //separate
                int currentCost = cost[row][sepe] + cost[sepe+1][row+off] + matrixes[row][0]*matrixes[sepe][1]*matrixes[row+off][1];
                if (currentCost < min) {
                    min = currentCost;
                }
            }
        }
    }
}
