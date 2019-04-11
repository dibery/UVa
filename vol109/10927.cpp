#include<bits/stdc++.h>
using namespace std;

int gcd( int a, int b )
{
	if( a && b )
		return a % b? gcd( b, a % b ) : b;
	else
		return max( a, b );
}

struct laser
{
	long long int x, y, z, dx, dy;
	bool operator< ( const laser& L ) const
	{
		if( dx != L.dx )
			return dx < L.dx;
		if( dy != L.dy )
			return dy < L.dy;
		return x * x + y * y < L.x * L.x + L.y * L.y;
	}
	laser( int X, int Y, int Z ): x( X ), y( Y ), z( Z )
	{
		int N = gcd( abs( X ), abs( Y ) );
		dx = x / N;
		dy = y / N;
	}
};

int main()
{
	for( int size, t = 0; scanf( "%d", &size ) && size; )
	{
		vector<laser> pole, block;

		for( int i = 0, x, y, z; i < size; ++i )
			scanf( "%d %d %d", &x, &y, &z ), pole.push_back( laser( x, y, z ) );
		sort( pole.begin(), pole.end() );

		for( size_t i = 0, j = 0; j < pole.size(); j = i )
			for( long long h = -1; pole[ i ].dx == pole[ j ].dx && pole[ i ].dy == pole[ j ].dy; h = max( h, pole[ i++ ].z ) )
				if( pole[ i ].z <= h )
					block.push_back( pole[ i ] );
		if( block.empty() )
			printf( "Data set %d:\nAll the lights are visible.\n", ++t );
		else
		{
			printf( "Data set %d:\nSome lights are not visible:\n", ++t );
			sort( block.begin(), block.end(), [] ( const laser& a, const laser& b ) { return a.x != b.x? a.x < b.x : a.y < b.y; } );
			for( size_t i = 0; i < block.size(); ++i )
				printf( "x = %lld, y = %lld%c\n", block[ i ].x, block[ i ].y, i == block.size() - 1? '.' : ';' );
		}
	}
}
