#include<bits/stdc++.h>

void next( char* s )
{
	char tmp[ 2000 ] = { 0 }, *p = tmp;
	for( int i = 0; s[ i ]; )
	{
		int len;
		for( len = 0; s[ i + len ] == s[ i ]; ++len );
		sprintf( p, "%d", len );
		p += strlen( p );
		*p++ = s[ i ];
		i += len;
		if( p - tmp > 1800 )
			break;
	}
	strcpy( s, tmp );
}

int main()
{
	char buffer[ 2000 ];
	int digit, index, x1;

	while( scanf( "%d %d %d", &x1, &index, &digit ) && x1 )
	{
		sprintf( buffer, "%d", x1 );
		for( int i = 2; i <= index; ++i )
			next( buffer );
		printf( "%c\n", buffer[ digit-1 ] );
	}
}
