/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 09:06:24 by baguiar-          #+#    #+#             */
/*   Updated: 2025/08/27 09:07:53 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMeVector.hpp"

int PmergeMeVector::m_comparison_count = 0;

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
void PmergeMeVector::pairAndAllocate(std::vector<int>& source, std::vector<int>& main_chain, std::vector<int>& pending, int& straggler, bool& has_straggler) 
{ 
    //output containers must be cleared before starting 
    main_chain.clear(); 
    pending.clear(); 
    straggler = -1; 
    has_straggler = false; 
    
    //handle single element input 
    if (source.size() == 1) 
    { 
        main_chain.push_back(source[0]); 
        return ; 
    } 
    
    //handle two elements input 
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
    //reserve memory space in vector - more precise allocation 
    std::vector<int>::size_type pair_count = source.size() / 2;
    main_chain.reserve(pair_count + 1); 
    pending.reserve(pair_count);
    
    //handle the general case and build pairs 
    std::vector<int>::size_type i; 
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
    
    //handle straggler 
    if (source.size() % 2 == 1) 
    { 
        straggler = source.back();
        has_straggler = true;
    } 
}

std::vector<int> PmergeMeVector::JacobsthalSequence(int pending_count)
{
    std::vector<int> insertion_order;

    if (pending_count <= 0)
        return insertion_order;

    if (pending_count == 1)
    {
        insertion_order.push_back(0);
        return insertion_order;
    }

    insertion_order.reserve(pending_count);

    // Generate Jacobsthal numbers: 1, 1, 3, 5, 11, 21, 43, 85, ...
    std::vector<int> jacobsthal;
    jacobsthal.reserve(10);
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
    
    // Use vector<bool> for used tracking
    std::vector<bool> used(pending_count, false);
    used[0] = true;

    // Use Jacobsthal numbers starting from J(3) = 3
    std::vector<int>::size_type i;
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

void PmergeMeVector::insertPending(std::vector<int>& main_chain, std::vector<int> const& pending, int straggler, bool has_straggler, std::vector<int> const& jacobsthal_seq) 
{ 
    if (pending.empty() && !has_straggler) 
        return ; 
    
    // Pre-calculate final size and reserve space 
    std::vector<int>::size_type final_size = main_chain.size() + pending.size() + (has_straggler ? 1 : 0); 
    main_chain.reserve(final_size); 
        
    std::vector<int>::size_type i;
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
            search_limit = 1;
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

void PmergeMeVector::recursiveFordJohnson(std::vector<int>& container)
{
    // Optimized base cases with insertion sort for very small arrays
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
    
    // For small arrays (3-5 elements), insertion sort might be faster
    if (container.size() <= 5)
    {
        insertionSort(container);
        return;
    }

    std::vector<int> main_chain;
    std::vector<int> pending;
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
        std::vector<int> jacobsthal_seq = JacobsthalSequence(static_cast<int>(pending.size()));
        insertPending(main_chain, pending, straggler, has_straggler, jacobsthal_seq);
    }
    
    container = main_chain;
}

void PmergeMeVector::insertionSort(std::vector<int>& container)
{
    std::vector<int>::size_type i;
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

int PmergeMeVector::binarySearchInsertPosition(int value, int upper_bound_position)
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

//Public methods
void PmergeMeVector::sort()
{
    if (m_input.empty())
        throw std::runtime_error("Not able to sort empty container!");

    //need to start timing before sorting
    clock_t start_time = clock();

    //make copy of the input to process sorting
    m_sorted = m_input;

    //apply the FordJohnson Algorithm for sorting
    recursiveFordJohnson(m_sorted);

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
    //DEBUG
    //std::cout << "Number of comparisons made: " << getComparisonCount() << std::endl;
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

//methods to track comparisons
bool PmergeMeVector::compareAndCount(int a, int b) const
{
    m_comparison_count++;
    return a < b;
}

int PmergeMeVector::getComparisonCount()
{
    return m_comparison_count;
}

void PmergeMeVector::resetComparisonCount()
{
    m_comparison_count = 0;
}