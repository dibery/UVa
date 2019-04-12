#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
	int t, size, num[ 15 ];
	vector<int> next( 15, 0 );

	for( scanf( "%d", &t ); t--; )
	{
		set< vector<int> > exist;
		scanf( "%d", &size );
		for( int i = 0; i < size; ++i )
			scanf( "%d", num+i );
		exist.insert( vector<int>( num, num+size ) );
		while( true )
		{
			for( int i = 0; i < size; ++i )
				next[ i ] = abs( num[ i ] - num[ ( i+1 ) % size ] );
			copy( next.begin(), next.end(), num );
			if( exist.find( next ) == exist.end() )
				exist.insert( next );
			else
				break;
		}
		puts( count( next.begin(), next.begin()+size, 0 ) == size? "ZERO" : "LOOP" );
	}
}
