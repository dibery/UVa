#include<iostream>
#include<map>
#include<queue>
#define W first
#define V second
#define From first
#define To second
using namespace std;
typedef pair< int, pair<int,int> > node;

int main()
{
	for( int vertex, edge, t = 0; cin >> vertex >> edge && vertex; )
	{
		int adj[ 200 ][ 200 ] = { { 0 } }, begin, end, load[ 200 ] = { 0 };
		map<string,int> id;
		priority_queue<node> mst;
		string a, b;

		for( int i = 0, w; i < edge; ++i )
		{
			cin >> a >> b >> w;
			if( id.count( a ) == 0 )
				id.insert( make_pair( a, id.size() ) );
			if( id.count( b ) == 0 )
				id.insert( make_pair( b, id.size() ) );
			adj[ id[ a ] ][ id[ b ] ] = adj[ id[ b ] ][ id[ a ] ] = w;
		}

		cin >> a >> b;
		load[ begin = id[ a ] ] = 1e9;
		end = id[ b ];

		for( int i = 0; i < vertex; ++i )
			if( adj[ begin ][ i ] )
				mst.push( make_pair( adj[ begin ][ i ], make_pair( begin, i ) ) );
		while( !mst.empty() )
			if( load[ mst.top().V.To ] )
				mst.pop();
			else
			{
				int w = mst.top().W, f = mst.top().V.From, t = mst.top().V.To;

				mst.pop();
				load[ t ] = min( w, load[ f ] );
				for( int i = 0; i < vertex; ++i )
					if( !load[ i ] && i != begin && adj[ t ][ i ] )
						mst.push( make_pair( adj[ t ][ i ], make_pair( t, i ) ) );
			}

		cout << "Scenario #" << ++t << endl << load[ end ] << " tons\n\n";
	}
}
