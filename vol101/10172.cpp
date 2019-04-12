#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, station, cargo, out;

	for( cin >> t; t--; )
	{
		int time = 0, at = 0;
		queue<int> pb[ 100 ];
		stack<int> hold;

		cin >> station >> cargo >> out;
		for( int i = 0, q, s; i < station; ++i )
			for( cin >> q; q--; pb[ i ].push( s-1 ) )
				cin >> s;
		
		while( true )
		{
			while( !hold.empty() && ( pb[ at ].size() < out || hold.top() == at ) )
			{
				while( !hold.empty() && hold.top() == at )
					hold.pop(), ++time;
				while( !hold.empty() && pb[ at ].size() < out && hold.top() != at )
				{
					pb[ at ].push( hold.top() );
					hold.pop();
					++time;
				}
			} // Load
			while( !pb[ at ].empty() && hold.size() < cargo )
			{
				hold.push( pb[ at ].front() );
				pb[ at ].pop();
				++time;
			} // Unload
			if( hold.empty() && all_of( pb, pb + station, [] ( queue<int>& q ) { return q.empty(); } ) )
				break;
			else
				time += 2, ++at %= station;
		}
		cout << time << endl;
	}
}
