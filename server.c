/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:40:07 by ngalzand          #+#    #+#             */
/*   Updated: 2022/12/08 11:40:10 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

void	aff(int sig)
{
	static int	bits = 0;
	static int	c = 0;

	if (bits < 8)
	{
		if (sig == SIGUSR1)
			c += 1 << bits;
		else if (sig == SIGUSR2)
			c += 0 << bits;
		bits++;
	}
	if (bits == 8)
	{
		ft_printf("%c", c);
		c = 0;
		bits = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	while (42)
	{
		signal(SIGUSR1, &aff);
		signal(SIGUSR2, &aff);
		pause();
	}
}
