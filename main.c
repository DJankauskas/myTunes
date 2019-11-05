#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "node.h"
#include "song.h"

void test_find_node(struct node *list, char *artist, char *name) {
    struct node *n = find_node(list, artist, name);
    if(n != NULL) {
        printf("found node: ");
        print_node(n);
    }
    else printf("node not found\n");
}

void test_find_artist(struct node *linked_list, char *artist) {
    struct node *a = find_artist(linked_list, artist);
    if(a != NULL) {
        printf("found artist:\n");
        print_node(a);
    }
    else printf("artist not found");
}

int main() {
    srand(time(NULL));

    printf("LINKED LIST TESTS \n ====================");
    struct node * linked_list = NULL;
    printf("empty list: \n");
    print_list(linked_list);
    printf("\nlist with decent songs: \n");
    linked_list = insert_front(linked_list, "travis scott", "anecdote");
    linked_list = insert_front(linked_list, "travis scott", "goosebumps");
    linked_list = insert_front(linked_list, "lil baby and gunna", "drip harder");
    linked_list = insert_front(linked_list, "meek mill", "going bad");
    linked_list = insert_front(linked_list, "drake", "god's plan");
    linked_list = insert_front(linked_list, "drake", "scorpion");
    linked_list = insert_front(linked_list, "eminem", "rap god");
    linked_list = insert_front(linked_list, "eminem", "lose yourself");
    print_list(linked_list);
    printf("\n\n");
    printf("\nTesting print_node: (Expect eminem : lose yourself) \n");
    print_node(linked_list);
    printf("\nTesting get_random: \n");
    struct node *random = get_random(linked_list);
    print_node(random);
    printf("\nTesting find_node: \n");
    printf("looking for: drake : god's plan\n");
    test_find_node(linked_list, "drake", "god's plan");

    printf("\nlooking for: travis scott, anecdote\n");
    test_find_node(linked_list, "travis scott", "anecdote");

    printf("\nlooking for: elo : mr. blue sky (expect not found)\n");
    test_find_node(linked_list, "elo", "mr. blue sky");

    printf("\nTesting find_artist: \n");
    printf("looking for: eminem\n");
    test_find_artist(linked_list, "eminem");
    
    printf("\nlooking for: john (expect not found)\n");
    test_find_artist(linked_list, "john");

    printf("\nTesting songcmp: \n");
    //insert songcmp tests

    printf("\nTesting free_list: \n");
    //insert free node tests
    
    
    
    
    
    printf("\n\n MUSIC LIBRARY TESTING\n\n");
    
    song_node *lib = NULL;

    lib = add_song(lib, "travis scott", "anecdote");
    lib = add_song(lib, "travis scott", "goosebumps");
    lib = add_song(lib, "lil baby and gunna", "drip harder");
    lib = add_song(lib, "meek mill", "going bad");
    lib = add_song(lib, "drake", "god's plan");
    lib = add_song(lib, "drake", "scorpion");
    lib = add_song(lib, "eminem", "rap god");
    print_library(lib);
    
    printf("Testing print_letter\n");
    printf("\nprinting A-list:\n");
    print_letter(lib, 'a');
    printf("\nprinting D-list:\n");
    print_letter(lib, 'd');
    printf("\nprinting E-list:\n");
    print_letter(lib, 'e');
    printf("\nprinting R-list:\n");
    print_letter(lib, 'r');
    printf("\nprinting L-list:\n");
    print_letter(lib, 'l');
    printf("\nprinting T-list:\n");
    print_letter(lib, 't');
    
    printf("\nTesting Find:\n");
    printf("searching for travis scott - goosebumps:\n");
    print_song(find_song(lib, "travis scott", "goosebumps"));
    printf("\nsearching for eminem - rap god:\n");
    print_song(find_song(lib, "eminem", "rap god"));
    printf("\nsearching for drake - god's plan:\n");
    print_song(find_song(lib, "drake", "god's plan"));
    
    printf("\nTesting artist search:\n");
    printf("searching for eminem:\n");
    print_artist(lib, "eminem");
    printf("\nsearching for travis scott:\n");
    print_artist(lib, "travis scott");
    printf("\nsearching for lil baby and gunna:\n");
    print_artist(lib, "lil baby and gunna");
    
    printf("\nTesting Shuffle:\n");
    print_shuffled(lib);
    
    printf("\nRemove Songs from Library:\n");
    printf("removing lil baby and gunna - drip harder:\n");
    lib = remove_song(lib, find_song(lib, "lil baby and gunna", "drip harder"));
    print_library(lib);
    printf("\nremoving drake - scorpion:\n");
    lib = remove_song(lib, find_song(lib, "drake", "scorpion"));
    print_library(lib);
    
    printf("\nfreeing/clearing library:\n");
    lib = clear_library(lib);
    printf("\nlibrary after freeing:\n");
    print_library(lib);
    printf("\n");
}
