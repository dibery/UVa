#include<cstdio>
#include<cstring>
#include<algorithm>

int hamming( char* db, char* m, int size )
{
	int d = 0;
	for( int i = 0; i < size; ++i )
		d += db[ i ] != m[ i ];
	return d;
}

int diff( char* db, char* m )
{
	int d = 9999, len = strlen( db ), Len = strlen( m );
	for( int i = 0; i+Len <= len; ++i )
		d = std::min( d, hamming( db+i, m, Len ) );
	return d;
}

int main()
{
	char db[ 1000 ][ 101 ], movie[ 1001 ];
	int size, qnt;

	scanf( "%d %d\n", &size, &qnt );
	for( int i = 0; i < size; ++i )
		gets( db[ i ] );
	for( int n = 0; n < qnt; ++n )
	{
		gets( movie );
		int dist = 9999, id;
		for( int i = 0; i < size; ++i )
			if( diff( db[ i ], movie ) < dist )
				id = i, dist = diff( db[ i ], movie );
		printf( "%d\n", id+1 );
	}
}
