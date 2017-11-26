/*
 * Natalie Menato
 * Numero USP: 10295051
 * 26/11/2017
 * Submissao para SCC0223 Trabalho 2 - parte 1
 *
 */

#include "list.h"

double quick_random(int size, int repetitions);

int input_repetitions();

int input_size();

void run_trials();

int main() {
    run_trials();
    return 0;
}

/*
 * Pede para o usuario digitar o numero de repeticoes, retorna o valor
 */
int input_repetitions() {
    int repetitions = 0;
    char *str = (char *) malloc(sizeof(char) * 50);
    char *end;
    while (repetitions <= 0) {
        printf("Digite o numero de repeticoes: ");
        fgets(str, 50, stdin);
        repetitions = (int) strtol(str, &end, 10);
    }
    return repetitions;
}

/*
 * Pede para o usuario digitar o numero de elementos na lista, retorna o valor
 */
int input_size() {
    int size = 0;
    char *str = (char *) malloc(sizeof(char) * 50);
    char *end;
    while (size <= 0) {
        printf("Digite o tamanho da lista: ");
        fgets(str, 50, stdin);
        size = (int) strtol(str, &end, 10);
    }
    return size;

}

/*
 * Ordenar com quick sort uma lista aleatoria de size elementos, fazendo repetitions repeticoes, retorna o tempo medio para ordenar
 */
double quick_random(int size, int repetitions) {
    int i;
    list random;
    double tot_time = 0;
    clock_t begin, end;

    for (i = 0; i < repetitions; i++) {
        create_random_list(&random, size);
        begin = clock();
        quick_sort(&random);
        end = clock();
        destroy(&random);
        tot_time += (double) (end - begin) / CLOCKS_PER_SEC;
    }
    return tot_time / repetitions;
}

/*
 * Ordenar com quick sort uma lista incremente de size elementos, fazendo repetitions repeticoes, retorna o tempo medio para ordenar
 */
double quick_increasing(int size, int repetitions) {
    int i;
    list increasing;
    double tot_time = 0;
    clock_t begin, end;

    for (i = 0; i < repetitions; i++) {
        create_increasing_list(&increasing, size);
        begin = clock();
        quick_sort(&increasing);
        end = clock();
        destroy(&increasing);
        tot_time += (double) (end - begin) / CLOCKS_PER_SEC;
    }
    return tot_time / repetitions;
}

/*
 * Ordenar com quick sort uma lista decremente de size elementos, fazendo repetitions repeticoes, retorna o tempo medio para ordenar
 */
double quick_decreasing(int size, int repetitions) {
    int i;
    list decreasing;
    double tot_time = 0;

    clock_t begin, end;

    for (i = 0; i < repetitions; i++) {
        create_decreasing_list(&decreasing, size);
        begin = clock();
        quick_sort(&decreasing);
        end = clock();
        destroy(&decreasing);
        tot_time += (double) (end - begin) / CLOCKS_PER_SEC;
    }

    return tot_time / repetitions;
}

/*
 * Ordenar com insertion sort uma lista aleatoria de size elementos, fazendo repetitions repeticoes, retorna o tempo medio para ordenar
 */
double insertion_random(int size, int repetitions) {
    int i;
    list random;
    double tot_time = 0;

    clock_t begin, end;

    for (i = 0; i < repetitions; i++) {
        create_random_list(&random, size);
        begin = clock();
        insertion_sort(&random);
        end = clock();
        destroy(&random);
        tot_time += (double) (end - begin) / CLOCKS_PER_SEC;
    }

    return tot_time / repetitions;
}

/*
 * Ordenar com insertion sort uma lista incremente de size elementos, fazendo repetitions repeticoes, retorna o tempo medio para ordenar
 */
double insertion_increasing(int size, int repetitions) {
    int i;
    list increasing;
    double tot_time = 0;

    clock_t begin, end;

    for (i = 0; i < repetitions; i++) {
        create_increasing_list(&increasing, size);
        begin = clock();
        insertion_sort(&increasing);
        end = clock();
        destroy(&increasing);
        tot_time += (double) (end - begin) / CLOCKS_PER_SEC;
    }
    return tot_time / repetitions;
}

