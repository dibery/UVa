#include<cstdio>
#include<algorithm>
using namespace std;
int add( int a, int b ) { return a+b; }
int min( int a, int b ) { return a-b; }
int mul( int a, int b ) { return a*b; }
int ( *fn[ 3 ] ) ( int a, int b ) = { add, min, mul };
char op[] = { "+-*" };
bool judge( int* n )
{
	do
		for( int a = 0; a < 3; ++a )
			for( int b = 0; b < 3; ++b )
				for( int c = 0; c < 3; ++c )
					for( int d = 0; d < 3; ++d )
						if( fn[d]( fn[c]( fn[b]( fn[a]( n[0], n[1] ), n[2] ), n[3] ), n[4] ) == 23 )
							return true;
	while( next_permutation( n, n+5 ) );
	return false;
}

int main()
{
	int num[ 5 ];
	while( scanf( "%d %d %d %d %d", num, num+1, num+2, num+3, num+4 ) && *num )
		sort( num, num+5 ), puts( judge( num )? "Possible" : "Impossible" );
}
