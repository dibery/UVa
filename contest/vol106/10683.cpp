#include<cstdio>

int main()
{
	int h, m, s, ms;

	while( scanf( "%2d%2d%2d%2d", &h, &m, &s, &ms ) == 4 )
	{
		long long int n = ms + s * 100 + m * 6000 + h * 360000;
		printf( "%07lld\n", n * 1000 / 864 );
	}
}
