#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed 
{
    private:
        int m_fixedPtNum;
        static const int m_fractBitsNum = 8;

    public:
        Fixed();
        Fixed(const Fixed& src);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);

};

#endif
