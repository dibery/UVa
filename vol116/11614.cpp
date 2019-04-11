#include<iostream>
#include<cmath>

int main()
{
    long double n;
    std::cin >> n;

    while( std::cin >> n )
        std::cout << (long long int)floor( ( sqrt( 1 + 8.0 * n ) - 1 ) / 2.0 ) << std::endl;

    return 0;
}