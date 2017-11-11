//
// Created by nmeusling on 10/11/17.
//

#ifndef UNTITLED_SEARCH_H
#define UNTITLED_SEARCH_H

#include <stdlib.h>
#include <stdio.h>

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

#endif //UNTITLED_SEARCH_H
