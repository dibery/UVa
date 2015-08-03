#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	for( int size, n, t = 0; scanf( "%d", &size ) && size; )
	{
		int sum[ 5 ] = { 0 };

		for( int i = 0; i < size; ++i )
			for( int j = 0; j < size; ++j )
			{
				scanf( "%d", &n );
				if( size % 2 )
					sum[ max( abs( i - size / 2 ), abs( j - size / 2 ) ) ] += n;
				else
					sum[ max( abs( i * 2 - size + 1 ), abs( j * 2 - size + 1 ) ) / 2 ] += n;
			}
		
		printf( "Case %d: ", ++t );
		for( int i = ( size - 1 ) / 2; i >= 0; --i )
			printf( "%d%c", sum[ i ], i? ' ' : '\n' );
	}
}
