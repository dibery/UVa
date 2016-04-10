#include<cstdio>
#include<cmath>

int main()
{
  for( int a, b, t = 0; scanf( "%d : %d", &a, &b ) == 2; )
  {
	double r = hypot( a, b ) / 2,
		   theta = acos( ( r * r * 2 - b * b ) / ( r * r * 2 ) ),
		   track = a * 2 + r * theta * 2,
		   scale = 400 / track;
	printf( "Case %d: %.10f %.10f\n", ++t, a * scale, b * scale );
  }
}
