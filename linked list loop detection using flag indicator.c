#include <stdio.h>
#include <stdlib.h>

struct node //node creation
{
  char data;
  int flag;
  struct node *next;
};

void push(struct node** head, char new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* last = *head;

    new_node->data = new_data;
    new_node->flag=0;
    new_node->next = (*head);

    printf("#\n");

    if (*head == NULL) {
      *head = new_node;
      new_node->next = (*head);
          printf("$\n");
      return;
    }

  while (last->next != (*head)) last = last->next;

  last->next = new_node;
      printf("@\n");

}

int detectLoop(struct node* head)
{
    struct node *last = head;

      while (last){
           if (last->flag == 1) {
            return 1;
        }
          last->flag=1;
          last = last->next;
    }
    return 0;
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

    printf("%d",detectLoop(a));


    return 0;
}
