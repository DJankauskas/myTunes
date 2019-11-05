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

struct node * insert_front(struct node *list, char *artist, char *name) {
    struct node *front = calloc(1, sizeof(struct node));
    front->next = list;
    front->prev = NULL;
    strncpy(front->artist, artist, sizeof front->artist);
    strncpy(front->name, name, sizeof front->name);
    
    //ensure null termination
    front->artist[(sizeof front->artist) - 1] = '\0';
    front->name[(sizeof front->name) - 1] = '\0';
    
    return front;
}

struct node * insert_in_order(struct node *front, char *artist, char *name) {
  if(!front) {
    return insert_front(NULL, artist, name);
  }

  struct node dummy = { 0 };
  strncpy(dummy.artist, artist, sizeof dummy.artist);
  strncpy(dummy.name, name, sizeof dummy.name);
  struct node *ret = front;
  for(; front->next != NULL; front = front->next) {
    if(songcmp(&dummy, front) > 0) {
      insert_front(front, artist, name);
      return ret;
    }
  }

  //current data goes last
  dummy.prev = front;
  struct node *last = malloc(sizeof(struct node));
  memcpy(last, &dummy, sizeof(struct node));
  front->next = last;
  return ret;
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

void print_node(struct node *node) {
  if(node) {
    printf("%s : %s", node->artist, node->name);
  }
  else printf("null");
}

struct node * find_first_artist(struct node *list, char *artist) {
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


struct node * get_nth(struct node *list, size_t n) {
  for(; n != 0; n--) {
    list = list->next;
  }
  return list;
}

size_t get_length(struct node *list) {
    size_t length = 0;
    for(; list != NULL; list = list->next) {
        length++;
    }
    return length;
}

struct node * get_random(struct node *list) {
  if(!list) return NULL;
  size_t length = get_length(list);
  return get_nth(list, rand() % length);
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
