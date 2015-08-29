#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

bool tie( int v[][ 100 ], int a, int b, int c )
{ return !v[ a ][ b ] && !v[ a ][ c ] && !v[ b ][ c ]; }

bool cycle( int v[][ 100 ], int a, int b, int c )
{
	return v[ a ][ b ] == 1 && v[ b ][ c ] == 1 && v[ c ][ a ] == 1 ||
		v[ a ][ c ] == 1 && v[ c ][ b ] == 1 && v[ b ][ a ] == 1;
}

int main()
{
	for( int size; scanf( "%d", &size ) == 1; )
	{
		int v[ 100 ][ 100 ] = { { 0 } };
		vector<int> pending;

		for( int i = 0; i < size; ++i )
			for( int j = 0; j < size; ++j )
				scanf( "%d", v[ i ] + j );
		for( int i = 0; i < size; ++i )
			for( int j = 0; j < i; ++j )
				if( v[ i ][ j ] == 1 )
					v[ j ][ i ] = -1;
				else if( v[ j ][ i ] == 1 )
					v[ i ][ j ] = -1;
		for( int i = 0; i < size; ++i )
			for( int j = i + 1; j < size; ++j )
				for( int k = j + 1; k < size; ++k )
					if( tie( v, i, j, k ) )
						pending.push_back( i * 10000 + j * 100 + k );
					else if( cycle( v, i, j, k ) )
						if( v[ i ][ j ] == 1 )
							pending.push_back( i * 10000 + j * 100 + k );
						else
							pending.push_back( k * 10000 + j * 100 + i );
		sort( pending.begin(), pending.end() );
		printf( "%u\n", pending.size() );
		for( int i: pending )
			printf( "%d %d %d\n", i / 10000 + 1, i / 100 % 100 + 1, i % 100 + 1 );
	}
}
