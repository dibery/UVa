#include<cstdio>

int main()
{
	int t, hb, mb, he, me, HB, MB, HE, ME;
	scanf( "%d", &t );

	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d:%d %d:%d %d:%d %d:%d", &hb, &mb, &he, &me, &HB, &MB, &HE, &ME );
		if( HB > he || HB == he && MB >= me || hb > HE || hb == HE && mb > ME )
			printf( "Case %d: Hits Meeting\n", n );
		else
			printf( "Case %d: Mrs Meeting\n", n );
	}
}
