#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int canal1[2];
    int canal2[2];
    int canal3[2];
    int nbytes;
    pid_t pid;
    char mensagem[80];
    int val=0;
    int tamanho=0;

    // Inicializa os pipes
    pipe(canal1);
    pipe(canal2);
    pipe(canal3);

    val = -1;
    pid = fork();

    if(pid != 0) {
        printf("Proc pai %d- Antes do envio de val = %d\n", getpid(), val);
        val = 10;
        printf("Proc pai %d- Envio de val = %d\n", getpid(), val);
        write(canal1[1], &val, sizeof(int));

        // Espera mensagem do filho
        nbytes = read(canal2[0], &tamanho, sizeof(int));
        printf("Proc pai %d- Recebi do meu filho o tamanho da mensagem que me será enviada (%d Bytes)\n", getpid(), tamanho);
        nbytes = read(canal3[0], mensagem, sizeof(char)*tamanho);
        printf("Proc pai %d- Recebi do meu filho a seguinte mensagem: %s\n", getpid(), mensagem);
    } else {
        printf("Proc Filho %d- Antes de receber val do meu pai, val = %d\n", getpid(), val);
        // Espera mensagem do pai
        nbytes = read(canal1[0], &val, sizeof(int));
        printf("Proc Filho %d- Depois de receber val do meu pai, val = %d\n", getpid(), val);

        strcpy(mensagem, "Valeu paizao!!");
        tamanho = strlen(mensagem);
        write(canal2[1], &tamanho, sizeof(int));
        write(canal3[1], mensagem, sizeof(char)*tamanho);
    }
}