#include<cstdio>

int main()
{
    int t, cook, each;
    scanf( "%d", &t );

    while( t-- )
    {
        int epi = 1;
        scanf( "%d %d", &cook, &each );
        while( cook > each && ++epi )
            cook -= each - 1;
        if( cook != each )
            puts( "cannot do this" );
        else
            printf( "%d\n", epi );
    }

	return 0;
}