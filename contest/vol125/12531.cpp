#include<cstdio>
#include<cstdlib>

int main()
{
	int n;
	bool judge[ 180 ] = { false };

	for( int h = 0; h < 12; ++h )
		for( int m = 0; m < 60; ++m )
			judge[ abs( h - m ) <= 30? abs( h - m ) * 6 : ( 60 - abs( h - m ) ) * 6 ] = true;

	while( scanf( "%d", &n ) == 1 )
		puts( judge[ n % 180 ]? "Y" : "N" );
}
