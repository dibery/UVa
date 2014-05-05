#include<cstdio>

int main()
{
    int t, allow = 0;
    double len, wid, dep, wei;
    scanf( "%d", &t );

    while( t-- )
    {
        scanf( "%lf %lf %lf %lf", &len, &wid, &dep, &wei );
        if( ( len <= 56 && wid <= 45 && dep <= 25 || len+wid+dep <= 125 ) && wei <= 7 )
            puts( "1" ), ++allow;
        else
            puts( "0" );
    }
    printf( "%d\n", allow );

	return 0;
}