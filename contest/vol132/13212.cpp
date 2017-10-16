#include<cstdio>
#include<climits>
void msort( int*, int, int ), merge( int*, int, int, int );
long long int inv = 0;

int main()
{
	int size, *data = NULL;

	while( scanf( "%d", &size ) && size )
	{
		data = new int [ size+1 ];
		for( int i = 1; i <= size; ++i )
			scanf( "%d",data+i );
		msort( data, 1, size );
		delete[] data;
		printf( "%lld\n", inv );
		inv = 0;
	}

	return 0;
}

void msort( int *array, int begin, int end )
{
	if( begin >= end )
		return;
	int middle = ( begin+end ) >> 1;

	msort( array, begin, middle );
	msort( array, middle+1, end );
	merge( array, begin, middle, end );
}

void merge( int *array, int begin, int middle, int end )
{
	long long int left = middle-begin+1, right = end-middle;
	int *L = new int[ left+2 ], *R = new int[ right+2 ];

	for( long long int i = 1; i <= left; ++i )
		L[ i ] = array[ begin+i-1 ];
	for( long long int i = 1; i <= right; ++i )
		R[ i ] = array[ middle+i ];
	L[ left+1 ] = R[ right+1 ] = INT_MAX;

	for( long long int i = 1, j = 1, k = begin; k <= end; ++k )
		if( L[ i ] <= R[ j ] )
			array[ k ] = L[ i++ ];
		else
		{
			array[ k ] = R[ j++ ];
			inv += left - i + 1;
		}
	delete[] L;
	delete[] R;
}
