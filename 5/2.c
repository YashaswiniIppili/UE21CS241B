/*You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.*/

#include <stdio.h>
#include <stdlib.h>

int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    int perimeter = 0;
    for (int i = 0; i < gridRowSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            if (grid[i][j] == 1) {  // if cell is part of the island
                perimeter += 4;  // add 4 to the perimeter
                // check left neighbor
                if (j > 0 && grid[i][j-1] == 1) {
                    perimeter -= 2;  // subtract 2 from the perimeter
                }
                // check top neighbor
                if (i > 0 && grid[i-1][j] == 1) {
                    perimeter -= 2;
                }
            }
        }
    }
    return perimeter;
}

int main() {
    int r, c;
   
    scanf("%d", &r);
    ;
    scanf("%d", &c);

    int **matrix = (int **) malloc(r * sizeof(int *));
    for (int i=0; i<r; ++i) {
        matrix[i] = (int *) malloc(c * sizeof(int));
    }

 
    for (int i=0; i<r; ++i) {
        for (int j=0; j<c; ++j) {
            printf("", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Island perimeter: %d\n", islandPerimeter(matrix, r, c));

    for (int i=0; i<r; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}