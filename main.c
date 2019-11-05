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

void test_print_song(song_node *song, char *artist, char *name) {
    song = find_song(song, artist, name);
    if(song) print_song(song);
    else printf("song not found");
}

int main() {
    srand(time(NULL));

    printf("LINKED LIST TESTS====================");
    struct node * list = NULL;
    printf("\nlist with decent songs: \n");
    list = insert_front(list, "travis scott", "anecdote");
    list = insert_front(list, "travis scott", "goosebumps");
    list = insert_front(list, "lil baby and gunna", "drip harder");
    list = insert_front(list, "meek mill", "going bad");
    list = insert_front(list, "drake", "god's plan");
    list = insert_front(list, "drake", "scorpion");
    list = insert_front(list, "eminem", "rap god");
    list = insert_front(list, "eminem", "lose yourself");
    print_list(list);
    printf("\n\nTesting print_node: (Expect eminem: lose yourself)====== \n");
    print_node(list);

    printf("\n\nTest adding in order (function calls same order as above)======\n");
    list = free_list(list);
    list = insert_in_order(list, "travis scott", "anecdote");
    list = insert_in_order(list, "travis scott", "goosebumps");
    list = insert_in_order(list, "lil baby and gunna", "drip harder");
    list = insert_in_order(list, "meek mill", "going bad");
    list = insert_in_order(list, "drake", "god's plan");
    list = insert_in_order(list, "drake", "scorpion");
    list = insert_in_order(list, "eminem", "rap god");
    list = insert_in_order(list, "eminem", "lose yourself");
    printf("Printing list:\n");
    print_library(list);

    printf("\n\nTesting get_random====== \n");
    struct node *random = get_random(list);
    print_node(random);
    printf("\n");
    random = get_random(list);
    print_node(random);
    printf("\n");
    random = get_random(list);
    print_node(random);

    printf("\n\nTesting find_node====== \n");
    printf("looking for drake: god's plan\n");
    test_find_node(list, "drake", "god's plan");

    printf("\nlooking for travis scott: anecdote\n");
    test_find_node(list, "travis scott", "anecdote");

    printf("\nlooking for elo: mr. blue sky (expect not found)\n");
    test_find_node(list, "elo", "mr. blue sky");

    printf("\n\nTesting find_artist====== \n");
    printf("looking for: eminem\n");
    test_find_artist(list, "eminem");
    
    printf("\nlooking for: john (no song expected)\n");
    test_find_artist(list, "john");

    printf("\n\nTesting songcmp====== \n");
    printf("Comparing "); print_node(list); printf(" to "); print_node(list); printf(":\n");
    printf("%d\n", songcmp(list, list));
    printf("Comparing "); print_node(list); printf(" to "); print_node(list->next); printf(":\n");
    printf("%d\n", songcmp(list, list->next));

    printf("\n\nTesting free_node======");
    printf("\nTesting free_node by removing "); print_node(list->next); printf(":\n");
    list = free_node(list, list->next);
    print_list(list);

    printf("\nTesting free_node by removing "); print_node(list->next); printf(":\n");
    list = free_node(list, list->next);
    print_list(list);

    printf("\n\nTesting free_list======");
    printf("List before freeing:\n");
    print_list(list);
    printf("List after freeing:\n");
    list = free_list(list);
    print_list(list);
    
    
    printf("\n\n MUSIC LIBRARY TESTING\n\n");
    
    song_node *lib = NULL;

    lib = add_song(lib, "travis scott", "anecdote");
    lib = add_song(lib, "travis scott", "goosebumps");
    lib = add_song(lib, "lil baby and gunna", "drip harder");
    lib = add_song(lib, "meek mill", "going bad");
    lib = add_song(lib, "drake", "god's plan");
    lib = add_song(lib, "drake", "scorpion");
    lib = add_song(lib, "eminem", "rap god");

    printf("Test print_library====== \n");
    print_library(lib);
    
    printf("\n\nTesting print_letter======");
    printf("\nPrinting A-list:\n");
    print_letter(lib, 'a');
    printf("\nPrinting D-list:\n");
    print_letter(lib, 'd');
    printf("\nPrinting E-list:\n");
    print_letter(lib, 'e');
    printf("\nPrinting R-list:\n");
    print_letter(lib, 'r');
    printf("\nPrinting L-list:\n");
    print_letter(lib, 'l');
    printf("\nPrinting T-list:\n");
    print_letter(lib, 't');
    
    printf("\n\nTesting Find======\n");
    printf("Searching for travis scott - goosebumps:\n");
    test_print_song(lib, "travis scott", "goosebumps");
    printf("\nSearching for eminem - rap god:\n");
    test_print_song(lib, "eminem", "rap god");
    printf("\nSearching for drake - yeezys:\n");
    test_print_song(lib, "drake", "yeezys");
    
    printf("\n\nTesting artist search======\n");
    printf("Searching for eminem:\n");
    print_artist(lib, "eminem");
    printf("\nSearching for travis scott:\n");
    print_artist(lib, "travis scott");
    printf("\nSearching for beethoven:\n");
    print_artist(lib, "beethoven");
    
    printf("\n\nTesting Shuffle======\n");
    print_shuffled(lib);
    printf("\nAnother shuffle:\n");
    print_shuffled(lib);
    
    printf("\n\nRemove songs from library======\n");
    printf("Removing lil baby and gunna - drip harder:\n");
    lib = remove_song(lib, find_song(lib, "lil baby and gunna", "drip harder"));
    print_library(lib);
    printf("\nRemoving drake - scorpion:\n");
    lib = remove_song(lib, find_song(lib, "drake", "scorpion"));
    print_library(lib);
    
    printf("\n\nClearing library======\n");
    lib = clear_library(lib);
    printf("\nLibrary after freeing:\n");
    print_library(lib);

    printf("\n\nAdding to cleared library======\n");
    lib = add_song(lib, "abba", "money");
    lib = add_song(lib, "billie elish", "bad guy");
    lib = add_song(lib, "abba", "waterloo");
    lib = add_song(lib, "unicode consortium", "emoji 12.0");
    print_library(lib);

    printf("\n\nTest print_artist======");
    printf("\nabba songs: \n");
    print_artist(lib, "abba");

    printf("\n\nClear library======");
    printf("\nLibrary after clear:");
    lib = clear_library(lib);
    print_library(lib);

    printf("\n");
}
