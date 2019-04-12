#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
bool isprime( int n, int *prime )
{
    for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
        if( n % prime[ i ] == 0 )
            return false;
    return true;
}

int main()
{
    bool prime[ 100000 ] = { false, false, true };
    int P[ 9592 ] = { 2 }, put = 0;
    char in[ 256 ];
    for( int i = 3; i < 100000; i += 2 )
        if( isprime( i, P ) )
            prime[ i ] = true, P[ ++put ] = i;

    while( gets( in ) && strcmp( in, "0" ) )
    {
        int len = strlen( in ), max = 0;
        for( int i = 0; i < len; ++i )
            for( int j = 1; j <= 5 && i + j <= len; ++j )
            {
                char tmp[ 10 ] = { 0 };
                strncpy( tmp, in + i, j );
                int trans = strtol( tmp, NULL, 10 );
                if( prime[ trans ] && trans > max )
                    max = trans;
            }
        printf( "%d\n", max );
    }

    return 0;
}
