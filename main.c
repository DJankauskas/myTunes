#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"

int main(){
    printf("MUSIC LIBRARY TESTS \n ====================");
    struct node * linked_list = NULL;
    printf("empty list: \n");
    print_list(linked_list);
    int i;
    printf("\nlist with some ok songs: \n");
    linked_list = insert_front(linked_list, "Travis Scott", "Anecdote");
    linked_list = insert_front(linked_list, "Travis Scott", "Goosebumps");
    linked_list = insert_front(linked_list, "Lil Baby and Gunna", "Drip Harder");
    linked_list = insert_front(linked_list, "Meek Mill", "Dreams and Nightmares");
    linked_list = insert_front(linked_list, "Drake", "God's Plan");
    linked_list = insert_front(linked_list, "Drake", "One Dance");
    linked_list = insert_front(linked_list, "Eminem", "Rap God");
    linked_list = insert_front(linked_list, "Eminem", "Lose Yourself");
    print_list(linked_list);
    printf("\n\n");
    printf("Testing print_node: \n ====================");
    // insert after writing print_node function
    printf("Testing find_node: \n ====================");
    // insert after writing find_node funtion
}
