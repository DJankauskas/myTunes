#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"

int main(){
    printf("LINKED LIST TESTS \n ====================");
    struct node * linked_list = NULL;
    printf("empty list: \n");
    print_list(linked_list);
    int i;
    printf("[");
    linked_list = insert_front(linked_list, "Travis Scott", "Anecdote");
    linked_list = insert_front(linked_list, "Travis Scott", "Goosebumps");
    linked_list = insert_front(linked_list, "Lil Baby and Gunna", "Drip Harder");
    linked_list = insert_front(linked_list, "Meek Mill", "Going Bad");
    linked_list = insert_front(linked_list, "Drake", "God's Plan");
    linked_list = insert_front(linked_list, "Drake", "Scorpion");
    linked_list = insert_front(linked_list, "Eminem", "Rap God");
    linked_list = insert_front(linked_list, "Eminem", "Lose Yourself");
    print_list(linked_list);
    printf("]\n\n");
    printf("\nTesting print_node: \n ====================");
    // insert
    printf("\nTesting get_random: \n ====================\n");
    struct node *random = get_random(linked_list);
    //insert after writing print_node function
<<<<<<< HEAD
    
=======

>>>>>>> ccfd12f433d19e44349948910ad25f2e5825f1c2
    printf("\nTesting find_node: \n ====================");
    printf("looking for: Drake : God's Plan\n");
    if((find_node(linked_list,"Drake", "God's Plan")) != NULL){
        printf("found node:");
<<<<<<< HEAD
        print_node(find_node(linked_list, "Drake", "God's Plan"));
=======
        print_node(linked_list, "Drake", "God's Plan\n");
>>>>>>> ccfd12f433d19e44349948910ad25f2e5825f1c2
    }
    else printf("node not found\n");
    printf("looking for: Eminem: Rap God\n");
    if((find_node(linked_list,"Eminem", "Rap God")) != NULL){
        printf("found node:");
<<<<<<< HEAD
        print_node(find_node(linked_list, "Eminem", "Rap God"));
=======
        print_node(linked_list, "Eminem", "Rap God\n");
>>>>>>> ccfd12f433d19e44349948910ad25f2e5825f1c2
    }
    else printf("node not found\n");
    printf("looking for: Eminem: Kamikaze\n");
    if((find_node(linked_list,"Eminem", "Kamikaze")) != NULL){
        printf("found node:");
<<<<<<< HEAD
        print_node(find_node(linked_list, "Eminem", "Kamikaze"));
=======
        print_node(linked_list, "Eminem", "Kamikaze\n");
>>>>>>> ccfd12f433d19e44349948910ad25f2e5825f1c2
    }
    else printf("node not found\n");
    printf("\nTesting find_artist: \n ====================");
    printf("looking for: Travis Scott\n");
    if((find_artist(linked_list, "Travis Scott")) != NULL){
<<<<<<< HEAD
        printf("found artist:\n");
        print_node(find_artist(linked_list, "Travis Scott"));
=======
    printf("found artist:\n");
    print_node(find_artist(linked_list, "Travis Scott"));
>>>>>>> ccfd12f433d19e44349948910ad25f2e5825f1c2
    }
    else printf("artist not found");
    printf("looking for: Eminem\n");
    if((find_artist(linked_list, "Eminem")) != NULL){
        printf("found artist:\n");
        print_node(find_artist(linked_list, "Eminem"));
    }
    else printf("artist not found");
    printf("looking for: John\n");
    if((find_artist(linked_list, "John")) != NULL){
        printf("found artist:\n");
        print_node(find_artist(linked_list, "John"));
    }
    else printf("artist not found");
    printf("\nTesting songcmp: \n ====================");
    //insert songcmp tests
    printf("\nTesting random: \n ====================");
    //insert random tests
    printf("\nTesting free_listt: \n ====================");
    //insert free node tests
}
