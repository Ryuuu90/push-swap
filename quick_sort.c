#include "push_swap.h"

int    max_b(t_stack *stacks)
{
    t_link *a = stacks->b;
    int tmp = stacks->b->num;
    stacks->pos_max = 0;
    while(a)
    {
        if(tmp < a->num)
        {
            tmp = a->num;
        }
        a = a->next;
    }
     a = stacks->b;
    while(a->num != tmp)
    {
        stacks->pos_max++;
        a = a->next;
    }
    return(tmp);
}

int min(t_stack *stacks)
{
    t_link *a = stacks->a;
    int tmp = stacks->a->num;
    stacks->pos_min = 0;
    while(a)
    {
        if(tmp > a->num)
        {
            tmp = a->num;
        }
        a = a->next;
    }
    a = stacks->a;
    while(a->num != tmp)
    {
        stacks->pos_min++;
        a = a->next;
    }
    return(tmp);
}

int min_b(t_stack *stacks)
{
    t_link *a = stacks->b;
    int tmp = stacks->b->num;
    while(a)
    {
        if(tmp > a->num)
        {
            tmp = a->num;
        }
        a = a->next;
    }
    return(tmp);
}

int    bmax(t_stack *stacks)
{
    t_stack *l = stacks;
     t_link *a = stacks->b;
    int tmp = min_b(stacks);
    while(a)
    {
        if(a->num == max_b(l))
            a = a->next;
        if(tmp < a->num)
        {
            tmp = a->num;
        }
        a = a->next;
    }
    return(tmp);
}

void    quick_sort(t_parce *data)
{
    int i = 0;
    int j = 0;
    int tmp = 0;
   while(i < data->size)
   {
        j = i+1;
        while(j < data->size)
        {
            if(data->arr[i] > data->arr[j])
            {
                tmp = data->arr[i];
                data->arr[i] = data->arr[j];
                data->arr[j] = tmp;
            }
            j++;
        }
        i++;
   }
}

