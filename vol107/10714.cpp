#include<cstdio>
#include<algorithm>
inline int abs( int n ) { return n < 0? -n : n; }

int main()
{
    int t, len, ant, pos;
    scanf( "%d", &t );

    while( t-- )
    {
        int left = 2000000, right = -1, mid = -1;
        scanf( "%d %d", &len, &ant );
        while( ant-- )
        {
            scanf( "%d", &pos );
            left = std::min( left, pos );
            right = std::max( right, pos );
            if( abs( len / 2 - pos ) < abs( len / 2 - mid ) )
                mid = pos;
        }
        printf( "%d %d\n", std::min( len - mid, mid ), std::max( len - left, right ) );
    }

	return 0;
}