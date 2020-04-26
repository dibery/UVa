#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( int size, act; scanf( "%d %d", &size, &act ) == 2; )
	{
		unordered_set<int> *union_find = new unordered_set<int>[ size + 1 ];
		int *location = new int[ size + 1 ];

		for( int i = 1; i <= size; ++i )
			union_find[ i ].insert( location[ i ] = i );
		for( int type, a, b; act-- && scanf( "%d", &type ); )
			if( type == 1 )
			{
				scanf( "%d %d", &a, &b );
				if( location[ a ] != location[ b ] )
				{
					unordered_set<int> *sa = union_find + location[ a ], *sb = union_find + location[ b ];
					if( union_find[ location[ a ] ].size() < union_find[ location[ b ] ].size() )
						swap( sa, sb );
					for( const int& i: *sb )
					{
						sa->insert( i );
						location[ i ] = sa - union_find;
					}
					sb->clear();
				}
			}
			else if( type == 2 )
			{
				scanf( "%d %d", &a, &b );
				unordered_set<int> *sa = union_find + location[ a ], *sb = union_find + location[ b ];
				if( sa != sb )
				{
					sb->insert( a );
					sa->erase( a );
					location[ a ] = location[ b ];
				}
			}
			else
			{
				scanf( "%d", &a );
				unordered_set<int> *sa = union_find + location[ a ];
				printf( "%llu %d\n", sa->size(), accumulate( sa->begin(), sa->end(), 0 ) );
			}
	}
}
