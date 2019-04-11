#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int main()
{
	for( int x, c, n; cin >> x; )
	{
		string s;
		vector<long long> coef;
		long long ans = 0;

		cin.get();
		getline( cin, s );
		for( stringstream ss( s ); ss >> c; )
			coef.push_back( c );

		n = coef.size() - 1;
		for( int i = 0; i <= n; ++i )
			coef[ i ] *= n - i;
		ans = coef[ 0 ];
		for( int i = 1; i < n; ++i )
			ans = ans * x + coef[ i ];
		cout << ans << endl;
	}
}
