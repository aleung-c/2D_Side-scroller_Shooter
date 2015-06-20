/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:17:43 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/20 13:57:56 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

void ft_retro( void )
{
	Game		game;
	
	// Player		player(1, 20); // player class daughter of Entity
	// Ennemy		*ennemies; // Ennemy class daughter of Entity

	// Ennemy and player have Projectile subclass.

	game.init(); // start gamescreen et variables de jeu ( score, hp, etc etc );

	while (1)
	{
		//game.refresh(player, ennemies/*, items*/); // Prends le joueurs, les ennemies,
		// ce qui inclue leurs projectiles lancés, et les affiche sur le screen.



	}
}

int main( void )
{
		ft_retro();
	return (0);
}