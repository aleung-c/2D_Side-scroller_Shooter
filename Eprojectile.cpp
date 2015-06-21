/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Eprojectile.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 17:00:11 by ajulien           #+#    #+#             */
/*   Updated: 2015/06/21 17:13:49 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Eprojectile.hpp"

Eprojectile::Eprojectile( void ) : AEntity()
{
	return;
}

Eprojectile::Eprojectile( int x, int y, char c ) : AEntity(x, y, c){
	setvecX(-2);
	type = "Eprojectile";
	t_epro_obj	*n = new t_epro_obj;
	t_epro_obj	*tmp;
	n->obj = this;
	n->next = NULL;
	if (Game::eprojec_list == NULL)
	{
		Game::eprojec_list = n;
		Game::eprojec_list_last = n;
		n->prev = NULL;
	}
	else
	{
		Game::eprojec_list_last->next = n;
		tmp = Game::eprojec_list_last;
		Game::eprojec_list_last = n;
		n->prev = tmp;
	}
	_n = n;
	return;
}

Eprojectile::Eprojectile( Eprojectile const &src ) : AEntity(src) {
	return ;
}

Eprojectile::~Eprojectile( void ) {
	return ;
}

void	Eprojectile::die( void ) {
	// _n current;
	if (Game::eprojec_list == _n)
	{
		Game::eprojec_list = _n->next;
	}
	if (Game::eprojec_list_last == _n)
	{
		Game::eprojec_list_last = _n->prev;
	}
	if (_n->next)
		_n->next->prev = _n->prev;
	if (_n->prev)
		_n->prev->next = _n->next;

	return ;
}

Eprojectile & Eprojectile::operator=( Eprojectile const &rhs ) {
	posX = rhs.posX;
	posY = rhs.posY;
	display = rhs.display;
	return (*this);
}

// functions //
void	Eprojectile::shoot( void ) {
}
