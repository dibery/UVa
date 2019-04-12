#include<cstdio>
#include<numeric>
using namespace std;

bool ok( int type, int meal, int togo[], int me[] )
{
	if( accumulate( togo, togo + type, 0 ) > meal )
		return false;
	for( int i = 0; i < type; ++i )
		if( me[ i ] < togo[ i ] )
			return false;
	return true;
}

int main()
{
	int t, togo[ 10 ], me[ 10 ], type, meal;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d %d", &type, &meal );
		for( int i = 0; i < type; ++i )
			scanf( "%d", togo + i );
		for( int i = 0; i < type; ++i )
			scanf( "%d", me + i );

		printf( "Case %d: %s\n", n, ok( type, meal, togo, me )? "Yes" : "No" );
	}
}
