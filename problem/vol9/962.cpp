#include<cstdio>
#include<algorithm>
using namespace std;
int allcube[ 1005 ], taxicab[ 505520 ] = { 0 };

int main()
{
    int low, range, all = 0;
    for( int i = 1; i <= 1005; ++i )
        allcube[ i-1 ] = i*i*i;
    for( int i = 0; i < 1005; ++i )
        for( int j = i; j < 1005; ++j )
            taxicab[ all++ ] = allcube[ i ] + allcube[ j ];
    sort( taxicab, taxicab+all );

    while( scanf( "%d %d", &low, &range ) != EOF )
    {
        bool out = false;
        int *begin = lower_bound( taxicab, taxicab+all, low ), *end = upper_bound( taxicab, taxicab+all, low+range );
        for( int *ptr = begin; ptr != end; ++ptr )
            if( ( ptr == taxicab || *ptr != *( ptr-1 ) ) && *ptr == *( ptr+1 ) )
                out = true, printf( "%d\n", *ptr );
        if( !out )
            puts( "None" );
    }

    return 0;
}
