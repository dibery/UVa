#include<cstdio>
#include<algorithm>
using namespace std;
template<typename T>
inline T min( T a, T b, T c, T d ) { return min( min( min( a, b ), c ), d ); }

int main()
{
    long long int humble[ 5842 ] = { 1 }, n2 = 0, n3 = 0, n5 = 0, n7 = 0;
    int n;
    const char *end[] = { "th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th" };

    for( int i = 1; i < 5842; ++i )
    {
        for( ; humble[ n2 ] * 2 <= humble[ i-1 ]; ++n2 );
        for( ; humble[ n3 ] * 3 <= humble[ i-1 ]; ++n3 );
        for( ; humble[ n5 ] * 5 <= humble[ i-1 ]; ++n5 );
        for( ; humble[ n7 ] * 7 <= humble[ i-1 ]; ++n7 );
        humble[ i ] = min( humble[ n2 ]*2, humble[ n3 ]*3, humble[ n5 ]*5, humble[ n7 ]*7 );
    }
    while( scanf( "%d", &n ) && n )
        printf( "The %d%s humble number is %d.\n", n, n%100 >= 11 && n%100 <= 13? "th" : end[ n % 10 ], humble[ n-1 ] );

	return 0;
}