#include<cstdio>
#include<set>
using namespace std;

int main()
{
    int t, one, two, in;
    scanf( "%d", &t );

    while( t-- )
    {
        int discard = 0;
        multiset<int>list;
        scanf( "%d %d", &one, &two );
        for( int i = 0; i < one; ++i )
        {
            scanf( "%d", &in );
            list.insert( in );
        }
        for( int i = 0; i < two; ++i )
        {
            scanf( "%d", &in );
            if( list.find( in ) != list.end() )
                list.erase( list.find( in ) );
            else
                ++discard;
        }
        printf( "%d\n", discard + list.size() );
    }

	return 0;
}