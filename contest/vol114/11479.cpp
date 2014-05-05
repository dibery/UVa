#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    long long int test, edge[ 3 ];
    scanf( "%lld", &test );

    for( int i = 1; i <= test; ++i )
    {
        scanf( "%lld %lld %lld", edge, edge+1, edge+2 );
        sort( edge, edge+3 );
        printf( "Case %d: ", i );
        if( *edge <= 0 || edge[ 0 ] + edge[ 1 ] <= edge[ 2 ] )
            printf( "Invalid\n" );
        else if( edge[ 0 ] == edge[ 2 ] )
            printf( "Equilateral\n" );
        else if( edge[ 1 ] == edge[ 2 ] || edge[ 1 ] == edge[ 0 ] )
            printf( "Isosceles\n" );
        else
            printf( "Scalene\n" );
    }

	return 0;
}