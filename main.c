#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "src/specs/specs.h"

int main(){
    signal(SIGINT, SIG_IGN);
    char hostname[256];
    char username[256];

    system("clear");

    int statement = 1;

    while (1){
        char command[5000];

        get_hostname(hostname, sizeof(hostname));
        get_username(username, sizeof(username));

        printf("[%s@%s] ~ ", username, hostname);
        fgets(command, 5000, stdin);

        if (command == "exit") statement = 0;

        printf("\n");
        system(command);
        printf("\n");

    }

    return 0;
}
