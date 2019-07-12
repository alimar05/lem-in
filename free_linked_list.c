/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_linked_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:31:21 by rymuller          #+#    #+#             */
/*   Updated: 2019/07/13 12:31:59 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void			free_lst(t_lst **lst)
{
	t_lst				*victim;

	while (*lst)
	{
		victim = *lst;
		*lst = victim->next;
		free(victim);
	}
	*lst = NULL;
}

void			free_adjlst(t_adjlst **adjlst)
{
	t_adjlst			*victim;

	while (*adjlst)
	{
		victim = *adjlst;
		*adjlst = victim->next;
		free(victim);
	}
	*adjlst = NULL;
}
