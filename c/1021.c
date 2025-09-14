#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node* prev;
    struct node* next;
} node;

typedef struct deque
{
    int size;
    struct node* head;
    struct node* tail;
} deque;

bool is_deque_empty(deque* target)
{
    return target->size == 0;
}

void push_left(deque* target, int value)
{
    node* new_node = (node*) malloc(sizeof(node));

    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->value = value;
    if (is_deque_empty(target))
    {
        target->tail = new_node;
    }
    else
    {
        target->head->prev = new_node;
        new_node->next = target->head;
    }
    target->head = new_node;
    target->size++;
}

void push_right(deque* target, int value)
{
    node* new_node = (node*) malloc(sizeof(node));

    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->value = value;
    if (is_deque_empty(target))
    {
        target->head = new_node;
    }
    else
    {
        target->tail->next = new_node;
        new_node->prev = target->tail;
    }
    target->tail = new_node;
    target->size++;
}

int pop_left(deque* target)
{
    if (is_deque_empty(target))
    {
        return -1;
    }

    node* temp = target->head;
    int result = temp->value;

    target->head = target->head->next;

    if (target->size == 1)
    {
        target->tail = NULL;
    }
    else
    {
        target->head->prev = NULL;
    }

    target->size--;
    free(temp);
    return result;
}

int pop_right(deque* target)
{
    if (is_deque_empty(target))
    {
        return -1;
    }

    node* temp = target->tail;
    int result = temp->value;

    target->tail = target->tail->prev;

    if (target->size == 1)
    {
        target->head = NULL;
    }
    else
    {
        target->tail->next = NULL;
    }

    target->size--;
    free(temp);
    return result;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    deque deq = {};

    int count = 0;
    int count_left = 0;

    int result = 0;

    for (int i = 1; i <= n; i++)
    {
        push_left(&deq, i);
    }

    for (int i = 1; i <= m; i++)
    {
        int location;
        scanf("%d", &location);

        while (1)
        {
            int temp = pop_right(&deq);

            push_left(&deq, temp);

            if (temp == location)
            {
                break;
            }
            count++;
        }

        for (int j = 0; j < count; j++)
        {
            int temp = pop_left(&deq);
            push_right(&deq, temp);
        }

        while (1)
        {
            int temp_left = pop_left(&deq);

            push_right(&deq, temp_left);

            if (temp_left == location)
            {
                break;
            }
            count_left++;
        }

        for (int j = 0; j < count_left; j++)
        {
            int temp = pop_right(&deq);
            push_left(&deq, temp);
        }

        if (count > count_left)
        {
            result += count_left;
            while (1)
            {
                int temp_left = pop_left(&deq);

                if (temp_left == location)
                {
                    break;
                }
                push_right(&deq, temp_left);

            }
        }
        else
        {
            result += count;
            while (1)
            {
                int temp = pop_right(&deq);

                if (temp == location)
                {
                    break;
                }
                push_left(&deq, temp);
            }
        }
        count = 0;
        count_left = 0;
    }
    printf("%d", result);

    return 0;
}