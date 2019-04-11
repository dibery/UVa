#include<bits/stdc++.h>
using namespace std;

int find( vector<pair<double,double>>& v, int idx, double right )
{
	int ans = -1, pos = idx;
	for( int ext = -1; pos + 1 < v.size() && v[ pos + 1 ].first <= right; ++pos )
		if( v[ pos + 1 ].second > ext )
			ext = v[ pos + 1 ].second, ans = pos + 1;
	return ans;
}

int main()
{
	for( int l, w, num; cin >> num >> l >> w; )
	{
		vector<pair<double,double>> seg;
		int ans = 0;
		bool wrong = false;

		for( int pos, r, i = 0; i < num && cin >> pos >> r; ++i )
			if( r * 2 >= w )
				seg.push_back( make_pair( pos - sqrt( pow( r, 2 ) - pow( w / 2., 2 ) ), pos + sqrt( pow( r, 2 ) - pow( w / 2., 2 ) ) ) );

		sort( seg.begin(), seg.end() );
		for( double right = 0, idx = -1; right < l; )
			if( wrong = ( idx = find( seg, idx, right ) ) == -1 )
				break;
			else
				right = seg[ idx ].second, ++ans;

		cout << ( wrong? -1 : num - ans ) << endl;
	}
}
