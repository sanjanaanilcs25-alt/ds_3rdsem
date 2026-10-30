
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

// Count the number of nodes
int count()
{
    struct node *temp;
    int i = 0;

    temp = head;

    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }

    return i;
}

// Create a new node
struct node *create(int value)
{
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    temp->data = value;
    temp->next = NULL;

    return temp;
}

// Insert at beginning
void insert_begin(int value)
{
    struct node *newnode;

    newnode = create(value);

    if (newnode == NULL)
        return;

    newnode->next = head;
    head = newnode;
}

// Insert at end
void insert_end(int value)
{
    struct node *newnode, *temp;

    newnode = create(value);

    if (newnode == NULL)
        return;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
}

// Insert at a given position
void insert_pos(int value, int pos)
{
    struct node *newnode, *temp1, *temp2;
    int i, c = 1;

    i = count();

    if (pos < 1 || pos > i + 1)
    {
        printf("Insertion is not possible\n");
        return;
    }

    if (pos == 1)
    {
        insert_begin(value);
        return;
    }

    newnode = create(value);

    if (newnode == NULL)
        return;

    temp1 = head;

    while (c < pos)
    {
        temp2 = temp1;
        temp1 = temp1->next;
        c++;
    }

    newnode->next = temp2->next;
    temp2->next = newnode;
}

// Display linked list
void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("%d\n", temp->data);
    }
}

// Main function
int main()
{
    int ch, pos, value;

    do
    {
        printf("\n1. Insert begin");
        printf("\n2. Insert end");
        printf("\n3. Insert position");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                insert_begin(value);
                break;

            case 2:
                printf("Enter the value: ");
                scanf("%d", &value);
                insert_end(value);
                break;

            case 3:
                printf("Enter the value: ");
                scanf("%d", &value);

                printf("Enter position you want to insert: ");
                scanf("%d", &pos);

                insert_pos(value, pos);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Your choice is wrong!\n");
        }

    } while (ch != 5);

    return 0;
}
