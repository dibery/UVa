#include<cstdio>
#include<cctype>
#include<algorithm>
inline int cov( char n ) { return islower( n )? n - 'a' + 26 : n - 'A'; }
inline char cov( int n ) { return n < 26? n+'A' : n+'a'-26; }

int main()
{
    char str[ 10000 ];

    while( gets( str ) )
    {
        int letter[ 52 ] = { 0 }, max = 0;
        for( int i = 0; str[ i ]; ++i )
            if( isalpha( str[ i ] ) )
                ++letter[ cov( str[ i ] ) ];
        for( int i = 0; i < 52; ++i )
            max = std::max( max, letter[ i ] );
        for( int i = 0; i < 52; ++i )
            if( letter[ i ] == max )
                printf( "%c", cov( i ) );
        printf( " %d\n", max );
    }

	return 0;
}