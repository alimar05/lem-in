/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:31:03 by rymuller          #+#    #+#             */
/*   Updated: 2019/07/13 13:33:38 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_lst		*ft_new_lst(t_node *node)
{
	t_lst			*lst;

	if (!(lst = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	lst->node.name_hash = node->name_hash;
	lst->node.x = node->x;
	lst->node.y = node->y;
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

t_lst			*ft_lst_push_back(t_lst *lst, t_node *node)
{
	t_lst			*buffer;

	if (lst)
	{
		buffer = lst;
		while (buffer->next)
			buffer = buffer->next;
		if (!(buffer->next = ft_new_lst(node)))
		{
			free_lst(&lst);
			exit(EXIT_FAILURE);
		}
		return (lst);
	}
	else
	{
		if (!(buffer = ft_new_lst(node)))
			exit(EXIT_FAILURE);
		return (buffer);
	}
}

t_adjlst		*ft_adjlst_push_back(t_adjlst *adjlst, t_node *node)
{
	t_adjlst		*buffer;

	if (adjlst)
	{
		buffer = adjlst;
		while (buffer->next)
			buffer = buffer->next;
		if (!(buffer->next = ft_new_adjlst(node)))
		{
			// TO DO free_lst and free_adjlst
			exit(EXIT_FAILURE);
		}
		return (adjlst);
	}
	else
	{
		if (!(buffer = ft_new_adjlst(node)))
			exit(EXIT_FAILURE);
		return (buffer);
	}
}
