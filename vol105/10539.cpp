#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const long long int LIM = 1000000000000LL;
bool ok( long long int n )
{
    for( long long int i = 2; i*i <= n; ++i )
        if( n % i == 0 )
            return false;
    return true;
}

int main()
{
    long long int t, end, begin;
    vector<long long int> data;
    for( long long int i = 2; i < 1000000; ++i )
        if( ok( i ) )
            for( long long int j = i*i; j < LIM; j *= i )
                data.push_back( j );
    sort( data.begin(), data.end() );
    unique( data.begin(), data.end() );
    for( scanf( "%lld", &t ); t--; )
    {
        scanf( "%lld %lld", &begin, &end );
        printf( "%d\n", upper_bound( data.begin(), data.end(), end ) - lower_bound( data.begin(), data.end(), begin ) );
    }
}
