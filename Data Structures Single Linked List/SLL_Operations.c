#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

struct node {
    int data;
    struct node* next;
};

struct node* header;
struct node* newNode;

void insertAtFront(int val);
void insertAtEnd(int val);
void insertAtPos(int val, int pos);
void deletethefirstnode();
void deletethendnode();
void deleteatanyposition(int pos);
void printLinkedList();

int main() {
    int size, valFirst, val ,pos;
    struct node* temp;

    header = NULL;

    printf("Enter the Size of Linked List: ");
    scanf("%d", &size);

    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value of the first node: ");
    scanf("%d", &valFirst);
    newNode->data = valFirst;
    newNode->next = NULL;
    header = newNode;
    temp = header;


    for (int i = 2; i <= size; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the values of the linked list: ");
        scanf("%d", &val);
        newNode->data = val;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
      
      
    }
      printf("Original Linked List\n");
      printLinkedList();
      char continueChoice;
do
{
    printf("\n******************** Menu ********************\n");
    printf("\n1.Insert At The Front");
    printf("\n2.Insert at the End");
    printf("\n3.Instert at any Position");
    printf("\n5.Delete First Node");
    printf("\n7.Deletion at the End");
    printf("\n8.Delete any Position on the Node");
    printf("\n4.Display Linked List Values");
    printf("\n5.EXIT Program\n");
    int choice;
    printf("\nEnter Choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Enter the value: ");
        scanf("%d",&val);
        insertAtFront(val);
        break;
    case 2:
        printf("Enter the Value: ");
        scanf("%d",&val);
        insertAtEnd(val);
        break;
    case 3:
        printf("Enter the value: ");
        scanf("%d",&val);
        printf("Enter the Position: ");
        scanf("%d",&pos);
        insertAtPos(val,pos);
        break;
        
    case 4:
        printLinkedList();
        break;

    case 5:
        deletethefirstnode();
        break;
    case 7:
        deletethendnode();
        break;
    case 8:
        printf("Enter the Position you want to delete ");
        scanf("%d",&pos);
        deleteatanyposition(pos);
        break;
    default:  
        printf("Wrong Choice Please Try Again");
        break;
    }
    printf("\nDo you want to continue (Y/N) ");
    scanf(" %c", &continueChoice);
} while (continueChoice == 'y'|| continueChoice=='Y');}
void printLinkedList(){
    struct node *temp;
    temp=header;
    printf("Linked List Data\n");
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}
void insertAtFront(int val){
    struct node*temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=header;
    header=newNode;
    temp=header;
    printf("Data Insertion Success");
}
void insertAtEnd(int val) {
    struct node* temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    
    if (header == NULL) {
        header = newNode;
    } else {
        temp = header;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    printf("Data insertion Success");
}
void insertAtPos(int val,int pos)
{
    struct node*temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=NULL;
    
    temp = header;
            for (int i=1; i<pos-1;i++) // go to pos-1 location to insert linked list
            {
                temp=temp->next;
            }
            newNode->next=temp->next; //EZ
            temp->next=newNode; //XD newnode name for all nodes xd
            printf("Data Inserted Successfully");
            

}
void deletethefirstnode()
{
    struct node*temp;
   
    if (header==NULL)
    {
        printf("List Is Empty");
    }
    else{
            temp=header;
            header=header->next;
    }
    free(temp);
    printf("First Node Successfully Deleted");
    
}
void deletethendnode()
{
    struct node *temp;
    struct node *secondlastnode;
    temp=header;
    secondlastnode=header;
    while (temp->next!=NULL)
    {
        secondlastnode=temp;
        temp=temp->next;
    }
    if(temp==header)
    {
        header=NULL;
    }
    else{
        secondlastnode->next=NULL;
    }
    printf("End Node Deleted Successfully");
    free(temp);
    
}
void deleteatanyposition(int pos)
{   
    struct node*temp;
    temp=header; // temp variable to store the header
    if (pos==1) //if the user enter 1 or want to delete the header node(first node)
    {
    header=temp->next; // make the header point to the next node
    free(temp); // delete the first header
    return;
        }
   for (int i=1; i<pos-1;i++)
            {
                temp=temp->next; // temp point to pos-1th node
            }
            struct node *deletednode = temp->next; // point to the nth(desired position) node
            temp->next=deletednode->next; //link n-1 and n+1 node
            free(deletednode); //delete the nth node
            printf("Data Deleted Success"); 
}