#include<cstdio>
#include<cstring>

int main()
{
    char s[ 201 ];
    const char finger[][9] = { "1236789", "123678", "12367", "1236", "123", "12", "1", "2", "0123678", "012367", "01236", "0123", "012", "01" }, note[] = { "cdefgabCDEFGAB" };
    int t;

    for( scanf( "%d\n", &t ); t--; )
    {
        bool press[ 10 ] = { false };
        int time[ 10 ] = { 0 };

        gets( s );
        for( int i = 0; s[ i ]; ++i )
        {
            int index = strchr( note, s[ i ] ) - note;
            for( int j = 0; j < 10; ++j )
                if( !strchr( finger[ index ], '0' + j ) )
                    press[ j ] = false;
                else if( !press[ j ] )
                    ++time[ j ], press[ j ] = true;
        }
        for( int i = 0; i < 10; ++i )
			printf( "%d%c", time[ i ], i == 9? '\n' : ' ' );
    }
}
