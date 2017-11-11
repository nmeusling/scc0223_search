//
// Created by nmeusling on 10/11/17.
//

#include "list.h"

void create(list *l) {
    l->first = NULL;
    l->last = NULL;
}

/*
 * Allocates memory for new node where info is x and inserts it as the last element of list l. Returns 0 if an error occurs.
 */
int insert(list *l, elem *x) {

    node *p;

    p = (node *) malloc(sizeof(node));

    if (p == NULL)
        return 0;

    p->info = *x;
    p->next = NULL;
    if (l->first == NULL)
        l->first = p;
    else
        l->last->next = p;
    l->last = p;
    return 1;
}

void destroy(list *l) {

    node *p;

    p = l->first;

    while (p != NULL) {
        l->first = l->first->next;
        free(p);
        p = l->first;
    }

    l->last = p;
}
//1 if element is deleted, 0 if not
int delete_element(list *l, elem *x) {
    node *current, *previous;
    current = l->first;
    previous = NULL;
    while (current != NULL && current->info != *x) {
        previous = current;
        current = current->next;
    }
    //element not found
    if (current == NULL)
        return 0;
    //element is first in list
    if (previous == NULL){
        l->first = current->next;
    }
        //last element in list
    else if(current->next==NULL){
        l->last = previous;
    }
    else
    {
        previous->next = current->next;
    }
    free(current);
    return 1;
}

int create_random_list(list *l, int num){
    srand(10295051);
    create(l);
    int i, temp;
    for(i = 0; i<num; i++){
        temp = rand() % 50;
        //if an error occurred during insertion
        if(!insert(l, &temp)){
            return 0;
        }
    }
    return 1;
}

void print_list(list *l){
    node *p = l->first;
    while(p != NULL){
        printf("%d ", p->info);
        p = p->next;
    }
}

int create_increasing_list(list *l, int num){
    create(l);
    int i, temp;
    for(i=0; i<num; i++){
        temp = i;
        if(!insert(l, &temp))
            return 0;
    }
    return 1;
}

int create_decreasing_list(list *l, int num){
    create(l);
    int i, temp;
    for(i=num; i>0; i--){
        temp = i;
        if(!insert(l, &temp))
            return 0;
    }
    return 1;
}

int insertion_sort(list *l){
    //pointer moves over elements from left to right, compares them with value of selector which is trying to find minimum value
    node *pointer, *selector, *minimum;
    elem info;
    pointer = l->first;

    //if list is empty
    if(pointer == NULL)
        return 0;
    //if pointer->next is null, it is last element and list is already ordered
    while(pointer->next != NULL){
        selector = pointer->next;
        minimum = pointer;
        while(selector != NULL){
            if(selector->info < minimum->info)
                minimum = selector;
            selector = selector->next;
        }

        //do the switch
        info = pointer->info;
        pointer ->info = minimum->info;
        minimum->info = info;

        pointer = pointer->next;
    }
    return 1;
}

int bubble_sort(list *l){
    return 1;
}

int quick_sort(list *l){
    return 1;
}