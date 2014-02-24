#include <stdlib.h>

struct node 
{ int data;
  struct node* left;
  struct node* right;
};

struct node* newnode(int data);
struct node* build();
int delete_tree(struct node* head);
int display_tree(struct node* head);
struct node* rand_insert(struct node* head, int val);
int display_level_tree(struct node* head);
int size_tree(struct node* head);
int maxDepth(struct node* head);
int count_red(struct node* head, int val);
int all_children_not_red(struct node* head, int val);
int all_desc_not_red(struct node* head, int val);
int count_red_children(struct node* head, int val);
