#include<cstdio>
#include<cstring>

bool ok( int n )
{
	char str[ 9 ];

	sprintf( str, "%d", n );
	if( n == 1 )
		return true;
	int len = strlen( str );
	for( int i = 0; i < len; ++i )
		if( str[ i ] != str[ len - i - 1 ] )
			return true;
	for( int i = 2; i*i <= n; ++i )
		if( n % i == 0 )
			return true;
	return false;
}

int main()
{
	for( int n; scanf( "%d", &n ) == 1; )
	{
		printf( "%d\n", n << 1 );
		if( !ok( n ) )
			break;
	}
}
