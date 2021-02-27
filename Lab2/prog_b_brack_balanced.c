#include<stdio.h>
#include<stdlib.h>

char*stack;
int stack_size;
int opCode;
int top=-1;

char br[30] = "{[][](())}{}";

int stackSize()
{
    return top+1;
}
int stackTop()
{  
    return stack[top];
}
int isEmpty()
{
    if(top==-1) return 1;
    else return 0;
}
int isFull()
{  
    if(top==stack_size-1) return 1;
    else return 0;
}
int push(char x)
{ 
    if(!isFull()) 
    {
        top = top + 1;
        stack[top] = x;
    }   
    else
        return -1;
}

char pop()
{	char data;
    if(!isEmpty()) 
    {
        data = stack[top];
        top = top -1;
        return data;
    }
    else
        return -1;
}

int main() {
    int check = 0;
    stack_size = 20;
    stack=(char*)calloc(sizeof(char), stack_size);

    for(int i=0;i<20;i++) 
    {
        if(br[i]=='[' || br[i]=='{' || br[i]=='(') 
        {
            push(br[i]);
        }
        if(br[i]==']') 
            if(pop()!='[') 
            { 
                check=1;
                break;
            }
        if(br[i]==')')
            if(pop()!='(') 
            {
                check=1;
                break;
            }   
        if(br[i]=='}') {
            if(pop()!='{') 
            {
                check=1;
                break;
            } 
        }
                  
    }
    
    if(check)
        printf("Incorrect parenthesis");
    else
        printf("Valid expression");
}