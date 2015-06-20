/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:07:54 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/20 17:20:07 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"


// init and canon ft //
Game::Game( void ) : _scr_x(140), _scr_y(36), _scroll(1), _nb_life(3), _score(0) {
	std::cout << "Game created." << std::endl;
	std::srand(time(0));
}

Game::Game( Game const &src ) {
	*this = src;
}

Game::~Game( void ) {
	std::cout << "End of Game." << std::endl;
}

Game & Game::operator=( Game const &rhs ) {
	this->set_scr_x(rhs.get_scr_x());
	this->set_scr_y(rhs.get_scr_y());
	this->set_nb_life(rhs.get_nb_life());
	return (*this);
}

// Content Related Fonction //
void	Game::spawn(){
	int	i = 2;

	while (i > 0)
	{
		Ennemy		ennemy(MAX_X, rand() % MAX_Y, 'X');
		i--;
	}
}

// Game class functions //

t_ent_obj * Game::obj_list = NULL;
t_ent_obj * Game::obj_list_last  = Game::obj_list;

void Game::init( void ) {
	int r_scrx; // real values of the screen; user inputed;
	int r_scry;

	initscr();
	getmaxyx(stdscr, r_scry, r_scrx );
	if ( r_scrx < this->_scr_x || r_scry < this->_scr_y )
	{
		std::cout << r_scrx << std::endl;
		std::cout << "Screen too small to launch game"
				<< "(actual size = " << r_scrx << "x " << r_scry << "y )"
				<< std::endl
				<< "Required size = " << this->_scr_x << "x " << this->_scr_y << "y."
				<< std::endl;
		exit(-1);
	}
	this->write_borders(); // Affiche une bordure !
	refresh();
}

void Game::write_borders( void ) {
	int c_x = 0;
	int c_y = 0;
	std::string str_display;

	while (c_y < this->get_scr_y())
	{
		while (c_x < this->get_scr_x())
		{
			if (c_y == 0 || c_y == (this->get_scr_y() - 1) || (c_y == 4 && (c_x != 0 && c_x != get_scr_x() - 1)))
				this->_display << "-";
			else if (c_x == 0 || c_x == (this->get_scr_x() - 1))
				this->_display << "|";
			else
				this->_display << " ";
			c_x++;
		}
		if (c_x == this->get_scr_x())
			this->_display << "\n";
		c_y++;
		c_x = 0;
	}
	str_display = this->_display.str();
	printw(str_display.c_str());
}

void Game::g_refresh( Player & player)
{
	int r_scry;
	int r_scrx;

	getmaxyx(stdscr, r_scry, r_scrx );
	std::string str_display;
	str_display = this->_display.str();
	str_display[player.getPosY() * r_scrx + player.getPosX()] = player.getDisplay();
	printw(str_display.c_str());
}

// accessors //

int Game::get_scr_x( void ) const {
	return (this->_scr_x);
}

int Game::get_scr_y( void ) const {
	return (this->_scr_y);
}

int Game::get_scroll( void ) const {
	return (this->_scroll);
}

int Game::get_nb_life( void ) const {
	return (this->_nb_life);
}

int Game::getScore(void){
	return _score;
}

void Game::setScore(int i){
	_score += i;
}

void Game::set_scr_x( int var ) {
	this->_scr_x = var;
}

void Game::set_scr_y( int var ) {
	this->_scr_y = var;
}

void Game::set_scroll( int var ) {
	this->_scroll = var;
}

void Game::set_nb_life( int var ) {
	this->_nb_life = var;
}
