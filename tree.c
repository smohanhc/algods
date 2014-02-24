#include <stdlib.h>
#include "tree.h"
#include "linkedlist.h"

struct node* newnode(int data)
{ struct node* head = malloc (sizeof(struct node));
  head->data = data;
  head->left = NULL;
  head->right = NULL;
  return(head);
}

struct node* build()
{ struct node* root = newnode(1);
  root->left = newnode(1);
  root->right = newnode(2);
  root->left->left = newnode(2);
  root->left->right = newnode(2);
  root->right->left = newnode(3);
  root->right->right = newnode(2);

  return(root); 
} 

int delete_tree(struct node* head)
{ if(head != NULL)
  { delete_tree(head->left);
    delete_tree(head->right);
  }
  free(head);
  return(0);
}

int display_tree(struct node* head)
{
  if (head == NULL) return 0;

  display_tree(head->left);
  printf("%d ", head->data);
  display_tree(head->right);
 
//  { if(head->left != NULL) display_tree(head->left);
 //   if(head->right != NULL) display_tree(head->right);
 // }
  return 1;
}

struct node* rand_insert(struct node* head, int val)
{ if(head == NULL) return(newnode(val));
  else { if(val <= head->data) 
           head->left = rand_insert(head->left,val); 
	 else
           head->right = rand_insert(head->right,val);
       }
return(head);
}


int display_level_tree(struct node* head)
{ if(head == NULL) return 0;
  
  printf("%d ", head->data);
  display_tree(head->left);
  display_tree(head->right);

  return 1;

}

int size_tree(struct node* head)
{ if(head == NULL)
    return(0);
  else
    return(size_tree(head->left)+1+size_tree(head->right));
}


int maxDepth(struct node* head)
{ if(head == NULL) return(0);
  else
  { int ldepth = maxDepth(head->left); 
    int rdepth = maxDepth(head->right); 
   
    if(ldepth<rdepth)
      return(ldepth+1);  
    else 
      return(rdepth+1);
  }
}


/*int countRedNodes(struct node* head, int val)
{ int count=0;
  if(head==NULL) return(0);
 
 
  if(head->data == val)
    {  
     if(!check_children_red(head))
		    (head->left->data != val) && (head->right->data != val)
     
    }


}*/

int count_red(struct node* head, int val)
{ int count = 0;
  if(head == NULL)
    return 0;
  if(head->left != NULL) count += count_red(head->left, val);
  if(head->right != NULL) count += count_red(head->right, val);
  if(head->data == val) count++;
  return count;
}


int all_children_not_red(struct node* head, int val)
{ if((head->left) != NULL)
  { if(head->left->data == val)
      return 0;
  }
 if((head->right) != NULL)
  { if(head->right->data == val)
      return 0;
  }
  if((head->left == NULL) && (head->right == NULL))
    return 0;
  return 1;
}

int all_desc_not_red(struct node* head, int val)
{ if(head == NULL)
	return 0;
  if(head->left != NULL)
  { if(head->left->data == val)
      return 0;
    if(!all_desc_not_red(head->left, val)) 
    return 0;
  }
  if(head->right != NULL)
  { if(head->right->data == val)
      return 0;
    if(!(all_desc_not_red(head->right, val))) 
    return 0; 
  }
  return 1;	
}

int count_red_children(struct node* head, int val)
{ int count = 0;
  if(head == NULL)
    return 0;
  
  if(head->left != NULL) count += count_red_children(head->left,val);
  if(head->right != NULL) count += count_red_children(head->right,val);
  
  if(head->data == val)
  { if(all_desc_not_red(head,val))
    { count++;
    }
  }
  
  return count;
}



