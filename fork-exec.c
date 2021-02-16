#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();
    if(pid != 0) {
        printf("Pai de PID: %d executando... Filho de PID: %d\n", getpid(), pid);
    } else {
        execv("./pipe", NULL); // Chamada que troca o binário executado pelo processo
        execv("./a.out", NULL); // Esta segunda chamada não será executada
    }
    return 0;
}