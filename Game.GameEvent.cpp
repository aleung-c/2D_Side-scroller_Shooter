/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.GameEvent.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:31:44 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/21 18:21:53 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

void Game::GameEvents() {
	t_en_obj *tmp_enn;
	t_pro_obj *tmp_proj;
	t_epro_obj *tmp_eproj;

	tmp_enn = Game::ennemy_list;
	tmp_proj = Game::projec_list;
	tmp_eproj = Game::eprojec_list;
	while (tmp_proj)
	{
		if (tmp_proj->obj->getPosX() == MAX_X - 1)
		{
			mvaddch(tmp_proj->obj->getPosY(), tmp_proj->obj->getPosX(), ' ' | COLOR_PAIR(1));
			tmp_proj->obj->die();
			delete tmp_proj->obj;
			delete tmp_proj;
		}
		tmp_proj = tmp_proj->next;
	}

	while (tmp_eproj)
	{
		if (tmp_eproj->obj->getPosX() == MIN_X)
		{
			mvaddch(tmp_eproj->obj->getPosY(), tmp_eproj->obj->getPosX(), ' ' | COLOR_PAIR(1));
			tmp_eproj->obj->die();
			delete tmp_eproj->obj;
			delete tmp_eproj;
		}
		tmp_eproj = tmp_eproj->next;
	}

	while (tmp_enn)
	{
		check_EnnemyEvents(tmp_enn);
		tmp_enn = tmp_enn->next;
	}
	check_PlayerEvents();
}

void Game::check_PlayerEvents( void ) {
	t_en_obj *tmp_enn;
	t_epro_obj *tmp_eproj;

	tmp_enn = Game::ennemy_list;
	tmp_eproj = Game::eprojec_list;

	while (tmp_enn)
	{
		// collision player - ennemy.
		if (Game::p1->getPosX() == tmp_enn->obj->getPosX()
			&& Game::p1->getPosY() == tmp_enn->obj->getPosY())
		{
			takeDamage();
			tmp_enn->obj->die();
			delete tmp_enn->obj;
		}
		tmp_enn = tmp_enn->next;
	}
	while (tmp_eproj)
	{
		// collision player - eprojec.
			if ((Game::p1->getPosX() == tmp_eproj->obj->getPosX() || Game::p1->getPosX() == tmp_eproj->obj->getPosX() + 1)
				&& Game::p1->getPosY() == tmp_eproj->obj->getPosY())
				{
					takeDamage();
					tmp_eproj->obj->die();
					delete tmp_eproj->obj;
				}
		tmp_eproj = tmp_eproj->next;
	}
}

void Game::check_EnnemyEvents(t_en_obj * ennemy) {
	t_pro_obj *tmp_proj;

	if (ennemy->obj->getPosX() == MIN_X + 1)
	{
		mvaddch(ennemy->obj->getPosY(), ennemy->obj->getPosX(), ' ' | COLOR_PAIR(1));
		ennemy->obj->die();
		delete ennemy->obj;
		delete ennemy;
		return ;
	}
	tmp_proj = Game::projec_list;
	// check collision project - ennemy;
	while (tmp_proj)
	{
		if ((ennemy->obj->getPosX() == tmp_proj->obj->getPosX() ||
			ennemy->obj->getPosX() == (tmp_proj->obj->getPosX() - 1)
			|| ennemy->obj->getPosX() == (tmp_proj->obj->getPosX() - 2)
			|| ennemy->obj->getPosX() == (tmp_proj->obj->getPosX() - 3))
			&&  ennemy->obj->getPosY() == tmp_proj->obj->getPosY())
		{
			// sleep(1);
			mvaddch(ennemy->obj->getPosY(), ennemy->obj->getPosX(), ' ' | COLOR_PAIR(1));
			ennemy->obj->die();
			mvaddch(tmp_proj->obj->getPosY(), tmp_proj->obj->getPosX(), ' ' | COLOR_PAIR(1));
			tmp_proj->obj->die();
			delete ennemy->obj;
			//delete ennemy;
			delete tmp_proj->obj;
			// delete tmp_proj;
			return ;
		}
		tmp_proj = tmp_proj->next;
	}
}
