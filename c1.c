#include<stdio.h>
#define SIZE 10
int stack[SIZE];
int top=-1;
void push(int value)
{
    if(top==SIZE-1)
    {
        printf("stack is ovreflow");
    }
    else{
        stack[++top]=value;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("stack is underflow");
    }
    else{
        printf("element is deleted :%d\n                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            ",stack[top]);
        top--;
    }
}
void peek()
{
    if(top==-1)
    {
        printf("stack is underflow");
    }
    else{
        printf("the peeked element is %d\n",stack[top]);
    }
}
void display()
{
    if(top==-1)
    {
        printf("stack is empty");
    }
    else{
        for(int i=top;i>=0;i--)
        {
            printf("the elements of stack are %d\n",stack[i]);
        }
    }
}
void main()
{
    int value;
    int choice;
    while(1){
    printf("1.Push\n2.Pop\n3.Peek\n4.Display\n ");
    printf("enter ur choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("enter the value to be inserted\n:");
              scanf("%d",&value);
              push(value);
              break;
        case 2:pop();
              break;
        case 3:peek();
              break;
        case 4:display();
              break;
        default:printf("wrong selection so try again!!");
    }
    }
}
