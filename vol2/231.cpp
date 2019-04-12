#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int LIS( vector<int> &s )
{
    vector<int> v( 1, s[ 0 ] );

    for( int i = 1; i < s.size(); ++i )
        if ( s[ i ] > v.back() )
            v.push_back( s[ i ] );
        else
            *lower_bound( v.begin(), v.end(), s[ i ] ) = s[ i ];
    s.clear();
    return v.size();
}

int main()
{
    int in, test = 0;
    vector<int> array;

    while( scanf( "%d", &in ) != EOF )
    {
        if( in == -1 )
            if( array.empty() )
                break;
            else
                printf( "%sTest #%d:\n  maximum possible interceptions: %d\n", test != 1? "\n" : "", ++test, LIS( array ) );
        else
            array.push_back( -in );
    }

    return 0;
}
