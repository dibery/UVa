#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
typedef vector<int> VI;

struct node
{
	int val;
	node *left, *right;

	node( int v = 0, node* l = NULL, node* r = NULL ) { val = v; left = l; right = r; }
	node( VI& in, VI& post )
	{
		int index = 0;

		val = *--post.end();
		while( in[ index ] != val )
			++index;
		left = build( VI( in.begin(), in.begin() + index ), VI( post.begin(), post.begin() + index ) ),
		right = build( VI( in.begin() + index + 1, in.end() ), VI( post.begin() + index, --post.end() ) );
	}
	~node()
	{
		if( left )
			delete left;
		if( right )
			delete right;
	}

	node* build( VI in, VI post )
	{
		if( in.empty() )
			return NULL;
		int root = *--post.end(), index = 0;

		while( in[ index ] != root )
			++index;
		node *L = build( VI( in.begin(), in.begin() + index ), VI( post.begin(), post.begin() + index ) ),
				 *R = build( VI( in.begin() + index + 1, in.end() ), VI( post.begin() + index, --post.end() ) );
		return new node( root, L, R );
	}
};

void path( const node* tree, int& minsum, int& leaf, int sum )
{
	if( tree->left == NULL && tree->right == NULL && ( sum < minsum || sum == minsum && leaf < tree->val ) )
		minsum = sum, leaf = tree->val;
	else if( tree )
	{
		if( tree->left )
			path( tree->left, minsum, leaf, sum + tree->left->val );
		if( tree->right )
			path( tree->right, minsum, leaf, sum + tree->right->val );
	}
}

int main()
{
	for( string in, post; getline( cin, in ) && getline( cin, post ); )
	{
		stringstream I( in ), P( post );
		VI vi, vp;
		int leaf, sum = 1e9;

		for( int n; I >> n; vi.push_back( n ) );
		for( int n; P >> n; vp.push_back( n ) );
		node tree( vi, vp );
		path( &tree, sum, leaf, tree.val );
		cout << leaf << endl;
	}
}
