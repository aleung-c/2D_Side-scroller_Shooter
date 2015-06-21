/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ennemy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:31:58 by ajulien           #+#    #+#             */
/*   Updated: 2015/06/21 18:05:49 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

Ennemy::Ennemy( void ) : AEntity(10, 20, 'X')
{
	setvecX(-1);
	this->type = "Ennemy";
	this->display = 'X';
	this->setPosX(MAX_X - 1);
	return;
}

Ennemy::Ennemy( int x, int y, char c ) : AEntity(x, y, c){
	type = "Ennemy";
	setvecX(-1);
	t_en_obj	*n = new t_en_obj;
	t_en_obj	*tmp;
	n->obj = this;
	n->next = NULL;
	if (Game::ennemy_list == NULL)
	{
		Game::ennemy_list = n;
		Game::ennemy_list_last = n;
		n->prev = NULL;
	}
	else
	{
		Game::ennemy_list_last->next = n;
		tmp = Game::ennemy_list_last;
		Game::ennemy_list_last = n;
		n->prev = tmp;
	}
	_n = n;
	return;
}

Ennemy::Ennemy( Ennemy const &src ) : AEntity(src) {
	return ;
}

Ennemy::~Ennemy( void ) {
	return ;
}

void	Ennemy::die( void ) {
	if (Game::ennemy_list == _n)
	{
		Game::ennemy_list = _n->next;
	}
		if (Game::ennemy_list_last == _n)
	{
		Game::ennemy_list_last = _n->prev;
	}
	if (_n->next)
		_n->next->prev = _n->prev;
	if (_n->prev)
		_n->prev->next = _n->next;
	Game::score += 1;
	return ;
}

Ennemy & Ennemy::operator=( Ennemy const &rhs ) {
	posX = rhs.posX;
	posY = rhs.posY;
	display = rhs.display;
	return (*this);
}

// functions //
void	Ennemy::shoot( void ) {
	int i;

	i = rand() % 40;
	if (i == 1)
	{
		Eprojectile *p = new Eprojectile(getPosX() - 1, getPosY(), '~');
		if (p)
		{}
	}
}

// accessors //
