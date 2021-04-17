#include <stdio.h>
#include <stdlib.h>

void cover(int **arr, int posX, int posY, int errX, int errY, int *id);
void chessCover(int **arr, int posX, int posY, int len, int errX, int errY, int *id);
void print2D(int **arr, int xl, int yl);

int
main() {
    int boardSize = 8;
    int *chessBoard[boardSize];
    int *chessRow;
    for (int i=0; i<boardSize; i++) {
        chessRow = (int*)malloc(sizeof(int)*boardSize);
        chessBoard[i] = chessRow;
    }
    chessBoard[0][0] = 0;
    chessBoard[0][1] = 3;
    int id = 1;
    print2D(chessBoard, boardSize, boardSize);
    chessCover(chessBoard, 0, 0, boardSize, 0, 0, &id);
    print2D(chessBoard, boardSize, boardSize);
}

// chessCover will cover the chess board with "the three block".
// The chess board is defined by 2D array "arr", position of left-top block "posX" and "posY" and the size of chess board "len". The "errX" and "errY" represent the special block of a chess board.
void chessCover(int **arr, int posX, int posY, int len, int errX, int errY, int *id) {
    if (len == 2) {
        cover(arr, posX, posY, errX, errY, id);
        return;
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

// cover will cover the chess board whose "len" is 2 with "id".
// i.e. given arr data[2][2] and call cover(data, 0, 0, 0, 1, &id); The result of data will be 
// {
//      id, 0,
//      id, id,
// }
void cover(int **arr, int posX, int posY, int errX, int errY, int *id) {
    for (int i=posX; i<posX+2; i++) {
        for (int j=posY; j<posY+2; j++) {
            if (i != errX || j != errY) {
                arr[i][j] = *id;
            }
        }
    }
    *id += 1;
}

// print2D will print all elements of 2D array "arr".
void print2D(int **arr, int xl, int yl) {
    for (int i=0; i<xl; i++) {
        for (int j=0; j<yl; j++) {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
}
