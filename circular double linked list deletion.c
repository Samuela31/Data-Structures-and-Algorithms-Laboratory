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
    new_node->next = (*head);
    new_node->prev = NULL;

    printf("#\n");

    if (*head == NULL) {
      *head = new_node;
      new_node->next = new_node;
      new_node->prev = new_node;
          printf("$\n");
      return;
    }

  while (last->next != (*head)) last = last->next;

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
        while (current->next != (*head)) current = current->next;

        current->next=(*head)->next;
        *head=(*head)->next;
        (*head)->prev=current;

        free(x);

    }

    else if(pos==n)
    {
        while(current->next!=(*head)) current=current->next;

        x=current;
        current->prev->next=(*head);
        (*head)->prev=current->prev;
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

void printList(struct node* head, int n)
{
    if (n == 0)
    {
            printf("||%c||\n\n",head->data);
        return;
    }

    printf("%c<->",head->data);
    printList(head->next, n-1);
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
    printList(a, n);

    del(&a, p, n);

    printList(a, n-1);


    return 0;
}
