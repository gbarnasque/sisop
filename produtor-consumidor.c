#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int N=5; // Tamanho do buffer
int i=0; // Índice do buffer

int um_resultado(int arg) {
    return (arg*2 + 1);
}

int produce(int* buffer) {
    // Armazena em 'i' e incrementa (para não ser sobreescrito o que outro processo escreveu)
    // buffer é utilizado como uma fila
    buffer[i] = um_resultado(i);
    i = (i+1) % N;
    return 0;
}

int consume(int* buffer) {
    // Consome em 'i' e decrementa (para liberar a entrada para outro processo)
    int res = buffer[i];
    i = (i-1) % N;
    return res;
}

int main(void) {
    pid_t pid;
    int* the_buffer = (int*) malloc(sizeof(int)*N);
    int ii;
    int res;

    pid = fork();
    if(pid != 0) { 
        // Pais geram os dados (Produtor)
        for(ii=0; ii<10; ii++) {
            produce(the_buffer);
            printf("Pai (produtor) produziu %d\n", the_buffer[i]);
        }
    } else {
        // Filhos consomem (Consumidor)
        for(ii=0; ii<10; ii++) {
            produce(the_buffer);
            printf("Filho (consumidor) consumiu %d\n", the_buffer[i]);
        }
    }
    return 0;
}