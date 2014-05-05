#include<cstdio>
inline int abs( int a ) { return a < 0? -a : a; }
inline int conv( char *a ) { return ( a[ 0 ]-'A' )*676 + ( a[ 1 ]-'A' )*26 + a[ 2 ]-'A'; }

int main()
{
    int t, num;
    char alpha[ 5 ];
    scanf( "%d", &t );

    while( t-- )
    {
        scanf( "%3s-%d", alpha, &num );
        puts( abs( conv( alpha ) - num ) <= 100? "nice" : "not nice" );
    }

    return 0;
}
