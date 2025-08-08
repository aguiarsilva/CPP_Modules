/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 09:06:24 by baguiar-          #+#    #+#             */
/*   Updated: 2025/08/08 23:56:13 by baguiar-         ###   ########.fr       */
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
        if (!compareAndCount(source[1], source[0]))
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

    //reserve memory space in vector
    main_chain.reserve(source.size() / 2 + 1);
    pending.reserve(source.size() / 2 + 1);

    //handle the general case and build pairs
    for (std::vector<int>::size_type i = 0; i < source.size() - 1; i += 2)
    {
        int first = source[i];
        int second = source[i + 1];

        if (!compareAndCount(second, first))
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

    //handle an empty sequence of numbers
    if (pending_count <= 0)
        return insertion_order;

    //handle one element in index
    if (pending_count == 1)
    {
        insertion_order.push_back(0);
        return insertion_order;
    }

    std::vector<int> jacobsthal;
    
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    while (true)
    {
    	int next_jacobsthal = jacobsthal[jacobsthal.size()-1] + 2 * jacobsthal[jacobsthal.size()-2];
	    if (next_jacobsthal - 1 >= pending_count)
		    break;
	    jacobsthal.push_back(next_jacobsthal);
    }

    //need to build the insertion sequence from J3 (index 3 in the jacobsthal sequence)
    std::vector<bool> used(pending_count, false);

    for (std::vector<int>::size_type i = 2; i < jacobsthal.size(); ++i)
    {
    	int index = jacobsthal[i] - 1;

	if (index < pending_count && !used[index])
	{
		insertion_order.push_back(index);
		used[index] = true;
	}

	//backwards insertion_order sequence check
	for (int j = jacobsthal[i]-2; j >= jacobsthal[i-1]; --j)
	{
		if (j >= 0 && j < pending_count && !used[j])
		{
			insertion_order.push_back(j);
			used[j] = true;
		}
	}
    }

    //handle the remaining elements
    for (int i = 0; i < pending_count; ++i)
    {
    	if (!used[i])
		insertion_order.push_back(i);
    }

    return insertion_order;
}

void PmergeMeVector::insertPending(std::vector<int>& main_chain, std::vector<int> const& pending, int straggler, bool has_straggler, std::vector<int> const& jacobsthal_seq)
{

  //use a bool vector to keep track of the already inserted elements
    std::vector<bool> inserted(pending.size(), false);

    //use the Jacobsthal numbers to insert the remaining elements
    for (std::vector<int>::size_type i = 0; i < jacobsthal_seq.size(); ++i)
    {
        int pending_index = jacobsthal_seq[i];

        if (pending_index >= static_cast<int>(pending.size()) || inserted[pending_index])
            continue ;

        int value = pending[pending_index];

        //do binary search for insertion position
        int insert_position = 0;
        int left = 0;
        int right = static_cast<int>(main_chain.size()) - 1;

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
        inserted[pending_index] = true;
    }
    
    //insert any remaining uninserted pending elements
    for (std::vector<int>::size_type i = 0; i < pending.size(); ++i)
    {
        if (!inserted[i])
        {
            int value = pending[i];

            //binary search entire main_chain for the position
            int insert_position = 0;
            int left = 0;
            int right = static_cast<int>(main_chain.size()) - 1;

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
    }
    //handle straggler if existent
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
	std::vector<int> main_chain;
	std::vector<int> pending;
	int straggler;
	bool has_straggler;

	//pair and separate
	pairAndAllocate(container, main_chain, pending, straggler, has_straggler);

	//recursively sort the main chain - it must be recursive
	if (main_chain.size() > 1)
	{
		recursiveFordJohnson(main_chain);
	}

	//generate the jacobsthal numbers and do insert
	if (!pending.empty() || has_straggler)
	{
		std::vector<int> jacobsthal_seq = JacobsthalSequence(static_cast<int>(pending.size()));

		//use jacobsthal order to insert pending elements
		insertPending(main_chain, pending, straggler, has_straggler, jacobsthal_seq);
	}
	//update containers;
	container = main_chain;
}

int PmergeMeVector::binarySearchInsertPosition(int value, int upper_bound_position)
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
    std::cout << "Number of comparisons made: " << getComparisonCount() << std::endl;
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


