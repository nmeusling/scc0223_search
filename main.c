//
// Created by nmeusling on 10/11/17.
//

#include "list.h"

int main(){
//    list random, increasing, decreasing;
//    create_random_list(&random, 100);
//    create_decreasing_list(&decreasing, 100);
//    create_increasing_list(&increasing, 100);
//    print_list(&random);
//    printf("\n");
//    print_list(&increasing);
//    printf("\n");
//    print_list(&decreasing);

    list random;
    create_random_list(&random, 100);
    print_list(&random);
    printf("\n");
    insertion_sort(&random);
    print_list(&random);

    return 0;
}