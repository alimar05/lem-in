#include "lem_in.h"

static void			free_stack(t_lemin *lemin)
{
	t_lst			*victim;
	t_lst			*buffer;

	if (lemin->stack)
	{
		buffer = lemin->stack;
		while (buffer)
		{
			victim = buffer;
			buffer = victim->next;
			free(victim);
		}
		lemin->stack = NULL;
	}
}

void				ft_push_stack(t_lemin *lemin, t_adjlst *adjlst)
{
	t_lst			*buffer;

	if (lemin->stack)
	{
		if (!(buffer = ft_new_lst(adjlst)))
		{
			free_stack(lemin);
			free_graph(lemin);
			exit(EXIT_FAILURE);
		}
		buffer->next = lemin->stack;
		lemin->stack = buffer;
	}
	else
	{
		if (!(buffer = ft_new_lst(adjlst)))
		{
			free_graph(lemin);
			exit(EXIT_FAILURE);
		}
		lemin->stack = buffer;
	}
}

void				ft_pop_stack(t_lemin *lemin)
{
	t_lst			*buffer;

	if (lemin->stack)
	{
		buffer = lemin->stack;
		if (buffer->next)
			lemin->stack = buffer->next;
		else
			lemin->stack = NULL;
		free(buffer);
	}
}
