#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cctype>
const char chr[] = { "0123456789ABCDEF" };
int check( char *n )
{
    char ans = 0;
    for( int i = 0; n[ i ]; ++i )
        ans = std::max( ans, n[ i ] );
    if( isdigit( ans ) )
        return std::max( ans-'0'+1, 2 );
    else
        return ans-'A'+11;
}

int main()
{
    int b1, b2;
    long long int real;
    char n[ 100 ], print[ 100 ];

    while( scanf( "%d %d %s", &b1, &b2, n ) != EOF )
    {
        real = strtoll( n, NULL, b1 );
        if( check( n ) > b1 )
            real = 0;
        if( real == 0 && strcmp( n, "0" ) )
            printf( "%s is an illegal base %d number\n", n, b1 );
        else
        {
            int i = 0;
            printf( "%s base %d = ", n, b1 );
            if( real == 0 )
                putchar( '0' );
            while( real )
            {
                print[ ++i ] = real % b2;
                real /= b2;
            }
            for( ; i > 0; --i )
                printf( "%c", chr[ print[ i ] ] );
            printf( " base %d\n", b2 );
        }
    }

	return 0;
}