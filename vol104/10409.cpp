#include<cstdio>

int main()
{
    int n, tmp;
    char cmd[ 6 ];

    while( scanf( "%d\n", &n ) && n )
    {
        int face[ 6 ] = { 1, 2, 3, 4, 5, 6 };
        for( int i = 0; i < n; ++i )
        {
            gets( cmd );
            if( *cmd == 'n' )
            {
                tmp = face[ 0 ];
                face[ 0 ] = face[ 4 ];
                face[ 4 ] = face[ 5 ];
                face[ 5 ] = face[ 1 ];
                face[ 1 ] = tmp;
            }
            else if( *cmd == 's' )
            {
                tmp = face[ 0 ];
                face[ 0 ] = face[ 1 ];
                face[ 1 ] = face[ 5 ];
                face[ 5 ] = face[ 4 ];
                face[ 4 ] = tmp;
            }
            else if( *cmd == 'e' )
            {
                tmp = face[ 0 ];
                face[ 0 ] = face[ 2 ];
                face[ 2 ] = face[ 5 ];
                face[ 5 ] = face[ 3 ];
                face[ 3 ] = tmp;
            }
            else
            {
                tmp = face[ 0 ];
                face[ 0 ] = face[ 3 ];
                face[ 3 ] = face[ 5 ];
                face[ 5 ] = face[ 2 ];
                face[ 2 ] = tmp;
            }
        }
        printf( "%d\n", face[ 0 ] );
    }

    return 0;
}
