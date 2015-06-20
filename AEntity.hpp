/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:43:58 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/20 11:19:11 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
# define AENTITY_HPP

#include "ft_retro.hpp"

class AEntity
{
	public:
		AEntity( void );
		AEntity( AEntity const &src );
		~AEntity( void );
		AEntity & operator=( AEntity const &rhs );

		void move( int x, int y ); // modifie la val du vect de deplacement;
		virtual void shoot( void ) = 0; // spawn un sous objet projectile


	private:
		// space var //
		int posX; // position
		int posY;

		int vecX; // valeur de deplacement au refresh 
		int vecY;

		// apparence //
		char display; // char qui sera affiché.
};

#endif