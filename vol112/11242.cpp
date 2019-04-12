#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int front, rear, index;
    double rate[ 100 ], f[ 10 ], r[ 10 ], ans;

    while( scanf( "%d %d", &front, &rear ) == 2 )
    {
        ans = index = 0;
        for( int i = 0; i < front; ++i )
            scanf( "%lf", f+i );
        for( int i = 0; i < rear; ++i )
            scanf( "%lf", r+i );
        for( int i = 0; i < front; ++i )
            for( int j = 0; j < rear; ++j )
                rate[ index++ ] = r[ j ] / f[ i ];
        sort( rate, rate+index );
        for( int i = 1; i < index; ++i )
            ans = max( ans, rate[ i ] / rate[ i-1 ] );
        printf( "%.2f\n", ans );
    }

	return 0;
}