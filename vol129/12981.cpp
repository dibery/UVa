#include<cstdio>
#include<algorithm>
using namespace std;

inline void rotate( int n[] )
{
	int c[] = { n[ 1 ], n[ 3 ], n[ 0 ], n[ 2 ] };
	copy( c, c + 4, n );
}

int main()
{
	int t = 0, n[ 4 ], m[ 4 ];

	for( scanf( "%*d" ); scanf( "%d %d %d %d", n, n+1, n+2, n+3 ) == 4; )
	{
		bool ok = false;

		scanf( "%d %d %d %d", m, m+1, m+2, m+3 );
		for( int i = 0; i < 4; ++i )
		{
			rotate( n );
			ok |= mismatch( n, n + 4, m ).first == n + 4;
		}
		printf( "Case #%d: %sPOSSIBLE\n", ++t, ok? "" : "IM" );
	}
}
