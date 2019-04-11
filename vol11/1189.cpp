#include<iostream>
#include<queue>
using namespace std;

int main()
{
	for( int n; cin >> n && n; )
	{
		string mod[ 200 ] = { "", "1" };
		queue<int> bfs;

		for( bfs.push( 1 ); mod->empty(); bfs.pop() )
		{
			int x = bfs.front(), p = x * 10 % n, q = ( x * 10 + 1 ) % n;
			if( mod[ p ].empty() )
				mod[ p ] = mod[ x ] + '0', bfs.push( p );
			if( mod[ q ].empty() )
				mod[ q ] = mod[ x ] + '1', bfs.push( q );
		}
		cout << *mod << endl;
	}
}
