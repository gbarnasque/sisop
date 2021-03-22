// Executado atomicamente
boolean test_and_set(boolen *target) {
    boolean rv = *target;
    *target = true;
    return rv;
}
while(test_and_set(&lock));	    
    // Roda o SC
    // …
    // Fim SC
    lock = fale


int compare_and_swap(int* old_value, int expected, int new_value) {
    int tmp = *old_value;
    if(*old_value == expected)
        *old_value = new_value; 
    return tmp; // Retorna o valor original
}
while(compare_and_swap(&lock, 0, 1) != 0); // Espera
    // Agora lock == 1, e  valia 0 antes
    // Roda o Seção Crítica
    // …
    // Fim Seção Crítica
    lock = 0; // Libera para outros processos após SC

// Mutex
get() {
    while(!available) ; // Espera ativa
    available = false;
}
release() {
    available = true;
}

// Semáforo ( Pseudo código )
int S; // Recursos disponíveis no momento
init (int N) { 
    /// Inicia a fila, seta em máximo
    S = N;
}
wait() { 
    // Alguém esta solicitando o recurso
    // caso seja maior que zero tem recurso sobrando e pode ser utilizado
    while( S <= 0) ;
    S--;
}
signal() { 
    // Libera que parou de utilizar o recurso
    S++;
}