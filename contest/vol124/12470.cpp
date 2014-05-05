#include<cstdio>
#include<vector>
#define mod 1000000009
using namespace std;

int main()
{
    vector<long long int>tribo;
    long long int n;
    tribo.push_back( 0 );
    tribo.push_back( 1 );
    tribo.push_back( 2 );
    tribo.push_back( 3 );

    while( tribo[ tribo.size()-1 ] != 0 || tribo[ tribo.size()-2 ] != 1 || tribo[ tribo.size()-3 ] != 2 )
        printf( "%I64d ", n = tribo[ tribo.size()-1 ] + tribo[ tribo.size()-2 ] + tribo[ tribo.size()-3 ] % mod ), tribo.push_back( n % mod );

	return 0;
}