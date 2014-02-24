#include <stdlib.h>

struct link_node
{ int data;
	  struct link_node* next;
};

int push(struct link_node **head, int data);
struct link_node* build_list();
int delete_list(struct link_node* head);
int length_list(struct link_node* head);
int display_list(struct link_node* head);
int count(struct link_node* head, int num);
int GetNth(struct link_node* head, int pos);
int pop(struct link_node** head);
int push_at_end(struct link_node* head, int val);
int insertNth(struct link_node* head, int pos, int val);
