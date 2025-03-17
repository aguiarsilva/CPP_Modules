/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:13:13 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/17 15:13:16 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_HPP
# define COLOR_HPP

# define RESET      "\033[0m"

//regular colors
# define BLACK       "\033[0;30m"
# define RED         "\033[0;31m"
# define GREEN       "\033[0;32m"
# define YELLOW      "\033[0;33m"
# define BLUE        "\033[0;34m"
# define MAGENTA     "\033[0;35m"
# define CYAN        "\033[0;36m"
# define WHITE       "\033[0;37m"

//bold colors
# define BOLD_BLACK     "\033[1;30m"
# define BOLD_RED       "\033[1;31m"
# define BOLD_GREEN     "\033[1;32m"
# define BOLD_YELLOW    "\033[1;33m"
# define BOLD_BLUE      "\033[1;34m"
# define BOLD_MAGENTA   "\033[1;35m"
# define BOLD_CYAN      "\033[1;36m"
# define BOLD_WHITE     "\033[1;37m"

//underline colors
# define UNDER_BLACK    "\033[4;30m"
# define UNDER_RED      "\033[4;31m"
# define UNDER_GREEN    "\033[4;32m"
# define UNDER_YELLOW   "\033[4;33m"
# define UNDER_BLUE     "\033[4;34m"
# define UNDER_MAGENTA  "\033[4;35m"
# define UNDER_CYAN     "\033[4;36m"
# define UNDER_WHITE    "\033[4;37m"

//background colors
# define BG_BLACK       "\033[40m"
# define BG_RED         "\033[41m"
# define BG_GREEN       "\033[42m"
# define BG_YELLOW      "\033[43m"
# define BG_BLUE        "\033[44m"
# define BG_MAGENTA     "\033[45m"
# define BG_CYAN        "\033[46m"
# define BG_WHITE       "\033[47m"

#endif
