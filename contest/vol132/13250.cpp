#include<cstdio>
typedef long long ll;
inline ll abs( ll n ) { return n > 0? n : -n; }
inline int min( int a, int b ) { return a < b? a : b; }

void gcd( int a, int b, ll& factor, ll& x, ll& y ) 
{
	if( b == 0 ) 
	{
		factor = a;
		x = 1;
		y = 0;
	}
	else
	{
		gcd( b, a % b, factor, y, x );
		y -= a / b * x;
	}
}

ll calc( int x, int y, int sum, int copy, ll A, ll B, ll f )	// use x and y to get sum
{
	A *= sum / f, B *= sum / f;
	ll dx = y / f, dy = x / f, move = ( A + copy ) / dx;
	move = A > -copy? ( A + copy ) / dx : ( copy + A - dx + 1 ) / dx;
	A -= dx * move;
	B += dy * move;

	if( sum % f || abs( A ) > copy || B < -copy )
		return 0;
	if( B > copy )
	{
		int move = ( B - copy + dy - 1 ) / dy;
		B -= dy * move;
		A += dx * move;
		if( A > copy || B < -copy )
			return 0;
	}
	return min( ( copy - A ) / dx, ( B + copy ) / dy ) + 1;
}

int main()
{
	for( int copy, w, a, b, c; ~scanf( "%d %d %d %d %d", &copy, &w, &a, &b, &c ); )
	{
		ll ans = 0, A, B, f;
		gcd( b, c, f, A, B );
		for( int i = -copy; i <= copy && w - i * a >= -copy * ( a + b ); ++i )
			ans += calc( b, c, abs( w - i * a ), copy, A, B, f );
		printf( "%lld\n", ans );
	}
}
