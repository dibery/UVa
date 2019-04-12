#include<cstdio>
bool find( int *tar, int *src, int index, bool *use )
{
    for( int i = 0; i < 4; ++i )
        if( src[ index ] == tar[ i ] && !use[ i ] )
            return use[ i ] = true;
    return false;
}

int main()
{
    int t, guess, n[ 4 ], A, B, tmp[ 4 ];
    scanf( "%d", &t );

    while( t-- )
    {
        bool no[ 10000 ] = { false };
        int cand = 0, ans;
        scanf( "%d", &guess );
        for( int i = 0; i < guess; ++i )
        {
            scanf( "%1d%1d%1d%1d %d/%d", n, n+1, n+2, n+3, &A, &B );
            for( tmp[ 0 ] = 0; tmp[ 0 ] < 10; ++tmp[ 0 ] )
                for( tmp[ 1 ] = 0; tmp[ 1 ] < 10; ++tmp[ 1 ] )
                    for( tmp[ 2 ] = 0; tmp[ 2 ] < 10; ++tmp[ 2 ] )
                        for( tmp[ 3 ] = 0; tmp[ 3 ] < 10; ++tmp[ 3 ] )
                            if( !no[ tmp[ 0 ]*1000 + tmp[ 1 ]*100 + tmp[ 2 ]*10 + tmp[ 3 ] ] )
                            {
                                int a = 0, b = 0;
                                bool used[ 4 ] = { false };
                                for( int i = 0; i < 4; ++i )
                                    if( tmp[ i ] == n[ i ] )
                                        ++a, used[ i ] = true;
                                for( int i = 0; i < 4; ++i )
                                    if( tmp[ i ] != n[ i ] && find( tmp, n, i, used ) )
                                        ++b;
                                if( a != A || b != B )
                                    no[ tmp[ 0 ]*1000 + tmp[ 1 ]*100 + tmp[ 2 ]*10 + tmp[ 3 ] ] = true;
                            }
        }
        for( int i = 0; i < 10000; ++i )
            if( !no[ i ] && cand <= 2 )
                ++cand, ans = i;
        if( cand == 1 )
            printf( "%04d\n", ans );
        else if( !cand )
            puts( "impossible" );
        else
            puts( "indeterminate" );
    }
    return 0;
}
