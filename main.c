//
// Created by nmeusling on 10/11/17.
//

#include "list.h"

int input_repetitions ();
int input_size();
void run_trials();
double random_trial(int size, int repetitions, int type);

int main(){
    list random, increasing, decreasing;
    create_random_list(&random, 20);
    print_list(&random);
    quick_sort(&random);
    print_list(&random);

    create_increasing_list(&increasing, 20);
    print_list(&increasing);
    quick_sort(&increasing);
    print_list(&increasing);

    create_decreasing_list(&decreasing, 20);
    print_list(&decreasing);
    quick_sort(&decreasing);
    print_list(&decreasing);

    //run_trials();
    //printf("Result: %lf", random_trial(100,100, 1));
    return 0;
}

int input_repetitions (){
    int repetitions = 0;
    char *str = (char*)malloc(sizeof(char)*50);
    char *end;
    while(repetitions <= 0) {
        printf("Digite o numero de repeticoes: ");
        fgets(str, 50, stdin);
        repetitions = (int)strtol(str, &end, 10);
    }
    return repetitions;
}

int input_size(){
    int size = 0;
    char *str = (char*)malloc(sizeof(char)*50);
    char *end;
    while(size <= 0) {
        printf("Digite o tamanho da lista: ");
        fgets(str, 50, stdin);
        size = (int)strtol(str, &end, 10);
    }
    return size;

}

//type = 1: insertion
//type = 2: bubble
//type = 3: quick
//todo copy list so that repetitions can be completed
double random_trial(int size, int repetitions, int type){
    int i;
    list random;

    time_t start_time, end_time;
    time(&start_time);
    if(type == 1){
        for(i = 0; i < repetitions; i++){
            create_random_list(&random, size);
            //list * pRandom = &random;
            print_list(&random);
            //insertion_sort(&pRandom);
            insertion_sort(&random);
            print_list(&random);
            destroy(&random);
        }
    }
    else if(type == 2){
        for(i = 0; i < repetitions; i++){
            create_random_list(&random, size);
            bubble_sort(&random);
            destroy(&random);
        }
    }
    else if(type ==3){
        for(i = 0; i < repetitions; i++){
            create_random_list(&random, size);
            quick_sort(&random);
            destroy(&random);
        }
    }
    time(&end_time);
    return difftime(end_time, start_time);
}

double increasing_trial(int size, int repetitions, int type){
    int i;
    list increasing;
    time_t start_time, end_time;
    time(&start_time);
    if(type == 1){
        for(i = 0; i < repetitions; i++){
            //print_list(&increasing_copy);
            create_increasing_list(&increasing, size);
            //list * pIncreasing = &increasing;
            //insertion_sort(&pIncreasing);
            insertion_sort(&increasing);
            destroy(&increasing);
            //print_list(&increasing_copy);
        }
    }
    else if(type == 2){
        for(i = 0; i < repetitions; i++){
            create_increasing_list(&increasing, size);
            bubble_sort(&increasing);
            destroy(&increasing);
        }
    }
    else if(type ==3){
        for(i = 0; i < repetitions; i++){
            create_increasing_list(&increasing, size);
            quick_sort(&increasing);
            destroy(&increasing);
        }
    }
    time(&end_time);
    return difftime(end_time, start_time);
}

double decreasing_trial(int size, int repetitions, int type){
    int i;
    list decreasing;
    time_t start_time, end_time;
    time(&start_time);
    if(type == 1){
        for(i = 0; i < repetitions; i++){
            create_decreasing_list(&decreasing, size);
            //list * pDecreasing = &decreasing;
            //insertion_sort(&pDecreasing);
            insertion_sort(&decreasing);
            destroy(&decreasing);
        }
    }
    else if(type == 2){
        for(i = 0; i < repetitions; i++){
            create_decreasing_list(&decreasing, size);
            bubble_sort(&decreasing);
            destroy(&decreasing);
        }
    }
    else if(type ==3){
        for(i = 0; i < repetitions; i++){
            create_decreasing_list(&decreasing, size);
            quick_sort(&decreasing);
            destroy(&decreasing);
        }
    }
    time(&end_time);
    return difftime(end_time, start_time);
}

//first row insertion sort: inc, random, dec
//second row bubble: inc, random, dec
//third row
void run_trials(){
    int rep, size;
    rep = input_repetitions();
    size = input_size();
    double results_increasing[3], results_decreasing[3], results_random[3]; //insertion, bubble then quick
    int i;
    for(i=1 ; i<=3; i++){
        results_increasing [i-1] = increasing_trial(size, rep, i);
    }
    for(i=1 ; i<=3; i++){
        results_random [i-1] = random_trial(size, rep, i);
    }
    for(i=1 ; i<=3; i++){
        results_decreasing [i-1] = decreasing_trial(size, rep, i);
    }

    printf("\n\nResultados: Media de tempo para ordenar os conjuntos");
    printf("\n\nInsercao");
    printf("\n------------------------------");
    printf("\nOrdem Crescente  : %lf", results_increasing[1]);
    printf("\nOrdem Decrescente: %lf", results_decreasing[1]);
    printf("\nOrdem Aleatorio  : %lf", results_random[1]);

    printf("\n\nBolha");
    printf("\n------------------------------");
    printf("\nOrdem Crescente  : %lf", results_increasing[2]);
    printf("\nOrdem Decrescente: %lf", results_decreasing[2]);
    printf("\nOrdem Aleatorio  : %lf", results_random[2]);

    printf("\n\nRapida");
    printf("\n------------------------------");
    printf("\nOrdem Crescente  : %lf", results_increasing[3]);
    printf("\nOrdem Decrescente: %lf", results_decreasing[3]);
    printf("\nOrdem Aleatorio  : %lf", results_random[3]);
}