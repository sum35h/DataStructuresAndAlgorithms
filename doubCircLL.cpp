#include<iostream>
using namespace std;

class node
{
public:
 int data;
 node *next;node *prev;
};
void init_node(node **start,int value)
{
  //cout<<"init";
     node *new_node=new node();
     new_node->data=value;
     new_node->prev=new_node;
     new_node->next=new_node;
     *start=new_node;
   
}
void insert_end(node **start,int value)
{
  //check empty list
   if(*start==NULL)
     return init_node(start,value);
     
   //list is not empty
   node *new_node=new node();
   new_node->data=value;
   
   //get the last node via the start
   node *last=(*start)->prev;
   last->next=new_node;
   new_node->prev=last;
   
   new_node->next=(*start);
   (*start)->prev=new_node;
   
}
void insert_front(node **start,int value)
{
   if(*start==NULL)
    return (init_node(start,value));
    
   node *new_node=new node();
   new_node->data=value;
   
   node *last=(*start)->prev;
   
   new_node->next=*start;
   (*start)->prev=new_node;
   
   last->next=new_node;
   new_node->prev=last;
   
   *start=new_node;
}
void disp_list(node *start)
 {
 if(start==NULL)
  {
   cout<<"list is empty..."; return;
   return;
  }
  node *t= start;
  while(1)
  {
    cout<<t->data<<" ";
	if(t->next==start)
	  return;
	t=t->next; 
	// getchar();
  }
  
 }
void insert_after(node **start,int key,int value)
{
  if(*start==NULL)
    {
     cout<<"list is empty..."; return;
    }
   node * t=*start;//t is the node front of the new
   while(t->data!=key)
   {
    t=t->next;
    if(t==*start)
     {
     cout<<"key not found"<<endl;
      return ;
     }
    }
     node *new_node=new node();
     new_node->data=value;
     //
     node *s=t->next;//s is the node after new node
     
	 t->next=new_node;
	 new_node->prev=t;
	 
	 new_node->next=s;
	 s->prev=new_node;
   } 
    
void delete_node(node **start,int key)
{
  if((*start)->next==*start&&(*start)->prev==*start)//only one node check
   {
     delete(*start);
     *start=NULL;
     return;
   }
   node *t=*start;
   while(t->data!=key)
   {
    t=t->next;
    if(t==*start)
    {
     cout<<"key not found"<<endl;
     return;
     }
   }
   //key found
     node *front=t->prev;
     node *back=t->next;
     front->next=back;
     back->prev=front;
     if(t==*start)
      *start=back;
      
      delete(t);
     
   }
   

int main()
{
     node *n=NULL;
     
    
//     insert_end(&n,1);
//      insert_end(&n,2);
//      insert_end(&n,3);
//      insert_end(&n,4);
      insert_front(&n,1);
      insert_front(&n,2);
      insert_front(&n,3);
      insert_front(&n,4);
      
      insert_after(&n,1,6);
      
     
     disp_list(n);
    
    
      while(n)
      {int in;
      cout<<"\n key to be deleted:";
       cin>>in;
       delete_node(&n,in);
       disp_list(n);
       cout<<endl;
      }
    
     
}
