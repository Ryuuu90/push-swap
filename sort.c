#include "push_swap.h"

int cmp(int a, int b)
{
    return(b - a);
}

void    sort_three(t_stack *stacks)
{
    t_link *a;
    t_link *a1;
    t_link *a2;

    a = stacks->a;
    a1 = stacks->a->next;
    a2 = stacks->a->next->next;
    if(a->num < a1->num && a->num < a2->num && a1->num > a2->num)
    {
        rra(stacks);
        sa(stacks);
    }
    if(a->num > a1->num && a->num > a2->num && a1->num < a2->num)
        ra(stacks);
    if(a->num > a1->num && a->num > a2->num && a1->num > a2->num)
    {
        ra(stacks);
        sa(stacks);
    }
    if(a->num > a1->num && a->num < a2->num)
        sa(stacks);
    if(a->num < a1->num && a->num > a2->num)
        rra(stacks);   
}
// void    sort_four(t_stack *stacks, int size)
// {
//     int mini = min(stacks);
//     while(stacks->a->num != mini && stacks->count <= (size / 2))
//         ra(stacks);
//     while(stacks->a->num != mini && stacks->count > (size / 2))
//         rra(stacks);
//     if(stacks->a->num == mini)
//         pb(stacks);
//     sort_three(stacks);
//     pa(stacks);
// }
// void    sort_five(t_stack *stacks, int size)
// {
//     int mini = min(stacks);
//     while(stacks->a->num != mini && stacks->count <= (size / 2))
//         ra(stacks);
//     while(stacks->a->num != mini && stacks->count > (size / 2))
//         rra(stacks);
//     if(stacks->a->num == mini)
//         pb(stacks);
//     mini = min(stacks);
//     while(stacks->a->num != mini && stacks->count <= (size / 2))
//         ra(stacks);
//     while(stacks->a->num != mini && stacks->count > (size / 2))
//         rra(stacks);
//     if(stacks->a->num == mini)
//         pb(stacks);
//     sort_three(stacks);
//     pa(stacks);
//     pa(stacks);
// }

void    sort_four_five(t_stack *stacks, int size)
{
    t_sort utils;

    utils.loop = cmp(4 , size);
    stacks->inc = 0;
    utils.i = 0;
    utils.j = 0;
    while(utils.i <= utils.loop)
    {
        utils.mini = min(stacks);
        while(stacks->a->num != utils.mini && stacks->pos_min <= ft_lstsizep(stacks->a) / 2)
            ra(stacks);
        while(stacks->a->num != utils.mini && stacks->pos_min > ft_lstsizep(stacks->a) / 2)
            rra(stacks);
        if(stacks->a->num == utils.mini)
            pb(stacks);
        sort_three(stacks);
        utils.i++;
    }
    while(utils.j < utils.i)
    {
            pa(stacks);
            utils.j++;
    }

}
int    check_if(t_stack *stacks, int start, int end, t_parce data)
{
    t_link *a;

    a = stacks->a;
    stacks->pos_chunk = 0;
    while(a->next)
    {
        stacks->pos_chunk++;
        if(a->num >= data.arr[start] && a->num <= data.arr[end])
            return(1);
        a = a->next;
    }
    return(0);
}
void    sort_bigger(t_stack *stacks, t_parce *data)
{
    t_sort utils;
    int i = 0;
    int flag = 0;

    utils.div = 5;
    if(utils.div == 0)
        utils.div = 1;
    utils.mid = (data->size / 2) - 1;
    utils.offset = data->size / utils.div;

    if(utils.offset == 0)
    {
        utils.offset = 1;
    }
    utils.start = utils.mid - utils.offset;
    utils.end = utils.mid + utils.offset;
    stacks->b = NULL;

    quick_sort(data);
    while(stacks->a)
    {
        if(check_if(stacks, utils.start, utils.end, *data) == 0)
        {
            utils.start -= utils.offset;
            utils.end += utils.offset;
            if(utils.start < 0)
                utils.start = 0;
            if(utils.end >= data->size)
                utils.end = data->size - 1;
        }
        while(!(stacks->a->num >= data->arr[utils.start] && stacks->a->num <= data->arr[utils.end])&& stacks->pos_chunk <= ft_lstsizep(stacks->a) / 2)
            ra(stacks);
        while(!(stacks->a->num >= data->arr[utils.start] && stacks->a->num <= data->arr[utils.end])&& stacks->pos_chunk > ft_lstsizep(stacks->a) / 2)
            rra(stacks);
        if(stacks->a->num >= data->arr[utils.start] && stacks->a->num <= data->arr[utils.end])
            pb(stacks);
        if(stacks->b->num < data->arr[utils.mid] && stacks->b->next)
            rb(stacks);
        if(ft_lstsizep(stacks->a) == 1)
            pb(stacks);
    }
    while(stacks->b)
    {
        flag = 0;
        max_b(stacks);
        while(stacks->b->num != data->arr[data->size - 1] && stacks->pos_max < ft_lstsizep(stacks->b) / 2)
        {
            if(stacks->b->num == data->arr[data->size - 2])
            {
                pa(stacks);
                flag = 1;
            }
            else
                rb(stacks);
        }
        while(stacks->b->num != data->arr[data->size - 1] && stacks->pos_max >= ft_lstsizep(stacks->b) / 2)
        {
            if(stacks->b->num == data->arr[data->size - 2])
            {
                pa(stacks);
                flag = 1;
            }
            else
                rrb(stacks);
        }
        if(stacks->b->num == data->arr[data->size - 1])
        {
            if(flag == 1)
            {
                pa(stacks);
                sa(stacks);
                data->size -= 2;
            }
            else
            {
                pa(stacks);
                data->size--;
            }
        }
    }
    // printf("start == %d && end == %d && mid == %d && div == %d && off == %d && posc == %d\n", data->arr[utils.start], data->arr[utils.end], data->arr[utils.mid], utils.div, utils.offset, stacks->pos_chunk);
    
}