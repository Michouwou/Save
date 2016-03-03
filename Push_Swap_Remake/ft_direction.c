/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 17:08:02 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/03 17:22:13 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_direction(t_stack *alpha)
{
	t_stack *tmp;
	int     middle;
	int     cursor;

	middle = ft_stack_len(alpha);
	tmp = alpha;
	cursor = 0;
	while (cursor < middle)
	{
		if (tmp->previous->element > tmp->element &&
				tmp->next->element > tmp->element)
			return (1);
		tmp = tmp->next;
		cursor++;
	}
	return (0);
}
