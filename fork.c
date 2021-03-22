#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int fibo(int n) {
    if (n<=1)
        return n;
    else
        return fibo(n-2) + fibo(n-1);
}

int main(int argc, char** argv){
    int resultado = 0;
    int fk = -1;
    int arg = 5;
    int meu_pid = -1;

    fk = fork();

    if(fk == 0) {
        printf("Processo pai PID = %d\n", getpid());
    }
    else
        printf("Processo filho PID = %d\n", getpid());

    meu_pid = getpid();
    resultado = fibo(arg);
    printf("Fibo(%d) = %d\n", arg, resultado);
    printf("Resultado oferecido pelo processo de PID = %d\n", meu_pid);
    return 0;
}