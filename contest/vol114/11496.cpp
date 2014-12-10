#include<cstdio>

int main()
{
	int music[ 10001 ], size;

	while( scanf( "%d", &size ) && size )
	{
		for( int i = 0; i < size; ++i )
			scanf( "%d", music+i );
		int peak = 0;
		for( int i = 0; i < size; ++i )
			if( music[ (i+size-1) % size ] < music[ i ] == music[ (i+1) % size ] < music[ i ] )
				++peak;
		printf( "%d\n", peak );
	}
}
