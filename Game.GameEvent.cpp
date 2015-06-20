/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.GameEvent.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:31:44 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/20 19:40:07 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

void Game::GameEvents() {
	t_ent_obj *tmp;

	tmp = Game::obj_list;
	while (tmp)
	{
		if (tmp->obj->getType() == "Player")
			check_PlayerEvents(tmp->obj);
		if (tmp->obj->getType() == "Ennemy")
			check_EnnemyEvents(tmp->obj);
		tmp = tmp->next;
	}
}

void Game::check_PlayerEvents(AEntity *player) {
	t_ent_obj *tmp;

	tmp = Game::obj_list;
	while (tmp)
	{
		// collision player - objet.
		if (tmp->obj->getType() != "Player")
		{

			if (player->getPosX() == tmp->obj->getPosX()
				&& player->getPosY() == tmp->obj->getPosY())
			{
				sleep(5);
				// call die player.
				std::cout << "Collision !" << std::endl;
			}
		}
		tmp = tmp->next;
	}
}

void Game::check_EnnemyEvents(AEntity *ennemy) {
	t_ent_obj *tmp;

	tmp = Game::obj_list;
	while (tmp)
	{
		// collision player - objet.
		if (tmp->obj->getType() != "Player")
		{

			if (player->getPosX() == tmp->obj->getPosX()
				&& player->getPosY() == tmp->obj->getPosY())
			{
				sleep(5);
				// call die player.
				std::cout << "Collision !" << std::endl;
			}
		}
		tmp = tmp->next;
	}
}
