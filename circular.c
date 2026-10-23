#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int items[SIZE];
int front=-1;
int rear=-1;
int isfull()
{
    if((front==rear+1)||(front==0 && rear==SIZE-1))
        return 1;
    return 0;
}
int isempty()
{
    if(front==-1)
        return 1;
    return 0;
}
void enqueue(int ele)
{
     if(isfull())
     {
         printf("\n Queue is full");
     }
     else
     {
         if(front==-1)
            front=0;
         rear=(rear+1)%SIZE;
         items[rear]=ele;
         printf("\n Inserted ->%d\n",ele);
     }
}
int dequeue()
{
    int ele;
    if(isempty())
    {
        printf("\n queue is empty");
        return -1;
    }
    else{
        ele=items[front];
        if(front==rear)
        {
        front=-1;
        rear=-1;
        }
        else
        {

    front=(front+1)%SIZE;
        }
        printf("\n Deleted element ->%d\n",ele);
        return ele;
    }

}
void display()
{
    int i;
    if(isempty())
    {
        printf("\nEmpty queue");
    }
    else
    {
        printf("\n Items->\n");
        for(i=front;i!=rear;i=(i+1)%SIZE)

            printf("%d   ",items[i]);
        printf("%d",items[i]);

    }
}
int main()
{
    int option,val,del;
    while(1)
    {

        printf("\n1.insert an ele\n");
        printf("2.delete an ele\n");
        printf("3.Display items\n");
        printf("enter an option\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1 :printf("enter the no to be inserted\n");
                    scanf("%d",&val);
                    enqueue(val);
                    break;
            case 2: del=dequeue();
                    printf("\n the no is deleted is %d\n",del);
                    break;
            case 3: display();
                    break;
            default:printf("it is an invalid option");
        }

    }
}
