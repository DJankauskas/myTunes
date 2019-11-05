#ifndef __NODE_GUARD
#define __NODE_GUARD

struct node {
    char name[128];
    char artist[128];
    
    struct node *prev;
    struct node *next;
};

void print_node(struct node *node);
void print_list(struct node *list);

//characters beyond index 127 will be ignored
struct node * insert_front(struct node *list, char *artist, char *name);

struct node * insert_in_order(struct node *front, char *artist, char *name);

//returned pointer may be invalidated by any mutating function called after this call!
//NULL returned on no match
struct node * find_first_artist(struct node *list, char *artist);

struct node * find_node(struct node *node, char *artist, char *name);

//compare by artist, then name
int songcmp(struct node *s1, struct node *s2);

struct node * get_random(struct node *list);

//returns pointer to given node, which is now NULL
struct node * free_node(struct node *node);

//returns pointer to list, which is now NULL
struct node * free_list(struct node *list);

// if strlen(data) > 15 this will not remove anything
// struct node * remove_data(struct node *front, char *data);

#endif //__NODE_GUARD
