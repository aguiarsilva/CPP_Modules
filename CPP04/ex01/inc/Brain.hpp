/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 23:20:37 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/30 23:20:41 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain 
{
    public:
        Brain();
        Brain(const Brain& obj);
        ~Brain();
        Brain& operator=(const Brain& other);
        std::string getIdea(int i) const;
        void setIdea(int i, const std::string& idea);

    private:
        std::string ideas[100];
};

#endif
