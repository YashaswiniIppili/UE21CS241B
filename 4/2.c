#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(const int*) a - *(const int*) b;
}


void diagonalSort( int matSize, int matColSiz, int mat[][matColSiz]){
   int rSize = matSize;
   int cSize = matColSiz;
    int** res = (int**) malloc(rSize * sizeof(int*));
    int* tmp = (int*) malloc(cSize * sizeof(int));

    for(int i = 0; i < rSize; i++) {
        res[i] = (int*) malloc(cSize * sizeof(int));
    }
    res[rSize-1][0] = mat[rSize-1][0];
    res[0][cSize-1] = mat[0][cSize-1];
    
    for(int r = rSize-2; r >= 0; r--) {
        int idx = 0, ridx = r, cidx = 0;
        while(ridx < rSize && cidx < cSize) {
            tmp[idx++] = mat[ridx++][cidx++];
        }
        qsort(tmp, idx, sizeof(int), cmp);
        idx = 0; ridx = r; cidx = 0;
        while(ridx < rSize && cidx < cSize) {
            res[ridx++][cidx++] = tmp[idx++];
        }
    }
    
    for(int c = 1; c < cSize-1; c++) {
        int idx = 0, ridx = 0, cidx = c;
        while(ridx < rSize && cidx < cSize) {
            tmp[idx++] = mat[ridx++][cidx++];
        }
        qsort(tmp, idx, sizeof(int), cmp);
        idx = 0; ridx = 0, cidx = c;
        while(ridx < rSize && cidx < cSize) {
            res[ridx++][cidx++] = tmp[idx++];
        }
    }
    free(tmp);
    for(int i=0;i<rSize;i++)
    {
        for(int j=0;j<cSize;j++)
        {
            printf("%d ",res[i][j]);
        }
    }
}


int main() {
       int row;
  int column;
 
  // take row and column size
  //printf("Enter row size: ");
  scanf("%d", &row);
  //printf("Enter column size: ");
  scanf("%d", &column);
 
  int arr[row][column];
 
  // take matrix elements as input
 // printf("Enter elements for %dx%d matrix:\n", row, column);
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<column;j++)
    {
      //printf("arr[%d][%d]: ",i,j);
      scanf("%d", &arr[i][j]);
    }
    //printf("\n");
  }

    diagonalSort(  row, column, arr);
 
    return 0;

}