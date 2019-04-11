#include<iostream>
#include<algorithm>
using namespace std;
int Kadane( int* ), size;

int main()
{
	cin >> size;
	while( cin >> size )
	{
		int num[ 150 ][ 150 ], M = 0;

		for( int i = 0; i < size; i++ )
			for( int j = 0; j < size; j++ )
			{
				cin >> num[ i ][ j ];
				num[ i ][ j+size ] = num[ i+size ][ j ] = num[ i+size ][ j+size ] = num[ i ][ j ];
			}

		for( int i = 0; i < size; i++ )
		{
			int calc[ 150 ] = { 0 };
			for( int j = i; j < size + i; j++ )
			{
				for( int k = 0; k < size * 2; k++ )
					calc[ k ] += num[ j ][ k ];
				M = max( Kadane( calc ), M );
			}
		}
		cout << M << endl;
	}
}

int Kadane( int *array )
{
	int sum = 0, max = 0;
	for( int i = 0; i < size; i++, sum = 0 )
		for( int j = i; j < size + i; j++ )
		{
			sum += array[ j ];
			if( sum > max )
				max = sum;
			if( sum < 0 )
				sum = 0;
		}
	return max;
}
