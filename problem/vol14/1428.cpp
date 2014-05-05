#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
    int val, B, b, S, s;
} data[ 20000 ];

int main()
{
    int t, size;
    scanf( "%d", &t );

    while( t-- )
    {
        vector<int>seq;
        long long int ans = 0;
        scanf( "%d", &size );
        for( int i = 0; i < size; ++i )
            scanf( "%d", &data[ i ].val );

        for( int i = 0; i < size; ++i )
        {
            seq.insert( upper_bound( seq.begin(), seq.end(), data[ i ].val ), data[ i ].val );
            data[ i ].b = lower_bound( seq.begin(), seq.end(), data[ i ].val ) - seq.begin();
            data[ i ].s = seq.size() - data[ i ].b - 1;
        }
        seq.clear();
        for( int i = size-1; i >= 0; --i )
        {
            data[ i ].B = seq.insert( upper_bound( seq.begin(), seq.end(), data[ i ].val ), data[ i ].val ) - seq.begin();
            data[ i ].S = seq.size() - data[ i ].B - 1;
        }

        for( int i = 0; i < size; ++i )
            ans += data[ i ].b * data[ i ].S + data[ i ].s * data[ i ].B;
        printf( "%lld\n", ans );
    }

    return 0;
}