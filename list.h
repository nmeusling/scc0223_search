//
// Created by nmeusling on 10/11/17.
//

#ifndef UNTITLED_SEARCH_H
#define UNTITLED_SEARCH_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef int elem;

typedef struct block {
    elem info;
    struct block *next;
} node;

typedef struct {
    node *first, *last;
} list;

void create(list *l);
int insert(list *l, elem *x);
void destroy(list *l);
int delete_element(list *l, elem *x);

int create_random_list(list *l, int num);
void print_list(list *l);
int create_increasing_list(list *l, int num);
int create_decreasing_list(list *l, int num);

int selection_sort(list *l);
int insertion_sort(list *l);
int bubble_sort(list *l);
int quick_sort(list *l);
node* get_last_node(list *l);

#endif //UNTITLED_SEARCH_H
