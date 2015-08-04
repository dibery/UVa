#include<cstdio>
#include<algorithm>
using namespace std;

bool isp( int n )
{
	if( n % 2 == 0 && n != 2 )
		return false;
	for( int i = 3; i*i <= n; i += 2 )
		if( n % i == 0 )
			return false;
	return true;
}

int main()
{
	int factor[ 10001 ] = { 0, 1 }, ok[ 10001 ] = { 0 }, size = 0, L, H, t;

	for( int i = 2; i <= 10000; ++i )
	{
		for( int j = 1; j <= i; ++j )
			factor[ i ] += i % j == 0;
		if( isp( factor[ i ] ) )
			ok[ size++ ] = i;
	}

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d", &L, &H );
		bool out = false;
		for( int *lp = lower_bound( ok, ok+size, L ), *hp = upper_bound( ok, ok+size, H ); lp != hp; ++lp )
			printf( "%d%c", *lp, lp+1 == hp? '\n' : ' ' ), ++out;
		if( !out )
			puts( "-1" );
	}
}
