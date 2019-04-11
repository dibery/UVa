#include<cstdio>
#include<algorithm>
int calc( int a, int b )
{
	int ans = 1;

	while( b-a != 1 || a & 1 )
		++ans, a >>= 1, b >>= 1;

	return ans;
}

int main()
{
	int round, a, b;

	while( scanf( "%d %d %d", &round, &a, &b ) != EOF )
		printf( "%d\n", calc( std::min( a, b )-1, std::max( a, b )-1 ) );

	return 0;
}
