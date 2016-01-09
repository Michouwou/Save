/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 16:03:20 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/09 14:03:30 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#define INT_TYPE 1
#define POINTER_TYPE 2
#define CHAR_TYPE 3
#define NO_SPEC_TYPE 0
#define CORRECT_FLAG 1
#define NO_SPEC_FLAG 0

typedef struct	s_list
{
	struct s_list *next;
	int location;
} t_list;

void	ft_putnbr(int num);
char	*ft_base(intmax_t num, int base);
