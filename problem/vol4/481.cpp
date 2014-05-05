#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int pos[ 600000 ] = { 0 }, now = 0;
int LIS( vector<int> &s )
{
    if ( s.empty() )
        return 0;
    vector<int> v;
    v.push_back( s[ 0 ] );
    *pos = ++now;

    for( int i = 1; i < s.size(); ++i )
        if ( s[ i ] > v.back() )
        {
            v.push_back( s[ i ] );
            pos[ i ] = ++now;
        }
        else
        {
            *lower_bound( v.begin(), v.end(), s[ i ] ) = s[ i ];
            pos[ i ] = lower_bound( v.begin(), v.end(), s[ i ] ) - v.begin() + 1;
        }
    return v.size();
}

int main()
{
    int in, size;
    vector<int> array, ans;

    while( scanf( "%d", &in ) != EOF )
        array.push_back( in );
    printf( "%d\n-\n", size = LIS( array ) );
    for( int i = array.size()-1; i >= 0; --i )
        if( pos[ i ] == size && --size >= 0 )
            ans.push_back( array[ i ] );
    for( int i = ans.size(); !ans.empty(); --i, ans.pop_back() )
        printf( "%d\n", ans.back() );

    return 0;
}
