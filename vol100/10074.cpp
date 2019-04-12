#include<iostream>
#include<algorithm>
using namespace std;
int zero( int*, int );

int main()
{
	int h, w;
	while( cin >> h >> w && h+w )
	{
		int num[ 100 ][ 100 ], M = 0, calc[ 100 ];

		for( int i = 0; i < h; i++ )
			for( int j = 0; j < w; j++ )
				cin >> num[ i ][ j ];

		for( int i = 0; i < h; i++, fill( calc, calc+w, 0 ) )
			for( int j = i; j < h; j++ )
			{
				for( int k = 0; k < w; k++ )
					calc[ k ] += num[ j ][ k ];
				M = max( zero( calc, w ) * ( j - i + 1 ), M );
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
