#include<cstdio>
#include<cstring>

int main()
{
    char word[ 1000001 ] = { 0 };

    while( gets( word ) && strcmp( word, "END" ) )
    {
        if( word[ 9 ] )
            puts( "4" );
        else if( word[ 1 ] )
            puts( "3" );
        else if( *word != '1' )
            puts( "2" );
        else
            puts( "1" );
        memset( word, 0, sizeof( word ) );
    }

	return 0;
}