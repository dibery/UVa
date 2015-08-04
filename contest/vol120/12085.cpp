#include<cstdio>
#include<cstring>
#include<algorithm>

int main()
{
	int size, phone[ 100000 ], t = 0;

	while( scanf( "%d", &size ) && size )
	{
		for( int i = 0; i < size; ++i )
			scanf( "%d", phone+i );
		printf( "Case %d:\n", ++t );
		for( int i = 0; i < size; ++i )
			if( i == size-1 || phone[ i ] + 1 != phone[ i+1 ] )
				printf( "0%d\n", phone[ i ] );
			else
			{
				int e;
				char begin[ 20 ] = { 0 }, end[ 20 ] = { 0 };
				for( e = i; phone[ e ] + 1 == phone[ e+1 ] && e < size-1; ++e );
				sprintf( begin, "%d", phone[ i ] );
				sprintf( end, "%d", phone[ e ] );
				printf( "0%d-", phone[ i ] );
				puts( std::mismatch( begin, begin + strlen( begin ), end ).second );
				i = e;
			}
		puts( "" );
	}
}
