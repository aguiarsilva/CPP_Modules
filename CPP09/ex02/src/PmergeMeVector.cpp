/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 09:06:24 by baguiar-          #+#    #+#             */
/*   Updated: 2025/08/05 09:55:05 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMeVector.hpp"

PmergeMeVector::PmergeMeVector() : m_exec_time(0.0)
{}

PmergeMeVector::PmergeMeVector(std::vector<int> const& input) : m_input(input), m_exec_time(0.0)
{
    m_sorted.reserve(input.size());
}

PmergeMeVector::PmergeMeVector(PmergeMeVector const& other) : m_input(other.m_input), m_sorted(other.m_sorted), m_exec_time(other.m_exec_time)
{}

PmergeMeVector &PmergeMeVector::operator=(PmergeMeVector const& other)
{
    if (this != &other)
    {
        m_input = other.m_input;
        m_sorted = other.m_sorted;
        m_exec_time = other.m_exec_time;
    }
    return (*this);
}

PmergeMeVector::~PmergeMeVector() {}

//Private Methods
void PmergeMeVector::pairAndAllocate(std::vector<int>& main_chain, std::vector<int>& pending, int& straggler, bool& has_straggler)
{
    //output containers must be cleared before starting
    main_chain.clear();
    pending.clear();
    straggler = -1;
    has_straggler = false;

    //handle single element input
    if (m_sorted.size() == 1)
    {
        main_chain.push_back(m_sorted[0]);
        return ;
    }

    //handle two elements input
    if (m_sorted.size() == 2)
    {
        if (m_sorted[0] <= m_sorted[1])
        {
            main_chain.push_back(m_sorted[1]);
            pending.push_back(m_sorted[0]);        
        }
        else
        {
            main_chain.push_back(m_sorted[0]);
            pending.push_back(m_sorted[1]);
        }
        return ;
    }

    //reserve memory space in vector
    main_chain.reserve(m_sorted.size() / 2 + 1);
    pending.reserve(m_sorted.size() / 2 + 1);

    //handle the general case and build pairs
    for (std::vector<int>::size_type i = 0; i < m_sorted.size() - 1; i += 2)
    {
        int first = m_sorted[i];
        int second = m_sorted[i + 1];

        if (first <= second)
        {
            main_chain.push_back(second);
            pending.push_back(first);
        }
        else
        {
            main_chain.push_back(first);
            pending.push_back(second);
        }
    }
    
    //handle straggler
    if (m_sorted.size() % 2 == 1)
    {
        straggler = m_sorted.back();
        has_straggler = true;
    }

}

void PmergeMeVector::sortWinners()
{}

std::vector<int> PmergeMeVector::JacobsthalSequence(int pending_count)
{
    std::vector<int> insertion_order;

    //handle an empty sequence of numbers
    if (pending <= 0)
        return insertion_order;

    //handle one element in index
    if (pending_count == 1)
    {
        insertion_order.
    }
}

void PmergeMeVector::insertPending(std::vector<int>& main_chain, std::vector<int> const& pending, int straggler, bool has_straggler, std::vector<int> const& jacobsthal_seq)
{}

void PmergeMeVector::recursiveFordJohnson(std::vector<int>& container)
{}

int PmergeMeVector::binarySearchInsertPosition(int value, int upper_bound_position)
{}

//Public methods
void PmergeMeVector::sort()
{
    if (m_input.empty())
        throw std::runtime_error("Not able to sort empty container!");

    //need to start timing before sorting
    clock_t start_time = clock();

    //make copy of the input to process sorting
    m_sorted = m_input;

    //apply the FordJohnson Algorithm for sorting - do not forget it must recursively sort, or else is not the Ford-Johnson Algorithm (it must sort 100 nums in between 500 and 600 comparisons)
    recursiveFordJohnson(std::vector<int>& container);

    //after sorting, end clock and calculate processing time in microseconds
    clock_t end_time = clock();

    m_exec_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000.0;
}

void PmergeMeVector::printResults() const
{
    Utils::displayVec(m_input, "Before: ");
    Utils::displayVec(m_sorted, "After: ");

    std::cout << "Time to process a range of " << m_input.size()
        << " elements with std::vector : " << m_exec_time << " us " << std::endl;
}

double PmergeMeVector::getExecutionTime() const
{
    return m_exec_time;
}

bool PmergeMeVector::isEmpty() const
{
    return m_input.empty();
}

std::vector<int>::size_type PmergeMeVector::size() const
{
    return m_input.size();
}

