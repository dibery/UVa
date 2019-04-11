#include<bits/stdc++.h>
#define N 14143
using namespace std;

int main()
{
	int S[ N ] = { 0 }, n, *p;

	for( int i = 1; i < N; ++i )
		S[ i ] = S[ i-1 ] + i;

	while( scanf( "%d", &n ) && n )
		p = upper_bound( S, S+N, n ), printf( "%d %d\n", *p - n, p - S );
}
