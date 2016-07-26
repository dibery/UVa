#include<bits/stdc++.h>
using namespace std;

const int N = 5001;
int GCD[ N ][ N ], size = 3;
int gcd( int a, int b ) { return a % b? GCD[ b ][ a % b ] : b; }
bool trouble[ N ][ N ];

struct frac
{
	long long x, y;
	frac( long long u = 0, long long d = 0 ) : x( u ), y( d ) {}
	bool operator< ( const frac& f ) const { return x * f.y < y * f.x; }
	bool operator> ( const frac& f ) const { return f < *this; }
	long long sq_dot( const frac& f ) const { return ( x * f.x + y * f.y ) * ( x * f.x + y * f.y ); }
	long long len() const { return x * x + y * y; }
} line[ 15201000 ];

long double cos( frac& a, frac& b )
{
	return ( ( a.x * b.x + a.y * b.y ) / sqrt( (long double) ( ( a.x * a.x + a.y * a.y ) * ( b.x * b.x + b.y * b.y ) ) ) );
	//return ( ( a.x * b.x + a.y * b.y ) ) / ( hypot( (long double) a.x, a.y ) * hypot( (long double) b.x, b.y ) );
}

double angle( frac& a, frac& b ) { return acos( cos( a, b ) ); }

int main()
{
	//freopen( ".test", "r", stdin );
	line[ 0 ] = frac( 1, 0 );
	line[ 1 ] = frac( 0, 1 );
	line[ 2 ] = frac( 1, 1 );
	for( int i = 1; i < N; ++i )
		for( int j = i + 1; j < N; ++j )
			if( ( GCD[ i ][ j ] = GCD[ j ][ i ] = gcd( j, i ) ) == 1 )
				line[ size++ ] = frac( i, j ), line[ size++ ] = frac( j, i );
	sort( line, line + size, greater<frac>() );

	int n, t;
	long long k;

	for( scanf( "%d", &t ); t-- && scanf( "%d %lld", &n, &k ); )
	{
		memset( trouble, false, sizeof( trouble ) );
		//long double cos_limit = sqrt( k * k / ( k * k + 1 ) )
		//long long lim_up = k * k, lim_down = k * k + 1;
		frac limit( k * k, k * k + 1 );
		//double limit = atan( 1 / k );
		int ans = 0;

		for( int i = 0; i < size; ++i )
			if( line[ i ].x <= n && line[ i ].y <= n )
				for( int j = i + 1, first = true; j < size; ++j )
					if( line[ j ].x <= n && line[ j ].y <= n )
						//if( cos( line[ i ], line[ j ] ) > cos_limit )
						//if( angle( line[ i ], line[ j ] ) <= limit )
						if( limit < frac( line[ i ].sq_dot( line[ j ] ), line[ i ].len() * line[ j ].len() ) )
						{
							//printf( "(%3lld,%3lld) (%3lld,%3lld)\n", line[ i ].x, line[ i ].y, line[ j ].x, line[ j ].y );
							if( first )
								for( int x = 0, y = 0; x <= n && y <= n; x += line[ i ].x, y += line[ i ].y )
									trouble[ x ][ y ] = true;
							for( int x = 0, y = 0; x <= n && y <= n; x += line[ j ].x, y += line[ j ].y )
								trouble[ x ][ y ] = true;
							first = false;
						}
						else
							break;
		**trouble = false;
		for( int i = 0; i <= n; ++i )
			for( int j = 0; j <= n; ++j )
				if( trouble[ i ][ j ] && trouble[ n - i ][ j ] )
					++ans;//, printf( "(%3d,%3d) (%3d,%3d)\n", i, j, n - i, j );
		printf( "%d\n", ans );
	}
}
