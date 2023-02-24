/*
A person wants to go around a matrix in zig zag pattern but doesn’t know the path. You
are given a matrix of 2D array of n rows and m columns. You are required print this
matrix in ZIG-ZAG fashion as shown in figure.

Example 1:
Input:
1 2 3
4 5 6
7 8 9
Output:

1 2 4 7 5 3 6 8 9
*/

#include<stdio.h>

int main() 
    {
        int r,c;
        scanf("%d",&r);
        scanf("%d",&c);
        int matrix[r][c] ;
        int p,q;
        for(p=0;p<r;p++)
        {
          for(q=0;q<c;q++)
          {
            scanf("%d",&matrix[p][q]);
          }
        }
      
        // size of final matrix
        int final[r*c];
        // initial value of final matrix
        final[0] = matrix[0][0]; 
        int up=0, down=0, s=1;
        while(s < r*c)
        {
            
            while(up>=1&&down<c-1)
            { 
                up--;
                down++;
                final[s++] = matrix[up][down];
            }
            
            if(down<c-1)
            { 
                down++;
                final[s++] = matrix[up][down];
            }
            else if(up<r-1) 
            { 
                up++;
                final[s++] = matrix[up][down];
            }
            
            while(up<r-1&&down>=1) 
            { 
                up++;
                down--;
                final[s++] = matrix[up][down];
            }
            if(up<r-1)
            { 
                up++;
                final[s++] = matrix[up][down];
            }
            else if(down<c-1)
            { 
                down++;
                final[s++] = matrix[up][down];
            }  
           
        }
        for (int i=0; i<r*c; i++)
            printf("%d ",final[i]);
        return 0;  
}