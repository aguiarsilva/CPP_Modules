/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:21:23 by baguiar-          #+#    #+#             */
/*   Updated: 2025/08/27 09:07:39 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMeDeque.hpp"

int PmergeMeDeque::m_comparison_count = 0;

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
        if (!compareAndCount(source[1], source[0])) // source[0] <= source[1]
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

        if (!compareAndCount(second, first)) // first <= second
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

    // Generate Jacobsthal numbers: 1, 1, 3, 5, 11, 21, 43, 85, ...
    std::deque<int> jacobsthal;
    jacobsthal.push_back(1);  // J(1) = 1
    jacobsthal.push_back(1);  // J(2) = 1
    
    // Generate: J(n) = J(n-1) + 2*J(n-2)
    while (jacobsthal.back() < pending_count)
    {
        int next = jacobsthal[jacobsthal.size()-1] + 2 * jacobsthal[jacobsthal.size()-2];
        jacobsthal.push_back(next);
    }

    // Always insert pending[0] first
    insertion_order.push_back(0);
    std::vector<bool> used(pending_count, false);
    used[0] = true;

    // Use Jacobsthal numbers starting from J(3) = 3
    std::deque<int>::size_type i;
    for (i = 2; i < jacobsthal.size(); ++i) // Start from jacobsthal[2] = 3
    {
        int current_jacobsthal = jacobsthal[i];
        int prev_jacobsthal = jacobsthal[i-1];
        
        // Insert in descending order from current_jacobsthal down to prev_jacobsthal + 1
        int j;
        for (j = (current_jacobsthal < pending_count ? current_jacobsthal : pending_count) - 1; j >= prev_jacobsthal; --j)
        {
            if (j >= 0 && j < pending_count && !used[j])
            {
                insertion_order.push_back(j);
                used[j] = true;
            }
        }
    }

    // Add remaining elements
    int k;
    for (k = 1; k < pending_count; ++k) // Start from 1 since 0 is already added
    {
        if (!used[k])
            insertion_order.push_back(k);
    }

    return insertion_order;
}

void PmergeMeDeque::insertPending(std::deque<int>& main_chain, std::deque<int> const& pending, int straggler, bool has_straggler, std::deque<int> const& jacobsthal_seq)
{
    if (pending.empty() && !has_straggler)
        return;

    std::deque<int>::size_type i;
    for (i = 0; i < jacobsthal_seq.size(); ++i)
    {
        int pending_index = jacobsthal_seq[i];
        
        if (pending_index >= static_cast<int>(pending.size()))
            continue;

        int value = pending[pending_index];
        
        int search_limit;
        
        if (pending_index == 0)
        {
            // pending[0] can only go up to position of its pair (main_chain[0])
            search_limit = 1; // It's guaranteed ≤ main_chain[0]
        }
        else
        {
            // For pending[k], upper bound is position of main_chain[k] + elements already inserted
            search_limit = pending_index + 1 + static_cast<int>(i); // +i for elements already inserted
            if (search_limit > static_cast<int>(main_chain.size()))
                search_limit = static_cast<int>(main_chain.size());
        }

        // Binary search with limited range
        int insert_position = 0;
        int left = 0;
        int right = search_limit - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (compareAndCount(main_chain[mid], value))
            {
                insert_position = mid + 1;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        
        main_chain.insert(main_chain.begin() + insert_position, value);
    }

    if (has_straggler)
    {
        int insert_position = 0;
        int left = 0;
        int right = static_cast<int>(main_chain.size()) - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (compareAndCount(main_chain[mid], straggler))
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
    if (container.size() <= 1)
        return;
    
    if (container.size() == 2)
    {
        if (compareAndCount(container[1], container[0])) // container[1] < container[0]
        {
            std::swap(container[0], container[1]);
        }
        return;
    }
    
    if (container.size() <= 5)
    {
        insertionSort(container);
        return;
    }

    std::deque<int> main_chain;
    std::deque<int> pending;
    int straggler;
    bool has_straggler;

    pairAndAllocate(container, main_chain, pending, straggler, has_straggler);

    // Recursively sort the main chain
    if (main_chain.size() > 1)
    {
        recursiveFordJohnson(main_chain);
    }

    // Insert pending elements using Jacobsthal sequence
    if (!pending.empty() || has_straggler)
    {
        std::deque<int> jacobsthal_seq = JacobsthalSequence(static_cast<int>(pending.size()));
        insertPending(main_chain, pending, straggler, has_straggler, jacobsthal_seq);
    }
    
    container = main_chain;
}

// New optimized insertion sort for small arrays
void PmergeMeDeque::insertionSort(std::deque<int>& container)
{
    std::deque<int>::size_type i;
    for (i = 1; i < container.size(); ++i)
    {
        int key = container[i];
        int j = static_cast<int>(i) - 1;
        
        // Move elements greater than key one position ahead
        while (j >= 0 && compareAndCount(key, container[j]))
        {
            container[j + 1] = container[j];
            j--;
        }
        container[j + 1] = key;
    }
}

int PmergeMeDeque::binarySearchInsertPosition(int value, int upper_bound_position)
{
    int left = 0;
    int right = upper_bound_position;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (compareAndCount(m_sorted[mid], value))
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
    //DEBUG
    //std::cout << "Number of comparisons made: " << getComparisonCount() << std::endl;
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

//methods to track comparisons
bool PmergeMeDeque::compareAndCount(int a, int b) const
{
    m_comparison_count++;
    return a < b;
}

int PmergeMeDeque::getComparisonCount()
{
    return m_comparison_count;
}

void PmergeMeDeque::resetComparisonCount()
{
    m_comparison_count = 0;
}