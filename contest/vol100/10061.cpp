#include<cstdio>
#include<cmath>
#include<climits>
#include<algorithm>
double fact[ 1 << 20 ] = { 0 }, ln[ 801 ] = { 0 };
int base, real, prime[ 400000 ] = { 2, 3, 5, 7 }, all = 4;
int has( int n, int factor )
{
    int ans = 0;
    while( n % factor == 0 )
    {
        n /= factor;
        ++ans;
    }
    return ans;
}

int main()
{
    for( int i = 11; i <= 1 << 20; i += 2 )
        for( int j = 1; prime[ j-1 ] * prime[ j-1 ] <= i; ++j )
            if( i % prime[ j ] == 0 )
                break;
            else if( prime[ j ] * prime[ j ] > i )
                prime[ all++ ] = i;
    for( int i = 2; i <= 800; ++i )
        ln[ i ] = log( i );
    for( int i = 2; i < 1 << 20; ++i )
        fact[ i ] = fact[ i-1 ] + log( i );

    while( scanf( "%d %d", &real, &base ) == 2 )
    {
        int trail = INT_MAX, factor[ 801 ] = { 0 };
        for( int i = 2; i <= real; ++i )
            for( int j = 0; prime[ j ] <= base; ++j )
                factor[ prime[ j ] ] += has( i, prime[ j ] );
        for( int i = 0; prime[ i ] <= base; ++i )
			if( base % prime[ i ] == 0 )
				trail = std::min( trail, factor[ prime[ i ] ] / has( base, prime[ i ] ) );
        printf( "%d %d\n", trail, int( fact[ real ] / ln[ base ] + 1 ) );
    }

    return 0;
}
