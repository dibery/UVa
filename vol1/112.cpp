#include<cstdio>
bool found;
int goal;

class node
{
	public:
		node( int N = 0 ) { n = N; left = right = NULL; }
		int n;
		node *left, *right;
};

void build( node& now )
{
	int tmp;
	if( scanf( " ( %d ", &tmp ) == 1 )
		now.left = new node( tmp ), build( *now.left );
	scanf( " ) " );
	if( scanf( " ( %d ", &tmp ) == 1 )
		now.right = new node( tmp ), build( *now.right );
	scanf( " ) " );
}

void search( node& now, int sum = 0 )
{
	if( found )
		return;
	if( now.left == NULL && now.right == NULL )
		found |= sum + now.n == goal;
	if( now.left )
		search( *now.left, sum + now.n );
	if( now.right )
		search( *now.right, sum + now.n );
}

int main()
{
	while( scanf( " %d ", &goal ) == 1 )
	{
		node *root = NULL;
		int tmp;
		if( scanf( " ( %d ", &tmp ) == 1 )
			build( *( root = new node( tmp ) ) );
		scanf( " )" );
		found = false;
		if( root )
			search( *root );
		puts( found? "yes" : "no" );
	}
}
