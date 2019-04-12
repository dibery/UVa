#include<bits/stdc++.h>
using namespace std;

int find( vector<pair<double,double>>& v, int idx, double right )
{
	int ans = -1, pos = idx;
	for( double ext = -1; pos + 1 < v.size() && v[ pos + 1 ].first <= right; ++pos )
		if( v[ pos + 1 ].second > ext )
			ext = v[ pos + 1 ].second, ans = pos + 1;
	return ans;
}

int main()
{
	for( int n, l, w; cin >> n >> l >> w; )
	{
		vector<pair<double,double>> seg;
		bool wrong = false;
		int ans = 0;

		for( double i = 0, p, r; i < n && cin >> p >> r; ++i )
			if( r * 2 > w )
				seg.emplace_back( p - sqrt( r * r - w * w / 4. ), p + sqrt( r * r - w * w / 4. ) );

		sort( seg.begin(), seg.end() );
		for( double right = 0, idx = -1; right < l; )
			if( wrong = ( idx = find( seg, idx, right ) ) == -1 )
				break;
			else
				++ans, right = seg[ idx ].second;

		cout << ( wrong? -1 : ans ) << endl;
	}
}
