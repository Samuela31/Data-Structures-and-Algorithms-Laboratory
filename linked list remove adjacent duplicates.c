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

    if (*head == NULL) {
      *head = new_node;
      return;
    }

  while (last->next != NULL) last = last->next;

  last->next = new_node;

}

void remove_adj_dup(struct node** head)
{
    struct node *temp=NULL, *current= *head, *temp2=NULL;
    int flag=1;

    while(flag && current)
    {
        current = *head;
        flag=0;

        while(current && current->next)
        {
            //printf("$ %c\n",current->data);
            if(current->data==current->next->data)
            {
                temp=current;
                flag=1;
                //in this while loop if we put current->next!=NULL after current->data==current->next->data, it doesn't work
                //https://en.wikipedia.org/wiki/Short-circuit_evaluation
                while(current->next!=NULL && current->data==current->next->data )
                {
                    current=current->next;
                }
                //printf("@ %c\n",current->data);
                if(temp== *head) *head=current->next;

                else
                {
                    //printf("# %c\n",current->data);
                    temp2= *head;
                    while(temp2->next!=temp) temp2=temp2->next;
                    temp2->next=current->next;
                }
                //printf("# %c\n",current->next->data);
                //printList(*head);
            }

            current=current->next;
        }
    }
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
    char s[100];
    int i;
    struct node* a = NULL;

    printf("Enter string: ");
    scanf("%s",s);

    for(i=0;s[i]!='\0';i++){
        push(&a, s[i]);
    }

    printf("\nBefore: \n");
    printList(a);

   remove_adj_dup(&a);

    printf("\nAfter: \n");
    printList(a);


    return 0;
}
