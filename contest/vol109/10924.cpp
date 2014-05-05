#include<cstdio>
#include<cmath>
#include<cctype>
#include<algorithm>
inline int convert( char ch ) { return islower( ch )? ch - 'a' + 1 : ch - 'A' + 27; }
bool isprime( int n, int *prime )
{
    int bound = sqrt( double( n ) );
    for( int i = 0; prime[ i ] <= bound; ++i )
        if( n % prime[ i ] == 0 )
            return false;
    return true;
}

int main()
{
    char str[ 21 ];
    int prime[ 1000 ] = { 2 }, all = 1;
    for( int i = 3; i < 2000; i += 2 )
        if( isprime( i, prime ) )
            prime[ all++ ] = i;

    while( scanf( "%s", str ) != EOF )
    {
        int sum = 0;
        for( int i = 0; str[ i ]; ++i )
            sum += convert( str[ i ] );
        puts( sum == 1 || std::binary_search( prime, prime+all, sum )? "It is a prime word." : "It is not a prime word." );
    }

	return 0;
}