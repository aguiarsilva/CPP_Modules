/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 08:18:03 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/30 14:55:19 by baguiar-         ###   ########.fr       */
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

        //Ford-Johnson Algorithm
        void pairAndAllocate();
        void sortWinners();
        std::vector<int> JacobsthalSequence(int pending_count);
        void insertPending();
        void recursiveFordJohnson(std::vector<int>& container);
        int binarySearchInsertPosition(int value, int upper_bound_position);

    public:
        //Orthodox Canonical Form
        PmergeMeVector();
        PmergeMeVector(std::vector<int> const& input);
        PmergeMeVector(PmergeMeVector const& other);
        PmergeMeVector &operator=(PmergeMeVector const& other);
        ~PmergeMeVector();

        //Public methods
        void sort();
        void printResults() const;
        double getExecutionTime() const;
        bool isEmpty() const;
        std::vector<int>::size_type size() const;

};

#endif
