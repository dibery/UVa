#include<cstdio>
#include<vector>
using namespace std;

vector< vector<int> > sol;

void solve( int n, vector<int>& dec, int last = 2 )
{
	for( int i = last; i <= n; ++i )
		if( n % i == 0 )
		{
			dec.push_back( i );
			solve( n/i, dec, i );
			dec.pop_back();
		}
	if( n == 1 && dec.size() > 1 )
		sol.push_back( dec );
}

int main()
{
	int n;

	while( scanf( "%d", &n ) && n )
	{
		vector<int> dec;
		sol.clear();
		solve( n, dec );
		printf( "%u\n", sol.size() );
		for( int i = 0; i < sol.size(); ++i )
			for( int j = 0; j < sol[ i ].size(); ++j )
				printf( "%d%c", sol[ i ][ j ], j == sol[ i ].size() - 1? '\n' : ' ' );
	}
}
