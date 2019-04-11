#include<cstdio>
#include<algorithm>
#include<sstream>
using namespace std;
const int INF = 1e9;
char c[ 10000 ];
double unit, price[ 21 ];
int sets, qnt[ 21 ] = { 1 }, ask;

double find( double pay[], int q )
{
	if( q <= 0 )
		return 0;
	if( pay[ q ] < INF )
		return pay[ q ];
	for( int i = 0; i <= sets; ++i )
		pay[ q ] = min( pay[ q ], price[ i ] + find( pay, q - qnt[ i ] ) );
	return pay[ q ];
}

int main()
{
	for( int t = 0; scanf( "%lf %d\n", price, &sets ) == 2; )
	{
		for( int i = 1; i <= sets; ++i )
			scanf( "%d %lf\n", qnt + i, price + i );

		double pay[ 101 ];

		for( int i = 0; i <= 100; ++i )
			pay[ i ] = INF;
		find( pay, 100 );

		printf( "Case %d:\n", ++t );
		for( stringstream ss( gets( c ) ); ss >> ask; )
			printf( "Buy %d for $%.2f\n", ask, pay[ ask ] );
	}
}
