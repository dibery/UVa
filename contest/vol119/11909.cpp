#include<cstdio>
#include<cmath>
const double pi = acos( -1 );
inline double rad( int theta ) { return theta * pi / 180; }

int main()
{
	int len, wid, high, theta;

	while( scanf( "%d %d %d %d", &len, &wid, &high, &theta ) == 4 )
		if( len * tan( rad( theta ) ) <= high )
			printf( "%.3f mL\n", wid * ( len * high - len * len * tan( rad( theta ) ) / 2 ) );
		else
			printf( "%.3f mL\n", wid * high / tan( rad( theta ) ) * high / 2 );
}
