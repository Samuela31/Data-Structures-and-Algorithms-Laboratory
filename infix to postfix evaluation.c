#include <ctype.h>
#include <stdio.h>

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
     char ch, w;
     int i = 0, k = 0;

     while ((ch = infix[i++]) != '\0') {
         if (ch == '(')
             push(ch);

         else if (isalnum(ch))
             postfix[k++] = ch;

         else if (ch == ')') {
             while (s[top] != '(' && top!=-1) postfix[k++] = pop();

             w = pop();
             }

         else {
             while (top!=-1 && precedence(s[top]) >= precedence(ch)) postfix[k++] = pop();
             push(ch);
         }
     }

     while (top!= -1) /* Pop from stack till empty */
     postfix[k++] = pop();

     postfix[k] = '\0'; /* Make postfix as valid string */
}


int eval_postfix(char postfix[]) {
     char ch;
     int i = 0, op1, op2;

     while((ch = postfix[i++]) != '\0') {
         if(isdigit(ch)) push(ch-'0'); /* Push the operand by converting it to integer*/

         else { /* Operator,pop two operands */
             op2 = pop();
             op1 = pop();
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

 char infx[50], pofx[50];
 printf("\nInput the infix expression: ");
 scanf("%s",infx);

 infix_to_postfix(infx, pofx);

 printf("\nGiven Infix Expression: %sPostfix Expression: %s", infx, pofx);

 top = -1; //resetting for new stack in evaluation
 printf("\nResult of evaluation of postfix expression : %d", eval_postfix(pofx));

}
