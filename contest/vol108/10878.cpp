#include<stdio.h>
#include<string.h>
const int pow2[] = { 0, 0, 64, 32, 16, 8, 0, 4, 2, 1, 0 };

int main()
{
    char input[ 20 ], code;

    gets( input );
    while( gets( input ) && *input != '_' )
    {
        code = 0;
        for( int i = 10; i >= 0; --i )
            if( input[ i ] == 'o' )
                code += pow2[ i ];
        printf( "%c", code );
    }

    return 0;
}
