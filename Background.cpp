/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 18:30:14 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/21 18:38:11 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

Background::Background( void ) : AEntity(10, 20, '*')
{
	setvecX(-1);
	this->type = "Background";
	this->display = '*';
	this->setPosX(MAX_X - 1);
	return;
}

Background::Background( int x, int y, char c ) : AEntity(x, y, c){
	type = "Background";
	setvecX(-1);
	t_bg_obj	*n = new t_bg_obj;
	t_bg_obj	*tmp;
	n->obj = this;
	n->next = NULL;
	if (Game::background_list == NULL)
	{
		Game::background_list = n;
		Game::background_list_last = n;
		n->prev = NULL;
	}
	else
	{
		Game::background_list_last->next = n;
		tmp = Game::background_list_last;
		Game::background_list_last = n;
		n->prev = tmp;
	}
	_n = n;
	return;
}

Background::Background( Background const &src ) : AEntity(src) {
	return ;
}

Background::~Background( void ) {
	return ;
}

void	Background::die( void ) {
	if (Game::background_list == _n)
	{
		Game::background_list = _n->next;
	}
		if (Game::background_list_last == _n)
	{
		Game::background_list_last = _n->prev;
	}
	if (_n->next)
		_n->next->prev = _n->prev;
	if (_n->prev)
		_n->prev->next = _n->next;
	Game::score += 1;
	return ;
}

Background & Background::operator=( Background const &rhs ) {
	posX = rhs.posX;
	posY = rhs.posY;
	display = rhs.display;
	return (*this);
}

// functions //
void	Background::shoot( void ) {
	return;
}

// accessors //
