#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, rate, qnt;

	scanf( "%d", &t );
	for( int c = 1; c <= t; ++c )
	{
		map<long long,long long,greater<long long> > stat;
		long long total = 0, ans = 0;

		scanf( "%d", &n );
		for( int i = 0; i < n; ++i )
		{
			scanf( "%d %d", &qnt, &rate );
			stat[ rate ] += qnt;
		}

		for( auto i: stat )
			ans = max( ( total += i.second ) * i.first, ans );
		printf( "Case %d: %lld\n", c, ans );
	}
}
