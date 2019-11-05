#include "song.h"
#include "node.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

song_node * add_song(song_node *list, char *artist, char *name) {
  return insert_in_order(list, artist, name);
}


song_node * find_song(song_node *songs, char *artist, char *name) {
  return find_node(songs, artist, name);
}


song_node * find_artist(song_node *songs, char *artist) {
  return find_first_artist(songs, artist);
}

void print_library(song_node *songs) {
  printf("|");
  for(; songs != NULL; songs = songs->next) {
    printf(" %s : %s", songs->artist, songs->name);
  }
  printf(" |");
}

void print_letter(song_node *songs, char letter) {
  printf("|");
  for(; songs != NULL; songs = songs->next) {
    if(songs->artist[0] == letter) {
      printf(" %s : %s", songs->artist, songs->name);
    }
  }
  printf(" |");
}

void print_artist(song_node *songs, char *artist) {
  printf("|");
  for(; songs != NULL; songs = songs->next) {
    if(strncmp(songs->artist, artist, sizeof songs->artist) == 0) {
      printf(" %s : %s", songs->artist, songs->name);
    }
  }
  printf(" |");
}

void print_shuffled(song_node *songs) {
  song_node *shuffled_list = NULL;
  for(; songs != NULL; songs = songs->next) {
    song_node *insert_at = get_random(shuffled_list);
    song_node *new_node = insert_front(shuffled_list, songs->artist, songs->name);
    if(insert_at == songs) {
      shuffled_list = new_node;
    }
  }

  print_library(shuffled_list);
  clear_library(shuffled_list);
}

song_node * remove_song(song_node *song) {
  return free_node(song);
}

song_node * clear_library(song_node *library) {
  return free_list(library);
}
