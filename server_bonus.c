/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:40:07 by ngalzand          #+#    #+#             */
/*   Updated: 2022/12/08 15:09:47 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

void	aff(int sig, siginfo_t *siginfo, void *nothing)
{
	static int	bits = 0;
	static int	c = 0;

	(void)nothing;
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
		if (c == 0)
			kill(siginfo->si_pid, SIGUSR1);
		ft_printf("%c", c);
		c = 0;
		bits = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = aff;
	action.sa_flags = SA_SIGINFO;
	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	while (42)
	{
		pause();
	}
}
