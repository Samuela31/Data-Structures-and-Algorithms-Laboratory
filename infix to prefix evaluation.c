#include <ctype.h>
#include <stdio.h>
#include <string.h>

char s[50];
int top = -1;

void push(char ch) {
    s[++top]=ch;
}

char pop(){
    return (s[top--]);
}

int precedence(char op) {
     switch (op) {

     case '(':
     return 1;

     case '+':
     case '-':
     return 2;

     case '*':
     case '/':
     return 3;
     }
}

void infix_to_postfix(char infix[], char postfix[]) {
     char ch, w, temp, tpost[50];
     int i = 0, k = 0;

     while ((ch = infix[i++]) != '\0') {
         if (ch == '(')
         {
             push(ch);
            //printf("\n* %s\n",s);
         }

         else if (isalnum(ch))
         {
             postfix[k++] = ch;
            //printf("\n$%c\n",postfix[k-1]);
         }

         else if (ch == ')') {
             while (s[top] != '(' && top!=-1)
                 postfix[k++] = pop();

             w = pop();
            //printf("\n#%s %s\n",postfix,s);
             }

         else {
             while (top!=-1 && precedence(s[top]) > precedence(ch)) postfix[k++] = pop();
             push(ch);
            //printf("\n& %s\n",s);
         }
     }

     while (top!= -1) /* Pop from stack till empty */
     postfix[k++] = pop();

     postfix[k] = '\0'; /* Make postfix as valid string */

     strcpy(tpost,postfix);

     for (i = 0; i < strlen(tpost)/2; i++)
    {
        temp = tpost[i];
        tpost[i] = tpost[strlen(tpost) - i - 1];
        tpost[strlen(tpost) - i - 1] = temp;
    }

     printf("\nPrefix Expression: %s", tpost);
}


int eval_prefix(char postfix[]) {
     char ch;
     int i = 0, op1, op2;

     while((ch = postfix[i++]) != 0) {
         if(isdigit(ch)) push(ch-'0'); /* Push the operand by converting it to integer*/

         else { /* Operator,pop two operands */
             op1 = pop();
             op2 = pop();
             switch(ch) {
                 case '+' : push(op1+op2);
                 break;
                 case '-' : push(op1-op2);
                 break;
                 case '*' : push(op1*op2);
                 break;
                 case '/' : push(op1/op2);
                 break;
             }
         }
     }
     return s[top];
}

void main() { /* Main Program */

 char infx[50], pofx[50], temp;
 printf("\nInput the infix expression: ");
 scanf("%s",infx);

  for (int i = 0; i < strlen(infx)/2; i++)
    {
        temp = infx[i];
        infx[i] = infx[strlen(infx) - i - 1];
        infx[strlen(infx) - i - 1] = temp;
    }

    for (int i = 0; i < strlen(infx); i++)
    {
        if( infx[i]==')') infx[i]='(';
        else if(infx[i]=='(') infx[i]=')';
    }


 printf("\nReverse Infix Expression: %s", infx);

 infix_to_postfix(infx, pofx);

 top = -1; //resetting for new stack in evaluation
 printf("\nResult of evaluation of prefix expression : %d", eval_prefix(pofx));

}
