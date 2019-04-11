#include<cstdio>
#include<set>
std::set<int>exist;
bool happy( int n, const int start )
{
    if( n == 1 )
        return true;
    if( exist.find( n ) != exist.end() )
        return false;
    exist.insert( n );
    int tmp = 0;
    while( n )
    {
        tmp += ( n % 10 ) * ( n % 10 );
        n /= 10;
    }
    return happy( tmp, start );
}

int main()
{
    int t, n;
    scanf( "%d", &t );

    for( int i = 1; i <= t; ++i )
    {
        scanf( "%d", &n );
        printf( "Case #%d: %d is %s number.\n", i, n, happy( n, n )? "a Happy" : "an Unhappy" );
        exist.clear();
    }

    return 0;
}
