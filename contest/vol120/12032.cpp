#include<cstdio>
#include<algorithm>
using namespace std;
bool jump( int h, const int *ladder, const int &stage )
{
    bool can = true;
    for( int i = 1; i <= stage && can; ++i )
        if( ladder[ i ] - ladder[ i-1 ] == h )
            --h;
        else if( ladder[ i ] - ladder[ i-1 ] > h )
            can = false;
    return can;
}

int main()
{
    int test, size;
    scanf( "%d", &test );

    for( int i = 1; i <= test; ++i )
    {
        scanf( "%d", &size );
        int ladder[ size ], prev = 0, high = 0, low = 1, mid;
        *ladder = 0;

        for( int k = 1; k <= size; ++k )
        {
            scanf( "%d", ladder+k );
            high = max( high, ladder[ k ]-prev+1 );
            prev = ladder[ k ];
        }
        while( low < high )
        {
            mid = ( low+high ) / 2;
            if( jump( mid, ladder, size ) )
                high = mid;
            else
                low = mid+1;
        }
        printf( "Case %d: %d\n", i, low );
    }

	return 0;
}