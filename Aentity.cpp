/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aentity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 12:46:15 by ajulien           #+#    #+#             */
/*   Updated: 2015/06/20 14:21:17 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

AEntity::AEntity(){
};

AEntity::AEntity(int x, int y, char c): display(c){
	if (setPosX(y) == false)
	{
		std::cout << "y " << y << " should be between : " << MAX_Y << std::endl;
		exit(-1);
	}
	if (setPosY(x) == false)
	{
		std::cout << "y " << y << " should be more than : " << MAX_Y << std::endl;
		exit(-1);
	}
	t_ent_obj	*n = new t_ent_obj;

	n->obj = this;
	n->next = NULL;

	if (Game::obj_list == NULL)
		Game::obj_list = n;
	else
	{
		Game::obj_list_last->next = n;
		Game::obj_list_last = n;
	}
}
AEntity::AEntity(AEntity const &src){
	*this = src;
};

AEntity &	AEntity::operator=(AEntity const & rhs){
	posX = rhs.posX;
	posY = rhs.posY;
	return (*this);
}

int			AEntity::getPosX(){
	return(this->posX);
}

int			AEntity::getPosY(){
	return(this->posY);
}

bool		AEntity::setPosX(int x)
{
	if (x > MAX_X){
		posX = MAX_X;
		return false;
	}
	if (x > MIN_X){
		posX = MIN_X;
		return false;
	}
	this->posX = x;
	return true;
}

bool		AEntity::setPosY(int y)
{
	if (y > MAX_Y){
		posY = MAX_Y;
		return false;
	}
	if (y > MIN_Y){
		posY = MIN_Y;
		return false;
	}
	this->posY = y;
	return true;
}

void		AEntity::move( int x, int y ){
	setPosY(y);
	setPosX(x);
}

AEntity::~AEntity(){};
