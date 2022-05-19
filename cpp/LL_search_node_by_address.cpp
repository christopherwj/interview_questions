
struct node { 
  int data; 
  struct node *next; 
}

node *search_by_address(struct node *head, struct node *candidate) { 
  struct node *iter; 
  for(iter = head; iter != NULL; iter = iter->next) { 
    if(iter == candidate) break; 
  } 
  return iter; 
} 


//==========================================================================
//version 2
Let's say your structure for linked list is like:

struct ll 
{ 
    int data; 
    struct ll *next; 
} *start; 

//Now, let's say the address of the node you want to search is stored in the pointer called key, then you can directly go for linear search as follows:

struct ll *key=start->next;        //For example I'm searching for 2nd node of the list. 
 
int search(struct ll *start, struct ll *key) 
{ 
    struct ll *tmp=start; 
    while(tmp) 
    { 
        if(tmp==key) 
            return tmp->data; 
        tmp=tmp->next; 
    } 
    return -1;            //Or return some indicator that node not found. 
} 
