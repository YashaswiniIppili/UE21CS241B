// Ram realized he had forgotten to add one bar of chocolate while sorting chocolates by length in inches. Write a program to determine the index at which the chocolate should be inserted given the length of the chocolate.


#include <stdio.h>

int searchInsert(int* array, int length, int n)
{
    int i=0;
    int j=0;
    while(array[i]<length && i<n)
    {
        i++;
        j++;
    }
    return j;
}

int main()
{
    int length,n;
    scanf("%d",&length);
    scanf("%d",&n);
    int array[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    int result = searchInsert(array,length,n);
    printf("%d",result);
    return 0;
}