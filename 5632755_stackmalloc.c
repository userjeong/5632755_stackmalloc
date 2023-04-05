#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_STACK_SIZE 10

typedef int element;

typedef struct {  //������ ����ü�� ����
    element* data; //data�� ������ ����
    int capacity; //���� ũ��
    int top;

}StackType;

void init_stack(StackType* s);
void push(StackType* s, element item);
int is_full(StackType* s);
element pop(StackType* s);
int is_empty(StackType* s);

int main(void)
{
    StackType s;
    init_stack(&s);

    srand(time(NULL));
    for (int i = 1; i <= 30; i++)
    {
        int rand_num = rand() % 100 + 1;

        if ((rand_num % 2) == 1)
        {
            push(&s, rand_num);
            printf("[ %d ] Push %d\n", i, rand_num);
        }
        else
        {

            printf("[ %d ] Pop %d\n", i, pop(&s));
        }


    }
    free(s.data);
    system("pause");
}

void init_stack(StackType* s) //���� �ʱ�ȭ �Լ�
{
    s->top = -1;
    s->capacity = 1;
    s->data = (element*)malloc(s->capacity * sizeof(element));
}

void push(StackType* s, element item)
{
    if (is_full(s))
    {
        s->capacity *= 2;
        s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
    }
    s->data[++(s->top)] = item; //s�� ����Ű�� ���� data���� index(top��)�� 1 ������Ų�� item�� ����ֱ�.
}

int is_full(StackType* s)
{
    return (s->top == (s->capacity - 1));
}

element pop(StackType* s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "Stack Empty!\n");
        return (s->top = -1);
    }
    else return s->data[(s->top)--];
}

int is_empty(StackType* s)
{
    return (s->top == -1);
}