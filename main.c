#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "src/specs/specs.h"
#include "src/display/ascii.h"
#include "src/utils/utils.h"
#include "src/lib/str.h"

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

    //printf("!! TEST !! : %d\n", str_hspace("a f  b"));

    while (statement){
        char command[5000];

        printf("[%s@%s] ~ /%s : ", username, hostname, current_dir);
        fgets(command, 5000, stdin);

        // -- exit cmd
        if (!strcmp(command, "exit\n")) break;


        if (str_hspace(command)){
            char** tokens;
	    tokens = str_split(command, ' ');

            if (tokens){
                for (int i = 0; *(tokens + i); i++){
                    printf("-> %s\n", *(tokens + i));
                    free(*(tokens + i));
                }
                free(tokens);
    	    }


        } else {
            printf("\n");
            system(command);
            printf("\n");
        }

    }

    return 0;
}

