/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:37:55 by ajulien           #+#    #+#             */
/*   Updated: 2015/06/21 13:59:03 by ajulien          ###   ########.fr       */
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
		virtual ~Projectile( void );
		Projectile & operator=( Projectile const &rhs );
		void die( void );
	private:
		t_pro_obj	* _n;
		void	shoot( void );
		Projectile( void );
};

#endif
