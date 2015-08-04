#include<cstdio>

void bst( int q, int h, int offset = 0 )
{
	if( !q )
		return;
	else if( q <= 1 << h-1 )
		printf( " %d", offset+1 ), bst( q-1, h-1, offset+1 );
	else
	{
		printf( " %d", q - ( 1 << h-1 ) + offset + 1 );
		bst( q - ( 1 << h-1 ), h-1, offset );
		bst( ( 1 << h-1 ) - 1, h-1, offset + q - ( 1 << h-1 ) + 1 );
	}
}

int main()
{
	int qnt, h, t = 0;

	while( scanf( "%d %d", &qnt, &h ) && qnt )
		if( qnt >= 1 << h )
			printf( "Case %d: Impossible.\n", ++t );
		else
			printf( "Case %d:", ++t ), bst( qnt, h ), puts( "" );
}
