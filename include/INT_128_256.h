#ifndef __INT_128_256_H__

#define __INT_128_256_H__
namespace INT_128_256
{
    class INT_128_t
    {
    private:
        unsigned long long UPPER_t, LOWER_t;

    public:
        INT_128_t();
        INT_128_t(unsigned long long x);
        INT_128_t(unsigned long long x_upper, unsigned long long x_lower);
        INT_128_t operator+(INT_128_t &);
        INT_128_t operator-();
        INT_128_t operator-(INT_128_t &);
        INT_128_t operator*(INT_128_t &);
        INT_128_t operator=(INT_128_t &);
        void Print_Base16();
    };
}

#endif