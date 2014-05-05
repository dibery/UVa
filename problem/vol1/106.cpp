#include<cstdio>
int gcd( int a, int b ) { return a % b? gcd( b, a%b ) : b; }

int main()
{
    int N, tmp;

    while( scanf( "%d", &N ) != EOF )
    {
        bool exist[ 1000001 ] = { false };
        int sol = 0, use = 0;
        for( long long int m = 2; m < N; ++m )
            for( long long int n = m % 2? 2 : 1; m*m + n*n <= N && m > n; n += 2 )
            if( gcd( m, n ) == 1 )
            {
                for( int i = 1; i * ( m*m + n*n ) <= N; ++i )
                {
                    if( !exist[ tmp = i * ( m*m - n*n ) ] )
                    {
                        ++use;
                        exist[ tmp ] = true;
                    }
                    if( !exist[ tmp = i * 2 * m * n ] )
                    {
                        ++use;
                        exist[ tmp ] = true;
                    }
                    if( !exist[ tmp = i * ( m*m + n*n ) ] )
                    {
                        ++use;
                        exist[ tmp ] = true;
                    }
                }
                ++sol;
            }
        printf( "%d %d\n", sol, N-use );
    }

    return 0;
}
