#include "push_swap.h"
#include "push_swap_structs.h"

int	append(t_stack **head_ref, int new_data)
{
	t_stack *new_node = malloc(sizeof(t_stack));
    new_node->nb = new_data;
    new_node->next     = NULL;

    if(*head_ref == NULL)
         *head_ref = new_node;
    else
    {
        t_stack *last_node = *head_ref;
        while(last_node->next != NULL)
            last_node = last_node->next;
        last_node->next = new_node;
    }
    return (0);
}
