/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:17:43 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/21 19:06:47 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

void ft_retro( void )
{
	Game		game;

	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	int		i=0;


	game.init(); // start gamescreen et variables de jeu ( score, hp, etc etc );
	// game.g_place(); // place player et game info
	while (1)
	{
			usleep(100);
			i++;
			game.spawn_background();
			game.g_check_getch();
			game.g_place(); // place player and score;
			if (i == 300 || i == 900 || i == 600)
			{
				game.g_refresh();
				game.GameEvents();
			}
			game.spawn();
			if (i == 1000)
			{
				Game::score += 1;
				Game::shoot_delay = 0;
				i =0;
			}
			refresh();
	}
	endwin();
}

int main( void )
{
	ft_retro();
	return (0);
}
