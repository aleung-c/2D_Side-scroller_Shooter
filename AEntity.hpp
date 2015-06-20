/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:43:58 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/20 14:46:38 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
# define AENTITY_HPP

#include "ft_retro.hpp"

class AEntity
{
	public:
		AEntity(int x, int y, char c);
		AEntity( AEntity const &src );
		~AEntity( void );
		AEntity & operator=( AEntity const &rhs );

		void			move( int x, int y ); // modifie la val du vect de deplacement;
		virtual void	shoot( void ) = 0; // spawn un sous objet projectile
		int				getPosX();
		int				getPosY();
		bool			setPosX(int x);
		bool			setPosY(int y);
		char			getDisplay( void ) const;
		int				getvecX( void ) const;
		int				getvecY( void ) const;

		void			setvecX( int var );
		void			setvecY( int var );

	protected:
		AEntity( void );
		// space var //
		int posX; // position
		int posY;

		int vecX; // valeur de deplacement au refresh
		int vecY;

		// apparence //
		char display; // char qui sera affiché.
};

#endif
