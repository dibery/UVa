#include<cstdio>
#include<algorithm>
#define INT_MAX ( ( 1 << 30 ) - 1 )
using namespace std;
int move[ 4 ][ 4 ] = { { -3, -1, 4, -4 }, { 1, 3, 4, -4 }, { 1, -1, 4, -4 }, { 1, -1, 4, -4 } }, dist[ 41 ][ 41 ];
bool A_star( int* pos, int king, int size, int currentEstimate, int costToEnd, int spentCost = 0, int last = -1 )
{
	if( !costToEnd )
		return true;
	if( costToEnd + spentCost > currentEstimate )
		return false;
	for( int i = 0; i < 4; ++i )
	{
		int newPos = king + move[ king % 4 ][ i ];
		if( newPos > 0 && newPos <= size && newPos != last )
		{
			int newCost = costToEnd - dist[ pos[ newPos ] ][ newPos ] + dist[ pos[ newPos ] ][ king ];
			swap( pos[ king ], pos[ newPos ] );
			if( A_star( pos, newPos, size, currentEstimate, newCost, spentCost+1, king ) )
				return true;
			swap( pos[ king ], pos[ newPos ] );
		}
	}
	return false;
}

int main()
{
    int size, pos[ 41 ], t = 0, king;
    for( int i = 1; i <= 40; ++i )
		for( int j = 1; j <= 40; ++j )
			dist[ i ][ j ] = i == j ? 0 : INT_MAX;
	for( int i = 1; i <= 40; ++i )
		for( int j = 0; j < 4; ++j )
			if( i + move[ i % 4 ][ j ] <= 40 && i + move[ i % 4 ][ j ] > 0 )
				dist[ i ][ i + move[ i % 4 ][ j ] ] = dist[ i + move[ i % 4 ][ j ] ][ i ] = 1;
	for( int i = 1; i <= 40; ++i )
		for( int j = 1; j <= 40; ++j )
			for( int k = 1; k <= 40; ++k )
				dist[ i ][ j ] = min( dist[ i ][ j ], dist[ i ][ k ] + dist[ k ][ j ] );

    while( scanf( "%d", &size ) && size )
    {
        int estimatedCostToEnd = 0;
        bool found = false;

        for( int i = 1; i <= size; ++i )
            scanf( "%d", pos+i );
        for( int i = 1; i <= size; ++i )
			if( pos[ i ] == 1 )
				king = i;
			else
				estimatedCostToEnd += dist[ i ][ pos[ i ] ];
        for( int jump = 0; !found; ++jump )
			if( found = A_star( pos, king, size, jump, estimatedCostToEnd ) )
				printf( "Set %d:\n%d\n", ++t, jump );
    }
    return 0;
}
