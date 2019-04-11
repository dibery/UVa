#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int one( int*, int, int );

int main()
{
	int t;
	for( cin >> t; t--; )
	{
		char tmp[ 100 ];
		cin >> tmp;
		int num[ 100 ][ 100 ], M = 0, calc[ 100 ], len = strlen( tmp );

		for( int i = 0; i < len; i++ )
			num[ 0 ][ i ] = tmp[ i ] - '0';
		for( int i = 1; i < len; i++ )
		{
			cin >> tmp;
			for( int j = 0; j < len; j++ )
				num[ i ][ j ] = tmp[ j ] - '0';
		}

		for( int i = 0; i < len; i++, fill( calc, calc+len, 0 ) )
			for( int j = i; j < len; j++ )
			{
				for( int k = 0; k < len; k++ )
					calc[ k ] += num[ j ][ k ];
				M = max( one( calc, len, j - i + 1 ) * ( j - i + 1 ), M );
			}
		cout << M << ( t? "\n\n" : "\n" );
	}
}

int one( int *array, int size, int num )
{
	int M = 0;
	for( int begin = 0, end = 0; begin < size; begin++ )
		if( array[ begin ] == num )
		{
			for( end = begin; end < size && array[ end ] == num; end++ );
			M = max( M, end - begin );
			begin = end;
		}
	return M;
}
