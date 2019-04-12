#include<cctype>
#include<iostream>
#include<algorithm>
using namespace std;

struct car
{
	char name[ 21 ];
	int time;
	void get()
	{
		int m, s, ms;
		fill( name, name+21, 0 );
		scanf( "%s : %d min %d sec %d ms", name, &m, &s, &ms );
		time = ms + s * 1000 + m * 60000;
	}
	bool operator< ( const car& rhs ) const
	{
		if( time != rhs.time )
			return time < rhs.time;
		for( int i = 0; i <= 20; ++i )
			if( tolower( name[ i ] ) != tolower( rhs.name[ i ] ) )
				return tolower( name[ i ] ) < tolower( rhs.name[ i ] );
	}
} item[ 100 ];

int main()
{
	for( int size, r = 0; scanf( "%d", &size ) == 1; puts( "" ), r = 0 )
	{
		for( int i = 0; i < size; ++i )
			item[ i ].get();
		sort( item, item + size );
		for( int i = 0; i < size; ++i )
			if( i % 2 == 0 )
				printf( "Row %d\n%s\n", ++r, item[ i ].name );
			else
				puts( item[ i ].name );
	}
}
