#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "specs.h"

void get_hostname(char *hostname, size_t size){
    FILE *fp;
    char path[1035];

    fp = popen("hostname", "r");

    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    if (fgets(path, sizeof(path), fp) != NULL) {
        path[strcspn(path, "\n")] = '\0';
        strncpy(hostname, path, size - 2);
        hostname[size - 1] = '\0';
    }

    pclose(fp);
}


void get_username(char *username, size_t size){
    FILE *fp;
    char path[1035];

    fp = popen("whoami", "r");

    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    if (fgets(path, sizeof(path), fp) != NULL) {
        path[strcspn(path, "\n")] = '\0';
        strncpy(username, path, size - 1);
        username[size - 1] = '\0';
    }

    pclose(fp);
}

void get_pwd(char *pwd, size_t size){
    FILE *fp;
    char path[1035];

    fp = popen("basename `pwd`", "r");

    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    if (fgets(path, sizeof(path), fp) != NULL) {
        path[strcspn(path, "\n")] = '\0';
        strncpy(pwd, path, size - 1);
        pwd[size - 1] = '\0';
    }

    pclose(fp);
}
