#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int prime[ 4800 ] = { 2 }, counter, size = 0, a, b, num[ 10001 ];
bool judge[ 10000 ] = { false };
bool isprime( int in )
{
    for( int i = 1; i <= size; ++i )
        if( in % prime[ i ] == 0 )
            return false;
    return true;
}

int main()
{
    for( int i = 3; i < 46340; i += 2 )
        if( isprime( i ) )
            prime[ ++size ] = i;
    prime[ ++size ] = 46341;
    for( int i = 0; i <= 10000; ++i )
        num[ i ] = i*i+i+41;
    for( int i = 0; i <= 10000; ++i )
    {
        double bound = sqrt( num[ i ] );
        for( counter = 0; prime[ counter ] <= bound; counter++ )
            if( num[ i ] % prime[ counter ] == 0 )
                break;
        judge[ i ] = num[ i ] % prime[ counter ];
    }

    while( cin >> a >> b )
    {
        int total = 0;
        for( int i = a; i <= b; ++i )
            if( judge[ i ] )
                ++total;
        printf( "%.2f\n", (double)total / (double)(b-a+1) * 100 + 1e-7 );
    }

    return 0;
}
