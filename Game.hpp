/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:22:44 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/21 19:17:38 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

#include "ft_retro.hpp"

class Game
{
	public:
		Game( void );
		Game( Game const &src );
		~Game( void );
		Game & operator=( Game const &rhs );

		// Game Class functions //
		void init( void ); // init ncurse screen
		void write_borders( void ); // affiche une bordure initiale;
		void g_place( void );//, Ennemy & ennemies = NULL);
		void g_refresh( void );
		void g_check_getch(); 	// check player touch et modifie les valeurs si touche pressed.
		void GameEvents(); // Les events de jeu;
		void check_PlayerEvents( void );
		void check_EnnemyEvents(t_en_obj * ennemy);
		void check_ProjectileEvents(AEntity * ennemy);
		void	spawn(); // ennemy spawn
		void	spawn_background(); // spawn decors;
		void	takeDamage();
		// accessors //

			int get_scr_x( void ) const;
			int get_scr_y( void ) const;
			int get_init_scr_x( void ) const;
			int get_init_scr_y( void ) const;
			int get_scroll( void ) const;
			int get_nb_life( void ) const;
			int get_shoot_delay( void ) const;

			void set_scr_x( int var );
			void set_scr_y( int var );
			void set_init_scr_x( int var );
			void set_init_scr_y( int var );
			void set_scroll( int var );
			void set_nb_life( int var );

			static int			score;
			static t_pro_obj *	projec_list;
			static t_pro_obj *	projec_list_last;
			static int shoot_delay;
			static	Player * p1 ;

			static t_epro_obj *	eprojec_list;
			static t_epro_obj *	eprojec_list_last;

			static t_en_obj *	ennemy_list;
			static t_en_obj *	ennemy_list_last;

			static t_bg_obj *	background_list;
			static t_bg_obj *	background_list_last;
	private:


		// game screen;
		int		_scr_x; // size x;
		int		_scr_y; // size y;
		int		_init_scr_x; // size shell initiale x;
		int		_init_scr_y; // size shell initiale y;
		std::stringstream _display;

		int		_scroll; // valeur du scroll par tour. == 1 ?

		// game_var
		int		_nb_life;

};

#endif
