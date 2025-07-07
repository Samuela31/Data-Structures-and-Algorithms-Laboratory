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

void insert(struct node** head, int x, int pos, int n)
{
    int i=1;
    struct node* current = *head;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = x;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (pos==1 && current != NULL)
    {
        new_node->next=*head;
        while (current->next != (*head)) current = current->next;

        current->next=new_node;
        new_node->prev=current;
        *head=new_node;
    }

    else if(pos==n)
    {
        push(head, x);
    }

    else{
        while(i<pos-1)
        {
            current = current->next;
            i++;
        }
        new_node->next=current->next;
        current->next->prev=new_node;
        new_node->prev=current;
        current->next=new_node;
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

    printf("\nEnter element to insert: ");
    scanf(" %c",&c);

    printf("\nEnter position to insert: ");
    scanf("%d",&p);

    if(p<1 || p>n) return -1;

    printf("\nConverting string to linked list: \n");
    printList(a, n);

    insert(&a, c, p, n);

    printList(a, n+1);


    return 0;
}
