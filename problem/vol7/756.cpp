#include<cstdio>

int main()
{
	int p, e, i, d, ans, T = 0;

	while( scanf( "%d %d %d %d", &p, &e, &i, &d ) && p >= 0 )
	{
		p = 23 - p;
		e = 28 - e;
		i = 33 - i;
		for( ans = 0; p | e | i; ++ans, p = (p+1) % 23, e = (e+1) % 28, i = (i+1) % 33 );
		printf( "Case %d: the next triple peak occurs in %d days.\n", ++T, ans-d+( ans > d? 0 : 21252 ));
	}
}
