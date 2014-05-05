#include<cstdio>
#include<cstring>

int main()
{
    int t;
    scanf( "%d\n", &t );

    for( int i = 1; i <= t; ++i )
    {
        bool current = false, voltage = false, power = false;
        char str[ 100000 ] = { 0 }, *pos = str, tmp[ 100000 ] = { 0 }, scale;
        double A, V, W;
        gets( str );
        while( *pos )
        {
            sscanf( pos, "%s", tmp );
            pos += strlen( tmp ) + 1;
            if( strchr( tmp, '=' ) )
                if( *tmp == 'U' )
                {
                    voltage = true;
                    sscanf( tmp+2, "%lf%c", &V, &scale );
                    if( scale == 'm' )
                        V *= 1e-3;
                    else if( scale == 'M' )
                        V *= 1e6;
                    else if( scale == 'k' )
                        V *= 1e3;
                }
                else if( *tmp == 'I' )
                {
                    current = true;
                    sscanf( tmp+2, "%lf%c", &A, &scale );
                    if( scale == 'm' )
                        A *= 1e-3;
                    else if( scale == 'M' )
                        A *= 1e6;
                    else if( scale == 'k' )
                        A *= 1e3;
                }
                else
                {
                    power = true;
                    sscanf( tmp+2, "%lf%c", &W, &scale );
                    if( scale == 'm' )
                        W *= 1e-3;
                    else if( scale == 'M' )
                        W *= 1e6;
                    else if( scale == 'k' )
                        W *= 1e3;
                }
        }
        printf( "Problem #%d\n", i );
        if( !current )
            printf( "I=%.2fA\n\n", W / V );
        else if( !voltage )
            printf( "U=%.2fV\n\n", W / A );
        else
            printf( "P=%.2fW\n\n", A * V );
    }

    return 0;
}
