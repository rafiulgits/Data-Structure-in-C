#include<stdio.h>

/* create a structure for Linked list
   variable will carry the element
   nextLink will carry the index or location for next element
*/
struct Node
{
    int variable;
    struct Node* nextLink;
};

/// linked list operation functions
struct Node* insertFront(int dataElement, struct Node* head);
void Print(struct Node* head);
struct Node* insertDataAt(int dataElement,int index, struct Node* head);
struct Node* deleteAt(int index, struct Node* head);
struct Node* reverseList(struct Node* head);

/// Main function
int main()
{
    struct Node* head = NULL; // initial the head as NULL

    int Counter=0;
    while(Counter<10)
    {
        head = insertFront(Counter,head); // Inserting 0 to 9 in linked list
        Print(head); // print the list after each insertion
        Counter++;
    }
    head = insertDataAt( 78, 2, head); // insert 78 at index 2
    Print(head); // print the link list
    head = deleteAt(2, head); // delete the element at index no 2
    Print(head); // print the link list
    head = reverseList(head); // reverse the whole list
    Print(head); // print the link list
}

/// function declaration area
struct Node* insertFront(int dataElement, struct Node* head)
{
    /* create a temp node
       Set memory allocation for temp
       store the new element into the temp node data box
       link temp node to previous node which indicate the head node
       link head node to temp node
    */
    struct Node* tempNode;
    tempNode=(int*)malloc(sizeof(struct Node));
    tempNode->variable=dataElement;
    tempNode->nextLink=head;
    head=tempNode;
    return head;

    /* ::::::::::::::remember:::::::::::::::
       in linked list generally new node inserted
       at the beginning point. link the previous
       node to new one and new one to head
    */
}
void Print(struct Node* head)
{
    while(head!=NULL)
    {
        printf("%d ",head->variable);
        head=head->nextLink;
    }
    puts(""); // for next line
}
struct Node* insertDataAt(int dataElement,int index, struct Node* head)
{
    struct Node* tempNode = (int*)malloc(sizeof(struct Node));
    tempNode->variable = dataElement;
    struct Node* tempHead = head; int i;
    for(i=0;i<index-1;i++)
    {
        /* if we want to insert an at 2-th position this loop will continue for
           i's value 0, 1. And 1-> next index will be the 2-th index
        */
        tempHead = tempHead->nextLink;
    }
    tempNode->nextLink = tempHead->nextLink;
    tempHead->nextLink = tempNode;

    return head;
}
struct Node* deleteAt(int index, struct Node* head)
{
    int i; struct Node* tempHead = head;
    for(i=0; i<index-1; i++)
    {
        /* if we want to delete at 2-th position's element this loop will continue for
           i's value 0, 1. And 1-> next index will be the 2-th index
        */
        tempHead = tempHead->nextLink;
    }
    struct Node* temp = tempHead->nextLink;
    tempHead->nextLink = temp->nextLink;
    free(temp);

    return head;
}
struct Node* reverseList(struct Node* head)
{
    /* :::::::::: Reverse Flow ::::::::::::::
       Check "Linked List Reverse Flow.JPG" file
    */
    struct Node* Current;
    struct Node* Previous;
    struct Node* Next;

    Current = head;
    Previous = NULL;

    while(Current != NULL)
    {
        Next = Current->nextLink;
        Current->nextLink = Previous;
        Previous = Current;
        Current = Next;
    }
    head = Previous;

    return head;
}
