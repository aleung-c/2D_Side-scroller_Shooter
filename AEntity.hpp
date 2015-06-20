/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:43:58 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/20 14:03:19 by ajulien          ###   ########.fr       */
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

	private:
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
