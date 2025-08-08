/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:21:23 by baguiar-          #+#    #+#             */
/*   Updated: 2025/08/08 20:04:08 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMeDeque.hpp"

PmergeMeDeque::PmergeMeDeque() : m_exec_time(0.0)
{}

PmergeMeDeque::PmergeMeDeque(std::vector<int> const& input) : m_exec_time(0.0)
{
    std::vector<int>::const_iterator it;
    for (it = input.begin(); it != input.end(); ++it)
        m_input.push_back(*it);
}

PmergeMeDeque::PmergeMeDeque(PmergeMeDeque const& other) : m_input(other.m_input), m_sorted(other.m_sorted), m_exec_time(other.m_exec_time)
{}

PmergeMeDeque &PmergeMeDeque::operator=(PmergeMeDeque const& other)
{
    if (this != &other)
    {
        m_input = other.m_input;
        m_sorted = other.m_sorted;
        m_exec_time = other.m_exec_time;
    }
    return (*this);
}

PmergeMeDeque::~PmergeMeDeque() {}

void PmergeMeDeque::pairAndAllocate(std::deque<int>& source, std::deque<int>& main_chain, std::deque<int>& pending, int& straggler, bool& has_straggler)
{
    main_chain.clear();
    pending.clear();
    straggler = -1;
    has_straggler = false;

    if (source.size() == 1)
    {
        main_chain.push_back(source[0]);
        return ;
    }

    if (source.size() == 2)
    {
        if (source[0] <= source[1])
        {
            main_chain.push_back(source[1]);
            pending.push_back(source[0]);
        }
        else
        {
            main_chain.push_back(source[0]);
            pending.push_back(source[1]);
        }
        return ;
    }

    std::deque<int>::size_type i;
    for (i = 0; i < source.size() - 1; i += 2)
    {
        int first = source[i];
        int second = source[i + 1];

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

    if (source.size() % 2 == 1)
    {
        straggler = source.back();
        has_straggler = true;
    }
}

std::deque<int> PmergeMeDeque::JacobsthalSequence(int pending_count)
{
    std::deque<int> insertion_order;

    if (pending_count <= 0)
        return insertion_order;

    if (pending_count == 1)
    {
        insertion_order.push_back(0);
        return insertion_order;
    }

    std::deque<int> jacobsthal;

    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    while (true)
    {
        int next_jacobsthal = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next_jacobsthal - 1 >= pending_count)
            break ;
        jacobsthal.push_back(next_jacobsthal);
    }

    insertion_order.push_back(0);

    std::vector<bool> used(pending_count, false);
    used[0] = true;

    std::deque<int>::size_type i;
    for (i = 2; i < jacobsthal.size(); ++i)
    {
        int index = jacobsthal[i] - 1;

        if (index < pending_count && !used[index])
        {
            insertion_order.push_back(index);
            used[index] = true;
        }

        int j;
        for (j = jacobsthal[i] - 2; j >= jacobsthal[i - 1]; --j)
        {
            if (j >= 0 && j < pending_count && !used[j])
            {
                insertion_order.push_back(j);
                used[j] = true;
            }
        }
    }

    int k;
    for (k = 0; k < pending_count; ++k)
    {
        if (!used[k])
            insertion_order.push_back(k);
    }

    return insertion_order;
}

void PmergeMeDeque::insertPending(std::deque<int>& main_chain, std::deque<int> const& pending, int straggler, bool has_straggler, std::deque<int> const& jacobsthal_seq)
{
    std::vector<bool> inserted(pending.size(), false);

    std::deque<int>::size_type i;
    for (i = 0; i < jacobsthal_seq.size(); ++i)
    {
        int pending_index = jacobsthal_seq[i];

        if (pending_index >= static_cast<int>(pending.size()) || inserted[pending_index])
            continue ;

        int value = pending[pending_index];

        int insert_position = 0;
        int left = 0;
        int right = static_cast<int>(main_chain.size()) - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (main_chain[mid] < value)
            {
                insert_position = mid + 1;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        main_chain.insert(main_chain.begin() + insert_position, value);
        inserted[pending_index] = true;
    }

    for (i = 0; i < pending.size(); ++i)
    {
        if (!inserted[i])
        {
            int value = pending[i];

            int insert_position = 0;
            int left = 0;
            int right = static_cast<int>(main_chain.size()) - 1;

            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (main_chain[mid] < value)
                {
                    insert_position = mid + 1;
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
            main_chain.insert(main_chain.begin() + insert_position, value);
        }
    }

    if (has_straggler)
    {
        int insert_position = 0;
        int left = 0;
        int right = static_cast<int>(main_chain.size()) - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (main_chain[mid] < straggler)
            {
                insert_position = mid + 1;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        main_chain.insert(main_chain.begin() + insert_position, straggler);
    }
}

void PmergeMeDeque::recursiveFordJohnson(std::deque<int>& container)
{
    std::deque<int> main_chain;
    std::deque<int> pending;
    int straggler;
    bool has_straggler;

    pairAndAllocate(container, main_chain, pending, straggler, has_straggler);

    if (main_chain.size() > 1)
    {
        recursiveFordJohnson(main_chain);
    }

    if (!pending.empty() || has_straggler)
    {
        std::deque<int> jacobsthal_seq = JacobsthalSequence(static_cast<int>(pending.size()));

        insertPending(main_chain, pending, straggler, has_straggler, jacobsthal_seq);
    }

    container = main_chain;
}

int PmergeMeDeque::binarySearchInsertPosition(int value, int upper_bound_position)
{
    int left = 0;
    int right = upper_bound_position;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (m_sorted[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

//Public Methods
void PmergeMeDeque::sort()
{
    if (m_input.empty())
        throw std::runtime_error("Not able to sort empty container!");

    clock_t start_time = clock();

    m_sorted = m_input;

    recursiveFordJohnson(m_sorted);

    clock_t end_time = clock();

    m_exec_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000.0;
}

void PmergeMeDeque::printResults() const
{
    std::vector<int> input_vec;
    std::vector<int> sorted_vec;

    std::deque<int>::const_iterator it;
    for (it = m_input.begin(); it != m_input.end(); ++it)
        input_vec.push_back(*it);

    for (it = m_sorted.begin(); it != m_sorted.end(); ++it)
        sorted_vec.push_back(*it);

    Utils::displayVec(input_vec, "Before: ");
    Utils::displayVec(sorted_vec, "After: ");

    std::cout << "Time to process a range of " << m_input.size()
        << " elements with std::deque : " << m_exec_time << " us " << std::endl;
}

double PmergeMeDeque::getExecutionTime() const
{
    return m_exec_time;
}

bool PmergeMeDeque::isEmpty() const
{
    return m_input.empty();
}

std::deque<int>::size_type PmergeMeDeque::size() const
{
    return m_input.size();
}
