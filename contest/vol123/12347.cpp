#include<cstdio>
class node
{
	public:
		int val;
		node *left, *right;
		node( int n ) { val = n; left = right = NULL; }
		void add( int n ) { ( n < val? left : right ) = new node( n ); }
		node* find( int n ) { return n < val? ( left? left->find( n ) : this ) : ( right? right->find( n ) : this ); }
} *tree = NULL, *tmp;
void post( node* ptr )
{
	if( !ptr )
		return;
	post( ptr->left );
	post( ptr->right );
	printf( "%d\n", ptr->val );
}

int main()
{
	int n;
	
	while( scanf( "%d", &n ) != EOF )
		if( !tree )
			tree = new node( n );
		else
			tree->find( n )->add( n );
	post( tree );

	return 0;
}
