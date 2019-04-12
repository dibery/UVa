#include<cstdio>
inline int abs( int n ) { return n < 0? -n : n; }

int main()
{
	int k, m;

	while( scanf( "%d %d", &k, &m ) == 2 )
	{
		double need = 43200.0 / abs( k - m ) * ( 86400 - k );
		int min = ( (long long int)need % 43200 + 30 ) / 60;
		printf( "%d %d %02d:%02d\n", k, m, min < 60? 12 : min / 60, min % 60 );
	}
}
