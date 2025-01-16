#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

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

        get_pwd(current_dir, sizeof(current_dir));
        printf("[%s@%s] ~ /%s : ", username, hostname, current_dir);
        fgets(command, 5000, stdin);
        rm_nline(command);

        // -- exit cmd
        if (my_strcmp(command, "exit")) break;

        // -- cd system
        if (str_include(command, "cd")){

            char** tokens;
	    tokens = str_split(command, ' ');
            chdir(*(tokens + 1));
            continue;
        }

        if (my_strcmp(command, "htb")){
            printf("\nHack The Box | Tool, made by dawnl3ss.\n\n");
            continue;
        }


        printf("\n");
        system(command);
        printf("\n");
        

    }

    return 0;
}

