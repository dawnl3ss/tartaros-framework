#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "src/specs/specs.h"

int main(){
    char hostname[256];
    char username[256];

    system("clear");

    while (1){
        char command[5000];

        get_hostname(hostname, sizeof(hostname));
        get_username(username, sizeof(username));

        printf("[%s@%s] ~ ", username, hostname);
        fgets(command, 5000, stdin);

        system(command);
        printf("\n");
    }

    return 0;
}
