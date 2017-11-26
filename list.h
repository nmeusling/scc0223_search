/*
 * Natalie Menato
 * Numero USP: 10295051
 * 26/11/2017
 * Submissao para SCC0223 Trabalho 2 - parte 1
 *
 */

#ifndef UNTITLED_SEARCH_H
#define UNTITLED_SEARCH_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef int elem;

//no para a lista
typedef struct block {
    elem info;
    struct block *next;
} node;

//lista
typedef struct {
    node *first, *last;
} list;

//inicializa a lista
void create(list *l);

//insere elem x na lista
int insert(list *l, elem *x);

//libera a memoria usada pela lista
void destroy(list *l);

//remove o elemento x da lista
int delete_element(list *l, elem *x);

//imprime os elementos da lista
void print_list(list *l);

//insere num elementos aleatorios na lista
int create_random_list(list *l, int num);

//insere num elementos crescentes na lista
int create_increasing_list(list *l, int num);

//insere num elementos decrescentes na lista
int create_decreasing_list(list *l, int num);

//ordena a lista usando insertion sort
int insertion_sort(list *l);

//ordena a lista usando bubble sort
int bubble_sort(list *l);

//ordena a lista usando quick sort
int quick_sort(list *l);


#endif //UNTITLED_SEARCH_H
