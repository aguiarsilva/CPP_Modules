#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed 
{
    private:
        int _fixedPointNum;
        static const int _fractionalBitsNum = 8;

    public:
        Fixed();
        Fixed(const Fixed& src);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);

};

#endif