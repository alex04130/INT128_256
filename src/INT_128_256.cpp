#include <INT_128_256.h>
#include <iostream>
#include <iomanip>
namespace INT_128_256
{
    INT_128_t::INT_128_t()
    {
        UPPER_t = 0;
        LOWER_t = 0;
    }
    INT_128_t::INT_128_t(unsigned long long x)
    {
        UPPER_t = 0;
        LOWER_t = x;
    }
    INT_128_t::INT_128_t(unsigned long long x_upper, unsigned long long x_lower)
    {
        UPPER_t = x_upper;
        LOWER_t = x_lower;
    }
    INT_128_t INT_128_t::operator+(INT_128_t &x)
    {
        unsigned long long tmp = x.LOWER_t + this->LOWER_t;
        return INT_128_t((tmp > this->LOWER_t) ? (x.UPPER_t + this->UPPER_t) : (x.UPPER_t + this->UPPER_t + 1), tmp);
    }
    INT_128_t INT_128_t::operator-(INT_128_t &x)
    {
        INT_128_t tmp = -x;
        return *this + tmp;
    }
    INT_128_t INT_128_t::operator-()
    {
        return INT_128_t((this->LOWER_t == 0xFFFFFFFFFFFFFFFFull) ? ~this->UPPER_t : ~this->UPPER_t + 1, ~this->LOWER_t + 1);
    }
    INT_128_t INT_128_t::operator*(INT_128_t &x)
    {
        unsigned long long a0 = this->UPPER_t >> 32, a1 = this->UPPER_t & 0xFFFFFFFF, a2 = this->LOWER_t >> 32, a3 = this->LOWER_t & 0xFFFFFFFF;
        unsigned long long b0 = x.UPPER_t >> 32, b1 = x.UPPER_t & 0xFFFFFFFF, b2 = x.LOWER_t >> 32, b3 = x.LOWER_t & 0xFFFFFFFF;
        unsigned long long tmp0 = a2 * b3 >> 32;
        unsigned long long tmp1 = tmp0 + a3 * b2 >> 32;
        unsigned long long tmp2 = (a0 * b3 + a1 * b2 + a2 * b1 + a3 * b0) << 32 + a1 * b3 + a2 * b2 + a3 * b1 + a2 * b3 >> 32 + a3 * b2 >> 32;
        unsigned long long tmp3 = a3 * b3 + tmp1;
        if (tmp1 < tmp0)
        {
            tmp2++;
        }
        if (tmp3 < tmp1)
        {
            tmp2++;
        }
        return INT_128_t(tmp2, tmp3);
    }
    INT_128_t INT_128_t::operator=(INT_128_t &x)
    {
        this->LOWER_t = x.LOWER_t;
        this->UPPER_t = x.UPPER_t;
        return *this;
    }
    void INT_128_t::Print_Base16()
    {
        std::cout << "0x";
        std::cout << std::hex << std::setw(16) << std::setfill('0') << UPPER_t << std::hex << std::setw(64) << std::setfill('0') << LOWER_t;
    }
}