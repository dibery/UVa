#include<cstdio>
#include<climits>
#include<algorithm>

bool use[ 30 ], ans[ 30 ];
int pair[ 450 ][ 2 ], vertex, edge, qnt, t;

void dfs( int index = 0, int used = 0 )
{
	if( used > qnt )
		return;
	if( index == edge )
	{
		if( used < qnt )
			qnt = used, std::copy( use, use+vertex, ans );
		return;
	}
	if( use[ pair[ index ][ 0 ] ] || use[ pair[ index ][ 1 ] ] )
		dfs( index+1, used );
	else
	{
		use[ pair[ index ][ 0 ] ] = true;
		dfs( index+1, used+1 );
		use[ pair[ index ][ 0 ] ] = false;
		use[ pair[ index ][ 1 ] ] = true;
		dfs( index+1, used+1 );
		use[ pair[ index ][ 1 ] ] = false;
	}
}

int main()
{
	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d %d", &vertex, &edge );
		for( int i = 0; i < edge; ++i )
			scanf( "%d %d", pair[ i ], pair[ i ]+1 );

		std::fill( use, use+vertex, false );
		std::fill( ans, ans+vertex, false );
		qnt = INT_MAX;
		dfs();

		bool first = true;
		printf( "Case #%d: %d\n", n, qnt );
		for( int i = 0; i < vertex; ++i )
			if( ans[ i ] )
				printf( "%s%d", first? "" : " ", i ), first = false;
		puts( "" );
	}
}
