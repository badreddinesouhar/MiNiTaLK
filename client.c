/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:06:16 by bsouhar           #+#    #+#             */
/*   Updated: 2023/02/23 16:26:16 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(600);
		bit++;
	}
}

void	send_char(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_message(pid, str[i]);
		i++;
	}
}

int	ft_check_valid_pid(char *str)
{
	size_t	i;
	size_t	j;
	int		pid;

	j = 0;
	pid = ft_atoi(str);
	i = ft_strlen(str);
	if (pid < 1)
	{
		ft_printf("%s\n", "unvalide PID");
		exit(1);
	}
	while (j < i)
	{
		if (!ft_isdigit(str[j]))
		{
			ft_printf("%s\n", "unvalide PID !int detected");
			exit(1);
		}
		j++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int		pid;
	size_t	i;
	int		check;

	if (argc != 3)
	{
		ft_printf("wrong format\n");
		return (1);
	}
	i = 0;
	ft_check_valid_pid(argv[1]);
	pid = ft_atoi(argv[1]);
	check = kill(pid, 0);
	if (check == -1)
	{
		ft_printf("%s\n", "unvalide PID process doesn't exist");
		exit(1);
	}
	send_char(pid, argv[2]);
	return (0);
}
