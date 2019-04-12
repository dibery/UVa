#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, op;
	char cmd[ 10 ];

	for( scanf( "%d", &t ); t--; )
	{
		stack<int> content;
		map<set<int>,int> serial;
		map<int,set<int> > lookup;
		lookup[ serial[ set<int>() ] = 1 ];

		for( scanf( "%d\n", &op ); op--; )
		{
			gets( cmd );
			if( *cmd == 'P' )
				content.push( 1 );
			else if( *cmd == 'D' )
				content.push( content.top() );
			else if( *cmd == 'U' )
			{
				int a = content.top(), b;
				content.pop();
				b = content.top();
				content.pop();
				set<int> &sa = lookup[ a ], sb = lookup[ b ];
				sb.insert( sa.begin(), sa.end() );
				if( serial.find( sb ) == serial.end() )
					lookup[ serial[ sb ] = serial.size() ] = sb;
				content.push( serial[ sb ] );
			}
			else if( *cmd == 'I' )
			{
				int a = content.top(), b;
				content.pop();
				b = content.top();
				content.pop();
				set<int> rm, &sa = lookup[ a ], sb = lookup[ b ];
				for( auto& i: sb )
					if( sa.find( i ) == sa.end() )
						rm.insert( i );
				for( auto& i: rm )
					sb.erase( i );
				if( serial.find( sb ) == serial.end() )
					lookup[ serial[ sb ] = serial.size() ] = sb;
				content.push( serial[ sb ] );
			}
			else
			{
				int a = content.top(), b;
				content.pop();
				b = content.top();
				content.pop();
				set<int> sb = lookup[ b ];
				sb.insert( a );
				if( serial.find( sb ) == serial.end() )
					lookup[ serial[ sb ] = serial.size() ] = sb;
				content.push( serial[ sb ] );
			}
			printf( "%u\n", lookup[ content.top() ].size() );
		}
		puts( "***" );
	}
}
