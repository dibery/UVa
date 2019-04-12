#include<bits/stdc++.h>
using namespace std;

void split( int& n, set<int>& factor, map<int,int>& expr )
{
	for( int i = 2; i < 1000; ++i )
		if( n % i == 0 )
		{
			factor.insert( i );
			while( n % i == 0 )
				n /= i, ++expr[ i ];
		}
}

long long fib( int a, int b, int n )
{
	for( int i = 1, c; i < n; ++i )
		c = a + b, a = b, b = c;
	return b;
}

int main()
{
	int t, a, b, n;

	for( scanf( "%d", &t ); t-- && scanf( "%d %d %d", &n, &a, &b ); )
	{
		set<int> factor;
		map<int,int> fa, fb;

		split( a, factor, fa );
		split( b, factor, fb );

		for( int f: factor )
			printf( "%d %lld\n", f, fib( fa[ f ], fb[ f ], n ) );
		puts( "" );
	}
}
