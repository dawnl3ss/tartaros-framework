#include <stdio.h>
#include <string.h>

// False -> 0 | True -> 1

/**
 *
 * my_strcmp : strcmp built from scratch
 * !! We assume that 'source' and 'tocmp' have the same length
 *
 */
int my_strcmp(char* source, char* tocmp){
    if (strlen(source) != strlen(tocmp))
        return 0;

    for (size_t i = 0; *(source + i) != '\0'; i++){
        if (*(source + i) != *(tocmp + i))
            return 0;
    }

    return 1;
}

int str_include(char* source, char* toinc){
    for (size_t i = 0; *(source + i) != '\0'; i++){
        if (i >= strlen(toinc))
            break;

        if (*(source + i) != *(toinc + i))
            return 0;
    }

    return 1;
}


int str_hspace(char* str){
    for (size_t i = 0; *(str + i) != '\0'; i++){
        if (*(str + i) == ' ')
            return 1;
    }

    return 0;
}
