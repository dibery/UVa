#include<cstdio>
#include<algorithm>
#include<cctype>
inline int convert( char ch )
{
    if( islower( ch ) )
        return ch - 'a' + 36;
    if( isupper( ch ) )
        return ch - 'A' + 10;
    return ch - '0';
}
bool isprime( int n, int total, int *prime )
{
    for( int i = 1; i < total; ++i )
        if( n % prime[ i ] == 0 )
            return false;
    return true;
}

int main()
{
    int t, prime[ 1000 ] = { 2 }, all = 1;
    char str[ 2001 ];
    for( int i = 3; i < 2000; i += 2 )
        if( isprime( i, all, prime ) )
            prime[ all++ ] = i;
    scanf( "%d\n", &t );

    for( int i = 1; i <= t; ++i )
    {
        int freq[ 62 ] = { 0 }, out = 0;
        gets( str );
        for( int i = 0; str[ i ]; ++i )
            ++freq[ convert( str[ i ] ) ];
        printf( "Case %d: ", i );
        for( int i = 0; i < 62; ++i )
            if( std::binary_search( prime, prime+all, freq[ i ] ) && ++out )
                if( i < 10 )
                    putchar( i + '0' );
                else if( i < 36 )
                    putchar( i + 'A' - 10 );
                else
                    putchar( i + 'a' - 36 );
        puts( out? "" : "empty" );
    }

	return 0;
}