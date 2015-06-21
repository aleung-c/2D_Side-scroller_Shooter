/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aentity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 12:46:15 by ajulien           #+#    #+#             */
/*   Updated: 2015/06/21 13:59:06 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

AEntity::AEntity(){
}

AEntity::AEntity(int x, int y, char c): type("AEnt"), display(c){
	if (setPosY(y) == false)
	{
		std::cout << "y " << y << " should be between : " << MIN_Y << " and " << MAX_Y << std::endl;
		exit(-1);
	}
	if (setPosX(x) == false)
	{
		std::cout << "x " << x << " should be between : " << MIN_X << " and " << MAX_X << std::endl;
		exit(-1);
	}
	vecX = 0;
	vecY = 0;
}

AEntity::AEntity(AEntity const &src){
	*this = src;
}

AEntity::~AEntity( void ){
	return ;
}

AEntity &	AEntity::operator=(AEntity const & rhs){
	posX = rhs.posX;
	posY = rhs.posY;
	return (*this);
}

// void		AEntity::die(){

// 	_n->prev->next = _n->next;
// 	if (_n->prev->next)
// 		_n->next->prev = _n->prev;
// 	// delete this;
// }

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
	if (x < MIN_X){
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
	if (y < MIN_Y){
		posY = MIN_Y;
		return false;
	}
	this->posY = y;
	return true;
}

char AEntity::getDisplay( void ) const {
	return (this->display);
}

int AEntity::getvecX( void ) const {
	return (this->vecX);
}

int AEntity::getvecY( void ) const {
	return (this->vecY);
}

std::string		AEntity::getType(void ) const {
	return(type);
}

void AEntity::setvecX( int var ) {
	this->vecX = var;
}

void AEntity::setvecY( int var ) {
	this->vecY = var;
}

void		AEntity::move( int x, int y ){
	setPosY(y);
	setPosX(x);
}


