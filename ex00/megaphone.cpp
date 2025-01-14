/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:45:26 by baguiar-          #+#    #+#             */
/*   Updated: 2025/01/14 12:54:38 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int i = 1; int j = 0; char c_upper='\0';
    
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (argv[i])
        {
            j = 0;
            while (argv[i][j])
            {
                c_upper = std::toupper(argv[i][j]);
                std::cout << c_upper;
                j++;
            }
            if (argv[i + 1])
                std::cout << " ";
            i++;
        }
        std::cout << std::endl;
        return (0);
    }
}
