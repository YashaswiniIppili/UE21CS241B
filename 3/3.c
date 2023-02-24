#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* arrangeSentence(char * s){
    //COMPLETE THE CODE
    int length = strlen(s);
    char *res = (char*)malloc(sizeof(char)*(length+9));
    int temp = 0;
    char word = '1';
    
    for(int i=length;i>=0;i--){
        if(s[i] == word){
            int x = i;
            while((s[i]!=' ') && (i>0)){i--;}
            if(i==0){i--;}
            int n = i+1;
            for(int j=n; j<x; j++){
                res[temp++] = s[j];
            }
            res[temp++] = ' ';
            word++;
            i=length+1;
        }
    }
    res[--temp] = '\0';
    return res;
}
    
int main() {
    char words[50];
    gets(words);
    int returnSize = sizeof(words)/sizeof(words[0]);
    char* original = arrangeSentence(words);
    printf("%s",original);
    printf("\n");
    return 0;
}
