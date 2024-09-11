#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "src/specs/specs"
#include "src/display/ascii.h"
#include "src/utils/utils.h"

int main(){
    // signal(SIGINT, SIG_IGN);
    char hostname[256];
    char username[256];
    char current_dir[500];

    system("clear");
    printf("[>_] Starting Tartaros Framework...\n\n");

    print_ascii();
    printf("\n");

    int statement = 1;

    get_hostname(hostname, sizeof(hostname));
    get_username(username, sizeof(username));
    get_pwd(current_dir, sizeof(current_dir));


    while (statement){
        char command[5000];

        printf("[%s@%s] ~ /%s : ", username, hostname, current_dir);
        fgets(command, 5000, stdin);

        if (!strcmp(command, "exit\n")) break;
	
	char months[] = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    	char** tokens;



        printf("\n");
        system(command);
        printf("\n");

    }

    return 0;
}

