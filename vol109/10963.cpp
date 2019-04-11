#include<cstdio>

int main()
{
    int t, gap, N, S, diff;
    scanf( "%d", &t );

    while( t-- )
    {
        bool fix = true;
        scanf( "%d", &gap );
        scanf( "%d %d", &N, &S );
        diff = N-S;
        for( int i = 1; i < gap; ++i )
        {
            scanf( "%d %d", &N, &S );
            if( N-S != diff )
                fix = false;
        }
        printf( "%s\n%s", fix? "yes" : "no", t? "\n" : "" );
    }

	return 0;
}