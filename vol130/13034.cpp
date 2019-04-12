#include<bits/stdc++.h>

int main()
{
	int t, in;

	std::cin >> t;
	for( int n = 1; n <= t; ++n )
	{
		bool ok = true;
		for( int i = 0; i < 13; ++i )
			std::cin >> in, ok &= in > 0;
		printf( "Set #%d: %s\n", n, ok? "Yes" : "No" );
	}
}
