#include<cstdio>
#include<algorithm>
int disc( int n )
{
    int back = 0;
    while( n )
        back += n % 10, n /= 10;
    return back;
}
void count( int *ddf, int *len, int n )
{
    int tmp = n;
    while( ddf[ tmp ] != tmp )
    {
        ++len[ n ];
        tmp = ddf[ tmp ];
    }
    ++len[ n ];
}

int main()
{
    int ddf[ 3001 ] = { 0 }, len[ 3001 ] = { 0 }, ans, from, to, t = 0, tmp;

    for( int i = 1; i <= 3000; ++i )
        for( int j = 1; j <= i; ++j )
            if( i % j == 0 )
                ddf[ i ] += disc( j );
    for( int i = 1; i <= 3000; ++i )
        count( ddf, len, i );

    while( scanf( "%d %d", &from, &to ) != EOF )
    {
        printf( "Input%d: %d %d\nOutput%d:", ++t, from, to, t );
        int longest = 0;
        if( from > to )
            std::swap( from, to );
        for( int i = from; i <= to; ++i )
            if( len[ i ] > len[ longest ] )
                longest = i;
        tmp = longest;
        while( tmp != ddf[ tmp ] )
            printf( " %d", tmp ), tmp = ddf[ tmp ];
        printf( " %d\n", tmp );
    }
	return 0;
}