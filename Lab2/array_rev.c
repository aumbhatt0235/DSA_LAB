#include<stdio.h>
#include<stdlib.h>

int*stack;
int stack_size;
int opCode;
int top=-1;

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
int push(int x)
{ 
    if(!isFull()) {
        top = top + 1;
        stack[top] = x;
    }   
    else
        return -1;
}

int pop()
{	int data;
    if(!isEmpty()) {
        data = stack[top];
        top = top -1;
        return data;
    }
    else
        return -1;
}

int main() 
{
    int arr[5];
    int i;
    
    for(i=0;i<5;i++)
    {
        arr[i] = i*2;
    }
    
    printf("Old array\n");
    for(i=0;i<5;i++) 
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    stack_size=10;
    stack=(int*)calloc(sizeof(int), stack_size);
    for(i=0;i<5;i++) 
    {
        push(arr[i]);
    }
    
    int newarr[5];
    
    for(i=0;i<5;i++)
        newarr[i] = pop();
    
    printf("Reversed array\n");
    for(i=0;i<5;i++)
        printf("%d ",newarr[i]);
    
}


