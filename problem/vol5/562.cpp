#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[ 25005 ][ 105 ];

int main()
{
    int t, size, coin[ 100 ];
    for( scanf( "%d", &t ); t--; t )
    {
        int total = 0;
        memset( dp, 0, sizeof( dp ) );
        scanf( "%d", &size );
        for( int i = 1; i <= size; ++i  )
            scanf( "%d", coin+i ), total += coin[ i ];
        for( int i = 1; i <= ( total + 1 ) / 2; ++i )
            for( int j = 1; j <= size; ++j )
                if( i >= coin[ j ] )
                    dp[ i ][ j ] = max( dp[ i ][ j-1 ], dp[ i-coin[ j ] ][ j-1 ] + coin[ j ] );
                else
                    dp[ i ][ j ] = dp[ i ][ j-1 ];
        printf( "%d\n", abs( total - dp[ ( total + 1 ) / 2 ][ size ] * 2 ) );
    }
}
