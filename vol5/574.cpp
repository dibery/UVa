#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct node
{
    int len, stack[ 12 ];
};
int call[ 12 ], put;
bool sol;
vector<node> prev;
bool cmp( int a, int b ) { return a > b; }
bool repeat( const int *ele )
{
    for( int i = prev.size()-1, k = 0; i >= 0; --i, k = 0 )
    {
        if( prev[ i ].len == put )
            for( k = 0; k < put; ++k )
                if( ele[ call[ k ] ] != prev[ i ].stack[ k ] )
                    break;
        if( k == put )
            return true;
    }
    return false;
}
void bt( const int target, const int index, const int total, const int *ele )
{
    call[ put++ ] = index;
    if( !target )
    {
        if( repeat( ele ) )
        {
            call[ --put ] = 0;
            return;
        }
        printf( "%d", ele[ *call ] );
        for( int i = 1; i < put; ++i )
            printf( "+%d", ele[ call[ i ] ] );
        node a;
        a.len = put;
        for( int i = 0; i < put; ++i )
            a.stack[ i ] = ele[ call[ i ] ];
        prev.push_back( a );
        puts( "" );
        call[ --put ] = 0;
        sol = true;
        return;
    }
    for( int i = index+1; i < total; ++i )
        if( target >= ele[ i ] )
            bt( target-ele[ i ], i, total, ele );
    call[ --put ] = 0;
}

int main()
{
    int target, quant, element[ 12 ];

    while( scanf( "%d %d", &target, &quant ) && target )
    {
        sol = false;
        put = 0;
        memset( call, 0, sizeof( call ) );
        printf( "Sums of %d:\n", target );
        for( int i = 0; i < quant; ++i )
            scanf( "%d", element+i );
        sort( element, element+quant, cmp );
        for( int i = 0; i < quant; ++i )
            if( target >= element[ i ] )
                bt( target-element[ i ], i, quant, element );
        if( !sol )
            puts( "NONE" );
        prev.clear();
    }

	return 0;
}