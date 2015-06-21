/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:43:58 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/21 19:18:11 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
# define AENTITY_HPP

#include "ft_retro.hpp"

class AEntity
{
	public:
		AEntity(int x, int y, char c);

		AEntity( void );
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
		std::string		getType( void ) const;
		void			setvecX( int var );
		void			setvecY( int var );
		virtual void	die() = 0;

	protected:
		// space var //
		int posX; // position
		int posY;
		virtual ~AEntity( void );
		AEntity( AEntity const &src );
		int vecX; // valeur de deplacement au refresh
		int vecY;

		std::string		type;
		// apparence //
		char display; // char qui sera affiché.
};

#endif
