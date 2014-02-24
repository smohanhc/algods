#include <stdlib.h>
#include "linkedlist.h"

int push(struct link_node **head, int data)
{ struct link_node* newlink_node;
  newlink_node=malloc(sizeof(struct link_node));
  newlink_node->data=data;
  newlink_node->next=*head;
  *head=newlink_node;
  return 0;
}


struct link_node* build_list()
{ struct link_node *one = NULL, *two = NULL, *three = NULL;
  one = malloc(sizeof(struct link_node));
  two = malloc(sizeof(struct link_node));
  three = malloc(sizeof(struct link_node));
  one->data=1;
  two->data=2;
  three->data=3;
  one->next=two;
  two->next=three;
  return one;
}


int delete_list(struct link_node* head)
{ struct link_node* temp = NULL;

  if(head == NULL)
    return 0;

  while(head != NULL)
  { temp=head->next;
    free(head);
    head = temp;
  }
  return 0;
}


int length_list(struct link_node* head)
{ int count = 0;
  while(head != NULL)
  { count++;
    head = head->next;
  }
  return count;
}

int display_list(struct link_node* head)
{
  struct link_node* temp = NULL;
  printf("Vals = ");
  do
  { printf("%d ", head->data);
    temp = head;
    head = head->next;
  } while(temp->next != NULL);
  printf("\n");
  return 0;
}

int count(struct link_node* head, int num)
{ int val = 0;
  while(head != NULL)
  { if(head->data == num)
      val++; 
    head = head->next; 
  }
return val;
}

int GetNth(struct link_node* head, int pos)
{ int count=0;
  while(head != NULL)
  { if(count == pos)
      return(head->data);
    count++; 
    head=head->next;
  }
return(-1);
}

int pop(struct link_node** head)
{ int result;
  struct link_node* next_link_node = NULL; 
  if(head != NULL)
    next_link_node = (*head)->next;
  result = (*head)->data;
  free(*head);
  *head=next_link_node;
  return(result);
}

int sorted_insert_1(struct link_node** head, struct link_node* curr_node)
{ if((*head == NULL) || ((*head)->data >= curr_node))
  { curr_node->next = *head;  
    *head = curr_node;
  }
  
  else
  { struct node* temp_node = *head;
    while((temp_node->next != NULL) && (temp_node->next->data < curr_node->data))
    { temp_node = temp_node->next;
    }
    curr_node->next = temp_node->next;
    temp_node->next = curr_node; 
  }
  return 0;
}


int sorted_insert_2(struct link_node** head, struct link_node* curr_node)
{ struct link_node dummy;
  struct link_node* current = &dummy;
  dummy.next = head;
  while((current->next != NULL) && (current->next->data > curr_node->data)) 
  { current = current->next;
  }
  curr_node->next = temp_node->next;
  temp_node->next = curr_node;
  return 0;
}

int sorted_insert_3(struct link_node** head, struct link_node* curr_node)
{ struct node** ref_node = head;
  while((*ref_node != NULL) && ((*ref_node)->data < curr_node->data ))
  { ref_node = &((*ref_node)->next);
  }
  curr_node->next = *ref_node;
  *refnode = curr_node;
  return 0;
}

int insert_sort(struct node* head)
{ struct node*  


}


int push_at_end(struct link_node* head, int val)
{ 
  
  return 1;

	
}


int insertNth(struct link_node* head, int pos, int val)
{ int count = 0;
  struct link_node *current = head;
  /*struct link_node *newlink_node = NULL;*/
  while((current!=NULL)&&(count<pos))
  { current=current->next;
    count++;
  }
  if(current == NULL)
    return(-1);
  
  push(&(current->next),val); 
  /*newlink_node = malloc(sizeof(struct link_node));
  newlink_node->data=val;
  newlink_node->next=current->next;
  current->next=newlink_node;
  */
  return(1);
}
