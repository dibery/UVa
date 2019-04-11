#include<cstdio>
#include<algorithm>
using namespace std;
int sum[ 1000000 ];

int main()
{
    int size, query, num[ 1000 ], target, index, t = 0;

    while( scanf( "%d", &size ) && size )
    {
        index = 0;
        printf( "Case %d:\n", ++t );
        for( int i = 0; i < size; ++i )
            scanf( "%d", num+i );
        for( int i = 0; i < size; ++i )
            for( int j = i+1; j < size; ++j )
                sum[ index++ ] = num[ i ] + num[ j ];
        sort( sum, sum+index );
        scanf( "%d", &query );
        for( int i = 0; i < query; ++i )
        {
            scanf( "%d", &target );
            int *a = lower_bound( sum, sum+index, target ), *b = upper_bound( sum, sum+index, target );
            while( *a > target && a != sum )
                --a;
            if( index == 1 || target <= *sum )
                a = b = sum;
            if( target >= sum[ index-1 ] )
                a = b = &sum[ index-1 ];
            printf( "Closest sum to %d is %d.\n", target, target-*a < *b-target? *a : *b );
        }
    }

    return 0;
}
