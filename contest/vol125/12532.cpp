#include<cstdio>
#include<set>
#define N 100001
using namespace std;

int main()
{
    for( int size, cmd; scanf( "%d %d", &size, &cmd ) == 2; puts( "" ) )
    {
        int tree[ N ] = { 0 }, num[ N ] = { 0 }, arg1, arg2;
        set<int> zero;
        char type;

        for( int i = 1; i <= size; ++i )
        {
            scanf( "%d ", num + i );
			tree[ i ] = num[ i ] >= 0? 1 : -1;
			if( !num[ i ] )
				zero.insert( i ), num[ i ] = 1;
        }

        for( int i = 2; i <= size; i <<= 1 )
			for( int j = i; j <= size; j += i )
				tree[ j ] *= tree[ j - i / 2 ];

		while( cmd-- && scanf( "%c %d %d\n", &type, &arg1, &arg2 ) )
			if( type == 'C' )
				if( zero.count( arg1 ) )
					if( arg2 > 0 )
						zero.erase( arg1 );
					else if( arg2 == 0 )
						continue;
					else
					{
						zero.erase( arg1 );
						num[ arg1 ] = -1;
						for( int pos = arg1; pos <= size; pos += pos & -pos )
							tree[ pos ] *= -1;
					}
				else if( num[ arg1 ] > 0 )
					if( arg2 > 0 )
						continue;
					else if( arg2 == 0 )
						zero.insert( arg1 );
					else
					{
						num[ arg1 ] = -1;
						for( int pos = arg1; pos <= size; pos += pos & -pos )
							tree[ pos ] *= -1;
					}
				else
					if( arg2 > 0 )
					{
						num[ arg1 ] = 1;
						for( int pos = arg1; pos <= size; pos += pos & -pos )
							tree[ pos ] *= -1;
					}
					else if( arg2 == 0 )
					{
						num[ arg1 ] = 1;
						zero.insert( arg1 );
						for( int pos = arg1; pos <= size; pos += pos & -pos )
							tree[ pos ] *= -1;
					}
					else
						continue;
			else
				if( !zero.empty() && *--zero.end() >= arg1 && *zero.lower_bound( arg1 ) <= arg2 )
					putchar( '0' );
				else
				{
					int begin = 1, end = 1;
					for( int pos = --arg1; pos; pos -= pos & -pos )
						begin *= tree[ pos ];
					for( int pos = arg2; pos; pos -= pos & -pos )
						end *= tree[ pos ];
					putchar( begin * end == 1? '+' : '-' );
				}
    }
}
