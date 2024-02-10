#include <stdio.h>
#include "auth.h"
#include <string.h>

#define LEN 80

int main(void){
    printf("hello world");
    // char* username = "admin";
    // char* password = "moxa";

     char username[LEN], password[LEN];
     puts("輸入username: ");
    fgets(username, LEN, stdin);
     puts("輸入password: ");
    fgets(password, LEN, stdin);

    VerifyUser(username, password);
}

int VerifyUser(char* username, char* password){
    char* u = "admin";
    char* p = "moxa";

if( username[strlen(username) - 1] == '\n'){
    username[strlen(username) - 1] = '\0';
}

    if(strcmp(username, u) == 0) {
        puts("密碼正確");
    }
    else{
        puts("密碼錯誤");
    }
    return 0;
}