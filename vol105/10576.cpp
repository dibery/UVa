#include<cstdio>

int main()
{
    int s, d;

    while( scanf( "%d %d", &s, &d ) != EOF )
        if( d > 4*s )
            if( 5*s > d )
                printf( "%d\n", 10*s - 2*d );
            else
                puts( "Deficit" );
        else if( 2*d > 3*s )
            if( 2*s > d )
                printf( "%d\n", 8*s - 4*d );
            else
                puts( "Deficit" );
        else if( 3*d > 2*s )
            if( s > d )
                printf( "%d\n", 6*s - 6*d );
            else
                puts( "Deficit" );
        else if( 4*d > s )
            if( s > 3*d )
                printf( "%d\n", 3*s - 9*d );
            else
                puts( "Deficit" );
        else
            puts( "Deficit" );
}
