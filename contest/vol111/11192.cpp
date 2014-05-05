#include<cstdio>
#include<cstring>

int main()
{
    int grp, len, per;
    char word[ 101 ];

    while( scanf( "%d", &grp ) && grp )
    {
        scanf( "%s", word );
        len = strlen( word );
        per = len / grp;
        for( int i = 0; i < grp; ++i )
            for( int k = per-1; k >= 0; --k )
                putchar( word[ i*per + k ] );
        puts( "" );
    }

	return 0;
}