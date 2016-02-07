#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* isPangram(int, char**);

int main(int argc, char *argv[]) {
    char const* const fileName = argv[1];
    FILE *f = fopen(fileName, "r");
    char* res;
    char line[1024];
    int _strings_size = 0;
    int _strings_i;
    fgets(line, sizeof(line), f);
    _strings_size = atoi(line);
    char* _strings[_strings_size];
    for(_strings_i = 0; _strings_i < _strings_size; _strings_i++) {
        char* _strings_item;
        _strings_item = (char *)malloc(102400 * sizeof(char));
        fgets(_strings_item, 102400 * sizeof(char), f);
        _strings[_strings_i] = (char *) _strings_item;
        
    }
    fclose(f);
    res = isPangram(_strings_size, _strings);
    for(_strings_i = 0; _strings_i < _strings_size; _strings_i++) {
        printf("%c",res[_strings_i]);
    }
    printf("\n");
    return 0;
}

char* isPangram(int strings_size, char** strings) {
    int i,j,k;
    char character;
    int compare;
    int alphabet[26];
    int counter=0;
    char* result = (char *)malloc(sizeof(char)*(strings_size));
    for(k=0; k<strings_size; k++){
        for(i=0; i<26;i++){
            alphabet[i]=0;
        }
        for(j=0; j<strlen(strings[k]);j++){
            character=strings[k][j];
            compare = (int)character-97;
            if(compare>=0 && compare<=95){
                if(alphabet[compare]==0){
                    counter++;
                    alphabet[compare]=1;
                }
                if(counter>=26){
                    result[k]='1';
                    break;
                }
            }
            
        }
        if(counter<26){
            result[k]='0';
        }
        counter=0;
    }
    return result;
}