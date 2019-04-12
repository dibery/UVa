#include<cstdio>
inline void count( int *dig, int n )
{
    while( n )
    {
        ++dig[ n % 10 ];
        n /= 10;
    }
}

int main()
{
    int t, in;
    scanf( "%d", &t );

    while( t-- )
    {
        int digit[ 10 ] = { 0 };
        scanf( "%d", &in );
        for( int i = 1; i <= in; ++i )
            count( digit, i );
        for( int i = 0; i < 10; ++i )
            printf( "%d%c", digit[ i ], i == 9? '\n' : ' ' );
    }

	return 0;
}