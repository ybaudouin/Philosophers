/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:44:34 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/17 17:13:36 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

int	main(int argc, char **argv)
{
	t_data		data;
	t_mutexes	mutexes;

	if (argc != 5 && argc != 6)
	{
		printf("Wrong amount of arguments\n");
		return (1);
	}
	if (check_num(argv))
	{
		print_error();
		return (1);
	}
	struct_init(&data, argv, &mutexes);
	init_mutex(&mutexes, data.number_philo);
	philo_init(&data, &mutexes);
	init_death(&data);
	clean_program(&mutexes, &data);
	return (0);
}
