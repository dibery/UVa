#include<cstdio>
bool self[ 1000001 ] = { false };
int d( int i )
{
	int back = i;
	while( i )
		back += i % 10, i /= 10;
	return back;
}

int main()
{
	for( int i = 1; i <= 1000000; ++i )
		if( !self[ i ] )
			for( int tmp = d( i ); tmp <= 1000000 && !self[ tmp ]; tmp = d( tmp ) )
				self[ tmp ] = true;
	for( int i = 1; i <= 1000000; ++i )
		if( !self[ i ] )
			printf( "%d\n", i );
	return 0;
}
