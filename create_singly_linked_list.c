/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_singly_linked_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:11:28 by rymuller          #+#    #+#             */
/*   Updated: 2019/07/25 13:30:31 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_lst		*ft_new_lst(unsigned long int name_hash)
{
	t_lst			*lst;

	if (!(lst = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	lst->name_hash = name_hash;
	lst->next = NULL;
	return (lst);
}

static t_adjlst		*ft_new_adjlst(t_node *node)
{
	t_adjlst		*adjlst;

	if (!(adjlst = (t_adjlst *)malloc(sizeof(t_adjlst))))
		return (NULL);
	adjlst->node.name_hash = node->name_hash;
	adjlst->node.x = node->x;
	adjlst->node.y = node->y;
	adjlst->lst = NULL;
	adjlst->next = NULL;
	return (adjlst);
}

t_lst				*ft_lst_push_back(t_adjlst *adjlst,
		unsigned long int name_hash)
{
	t_lst			*buffer;

	if (adjlst->lst)
	{
		buffer = adjlst->lst;
		while (buffer->next)
			buffer = buffer->next;
		if (!(buffer->next = ft_new_lst(name_hash)))
		{
			free_lst(adjlst);
			exit(EXIT_FAILURE);
		}
		return (adjlst->lst);
	}
	else
	{
		if (!(buffer = ft_new_lst(name_hash)))
			exit(EXIT_FAILURE);
		return (buffer);
	}
}

t_adjlst			*ft_adjlst_push_back(t_lemin *lemin, t_node *node)
{
	t_adjlst		*buffer;

	if (lemin->adjlst)
	{
		buffer = lemin->adjlst;
		while (buffer->next)
			buffer = buffer->next;
		if (!(buffer->next = ft_new_adjlst(node)))
		{
			free_adjlst(lemin);
			exit(EXIT_FAILURE);
		}
		return (lemin->adjlst);
	}
	else
	{
		if (!(buffer = ft_new_adjlst(node)))
			exit(EXIT_FAILURE);
		return (buffer);
	}
}
