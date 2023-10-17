#include <stdio.h>
#include <stdlib.h>
//creating structure
typedef struct node node;
struct node
{
    int data;
    node *next;
};
//function for creating new node for the linked list
node *newnode(int d,node *n)
{
    node *new_node=(node*)(malloc(sizeof(node)));
    new_node->data=d;
    new_node->next=n;
    return new_node;
}
//function for printing the linked list
void print(node *head)
{
   node *crnt=head;
   while(crnt!=NULL)
   {
     printf("%d ",crnt->data);
     crnt=crnt->next;
   }
}
//inserting new node at first
void start(node **head,int d)
{
    *head= newnode(d,*head);
    
}
//inserting new node in the end
void end(node **head,int d)
{
    node *crnt= *head;
    while(1)
    {
        if(crnt->next==NULL)
        {
            crnt->next=newnode(d,NULL);
            
            break;
        }
        crnt=crnt->next;
    }
}
//inserting new node in a specefic position
void pos(node **head,int d,int p)
{
    node *crnt= *head;
    node **t=head;
    if (p==1)
    {
        
        start(t,d);
    }
    else
    {
    int i=1;
    while(1)
    {
        crnt=crnt->next;
        if(i==p-1)
        {
            node *h=crnt->next;
            crnt->next=newnode(d,h);
            break;
        }
        i++;
    }
    }
    

}
int main()
{
  

   int n,s;
   node *head=NULL,*temp;
   printf("Create linked list\n");
   printf("Give size\n");  
   scanf("%d",&s);
   printf("Enter Data(using space)\n");
   for(int i=0;i<s;i++)
   {
    
    scanf("%d",&n);
    if(head==NULL)
    {
        head=temp=newnode(n,NULL);
    }
    else
    {
        temp->next=newnode(n,NULL);
        temp=temp->next;
        
    }
    
   }
   
   int choice, data, position;
  //taking user input by using switch case
    while (1) {
        printf("\nLinked List insert Operations:\n");
        printf("1. Add to start\n");
        printf("2. Add to end\n");
        printf("3. Add at a specific position\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add at the start: ");
                scanf("%d", &data);
                start(&head, data);
                printf("\nsuccessfully added\n");
                break;
            case 2:
                printf("Enter data to add at the end: ");
                scanf("%d", &data);
                end(&head, data);
                printf("\nsuccessfully added\n");
                break;
            case 3:
                printf("Enter data to add: ");
                scanf("%d", &data);
                printf("Enter position to add at: ");
                scanf("%d", &position);
                pos(&head, data, position);
                printf("\nsuccessfully added\n");
                break;
            case 4:
            printf("\n");
                print(head);
                printf("\n");
                break;
            case 5:
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}
