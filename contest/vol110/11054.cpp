#include<cstdio>
#include<cstdlib>

int main()
{
	int size;
	
	while( scanf( "%d", &size ) && size )
	{
		int val[ 100000 ] = { 0 };
		long long int work = 0;
		
		for( int i = 0; i < size; ++i )
			scanf( "%d", val+i );
		for( int i = 0; i < size; ++i )
			if( val[ i ] )
				work += abs( val[ i ] ), val[ i+1 ] += val[ i ];
		printf( "%lld\n", work );
	}
}
