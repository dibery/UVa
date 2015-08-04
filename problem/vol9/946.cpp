#include<bits/stdc++.h>
using namespace std;

struct box
{
	int size, child_size;
	vector<box*> sub;
	box( int n ) { size = n, child_size = 0; }
	~box()
	{
		for( size_t i = 0; i < sub.size(); ++i )
			delete sub[ i ];
	}
	bool insert( int n )
	{
		if( sub.empty() )
			if( n <= size )
			{
				sub.insert( sub.begin(), new box( n ) );
				child_size += n;
				return true;
			}
			else
				return false;
		else if( sub.front()->size < n )
			if( child_size + n <= size )
			{
				sub.insert( sub.begin(), new box( n ) );
				child_size += n;
				return true;
			}
			else
				return false;
		else
		{
			int p;
			for( p = 0; p < sub.size() && sub[ p ]->size > n; ++p );
			for( --p; p >= 0; --p )
				if( sub[ p ]->insert( n ) )
					return true;
			if( child_size + n <= size )
			{
				sub.insert( sub.begin(), new box( n ) );
				child_size += n;
				return true;
			}
			else
				return false;
		}
	}
};

int main()
{
	int size, n;

	while( scanf( "%d", &size ) == 1 )
	{
		box uni( INT_MAX );
		for( int i = 0; i < size; ++i )
			scanf( "%d", &n ), uni.insert( n );
		printf( "%d\n", uni.child_size );
	}
}
