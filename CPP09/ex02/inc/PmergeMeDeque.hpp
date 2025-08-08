/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:30:54 by baguiar-          #+#    #+#             */
/*   Updated: 2025/08/07 13:19:20 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMEDEQUE_HPP
# define PMERGEMEDEQUE_HPP

#include <deque>
#include <iostream>
#include <vector>
#include <ctime>
#include "Utils.hpp"

class PmergeMeDeque
{
    private:
        std::deque<int> m_input;
        std::deque<int> m_sorted;
        double m_exec_time;

        //Ford-Johnshon Algorithm
        void pairAndAllocate(std::deque<int>& source, std::deque<int>& main_chain, std::deque<int>& pending, int& straggler, bool& has_straggler);
        std::deque<int> JacobsthalSequence(int pending_count);
        void insertPending(std::deque<int>& main_chain, std::deque<int> const& pending, int straggler, bool has_straggler, std::deque<int> const& jacobsthal_seq);
        void recursiveFordJohnson(std::deque<int>& container);
        int binarySearchInsertPosition(int value, int upper_bound_position);

    public:
        //Orthodox Canonical Form
        PmergeMeDeque();
        PmergeMeDeque(std::vector<int> const& input);
        PmergeMeDeque(PmergeMeDeque const& other);
        PmergeMeDeque &operator=(PmergeMeDeque const& other);
        ~PmergeMeDeque();

        //Public Methods
        void sort();
        void printResults() const;
        double getExecutionTime() const;
        bool isEmpty() const;
        std::deque<int>::size_type size() const;
};

#endif
