#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void create_children(int level, int levelMax) {
    pid_t pid1, pid2;
    sleep(5);
    if(level<levelMax){
        pid1 = fork();
        if(pid1 == 0){
            printf("Level %d : Enfant pid %d de parent pid %d\n", level+1, getpid(), getppid());
            create_children(level+1, levelMax);
            if(level == levelMax-1){sleep(20);}
            exit(EXIT_SUCCESS);
        }
        else if(pid1 < 0){
            printf("Fork error\n");
            exit(EXIT_FAILURE);
        }
        pid2 = fork();
        if(pid2 == 0){
            printf("Level %d : Enfant pid %d de parent pid %d\n", level+1, getpid(), getppid());
            create_children(level+1, levelMax);
            if(level == levelMax-1){sleep(20);}
            exit(EXIT_SUCCESS);
        }
        else if(pid2 < 0){
            printf("Fork error\n");
            exit(EXIT_FAILURE);
        }
        wait(NULL);
        wait(NULL);
    }
}

int main(int argc, char *argv[]){
    int levelMax = atoi(argv[1]);
    create_children(1,levelMax);
    sleep(10);
}