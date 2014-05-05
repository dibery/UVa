#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int weight[ 1000000 ];

int main()
{
    int size, t = 0;

    while( scanf( "%d", &size ) && size && ++t )
    {
        if( t != 1 )
            puts( "" );
        int pack[ size ], M = 0;
        memset( weight, 0, sizeof( weight ) );
        for( int i = 0; i < size; ++i )
        {
            scanf( "%d", pack+i );
            ++weight[ pack[ i ] ];
            M = max( M, weight[ pack[ i ] ] );
        }
        sort( pack, pack+size );
        printf( "%d\n", M );
        for( int i = 0; i < M; ++i )
        {
            printf( "%d", pack[ i ] );
            for( int j = i+M; j < size; j += M )
                printf( " %d", pack[ j ] );
            puts( "" );
        }
    }

	return 0;
}