#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int total, query, number[ 10000 ], in, t = 0;

    while( scanf( "%d %d", &total, &query ) && ( total + query ) )
    {
        for( int i = 0; i < total; ++i )
            scanf( "%d", number+i );
        sort( number, number+total );
        printf( "CASE# %d:\n", ++t );
        for( int i = query; i; --i )
        {
            scanf( "%d", &in );
            if( binary_search( number, number+total, in ) )
                printf( "%d found at %d\n", in, lower_bound( number, number+total, in ) - number + 1 );
            else
                printf( "%d not found\n", in );
        }
    }

	return 0;
}