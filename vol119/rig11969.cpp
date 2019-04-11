#include<bits/stdc++.h>
using namespace std;

int sub = 20, stu = 200;
set<string> dict;
bool use[ 1001 ] = { false };

struct subject
{
	subject()
	{
		while( true )
		{
			char s[ 20 ] = { 0 };
			for( int i = 0; i < 3; ++i )
				s[ i ] = rand() % 26 + 'A';
			if( dict.find( string( s ) ) == dict.end() )
			{
				name = s;
				dict.insert( name );
				break;
			}
		}
		while( true )
		{
			int i = rand() % 1000 + 1;
			if( !use[ i ] )
			{
				id = i;
				use[ i ] = true;
				break;
			}
		}
		avail = rand() % 10;
	}
	string name;
	int id, avail;
};

set<int> stuid;

struct student
{
	student()
	{
		while( true )
		{
			char s[ 20 ] = { 0 };
			for( int i = 0; i < 8; ++i )
				s[ i ] = rand() % 26 + 'A';
			s[ 3 ] = ' ';
			if( dict.find( string( s ) ) == dict.end() )
			{
				name = s;
				dict.insert( name );
				break;
			}
		}
		while( true )
		{
			int i = rand() * rand();
			if( stuid.find( i ) == stuid.end() )
			{
				stuid.insert( i );
				id = i;
				break;
			}
		}
		apply = rand() % min( sub, 16 );
		while( int( sorder.size() ) < apply )
			sorder.insert( rand() % sub );
		order.insert( order.begin(), sorder.begin(), sorder.end() );
	}
	string name;
	int id, apply;
	vector<int> order;
	set<int> sorder;
};

int main()
{
	freopen( "test", "w", stdout );
	srand( time( NULL ) );

	printf( "%d %d\n", sub, stu );

	subject *su = new subject[ sub ];
	for( int i = 0; i < sub; ++i )
		printf( "%s\n%d %d\n", su[ i ].name.c_str(), su[ i ].id, su[ i ].avail );
	student *st = new student[ stu ];
	for( int i = 0; i < stu; ++i )
	{
		printf( "%s\n%d %d\n", st[ i ].name.c_str(), st[ i ].apply, st[ i ].id );
		for( int j = 0; j < st[ i ].apply; ++j )
			printf( "%d %d.%02d\n", su[ st[ i ].order[ j ] ].id, rand() % 10, rand () % 100 );
	}
}
