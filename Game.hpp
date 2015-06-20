/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:22:44 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/20 17:25:58 by ajulien          ###   ########.fr       */
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
		// 	void check_getch( Player & player ); 	// check player touch et modifie les valeurs si touche pressed.
		// 	void display( Player & player, Ennemy & ennemies );	// prends les objets et les affiche,
		// 	// et reinitialise leurs vect de deplacement si besoin;
		// 	void check_events( Player & player, Ennemy & ennemies ); // check les events(projectile touche, collision, etc ...)
		// 	void add_scroll( Player & player, Ennemy & ennemies );// puis, applique le scroll sur tous les obj sauf player.
		void	spawn();
		// accessors //

			int get_scr_x( void ) const;
			int get_scr_y( void ) const;
			int get_scroll( void ) const;
			int get_nb_life( void ) const;
			int getScore();

			void set_scr_x( int var );
			void set_scr_y( int var );
			void set_scroll( int var );
			void set_nb_life( int var );
			void setScore( int s);

			static t_ent_obj * obj_list;
			static t_ent_obj * obj_list_last;

	private:


		// game screen
		int		_scr_x; // size x;
		int		_scr_y; // size y;
		std::stringstream _display;
		int	_score;

		int		_scroll; // valeur du scroll par tour. == 1 ?

		// game_var
		int		_nb_life;
};

#endif
