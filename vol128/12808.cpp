#include<cstdio>
#include<cmath>

int main()
{
	double L, D, H, V, T, fly;
	int t;

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%lf %lf %lf %lf", &L, &D, &H, &V );
		L /= 1000, D /= 1000, H /= 1000, V /= 1000;
		fly = ( T = sqrt( H / 4.905 ) ) * V;
		if( fly < D-0.5 || fly > D+L+0.5 )
			puts( "FLOOR" );
		else if( fly > D+0.5 && fly < D+L-0.5 )
			puts( "POOL" );
		else
			puts( "EDGE" );
	}
}
