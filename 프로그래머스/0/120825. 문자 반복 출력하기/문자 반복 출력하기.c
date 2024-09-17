#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* my_string, int n) {
    char* answer = (char*)malloc(sizeof(my_string)*n);
    
    int k=0;
    for(int i=0;i<sizeof(my_string);i++){
        for(int j=0;j<n;j++)
            answer[k++] = my_string[i];
    }
    
    return answer;
}