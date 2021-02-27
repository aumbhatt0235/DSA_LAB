#include<stdio.h>
int stack[25];
int top = -1;

void push(int i)
{
    stack[++top] = i;
}

int pop()
{
    return stack[top--];
}

void main()
{
    char postfix[25];
    char *ptr;
    int n1,n2,n3,num;
    printf("Enter the expression: ");
    scanf("%s",postfix);
    ptr = postfix;
    while(*ptr != '\0')
    {
        if(isdigit(*ptr))
        {
            num = *ptr - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*ptr)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
        ptr++;
    }
    printf("\nThe result of expression is %s  =  %d\n\n", postfix, pop());
}