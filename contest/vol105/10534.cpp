#include<cstdio>
#include<algorithm>
using namespace std;

void process( int n[], int size, int seq[], int pos[] )
{
	int len = 1;
	for( int i = 1; i < size; ++i )
		if( n[ i ] > seq[ len-1 ] )
		{
			seq[ len++ ] = n[ i ];
			pos[ i ] = len;
		}
		else
		{
			int* ins = lower_bound( seq, seq+len, n[ i ] );
			*ins = n[ i ];
			pos[ i ] = ins - seq;
		}
}
int main()
{
	int size, n[ 10000 ];

	while( scanf( "%d", &size ) == 1 )
	{
		int lis[ 10000 ] = { 1 }, lds[ 10000 ] = { 1 }, seq[ 10000 ] = { 0 }, ans = 0;

		for( int i = 0; i < size; ++i )
			scanf( "%d", n+i );

		*seq = *n;
		process( n, size, seq, lis );
		fill( seq+1, seq+10000, 0 );
		reverse( n, n+size );
		*seq = *n;
		process( n, size, seq, lds );
		reverse( lds, lds+size );

		for( int i = 0; i < size; ++i )
			ans = max( ans, min( lis[ i ], lds[ i ] ) );
		printf( "%d\n", max( ans * 2 - 1, 1 ) );
	}
}
