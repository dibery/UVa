#include<cstdio>
#include<algorithm>
#include<cstring>
inline void plus( int &h, int &m )
{
    h += ++m / 60;
    m %= 60;
    h %= 24;
}
inline bool pand( const int h, const int m )
{
    char tmp[ 5 ], cp[ 5 ] = { 0 };
    sprintf( tmp, "%d", h * 100 + m );
    std::reverse_copy( tmp, tmp + strlen( tmp ), cp );
    return strcmp( tmp, cp ) == 0;
}

int main()
{
    int t, h, m;
    scanf( "%d", &t );

    while( t-- )
    {
        scanf( "%d:%d\n", &h, &m );
        do
            plus( h, m );
        while ( !pand( h, m ) );
        printf( "%02d:%02d\n", h, m );
    }

    return 0;
}
