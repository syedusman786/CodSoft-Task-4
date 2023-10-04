#include<iostream>
using namespace std;

class node
{
public:
string data;
bool task_completion;
node *next;
node *prev;

 node(string val)
 {
    data=val;
    task_completion=false;
    next=NULL;
    prev=NULL;
 }
};

class list
{
private:
   node *head;
   int length;
public:

  list()
   {
      head=NULL;
      length=0;
   }
   
   void insert(string val,int pos)
   {
    if (pos<1 || pos>length+1)
     return;

     node *n= new node(val);

    if (pos==1)
    {
        n->next=head;
        
        if (head!=NULL)
        {
         head->prev=n;   
        }

       head=n; 
        
    }
    else
    {
      node *curr=head;

      for(int i=1;i<pos-1;i++)
      {
        curr=curr->next;
      }

      n->prev=curr;
      n->next=curr->next;

      if(curr->next!=NULL)
      {
        curr->next->prev=n;
      }

      curr->next=n; 
    }

     length++;

   }

   void remove(int pos)
   {
      if (head==NULL)
        {
            cout<<"Empty list"<<endl;
            return;
        }

        if (pos<1 || pos>length)
        {
            cout<<"Invalid position"<<endl;
            return;
        }

        node *curr=head;

        if (pos==1)
        {
         head=head->next;
         delete curr;
         if(head!=NULL)
         {
            head->prev=NULL;
         }
        }
       else
       {
         node *slow=NULL;

        for(int i=1;i < pos;i++)
        {
         slow=curr;
         curr=curr->next;
        }

        slow->next=curr->next;

        if(curr->next!=NULL)
         {
          curr->next->prev=slow;
         }
         delete curr;
       } 

       length--;
   }

   void t_completion(int pos)
   {
    node *curr=head;

    for(int i=1;i<pos;i++)
    {
     curr=curr->next;
    }
    curr->task_completion=true;
   }

   void print()
   {
    if (length==0)
    {
      cout<<"empty list"<<endl;
      return;
    }
    node  *curr=head;
    string task;

    for  (int i=1;i<=length;i++)
    {
       if (curr->task_completion==true)
      {
       task="Completed";
      }

      else 
      {
       task="Not Completed"; 
      }
      cout<<i<<"). "<<curr->data<<" - "<<task<<endl;
      curr=curr->next;
    }
   }

   void remove_task()
   {
    node *curr=head;

    for(int i=1;i<=length;i++)
    {
      if(curr->task_completion==true)
       {
        remove(i);
       }
       curr = curr->next;
    }
   }
   
   void display()
   {
    node*curr=head;

    for(int i=1;i<=length;i++)
    {
      cout<<i<<"). "<<curr->data<<endl;
      curr=curr->next;
    }
   }

   
};

int main ()
{
    list l1;

    int choice,pos;
    string td;
    
    for(int i=0;1;i++)
  {
    cout<<"**************************"<<endl;
    cout<<"Menu"<<endl;
    cout<<"**************************"<<endl;
    cout<<"1. Add a Task"<<endl;
    cout<<"2. Mark as Completed"<<endl;
    cout<<"3. Remove Completed Tasks"<<endl;
    cout<<"4. Display Tasks"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Select an option: ";
    cin>>choice;

    if (choice==1)
    {
     cout<<"Enter the task description: ";
     getline(cin>>ws,td);

     cout<<"Enter its priority level: ";
     cin>>pos;
     
      l1.insert(td,pos);
      l1.print();
    }

    if (choice==2)
    {
      int num;

      l1.print();
      cout<<endl;

      cout<<"Enter the task number to  mark as completed: ";
      cin>>num;

      l1.t_completion(num);

      l1.print();
    }

    if (choice==3)
    {
     l1.remove_task();
     l1.print(); 
    }

   if(choice==4)
   {
    l1.display();
    }
    

   if (choice==5)
   {
    break;
   }
  
  }
   
}