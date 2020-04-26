#include<bits/stdc++.h>
using namespace std;

struct node
{
	node *left, *right;
	int cost, ans[ 21 ], child;
	bool found[ 21 ];
	static int height;

	node( int d = 0 )
	{
		scanf( "%d", &cost );
		child = 1 << height - d;
		fill( ans, ans + 21, INT_MIN );
		memset( found, false, sizeof( found ) );
		if( d < height )
		{
			left = new node( d + 1 );
			right = new node( d + 1 );
		}
		else
			left = right = NULL;
	}
	~node()
	{
		if( left )
		{
			delete left;
			delete right;
		}
	}
	int cut( int qnt )
	{
		if( found[ qnt ] )
			return ans[ qnt ];
		found[ qnt ] = true;
		if( qnt == 1 )
			return ans[ 1 ] = cost;
		for( int i = 1; i < qnt; ++i )
			if( left->child >= i && right->child >= qnt - i )
				ans[ qnt ] = max( ans[ qnt ], left->cut( i ) + right->cut( qnt - i ) );
		return ans[ qnt ];
	}
};

int node::height;

int main()
{
	for( int qnt; scanf( "%d %d", &node::height, &qnt ) && ~node::height; )
	{
		node *root = new node;
		for( int i = 1; i <= qnt && i <= root->child; ++i )
			root->cut( i );
		printf( "%d\n", *max_element( root->ans + 1, root-> ans + qnt + 1 ) );
		delete root;
	}
}
