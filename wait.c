#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    FILE* arq;
    int status1, status2;

    arq = fopen("output.txt", "w");
    pid1 = fork();
    if(pid1 == 0) {
        pid2 = fork();
        if(pid2 == 0) {
            fprintf(arq, "Eu sou ");
        }
        else {
            wait(&status2);
            //waitpid(pid2, &status2, 0);
            fprintf(arq, "um bolinho ");
        }
    } 
    else {
        wait(&status1);
        //waitpid(pid1, &status1, 0);
        fprintf(arq, "de arroz!!\n");
    }
    fclose(arq);
}