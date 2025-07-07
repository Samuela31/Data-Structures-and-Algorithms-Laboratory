#include <stdio.h>
#include <stdlib.h>

struct node //node creation
{
  char data;
  struct node *next;
  struct node *prev;
};

void push(struct node** head, char new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* last = *head;

    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;

    printf("#\n");

    if (*head == NULL) {
      *head = new_node;
          printf("$\n");
      return;
    }

  while (last->next != NULL) last = last->next;

  last->next = new_node;
  new_node->prev=last;
      printf("@\n");

}

void del(struct node** head, int pos, int n)
{
    int i=1;
    struct node *x, *current = *head;

    if (pos==1 && current != NULL)
    {
        x=*head;
        (*head)->next->prev=NULL;
        *head=(*head)->next;
        free(x);

    }

    else if(pos==n)
    {
        while(current->next!=NULL) current=current->next;

        x=current;
        current->prev->next=NULL;
        free(x);
    }

    else{
        while(i<pos)
        {
            current = current->next;
            i++;
        }
        x=current;
        current->prev->next=current->next;
        current->next->prev=current->prev;
        free(x);
    }
}

void printList(struct node* head)
{
    if (head == NULL)
    {
            printf("NULL\n\n");
        return;
    }

    printf("%c<->",head->data);
    printList(head->next);
}

int main()
{
    char ele;
    int i, p, n;
    struct node* a = NULL;

    printf("Enter size of linked list: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf(" %c",&ele);
        push(&a, ele);
    }

    printf("\nEnter position to delete: ");
    scanf("%d",&p);

    if(p<1 || p>n) return -1;

    printf("\nConverting string to linked list: \n");
    printList(a);

    del(&a, p, n);

    printList(a);


    return 0;
}
