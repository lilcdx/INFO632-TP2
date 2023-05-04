#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    pid_t pid = fork();
    //gestion erreur
    if (pid < 0) {
        printf("Fork error");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        printf("Enfant : pid %d\n", pid);
        sleep(10);
        exit(EXIT_SUCCESS);
    } 
    return 0;
}