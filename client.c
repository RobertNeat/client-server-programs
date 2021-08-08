#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUF_SIZE 2048

int main(int argc, char** argv){
    /*trying to run command*/
    FILE *command_result = popen("./server","r");
    if(command_result){
        char bufor[BUF_SIZE];
        /*reading output line*/
        sleep(2);
        fgets(bufor,BUF_SIZE,command_result);
        /*if "file" was not finished*/
        while(!feof(command_result)){
            printf("Server sent: %s",bufor);
            fgets(bufor,BUF_SIZE,command_result);
        }
        /*end of reading results*/
        pclose(command_result);
        fflush(stdout);
        return EXIT_SUCCESS;
    }
    else{
        printf("Popen function failed.\n");
        fflush(stdout);
        return EXIT_FAILURE;
    }
}