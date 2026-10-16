#include<stdio.h>
#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;
void enque()

{ int ele;
    if(rear==MAX-1)
    {
        printf("the queue is full");
    }
    else
    {
        printf("enter the element to be insert");
        scanf("%d",&ele);
        if(front=-1)
            front=0;
        rear++;
        queue[rear]=ele;

        printf("insertion is successfull");
    }
}
void deque()
{
    if(front==-1){
        printf("the queue is underflow");
    }
    else{
       printf("the deleted element is %d\n",queue[front]);
       front=front+1;
    }
}
void display()

{   int i;
    if(front==-1)
        printf("the queue is empty");
    else
        for(i=front;i<=rear;i++)
        printf("%d\n",queue[i]);

}
void main()
{
    int choice;
    while(1)
    {
        printf("1.enqueue\n2.deque\n3.display\n");
        printf("enter ur choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:enque();
                   break;
            case 2:deque();
                   break;
            case 3:display();
                   break;
            default:printf("the wrong choice");

    }}
}
