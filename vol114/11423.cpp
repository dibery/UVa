#include<bits/stdc++.h>
using namespace std;

const long long int N = 30, S = 1 << 24, M = 10000001, NPOS = -1;
int cache_limit[ N ], miss[ N ], last[ S+1 ], fenwick[ M ], distinct[ M ];
int size, Begin, Qnt, Interval, serial = 1;

void insert( int begin, int interval = 0, int qnt = 1 )
{
	for( int i = begin, t = 0; t < qnt; i += interval, ++t, ++serial )
		if( !last[ i ] )
		{
			for( int j = 0; j < size; ++j )
				++miss[ j ];
			distinct[ serial ] = distinct[ serial-1 ] + 1;
			for( int index = serial; index <= M; index += ( index & -index ) )
				++fenwick[ index ];
			last[ i ] = serial;
		}
		else
		{
			distinct[ serial ] = distinct[ serial-1 ];
			int prev = 0, index;
			for( index = last[ i ]; index; index -= ( index & -index ) )
				prev += fenwick[ index ];
			int after = distinct[ serial ] - prev, tmp;
			for( int j = 0; cache_limit[ j ] <= after && j < size; ++j )
				++miss[ j ];
			for( index = last[ i ]; index < serial; index += ( index & -index ) )
				--fenwick[ index ];
			for( tmp = index, index = serial; index < tmp; index += ( index & -index ) )
				++fenwick[ index ];
			last[ i ] = serial;
		}
}

int main()
{
	scanf( "%d", &size );
	for( int i = 0; i < size; ++i )
		scanf( "%d", cache_limit+i );

	for( char cmd[ 6 ]; scanf( "%s", cmd ) && *cmd != 'E'; )
		if( *cmd == 'A' )
			scanf( "%d", &Begin ), insert( Begin+1 );
		else if( *cmd == 'R' )
			scanf( "%d %d %d", &Begin, &Interval, &Qnt ), insert( Begin+1, Interval, Qnt );
		else
			for( int i = 0; i < size; ++i )
				printf( "%d%c", miss[ i ], i == size-1? '\n' : ' ' ), miss[ i ] = 0;
}
