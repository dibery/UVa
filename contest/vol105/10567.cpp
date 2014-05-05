#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
char in[ 1000001 ], query[ 101 ];

int main()
{
    int q;
    vector<int> stat[ 128 ];
    gets( in );
    scanf( "%d\n", &q );

    for( int i = 0; in[ i ]; ++i )
        stat[ in[ i ] ].push_back( i );

    for( int k = 0; k < q; ++k )
    {
        gets( query );
        int end = -1, start = -1;
        bool stop = false;
        vector<int>::iterator it;
        for( int i = 0; query[ i ] && !stop; ++i )
        {
            end = stat[ query[ i ] ][ ( it = upper_bound( stat[ query[ i ] ].begin(), stat[ query[ i ] ].end(), end ) ) - stat[ query[ i ] ].begin() ];
            if( it == stat[ query[ i ] ].end() )
                stop = true;
            if( !i )
                start = end;
        }
        if( stop )
            puts( "Not matched" );
        else
            printf( "Matched %d %d\n", start, end );
    }

	return 0;
}