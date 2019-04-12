#include<iostream>
#include<algorithm>
using namespace std;
int zero( int*, int );

int main()
{
	int size, t, block, x, y, X, Y;

	for( cin >> t; t; --t )
	{
		int M = 0, calc[ 100 ], brd[ 100 ][ 100 ] = { 0 };

		cin >> size >> block;
		for( int i = 0; i < block; ++i )
		{
			cin >> x >> y >> X >> Y;
			for( int m = x-1; m < X; ++m )
				for( int n = y-1; n < Y; ++n )
					brd[ m ][ n ] = 1;
		}

		for( int i = 0; i < size; i++, fill( calc, calc+size, 0 ) )
			for( int j = i; j < size; j++ )
			{
				for( int k = 0; k < size; k++ )
					calc[ k ] += brd[ j ][ k ];
				M = max( zero( calc, size ) * ( j - i + 1 ), M );
			}
		cout << M << endl;
	}
}

int zero( int *array, int size )
{
	int M = 0;
	for( int begin = 0, end = 0; begin < size; begin++ )
		if( begin == 0 || array[ begin-1 ] )
		{
			for( end = begin; end < size && array[ end ] == 0; end++ );
			M = max( M, end - begin );
			begin = end;
		}
	return M;
}
