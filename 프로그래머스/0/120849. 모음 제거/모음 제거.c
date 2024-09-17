#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* my_string) {
    char* answer = (char*)malloc(strlen(my_string)+1);
    
    int j=0;
    for(int i=0;i<strlen(my_string)+1;i++){
        if(my_string[i]=='a' || my_string[i]=='e'||my_string[i]=='i'||my_string[i]=='o'||my_string[i]=='u')
            continue;
        
        answer[j++] = my_string[i];
    }
    
    return answer;
}