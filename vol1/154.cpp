#include<cstdio>
#include<cctype>
#include<cstring>
inline int cov( char a )
{
    if( a == 'r' )
        return 0;
    else if( a == 'o' )
        return 1;
    else if( a == 'y' )
        return 2;
    else if( a == 'g' )
        return 3;
    return 4;
}

int main()
{
    char input[ 1000 ], color[ 100 ][ 5 ], kind[ 100 ][ 5 ], col, kin;
    int qnt = 0, ans;
    while( gets( input ) && strcmp( input, "#" ) )
    {
        if( *input == 'e' )
        {
            int now = 0, opt = 1e9;
            for( int i = 0; i < qnt; ++i, now = 0 )
            {
                for( int j = 0; j < qnt; ++j )
                    if( i != j )
                        for( int k = 0; k < 5; ++k )
                            if( kind[ i ][ k ] != kind[ j ][ k ] )
                                ++now;
                if( now < opt )
                    opt = now, ans = i;
            }
            printf( "%d\n", ans+1 );
            qnt = 0;
        }
        else
        {
            for( int i = 0; i < 5; ++i )
            {
                sscanf( input + i*4, "%c/%c", &col, &kin );
                kind[ qnt ][ cov( col ) ] = kin;
            }
            ++qnt;
        }
    }
    return 0;
}
