#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	for( int n, C, P, occupy[ 1000 ]; cin >> n && n; )
	{
		bool ok = true;

		fill( occupy, occupy + n, -1 );
		for( int i = 0; i < n; ++i )
		{
			cin >> C >> P;
			int p = i + P;
			if( p >= 0 && p < n && occupy[ p ] == -1 )
				occupy[ p ] = C;
			else
				ok = false;
		}
		if( ok )
			for( int i = 0; i < n; ++i )
				cout << occupy[ i ] << ( i == n - 1? '\n' : ' ' );
		else
			cout << -1 << endl;
	}
}
