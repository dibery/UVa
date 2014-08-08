#include<iostream>
#include<algorithm>
using namespace std;
int judge( string& a, string& b )
{
	for( int i = 0; i < a.length(); ++i )
		if( a[ i ] != b[ i ] )
			return i+1;
	return a.length();
}
int judge( string& a, string& b, string& c )
{
	unsigned int before = 0, after = 0;
	for( ; before < a.length() && a[ before ] != b[ before ]; ++before );
	for( ; after < a.length() && a[ after ] != c[ after ]; ++after );
	return min( unsigned int( a.length() ), max( before, after ) + 1 );
}

int main()
{
	int t, size;

	for( cin >> t; t--; )
	{
		int ans = 0;
		cin >> size;
		string dict[ size ];
		for( int i = 0; i < size; ++i )
			cin >> dict[ i ];
		sort( dict, dict+size );
		for( int i = 0; i < size; ++i )
			if( i == 0 || i == size-1 )
				ans += judge( dict[ i ], dict[ i+( i==size-1? -1 : 1 ) ] );
			else
				ans += judge( dict[ i ], dict[ i-1 ], dict[ i+1 ] );
		cout << ans << endl;
	}
}
