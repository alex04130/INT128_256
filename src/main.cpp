#include <iostream>
#include <INT_128_256.h>
#include <algorithm>
using namespace std;
int main()
{
    INT_128_256::INT_128_t a = {0xFFFFFFFEull, 0xFFFFFFFFFFFFFFFFull}, b = {0, 1};
    INT_128_256::INT_128_t c = a + b;
    c.Print_Base16();
    cout << endl;
    return 0;
}