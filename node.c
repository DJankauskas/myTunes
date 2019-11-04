#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_list(struct node *list) {
  printf("[ ");
  while(list != NULL) {
    printf("%s : %s, ", list->artist, list->name);
    list = list->next;
  }
  printf("]");
}


//characters beyond index 14 will be ignored

struct node * insert_front(struct node *list, char *artist, char *data) {
  struct node *front = calloc(1, sizeof(struct node));
  front->next = list;
  front->prev = NULL;
  strncpy(front->artist, data, sizeof front->artist);
  strncpy(front->name, data, sizeof front->name);

  //ensure null termination
  front->artist[(sizeof front->artist) - 1] = '\0';
  front->name[(sizeof front->name) - 1] = '\0';

  return front;
}

struct node * find_node(struct node *list, char *artist, char *data) {
  for(; list != NULL; list = list->next){
    if(strcmp(list->artist, artist) == 0) {
      if(strcmp(list->name, data) == 0) {
        return list;
      }
    }
  }
  //no match
  return NULL;
}

void print_node(struct node *list, char *artist, char *data){
    if (find_node(list, artist, data) != NULL){
        printf("%s : %s\n", artist, data);
    }
    else printf("not found");
}

struct node * find_artist(struct node *list, char *artist) {
  for(; list != NULL; list = list->next) {
    if(strcmp(list->artist, artist) == 0) {
      return list;
    }
  }
  //no match found
  return NULL;
}

int songcmp(struct node *s1, struct node *s2) {
  int artist_cmp = strcmp(s1->artist, s2->artist);

  //same artist
  if(artist_cmp == 0) {
    return strcmp(s1->name, s2->name);
  }

  //different artists, compare by their names
  else return artist_cmp;
}

struct node * free_node(struct node *node) {
  if(node->prev && node->next) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  else if(node->prev) {
    node->prev->next = NULL;
  }

  else if(node->next) {
    node->next->prev = NULL;
  }

  free(node);

  return NULL;
}

struct node * free_list(struct node *list) {
  while(list != NULL) {
    struct node *curr = list;
    list = list->next;
    free(curr);
  }
  return NULL;
}

//if strlen(data) > 15 this will not remove anything

/*struct node * remove_data(struct node *front, char *data) {
  struct node *ret = front;
  struct node *behind = NULL;
  while(front != NULL) {
    if(strncmp(front->data, data, sizeof front->data) == 0) {
      struct node *del = front;
      front = front->next;
      free(del);
      if(behind != NULL) {
        behind->next = front;
      }
      else {
        ret = front;
      }
      continue;
    }
    behind = front;
    front = front->next;
  }
  return ret;
}
*/
