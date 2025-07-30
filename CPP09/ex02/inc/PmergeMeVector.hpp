/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 08:18:03 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/30 09:27:18 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMEVECTOR_HPP
# define PMERGEMEVECTOR_HPP

#include <vector>
#include <ctime>
#include <iostream>

class PmergeMeVector
{
    private:
        std::vector<int> m_input;
        std::vector<int> m_sorted;
        double m_exec_time;

    public:
        //Orthodox Canonical Form
        PmergeMeVector();
        PmergeMeVector(std::vector<int> const& input);
        PmergeMeVector(PmergeMeVector const& other);
        PmergeMeVector &operator=(PmergeMeVector const& other);
        ~PmergeMeVector();

};

#endif
