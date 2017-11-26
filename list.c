/*
 * Natalie Menato
 * Numero USP: 10295051
 * 26/11/2017
 * Submissao para SCC0223 Trabalho 2 - parte 1
 *
 */

#include "list.h"

/*
 * Inicializa a lista
 */
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

/*
 * Insere um elemento na lista ordenada
 */
int insert_ordered(list *l, elem *x) {
    node *current, *prev, *p;

    p = (node *) malloc(sizeof(node));
    if (p == NULL)
        return 0;
    else {

        p->info = *x;
        if ((l->first == NULL) || (*x < l->first->info)) {
            if (l->first == NULL)
                l->last = p;
            p->next = l->first;
            l->first = p;
        } else {
            prev = NULL;
            current = l->first;
            while ((current != NULL) && (current->info <= *x)) {
                prev = current;
                current = current->next;
            }
            p->next = current;
            prev->next = p;
            if (p->next == NULL)
                l->last = p;
        }
    }

    return 1;
}

/*
 * Libera a memoria da lista
 */
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

/*
 * Remove o elemento da lista, retorna 1 se foi removido, 0 se nao
 */
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
    if (previous == NULL) {
        l->first = current->next;
    }
        //last element in list
    else if (current->next == NULL) {
        l->last = previous;
    } else {
        previous->next = current->next;
    }
    free(current);
    return 1;
}

/*
 * Remove o primeiro elemento da lista. Retorna 0 se a lista e vazia
 */
int delete_first(list *l, elem *x) {
    if (l->first == NULL)
        return 0;
    *x = l->first->info;
    l->first = l->first->next;
    return 1;

}

/*
 * Insere num elmentos aleatorios na lista l
 */
int create_random_list(list *l, int num) {
    srand(10295051);
    create(l);
    int i, temp;
    for (i = 0; i < num; i++) {
        temp = rand();
        //if an error occurred during insertion
        if (!insert(l, &temp)) {
            return 0;
        }
    }
    return 1;
}

/*
 * Imprime a lista
 */
void print_list(list *l) {
    node *p = l->first;
    printf("\n");
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->next;
    }
}

/*
 * Insere num elementos crescentes na lista l
 */
int create_increasing_list(list *l, int num) {
    create(l);
    int i, temp;
    for (i = 0; i < num; i++) {
        temp = i;
        if (!insert(l, &temp))
            return 0;
    }
    return 1;
}

/*
 * Insere num elementos decresentes na lista l
 */
int create_decreasing_list(list *l, int num) {
    create(l);
    int i, temp;
    for (i = num; i > 0; i--) {
        temp = i;
        if (!insert(l, &temp))
            return 0;
    }
    return 1;
}

/*
 * Ordenar a lista usando Insertion Sort
 */
int insertion_sort(list *l) {
    elem x;
    list *ordered = (list *) malloc(sizeof(list));
    if (ordered == NULL)
        return 0;
    create(ordered);
    while (l->first != NULL) {
        delete_first(l, &x);
        insert_ordered(ordered, &x);
    }

    *l = *ordered;
    free(ordered);
    return 1;

}

/*
 * Ordenar a lista usando Bubble Sort
 */
int bubble_sort(list *l) {
    int switched;
    node *pointer, *next;
    elem info;

    switched = 1; //0 when no swaps were made

    while (switched != 0) {
        switched = 0;

        pointer = l->first;
        if (pointer == NULL)
            return 0;
        next = pointer->next;

        while (next != NULL) {
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

/*
 * Trocar os valores armazenados em node1 e node2
 */
void swap(node *node1, node *node2) {
    if (node1 != NULL && node2 != NULL) {
        elem temp = node1->info;
        node1->info = node2->info;
        node2->info = temp;
    }
}

/*
 * Ordena a lista, deixando todos elementos menor do pivo a esquerda, e os elementos maiores a direita, retorna o pivo
 */
node *partition(list *l, node *start, node *end) {
    if (start == NULL)
        return NULL;
    node *i = start->next;
    if (i == NULL) {
        return NULL;
    }
    node *prev = NULL;
    node *pivot = start; //first element is pivot
    node *j = start->next;
    int final = 0;
    while (j != NULL && !final) {
        if (j == end)
            final = 1;
        if (j->info < pivot->info) {
            swap(i, j);
            prev = i;
            i = i->next;
        }
        j = j->next;
    }
    swap(pivot, prev);
    return prev;
}

/*
 * Funcao recursiva para quick sort. Divide a lista usando partition e depois chama quicksort para as duas partes da lista
 */
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

/*
 * Chama a funcao recursivo para quicksort
 */
int quick_sort(list *l) {
    quick_sort_aux(l, l->first, l->last);
    return 1;
}