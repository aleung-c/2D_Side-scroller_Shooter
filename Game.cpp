/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:07:54 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/21 18:16:49 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

int Game::shoot_delay = 1;
Player * Game::p1 = new Player(10, 20, 'o');

// init and canon ft //
int Game::score = 0;

Game::Game( void ) : _scr_x(140), _scr_y(36), _scroll(1), _nb_life(5){
	std::cout << "Game created." << std::endl;
	getmaxyx(stdscr, this->_init_scr_y, this->_init_scr_x);
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
void	Game::spawn() {
	int i;
	char t[3];
	int j;

	t[0] = '<';
	t[1] = 'K';
	t[2] = 'O';
	i = rand() % 200000;
	j = rand() % 3;
	if (i < score)
	{
		Ennemy *	ennemy = new Ennemy(MAX_X - 1, 10, t[j]);
		ennemy->setPosY(rand() % MAX_Y);
		if (ennemy)
			return;
	}
}

// Game class functions //

t_en_obj * Game::ennemy_list = NULL;
t_en_obj * Game::ennemy_list_last  = Game::ennemy_list;

t_pro_obj * Game::projec_list = NULL;
t_pro_obj * Game::projec_list_last  = Game::projec_list;

t_epro_obj * Game::eprojec_list = NULL;
t_epro_obj * Game::eprojec_list_last  = Game::eprojec_list;

void Game::init( void ) {
	int r_scrx; // real values of the screen; user inputed;
	int r_scry;

	initscr();
	noecho();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_CYAN);
	init_pair(2, COLOR_BLUE, COLOR_CYAN);
	init_pair(3, COLOR_RED, COLOR_CYAN);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	nodelay(stdscr, true);
	getmaxyx(stdscr, r_scry, r_scrx );
/*	if ( r_scrx < this->_scr_x || r_scry < this->_scr_y )
	{
		std::cout << r_scrx << std::endl;
		std::cout << "Screen too small to launch game"
				<< "(actual size = " << r_scrx << "x " << r_scry << "y )"
				<< std::endl
				<< "Required size = " << this->_scr_x << "x " << this->_scr_y << "y."
				<< std::endl;
		exit(-1);
	}*/
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
				this->_display << " ";
			else if (c_x == 0 || c_x == (this->get_scr_x() - 1))
				this->_display << " ";
			else if (c_y > 4)
				mvaddch(c_y, c_x, ' ' | COLOR_PAIR(1));
			else
				mvaddch(c_y, c_x, ' ');
				//this->_display << " ";
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

void Game::g_place( void )
{
	mvaddch(Game::p1->getPosY() - 1, Game::p1->getPosX(), ACS_TTEE | COLOR_PAIR(1));
	mvaddch(Game::p1->getPosY(), Game::p1->getPosX(), 'o' | COLOR_PAIR(1));
	mvaddch(Game::p1->getPosY(), Game::p1->getPosX() - 1, ' ' | COLOR_PAIR(1));
	mvaddch(Game::p1->getPosY(), Game::p1->getPosX() - 2, '=' | COLOR_PAIR(1));
	mvaddch(Game::p1->getPosY(), Game::p1->getPosX() + 1, ' ' | COLOR_PAIR(1));
	mvaddch(Game::p1->getPosY(), Game::p1->getPosX() + 2, '>' | COLOR_PAIR(1));
	mvaddch(Game::p1->getPosY() + 1, Game::p1->getPosX(), ACS_BTEE | COLOR_PAIR(1));

	// display game Info
	mvaddstr(2, 4, "Score");// | COLOR_PAIR(1));
	char const * str_score = std::to_string(score).c_str();
	mvaddstr(2, 11, str_score);
	mvaddstr(2, 20, "HP");// | COLOR_PAIR(1));
	// char const * str_life = std::to_string(_nb_life).c_str();
	if (_nb_life >= 5)
		mvaddch(2, 30, '|' | COLOR_PAIR(4));
	else
		mvaddch(2, 30, ' ' | COLOR_PAIR(4));
	if (_nb_life >= 4)
		mvaddch(2, 29, '|' | COLOR_PAIR(4));
	else
		mvaddch(2, 29, ' ' | COLOR_PAIR(4));
	if (_nb_life >= 3)
		mvaddch(2, 28, '|' | COLOR_PAIR(4));
	else
		mvaddch(2, 28, ' ' | COLOR_PAIR(4));
	if (_nb_life >= 2)
		mvaddch(2, 27, '|' | COLOR_PAIR(5));
	else
		mvaddch(2, 27, ' ' | COLOR_PAIR(5));
	if (_nb_life >= 1)
		mvaddch(2, 26, '|' | COLOR_PAIR(6));
	else
		mvaddch(2, 26, ' ' | COLOR_PAIR(6));
	// mvaddstr(2, 24, str_life);
}

void Game::g_refresh( void ) { // refresh ennemies et projectiles
	t_en_obj *tmp_ennemies;
	t_pro_obj *tmp_projec;
	t_epro_obj *tmp_eprojec;

	tmp_ennemies = Game::ennemy_list;
	tmp_projec = Game::projec_list;
	tmp_eprojec = Game::eprojec_list;
	while (tmp_ennemies)
	{
		mvaddch(tmp_ennemies->obj->getPosY(), tmp_ennemies->obj->getPosX(), ' ' | COLOR_PAIR(1));
		tmp_ennemies->obj->setPosX(tmp_ennemies->obj->getPosX() + tmp_ennemies->obj->getvecX());
		tmp_ennemies->obj->setPosY(tmp_ennemies->obj->getPosY() + tmp_ennemies->obj->getvecY());
		mvaddch(tmp_ennemies->obj->getPosY(), tmp_ennemies->obj->getPosX(), tmp_ennemies->obj->getDisplay() | COLOR_PAIR(1));
		tmp_ennemies->obj->shoot();
		tmp_ennemies = tmp_ennemies->next;
	}
	while (tmp_projec)
	{
		mvaddch(tmp_projec->obj->getPosY(), tmp_projec->obj->getPosX(), ' ' | COLOR_PAIR(1));
		tmp_projec->obj->setPosX(tmp_projec->obj->getPosX() + tmp_projec->obj->getvecX());
		tmp_projec->obj->setPosY(tmp_projec->obj->getPosY() + tmp_projec->obj->getvecY());
		mvaddch(tmp_projec->obj->getPosY(), tmp_projec->obj->getPosX(), tmp_projec->obj->getDisplay() | COLOR_PAIR(2));
		tmp_projec = tmp_projec->next;
	}
		while (tmp_eprojec)
	{
		mvaddch(tmp_eprojec->obj->getPosY(), tmp_eprojec->obj->getPosX(), ' ' | COLOR_PAIR(3));
		tmp_eprojec->obj->setPosX(tmp_eprojec->obj->getPosX() + tmp_eprojec->obj->getvecX());
		tmp_eprojec->obj->setPosY(tmp_eprojec->obj->getPosY() + tmp_eprojec->obj->getvecY());
		mvaddch(tmp_eprojec->obj->getPosY(), tmp_eprojec->obj->getPosX(), tmp_eprojec->obj->getDisplay() | COLOR_PAIR(3));
		tmp_eprojec = tmp_eprojec->next;
	}
}

void Game::g_check_getch( void ) {
	int key;

	key = getch();
	if (key == 65) // UP
	{
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX(), ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX() + 1, ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX() + 2, ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX() - 1, ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX() - 2, ' ' | COLOR_PAIR(1));	
		mvaddch(Game::p1->getPosY() + 1, Game::p1->getPosX(), ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY() - 1, Game::p1->getPosX(), ' ' | COLOR_PAIR(1));
		Game::p1->setPosY(Game::p1->getPosY() - 1 );
	}
	else if (key == 66) // DOWN
	{
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX(), ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX() + 1, ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX() + 2, ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX() - 1, ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX() - 2, ' ' | COLOR_PAIR(1));		
		mvaddch(Game::p1->getPosY() + 1, Game::p1->getPosX(), ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY() - 1, Game::p1->getPosX(), ' ' | COLOR_PAIR(1));
		Game::p1->setPosY(Game::p1->getPosY() + 1 );
	}
	else if (key == 67) // RIGHT
	{
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX(), ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX() + 1, ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX() + 2, ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX() - 1, ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX() - 2, ' ' | COLOR_PAIR(1));		
		mvaddch(Game::p1->getPosY() + 1, Game::p1->getPosX(), ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY() - 1, Game::p1->getPosX(), ' ' | COLOR_PAIR(1));
		Game::p1->setPosX(Game::p1->getPosX() + 1 );
	}
	else if (key == 68) // RIGHT
	{
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX(), ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX() + 1, ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX() + 2, ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX() - 1, ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY(), Game::p1->getPosX() - 2, ' ' | COLOR_PAIR(1));	
		mvaddch(Game::p1->getPosY() + 1, Game::p1->getPosX(), ' ' | COLOR_PAIR(1));
		mvaddch(Game::p1->getPosY() - 1, Game::p1->getPosX(), ' ' | COLOR_PAIR(1));
		Game::p1->setPosX(Game::p1->getPosX() - 1 );
	}
	else if (key == ' ') // space
	{
		// mvaddch(Game::p1->getPosY(), Game::p1->getPosX() + 1, '-');
		if (Game::shoot_delay == 0)
			Game::p1->shoot();
		Game::shoot_delay = 1;
		return ;
	}
	// std::cout << key << std::endl;
}
void	Game::takeDamage(){
	set_nb_life(_nb_life -1);
	if (get_nb_life() == 0)
	{
		clear();
		std::cout << " GAME OVER " << std::endl;
		sleep(5);
		exit(0);
	} 
}
// accessors //

int Game::get_scr_x( void ) const {
	return (this->_scr_x);
}

int Game::get_scr_y( void ) const {
	return (this->_scr_y);
}

int Game::get_init_scr_x( void ) const {
	return (this->_init_scr_x);
}

int Game::get_init_scr_y( void ) const {
	return (this->_init_scr_y);
}

int Game::get_scroll( void ) const {
	return (this->_scroll);
}

int Game::get_nb_life( void ) const {
	return (this->_nb_life);
}

void Game::set_scr_x( int var ) {
	this->_scr_x = var;
}

void Game::set_scr_y( int var ) {
	this->_scr_y = var;
}

void Game::set_init_scr_x( int var ) {
	this->_init_scr_x = var;
}

void Game::set_init_scr_y( int var ) {
	this->_init_scr_y = var;
}

void Game::set_scroll( int var ) {
	this->_scroll = var;
}

void Game::set_nb_life( int var ) {
	this->_nb_life = var;
}