/*
 * Ordenar com insertion sort uma lista decremente de size elementos, fazendo repetitions repeticoes, retorna o tempo medio para ordenar
 */
double insertion_decreasing(int size, int repetitions) {
    int i;
    list decreasing;
    double tot_time = 0;

    clock_t begin, end;

    for (i = 0; i < repetitions; i++) {
        create_decreasing_list(&decreasing, size);
        begin = clock();
        insertion_sort(&decreasing);
        end = clock();
        destroy(&decreasing);
        tot_time += (double) (end - begin) / CLOCKS_PER_SEC;
    }
    return tot_time / repetitions;
}

/*
 * Ordenar com bubble sort uma lista aleatoria de size elementos, fazendo repetitions repeticoes, retorna o tempo medio para ordenar
 */
double bubble_random(int size, int repetitions) {
    int i;
    list random;

    double tot_time = 0;

    clock_t begin, end;

    for (i = 0; i < repetitions; i++) {
        create_random_list(&random, size);
        begin = clock();
        bubble_sort(&random);
        end = clock();
        destroy(&random);
        tot_time += (double) (end - begin) / CLOCKS_PER_SEC;
    }
    return tot_time / repetitions;
}

/*
 * Ordenar com bubble sort uma lista incremente de size elementos, fazendo repetitions repeticoes, retorna o tempo medio para ordenar
 */
double bubble_increasing(int size, int repetitions) {
    int i;
    list increasing;

    double tot_time = 0;

    clock_t begin, end;

    for (i = 0; i < repetitions; i++) {
        create_increasing_list(&increasing, size);
        begin = clock();
        bubble_sort(&increasing);
        end = clock();
        destroy(&increasing);
        tot_time += (double) (end - begin) / CLOCKS_PER_SEC;
    }
    return tot_time / repetitions;
}

/*
 * Ordenar com bubble sort uma lista decremente de size elementos, fazendo repetitions repeticoes, retorna o tempo medio para ordenar
 */
double bubble_decreasing(int size, int repetitions) {
    int i;
    list decreasing;

    double tot_time = 0;

    clock_t begin, end;

    for (i = 0; i < repetitions; i++) {
        create_decreasing_list(&decreasing, size);
        begin = clock();
        bubble_sort(&decreasing);
        end = clock();
        destroy(&decreasing);
        tot_time += (double) (end - begin) / CLOCKS_PER_SEC;
    }
    return tot_time / repetitions;
}

/*
 * Fazer as repeticoes para todos os tipos de busca e imprimir os resultados
 */
void run_trials() {
    int rep, size;
    rep = input_repetitions();
    size = input_size();

    printf("\n\nResultados: Media de tempo para ordenar os conjuntos");
    printf("\nLista com %d elementos e %d repeticoes: ", size, rep);
    printf("\n\nInsercao");
    printf("\n------------------------------");
    printf("\nOrdem Crescente  : %lf", insertion_increasing(size, rep));
    printf("\nOrdem Decrescente: %lf", insertion_decreasing(size, rep));
    printf("\nOrdem Aleatorio  : %lf", insertion_random(size, rep));

    printf("\n\nBolha");
    printf("\n------------------------------");
    printf("\nOrdem Crescente  : %lf", bubble_increasing(size, rep));
    printf("\nOrdem Decrescente: %lf", bubble_decreasing(size, rep));
    printf("\nOrdem Aleatorio  : %lf", bubble_random(size, rep));

    printf("\n\nRapida");
    printf("\n------------------------------");
    printf("\nOrdem Crescente  : %lf", quick_increasing(size, rep));
    printf("\nOrdem Decrescente: %lf", quick_decreasing(size, rep));
    printf("\nOrdem Aleatorio  : %lf", quick_random(size, rep));
}