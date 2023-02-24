// A teacher wants to know how many columns are in a spreadsheet. She asks one of her students to decode the number of columns given the column title (as string) that represents the column as it appears in a spreadsheet. Write a program to assist the same

#include<stdio.h>
#include<string.h>
#define N 100

int TitleGenerator(char *string) 
{
       // Write your code here
       int result;
       while(string && *string)
       {
           result=result*26 + (*string) - 'A' + 1;
           string++;
       }
       return result;
}

int main() 
{
    char string[N];
    scanf("%s",string);
    printf("%d", TitleGenerator(string));
    return 0;
}