#include<cstdio>

int main()
{
    int test, money, line, letter;
    char str[ 10001 ];
    scanf( "%d\n", &test );

    while( test-- )
    {
        int paid[ 256 ] = { 0 }, pay = 0;
        scanf( "%d\n", &letter );
        for( int i = letter; i; --i )
        {
            scanf( "%c %d\n", str, &money );
            paid[ *str+128 ] = money;
        }
        scanf( "%d\n", &line );
        for( int i = 0; i < line; ++i )
        {
            gets( str );
            for( int j = 0; str[ j ]; ++j )
                pay += paid[ str[ j ]+128 ];
        }
        printf( "%d.%02d$\n", pay / 100, pay % 100 );
    }

	return 0;
}