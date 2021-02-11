#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N = 5608, size[ N ] = { INT_MAX }, id = 0;
	pair<int,int> box[ N ];
	fill( size + 1, size + N, -1 );
	while( scanf( "%d %d", &box[ id ].second, &box[ id ].first ) == 2 )
		++id;
	sort( box, box + id );
	reverse( box, box + id );
	for( int j = 0; j < id; ++j )
		for( int i = N - 1; i; --i )
			if( ~size[ i - 1 ] )
				size[ i ] = max( size[ i ], min( size[ i - 1 ], box[ j ].first ) - box[ j ].second );
	for( int i = 5607; i; --i )
		if( ~size[ i ] )
			printf( "%d\n", i ), i = 1;
}
