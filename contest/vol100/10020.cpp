#include<bits/stdc++.h>
using namespace std;

int find( vector<pair<int,int>>& v, int idx, int right )
{
	int ans = -1, pos = idx;
	for( int ext = -1; pos + 1 < v.size() && v[ pos + 1 ].first <= right; ++pos )
		if( v[ pos + 1 ].second > ext )
			ext = v[ pos + 1 ].second, ans = pos + 1;
	return ans;
}

int main()
{
	int t;

	for( cin >> t; t--; )
	{
		vector<pair<int,int>> seg, ans;
		int M;
		bool wrong = false;

		cin >> M;
		for( int begin, end; cin >> begin >> end && ( begin || end ); )
			if( begin < M && end > 0 )
				seg.push_back( make_pair( begin, end ) );

		sort( seg.begin(), seg.end() );
		for( int right = 0, idx = -1; right < M; )
			if( wrong = ( idx = find( seg, idx, right ) ) == -1 )
				break;
			else
			{
				ans.push_back( seg[ idx ] );
				right = seg[ idx ].second;
			}

		if( wrong )
			cout << 0 << endl;
		else
		{
			cout << ans.size() << endl;
			for( auto& i: ans )
				cout << i.first << ' ' << i.second << endl;
		}
		if( t )
			cout << endl;
	}
}
