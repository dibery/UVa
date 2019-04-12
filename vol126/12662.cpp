#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int qnt, pos[ 100 ] = { 0 }, in, size = 0;
	char *student[ 102 ] = { NULL }, tmp[ 4 ];
	scanf( "%d", &qnt );
	for( int i = 0; i < qnt; ++i )
	{
		scanf( "%s", tmp );
		student[ i ] = strdup( tmp );
	}
	for( int i = 0; i < qnt; ++i )
		if( strcmp( student[ i ], "?" ) )
			pos[ size++ ] = i;
	scanf( "%*d" );
	while( scanf( "%d", &in ) == 1 && in-- )
		if( strcmp( student[ in ], "?" ) )
			printf( "%s\n", student[ in ] );
		else
		{
			int *low = lower_bound( pos, pos+size, in ), *high = upper_bound( pos, pos+size, in );
			if( *low != in )
				--low;
			if( in < *pos )
			{
				while( in++ < *pos )
					printf( "left of " );
				printf( "%s\n", student[ *pos ] );
			}
			else if( in > pos[ size-1 ] )
			{
				while( in-- > pos[ size-1 ] )
					printf( "right of " );
				printf( "%s\n", student[ pos[ size-1 ] ] );
			}
			else if( in - *low == *high - in )
				printf( "middle of %s and %s\n", student[ *low ], student[ *high ] );
			else if( in - *low > *high - in )
			{
				while( in++ < *high )
					printf( "left of " );
				printf( "%s\n", student[ *high ] );
			}
			else
			{
				while( in-- > *low )
					printf( "right of " );
				printf( "%s\n", student[ *low ] );
			}
		}
	return 0;
}
