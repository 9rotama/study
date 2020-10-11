#include <stdio.h>
#include <stdlib.h>
#define STSIZE 50

void push(double);
double pop(void);

int dore, top = 0;
double data, stack[STSIZE]={0};

int main()
{
    while(1){

    printf("挿入:1, 取り出し:2, 表示:3, 終了:0>> ");
    scanf("%d", &dore);
    if (dore == 0) break;

    if (dore == 1)
    {
        scanf("%lf", &data);
        push(data);
    }
    else if (dore == 2)
    {
        printf("データ: %4.3f\n", pop());
    }
    else if (dore == 3)
    {
        for (int i = 0; i <= top-1; i++)
        {
            printf("%4.3f  ", stack[i]);
        }
        printf("\n");
    }
    }
    return 0;
}

void push(double data_)
{
    if (top == STSIZE)
    {

        printf("Stack overflow!\n");
        exit(2);
    }
    stack[top] = data_;
    top++;
}

double pop(void)
{
    if (top == 0)
    {
        printf("Stack is Empty!\n");
        exit(3);
    }
    top--;
    return stack[top];
}
