/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:37:55 by ajulien           #+#    #+#             */
/*   Updated: 2015/06/20 19:37:46 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP
# include "ft_retro.hpp"

class Projectile : public AEntity
{
	public:
		Projectile( int x, int y, char c );
		Projectile( Projectile const &src );
		~Projectile( void );
		Projectile & operator=( Projectile const &rhs );

	private:
		void	shoot( void );
		Projectile( void );
};

#endif
