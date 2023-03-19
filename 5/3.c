/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int** adj_list, int* visited, int course) {
    visited[course] = 1;
    for(int i=0; i<adj_list[course][0]; i++){
        int neighbor = adj_list[course][i+1];
        if (visited[neighbor] == 1 || dfs(adj_list, visited, neighbor)) {
            return true;
        }
    }
    visited[course] = 2;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize){
    // Create an adjacency list to represent the graph
    int** adj_list = calloc(numCourses, sizeof(int*));
    for(int i=0; i<numCourses; i++){
        adj_list[i] = calloc(numCourses+1, sizeof(int));
        adj_list[i][0] = 0;
    }
    for(int i=0; i<prerequisitesSize; i++){
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];
        adj_list[course][adj_list[course][0]+1] = prereq;
        adj_list[course][0]++;
    }
    // Run DFS on each course to detect cycles
    int* visited = calloc(numCourses, sizeof(int));
    for(int i=0; i<numCourses; i++){
        if (visited[i] == 0 && dfs(adj_list, visited, i)) {
            return false;
        }
    }
    return true;
}


int main() {
    int n, r;
     
    //printf("Enter number of courses: ");
    scanf("%d",&n);

    //printf("Enter number of prerequisites: ");
    scanf("%d",&r);

    int** matrix = calloc(r, sizeof(int*));
    for(int i=0; i<r; i++){
        matrix[i] = calloc(2, sizeof(int));
    }
 
    //printf("\nEnter matrix elements:\n");
    for(int i=0; i<r; i++){
        for(int j=0; j<2; j++){
            //printf("Enter element [%d,%d]: ",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
    }
    
    printf("%s", canFinish(n, matrix, r) ? "true" : "false");

    // Free allocated memory
    for(int i=0; i<r; i++){
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}