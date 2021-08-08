#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int i;
    for(i=0;i<10;++i){
        printf("Server: sending line nr %d\n",i);
        sleep(1);
        fflush(stdout);
    }
    return (EXIT_SUCCESS);
}