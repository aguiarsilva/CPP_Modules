/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 08:18:03 by baguiar-          #+#    #+#             */
/*   Updated: 2025/08/05 09:45:24 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMEVECTOR_HPP
# define PMERGEMEVECTOR_HPP

#include <vector>
#include <ctime>
#include <iostream>
#include "Utils.hpp"

class PmergeMeVector
{
    private:
        std::vector<int> m_input;
        std::vector<int> m_sorted;
        double m_exec_time;

        //Ford-Johnson Algorithm
        void pairAndAllocate(std::vector<int>& main_chain, std::vector<int>& pending, int& straggler, bool& has_straggler);
        void sortWinners();
        std::vector<int> JacobsthalSequence(int pending_count);
        void insertPending(std::vector<int>& main_chain, std::vector<int> const& pending, int straggler, bool has_straggler, std::vector<int> const& jacobsthal_seq);
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
