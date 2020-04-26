#include<bits/stdc++.h>
using namespace std;

struct node
{
	char c;
	node *left, *right;
	node( char C, node *L = NULL, node *R = NULL ) : c( C ), left( L ), right( R ) {}
	~node()
	{
		if( left )
			delete left;
		if( right )
			delete right;
	}
};

int main()
{
	int t;
	char post[ 10000 ];

	for( scanf( "%d", &t ); t-- && scanf( "%s", post ); )
	{
		stack<node*> expr;

		for( int i = 0; post[ i ]; ++i )
			if( islower( post[ i ] ) )
				expr.push( new node( post[ i ] ) );
			else
			{
				node *a = expr.top();
				expr.pop();
				node *b = expr.top();
				expr.pop();
				expr.push( new node( post[ i ], b, a ) );
			}

		queue<node*> bfs;
		string out;
		for( bfs.push( expr.top() ); !bfs.empty(); bfs.pop() )
		{
			out += bfs.front()->c;
			if( bfs.front()->left )
				bfs.push( bfs.front()->left );
			if( bfs.front()->right )
				bfs.push( bfs.front()->right );
		}

		reverse( out.begin(), out.end() );
		puts( out.c_str() );
		delete expr.top();
	}
}
