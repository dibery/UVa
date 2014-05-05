#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;
int sum( int n )
{
    int back = 0;
    while( n )
    {
        back += n % 10;
        n /= 10;
    }
    return back < 10? back : sum( back );
}

int main()
{
    char a[ 30 ], b[ 30 ];

    while( gets( a ) && gets( b ) )
    {
        int x = 0, y = 0;
        for( int i = 0; a[ i ]; ++i )
            if( isalpha( a[ i ] ) )
                x += tolower( a[ i ] ) - 'a' + 1;
        for( int i = 0; b[ i ]; ++i )
            if( isalpha( b[ i ] ) )
                y += tolower( b[ i ] ) - 'a' + 1;
        x = sum( x );
        y = sum( y );
        printf( "%.2f %%\n", (double)min( x, y ) / max( x, y ) * 100 + 1e-9 );
    }

	return 0;
}