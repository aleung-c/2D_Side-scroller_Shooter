/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 18:29:10 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/21 18:37:09 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BACKGROUND_HPP
# define BACKGROUND_HPP
# include "ft_retro.hpp"

class Background : public AEntity
{
public:
		Background( int x, int y, char c );
		~Background( void );
		Background & operator=( Background const &rhs );
		void	die( void );
		void		shoot( void );

private:
	Background( void );
	t_bg_obj	*_n;
	Background( Background const &src );
};
#endif
