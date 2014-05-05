#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cmath>
#include<set>
using namespace std;
typedef struct node
{
	double x, y;
	bool visited;
} node;
typedef struct line
{
	int xnode, ynode;
	double distance;
} line;
int comp(const void * a, const void * b)
{
	return ( ((*(line*)a).distance < (*(line*)b).distance)? -1:1 );
}

int main()
{
	int test;
	cin >> test;

	for( int counter = 1; counter <= test; ++counter )
	{
		int size;
		cin >> size;
		node map[ size ];
		line vertex[ size * (size-1) / 2 ];

		for( int i = 0; i < size; ++i )
			cin >> map[ i ].x >> map[ i ].y;
		if( size == 1 )
		{
			cout << "0.00\n";
			if( counter != test )
				cout << endl;
			continue;
		}
		for( int i = 0, in = 0; i < size; ++i )
			for( int j = i+1; j < size; ++j, ++in )
			{
				vertex[ in ].distance = sqrt( pow( map[ i ].x - map[ j ].x, 2 ) + pow ( map[ i ].y - map[ j ].y, 2 ) );
				vertex[ in ].distance = hypot( map[ i ].x - map[ j ].x, map[ i ].y - map[ j ].y );
				vertex[ in ].xnode = i;
				vertex[ in ].ynode = j;
			}
		qsort( vertex, size * (size-1) / 2, sizeof( line ), comp );

		double totaldistance = vertex[ 0 ].distance;
		set<int> visited_edge;
		visited_edge.insert( vertex[ 0 ].xnode );
		visited_edge.insert( vertex[ 0 ].ynode );

		while( visited_edge.size() < (unsigned)size )
			for( int i = 1; i < size * (size-1) / 2; ++i )
				if( (visited_edge.find( vertex[ i ].xnode ) != visited_edge.end()) ^ (visited_edge.find( vertex[ i ].ynode ) != visited_edge.end()) )
				{
					visited_edge.insert( vertex[ i ].xnode );
					visited_edge.insert( vertex[ i ].ynode );
					totaldistance += vertex[ i ].distance;
					break;
				}
		visited_edge.clear();
		cout << setiosflags(ios::fixed) << setprecision(2) << totaldistance << endl;
		if( counter != test )
			cout << endl;
	}
	return 0;
}

