#include "song.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

song_node * add_song(song_node *list, char *artist, char *name) {
  return insert_in_order(list, artist, name);
}


song_node * find_song(song_node *songs, char *artist, char *name) {
  return find_node(songs, artist, name);
}


song_node * find_artist(song_node *songs, char *artist);


void print_library(song_node *songs);

void print_letter(song_node *songs, char letter);

void print_artist(song_node *songs, char *artist);


void print_shuffled(song_node *songs);
