#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "tree.h"

int main(int argc, char *argv[])
{  
  struct node* head;
  int i,count = 0;

  if(argc != 2)
  { printf("Syntax Error : tree numb_of_elements");
    return 1;
  }

  head = build();
  display_tree(head);
  printf("\n");

  for(i=0;i<10;i++)
    head=rand_insert(head,i);
  display_tree(head);
  printf("\n");
  
  count = count_red(head,1); 
  printf("Count RED : %d \n",count);
  count = count_red_children(head,1); 
  printf("Count of red nodes with non red children: %d \n",count);
	  
  delete_tree(head); 
  
  printf("Val 1 = %d", test_me(1));
  printf("Val 2 = %d", test_me_2(1));
  return 0;

  
}
