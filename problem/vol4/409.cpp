#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
int show( char key[][ 71 ], char *str, int quant )
{
    int match = 0, cmp;
    char *ptr;
    for( int i = 0; i < quant; ++i )
    {
        for( ptr = str, cmp = 0; *ptr && key[ i ][ cmp ]; ++ptr )
            if( !isalpha( *ptr ) )
                continue;
            else//
                if( tolower( *ptr ) == tolower( key[ i ][ cmp ] ) )
                    ++cmp;
                else
                    break;
        if( !key[ i ][ cmp ] )
            ++match;
    }
    return match;
}

int main()
{
    int key, exc, t = 0;
    char word[ 20 ][ 71 ] = { 0 }, excuse[ 20 ][ 71 ] = { 0 }, ans[ 20 ][ 71 ] = { 0 };

    while( scanf( "%d %d\n", &key, &exc ) != EOF )
    {
        int max = 0, out = 0;
        for( int i = 0; i < key; ++i )
            gets( word[ i ] );
        for( int i = 0; i < exc; ++i )
        {
            int now = 0;
            gets( excuse[ i ] );
            for( int j = 0; excuse[ i ][ j ]; ++j )
                now += show( word, excuse[ i ]+j, key );
            if( now == max )
                strcpy( ans[ out++ ], excuse[ i ] );
            else if( now > max )
                strcpy( ans[ 0 ], excuse[ i ] ), max = now, out = 1;
        }
        printf( "Excuse Set #%d\n", ++t );
        for( int i = 0; i < out; ++i )
            puts( ans[ i ] );
        puts( "" );
    }

    return 0;
}