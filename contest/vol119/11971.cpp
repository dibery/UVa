#include<cstdio>

int main()
{
	int cut, t = 0;
	long long int up, down, t = 0, div;

	for( scanf( "%*d" ); scanf( "%*d %d", &cut ) == 1; )
	{
		up = 1ll << cut;
		down = up - cut - 1;
		div = down & -down;
		if( down )
			printf( "Case #%d: %lld/%lld\n", ++t, down / div, up / div );
		else
			printf( "Case #%d: 0/1\n", ++t );
	}
}
