//lnklst.c
#include<stdio.h>
#include<stdlib.h>
//Function prototype declarations

void insert_at_end(int);
void delete_from_middle(int);

int display();
struct node
{
    int data;
    struct node *next;
}*head,*trav;
int main()
{
    int i=0, value, loc, disp;
    head=NULL;

    insert_at_end(9);
    insert_at_end(7);
    insert_at_end(2);
    insert_at_end(12);
    insert_at_end(8);
    insert_at_end(2);
	insert_at_end(2);
	insert_at_end(15);
	insert_at_end(2);
    insert_at_end(6);
	 disp = display();

    if(disp!=0)
    {
        printf("\nEnter the data to be deleted : ");
        scanf("%d",&value);
        delete_from_middle(value);
        disp = display();
    }

}//end of main

void insert_at_end(int value)
{
    struct node *temp;
    temp=head;
    struct node *var=(struct node *)malloc(sizeof (struct node));
    var->data=value;
    var->next=NULL;
    if(head==NULL)
    {
        head=var;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=var;
    }
}//end of insert_at_end
void delete_from_middle(int value)
{
    struct node *temp = head;
    struct node *prev = NULL;

    // Traverse the list
    while (temp != NULL) {
        // If the value is found
        if (temp->data == value) {
            // If it's the head node
            if (temp == head) {
                head = temp->next;
                free(temp);
                temp = head;
            } else {
                // Update the previous node's next pointer
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
            printf("Data deleted from list: %d\n", value);
        } else {
            // Move to the next node
            prev = temp;
            temp = temp->next;
        }
    }
}//end of delete_from_middle

int display()
{
    trav=head;
    if(trav==NULL)
    {
        printf("\nList is Empty\n");
        return 0;
    }
    else
    {
        printf("\nElements in the List: ");
        while(trav!=NULL)
        {
            printf(" -> %d ",trav->data);
            trav=trav->next;
        }
        printf("\n");
        return 1;
    }
}//end of display
