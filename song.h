#ifndef __SONG_INCLUDES
#define __SONG_INCLUDES

#include "node.h"

typedef struct node song_node;

song_node * add_song(song_node *list, char *artist, char *name);

song_node * find_song(song_node *songs, char *artist, char *name);

song_node * find_artist(song_node *songs, char *artist);

void print_library(song_node *songs);
void print_letter(song_node *songs, char letter);
void print_artist(song_node *songs, char *artist);

void print_shuffled(song_node *songs);

song_node * remove_song(song_node *song);
song_node * clear_library(song_node *library);

#endif //__SONG_INCLUDES
