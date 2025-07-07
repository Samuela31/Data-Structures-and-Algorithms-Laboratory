#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node //node creation
{
  char data;
  struct node *next;
};

void push(struct node** head, char new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* last = *head;

    new_node->data = new_data;
    new_node->next = (*head);

    if (*head == NULL) {
      *head = new_node;
      new_node->next = (*head);
      return;
    }

  while (last->next != (*head)) last = last->next;

  last->next = new_node;

}

void printList(struct node* head, int n)
{
    if (n == 0)
    {
            printf("||%c||\n\n",head->data);
        return;
    }

    printf("%c->",head->data);
    printList(head->next,n-1);
}

void del(struct node** head, int k, int n)
{
    int i;
    struct node *x, *prev, *current = *head;

    printList(*head,n);
    while(n > 1)
    {
        i=1;
        while(i<k)
        {
            i++;
            prev = current;
            current=current->next;
        }

        x=current; //node to be deleted
        n--;

        if (x==(*head) && (*head) != NULL) //node to be deleted is head node
        {
            (*head)=(*head)->next;
            prev->next = (*head);
            free(x);
        }

        else{
            prev->next=current->next;
            free(x);
        }

        current = prev->next;
        printList(*head,n);
    }

    printf("%c\n",current->data);
    printList(*head,n-1);
}


int main()
{
    char ele;
    int i, p, n, k;
    struct node* a = NULL;

    printf("Enter size of linked list: ");
    scanf("%d",&n);

    printf("Enter skipping value: ");
    scanf("%d",&k);

    for(i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf(" %c",&ele);
        push(&a, ele);
    }

    del(&a, k, n);

    return 0;
}
