#include<cstdio>
#include<algorithm>

int main()
{
    int t = 0, len;

    while( scanf( "%d", &len ) != EOF )
    {
        long long int num[ len ], ans = 0;
        for( int i = 0; i < len; ++i )
            scanf( "%lld", num+i );
        for( int i = 0; i < len; ++i )
        {
            long long int tmp = 1;
            for( int j = i; j < len; ++j )
            {
                tmp *= num[ j ];
                ans = std::max( ans, tmp );
            }
        }
        printf( "Case #%d: The maximum product is %lld.\n\n", ++t, ans );
    }

	return 0;
}