/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 06:35:24 by bsouhar           #+#    #+#             */
/*   Updated: 2023/03/06 20:10:07 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	back_to_zero(int *i, int *c)
{
	*i = 0;
	*c = 0;
}

void	handlesignal(int signum, siginfo_t *info, void *luck)
{
	static int	i;
	static int	c;
	static int	cpid;

	(void)luck;
	if (cpid != info->si_pid)
	{
		back_to_zero(&i, &c);
		cpid = info->si_pid;
	}
	if (signum == SIGUSR2)
		i++;
	else
	{
		c |= 1 << i;
		i++;
	}
	if (i == 8)
	{
		write(1, &c, 1);
		back_to_zero(&i, &c);
	}
}

int	main(void)
{
	struct sigaction	sam;
	int					pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	sam.sa_sigaction = handlesignal;
	sam.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sam, 0);
	sigaction(SIGUSR2, &sam, 0);
	while (1)
		;
}
