#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); 

    // gestion erreur
    if (pid < 0) {
        printf("Fork error");
        exit(EXIT_FAILURE);
    // processus enfant
    } else if (pid == 0) {
        int val;
        printf("Entrer un entier : ");
        scanf("%d", &val);//recuperation de la valeur entree
        exit(val);//transmission de la valeur
    } else {
        int ret_enfant;
        wait(&ret_enfant);//attente du retour de l'enfant
        if (WIFEXITED(ret_enfant)) {
            int val = WEXITSTATUS(ret_enfant);//recuperation de la valeur
            printf("Processus enfant renvoie : %d\n", val);
        }
    }
    return 0;
}



