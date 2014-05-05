#include<cstdio>
#include<algorithm>

int main()
{
	int t, need[ 26 ] = { 0 };
	char ingre[ 601 ];
	need[ 0 ] = 3;
	need[ 6 ] = need[ 8 ] = need[ 12 ] = need[ 19 ] = 1;
	need[ 17 ] = 2;
	scanf( "%d\n", &t );

	while( t-- )
	{
		int has[ 26 ] = { 0 }, can = 100;
		gets( ingre );
		for( int i = 0; ingre[ i ]; ++i )
			++has[ ingre[ i ] - 'A' ];
		for( int i = 0; i < 20; ++i )
			if( need[ i ] )
				can = std::min( can, has[ i ] / need[ i ] );
		printf( "%d\n", can );
	}

	return 0;
}
