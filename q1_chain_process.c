#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    pid_t pid;
    int nbChild = atoi(argv[1]);

    for(int i=0; i<nbChild; i++){
        pid = fork();
        // gestion des erreurs
        if(pid<0){
            printf("Fork error\n");
            return 1;
        }
        // on verifie qu'il s'agit bien de l'enfant
        else if(pid == 0){
            printf("Enfant pid %d de parent pid %d\n",getpid(),getppid());
        }
        // on fait quitter la boucle au parent 
        else {
            wait(NULL);
            break;
        }

        sleep(5);
    }
}

