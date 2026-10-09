#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ele)
{
    stack[++top] = ele;
}

char pop()
{
    return stack[top--];
}

int precedence(char symbol)
{
    if (symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

int main()
{
    char infix[50], postfix[50], ch, ele;
    int i = 0, j = 0;

    printf("Enter the infix expression: ");
    scanf("%49s", infix);

    push('#');

    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')
        {
            push(ch);
        }
        else if (isalnum((unsigned char)ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == ')')
        {
            while (stack[top] != '(' && stack[top] != '#')
                postfix[j++] = pop();

            if (stack[top] == '(')
                ele = pop();
        }
        else
        {
            while (stack[top] != '#' &&
                   stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                   (precedence(stack[top]) == precedence(ch) &&
                    ch != '^')))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    while (stack[top] != '#')
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("The postfix expression: %s\n", postfix);

    return 0;
}
