#include <stdio.h>
#include <string.h>


/**
 * rm_nline : remove '\n' after string
 */
void rm_nline(char *str){
    int len = strlen(str);

    if (len > 0 && *(str + len - 1) == '\n'){
        *(str + len - 1) = '\0';
    }
}


/**
 * my_strcmp : strcmp built from scratch
 * !! We assume that 'source' and 'tocmp' have the same length
 * !! Depracated...
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

/**
 * str_include : check if 'toinc' is in 'source'
 */
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
