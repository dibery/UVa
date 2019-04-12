#include<cstdio>
#include<cmath>
long long int prime[ 670000 ] = { 2 }, size = 1;
bool notprime[ 10000000 ] = { true, true, false };
bool isprime( long long int n )
{
    int root = sqrt( n );
    for( int i = 0; prime[ i ] <= root; ++i )
        if( n % prime[ i ] == 0 )
            return false;
    return true;
}
long long int large( long long int n )
{
    int m = -1, item = 0;
    for( int i = 0; i < size && prime[ i ] < n; ++i )
        if( n % prime[ i ] == 0 )
        {
            m = i;
            ++item;
            while( n % prime[ i ] == 0 )
                n /= prime[ i ];
        }
    return n == 1? m == -1 || item == 1? -1 : prime[ m ] : n;
}

int main()
{
    long long int n;
    for( int i = 3; i < 3162; i += 2 )
        if( !notprime[ i ] )
            for( int j = i*i; j < 10000000; j += i<<1 )
                notprime[ j ] = true;
    for( int i = 3; i < 10000000; i += 2 )
        if( !notprime[ i ] )
            prime[ size++ ] = i;
    while( scanf( "%lld", &n ) && n )
        printf( "%lld\n", isprime( n < 0? -n : n )? -1 : large( n < 0? -n : n ) );
}
