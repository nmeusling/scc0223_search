//
// Created by nmeusling on 10/11/17.
//

#include "list.h"
#include <unistd.h>

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

int insert_ordered(list *l, elem *x){
    node *current, *prev, *p;

    p=(node*) malloc(sizeof(node));
    if (p==NULL)
        return 0;
    else {

        p->info=*x;
        if ((l->first==NULL) || (*x<l->first->info)) {
            if(l->first ==NULL)
                l->last = p;
            p->next=l->first;
            l->first=p;
        }
        else {
            prev=NULL;
            current=l->first;
            while ((current!=NULL) && (current->info<=*x)) {
                prev=current;
                current=current->next;
            }
            p->next=current;
            prev->next=p;
            if(p->next == NULL)
                l->last = p;
        }
    }

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

int delete_first(list *l, elem *x){
    if(l->first == NULL)
        return 0;
    *x = l->first->info;
    l->first = l->first->next;
    return 1;

}

int create_random_list(list *l, int num){
    srand(10295051);
    create(l);
    int i, temp;
    for(i = 0; i<num; i++){
        temp = rand()%50;
        //if an error occurred during insertion
        if(!insert(l, &temp)){
            return 0;
        }
    }
    return 1;
}

void print_list(list *l){
    node *p = l->first;
    printf("\n");
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
    elem x;
    list *ordered = (list *) malloc(sizeof(list));
    if(ordered == NULL)
        return 0;
    create(ordered);
    while(l->first != NULL) {
        delete_first(l, &x);
        insert_ordered(ordered, &x);
    }

    *l = *ordered;
    free(ordered);
    return 1;




}
//todo instead of moving values considering switching nodes
int selection_sort(list *l){

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
    int i, switched;
    node *pointer, *next;
    elem info;

    switched = 1; //0 when no swaps were made

    while(switched != 0){
        switched = 0;

        pointer = l->first;
        if(pointer == NULL)
            return 0;
        next = pointer->next;

        while(next != NULL) {
            if (next->info < pointer->info) {
                info = pointer->info;
                pointer->info = next->info;
                next->info = info;
                switched = 1;
            }
            pointer = next;
            next = next->next;
        }
    }
    return 1;
}

node* get_last_node(list *l){
    node* pointer = l->first;
    while(pointer != NULL && pointer->next != NULL){
        pointer = pointer->next;
    }
    return pointer;
}


void swap(node* node1, node* node2){
    if(node1 != NULL && node2 != NULL) {
        elem temp = node1->info;
        node1->info = node2->info;
        node2->info = temp;
    }
}

node * partition (list *l,node * start , node* end) {
    if(start == NULL)
        return NULL;
    node* i = start->next;
    if(i ==  NULL){
        return NULL;
    }
    node *prev = NULL;
    node * pivot = start; //first element is pivot
    node *j =  start->next;
    int final = 0;
    while(j != NULL && !final){
        if(j == end)
            final = 1;
        if(j->info < pivot->info){
            swap(i,j);
            prev = i;
            i = i->next;
        }
        j = j->next;
    }
    swap(pivot, prev);
   return prev;
}

void quick_sort_aux(list *l, node *start, node *end) {
    if (start == NULL || end == NULL)
        return;
    if (start == end)
        return;

    node *pivot_position = partition(l, start, end);
    if (pivot_position == NULL) {
        quick_sort_aux(l, start->next, end);
    } else {
        if (pivot_position->next == NULL) {
            quick_sort_aux(l, start, pivot_position);
        } else {
            quick_sort_aux(l, start, pivot_position);
            quick_sort_aux(l, pivot_position->next, end);
        }


    }
}

int quick_sort(list *l){
    quick_sort_aux(l, l->first, l->last);
    return 1;
}