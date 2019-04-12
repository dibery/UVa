#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cctype>
using namespace std;
int gcd( int a, int b ) { return a % b? gcd( b, a%b ) : b; }

int main()
{
    int t, tmp;
    char in[ 100000 ];
    vector<int> all;
    scanf( "%d\n", &t );

    while( t-- )
    {
        int ans = 0, num = 0;
        char delim = 0;
        gets( in );

        for( int i = 0; in[ i ]; ++i )
            if( ( !i || in[ i-1 ] == ' ' ) && isdigit( in[ i ] ) )
                all.push_back( strtol( in+i , NULL, 10 ) );

        for( int i = all.size()-1; i; --i )
            for( int j = i-1; j >= 0; --j )
                ans = max( ans, gcd( all[ i ], all[ j ] ) );

        printf( "%d\n", ans );
        all.clear();
    }
    return 0;
}
