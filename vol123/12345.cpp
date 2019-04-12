#include<cstdio>
#include<set>
using namespace std;

int main()
{
    int total, command, a, b, *number;
    char type;
    scanf( "%d %d", &total, &command );
    number = new int[ total ];
    for( int i = 0; i < total; ++i )
        scanf( "%d ", number+i );

    for( int i = 0; i < command; ++i )
    {
        scanf( "%c %d %d\n", &type, &a, &b );
        if( type == 'M' )
            number[ a ] = b;
        else
        {
            bool exist[ 1000000 ] = { false };
            int ans = 0;
            for( int i = a; i < b; ++i )
                if( !exist[ number[ i ] ] )
                {
                    ++ans;
                    exist[ number[ i ] ] = true;
                }
            printf( "%d\n", ans );
        }
    }

	return 0;
}