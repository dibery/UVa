#include<cstdio>
#include<cstring>

int main()
{
    int t, len, word;
    char prev[ 101 ], now[ 101 ];
    scanf( "%d", &t );

    while( t-- )
    {
        scanf( "%d %d %s", &len, &word, prev );
        int ans = len;
        for( int i = 1, k; i < word; ++i )
        {
            scanf( "%s", now );
            for( k = 0; k < len; ++k )
                if( !strncmp( prev+k, now, len-k ) )
                {
                    ans += k;
                    break;
                }
            if( k == len )
                ans += len;
            strcpy( prev, now );
        }
        printf( "%d\n", ans );
    }
    return 0;
}
