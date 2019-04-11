#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
inline bool check( char *src, char *cmp, int A, int B )
{
    int a = 0, b = 0;
    for( int i = 0; i < 4; ++i )
        if( src[ i ] == cmp[ i ] )
            ++a;
        else if( strchr( cmp, src[ i ] ) )
            ++b;
    return a == A && b == B;
}

int main()
{
    int test, a[ 2 ], b[ 2 ];
    char guess[ 2 ][ 5 ], comb[] = { "BGORVY" }, brute[ 5 ] = { 0 };
    cin >> test;

    while( test-- )
    {
        bool cheat = true;
        cin >> guess[ 0 ] >> a[ 0 ] >> b[ 0 ] >> guess[ 1 ] >> a[ 1 ] >> b[ 1 ];
        for( int i = 0; i <= 2 && cheat; ++i )
            for( int j = i+1; j <= 3 && cheat; ++j )
                for( int k = j+1; k <= 4 && cheat; ++k )
                    for( int l = k+1; l <= 5 && cheat; ++l )
                    {
                        brute[ 0 ] = comb[ i ];
                        brute[ 1 ] = comb[ j ];
                        brute[ 2 ] = comb[ k ];
                        brute[ 3 ] = comb[ l ];
                        do
                            if( check( brute, guess[ 0 ], a[ 0 ], b[ 0 ] ) && check( brute, guess[ 1 ], a[ 1 ], b[ 1 ] ) )
                                cheat = false;
                        while( next_permutation( brute, brute+4 ) );
                    }
        cout << ( cheat? "Cheat" : "Possible" ) << endl;
    }

    return 0;
}
