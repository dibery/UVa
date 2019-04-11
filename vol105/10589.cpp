#include<cstdio>
#include<cmath>
inline bool ok( double x, double y, int lim ) { return x*x + y*y <= lim; }

int main()
{
	int point, len;
	double x, y;

	while( scanf( "%d %d", &point, &len ) && point )
	{
		int in = 0;

		for( int i = 0; i < point; ++i )
		{
			scanf( "%lf %lf", &x, &y );
			if( ok( x, y, len*len ) && ok( len-x, y, len*len ) && ok( len-x, len-y, len*len ) && ok( x, len-y, len*len ) )
				++in;
		}
		printf( "%.05f\n", len * len * in / (double)point + 1e-12 );
	}

	return 0;
}
