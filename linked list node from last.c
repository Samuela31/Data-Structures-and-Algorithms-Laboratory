#include <stdio.h>
#include <stdlib.h>

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
    new_node->next = NULL;

    printf("#\n");

    if (*head == NULL) {
      *head = new_node;
          printf("$\n");

      return;
    }

  new_node->next=(*head);
  *head=new_node;
      printf("@\n");

}

void last(struct node** head, int pos)
{
    int i=1;
    struct node* current = *head;

    while(i<pos)
        {
            current = current->next;
            i++;
        }
    printf("\n%c",current->data);
}

void printList(struct node* head)
{
    if (head == NULL)
    {
        printf("NULL\n\n");
        return;
    }

    printf("%c->",head->data);
    printList(head->next);
}

int main()
{
    char ele, c;
    int i, p, n;
    struct node* a = NULL;

    printf("Enter size of linked list: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf(" %c",&ele);
        push(&a, ele);
    }

    printf("\nEnter position: ");
    scanf("%d",&p);

    if(p<1 || p>n) return -1;

    printf("\nConverting string to linked list: \n");
    printList(a);

    last(&a, p);

    return 0;
}
