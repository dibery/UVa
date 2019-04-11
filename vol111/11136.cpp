#include<cstdio>
#include<set>
using namespace std;

int main()
{
    int day, quant, tmp;

    while( scanf( "%d", &day ) && day )
    {
        long long int cost = 0;
        multiset<int> urn;

        for( int i = 0; i < day; ++i )
        {
            scanf( "%d", &quant );
            for( int k = 0; k < quant; ++k )
                scanf( "%d", &tmp ), urn.insert( tmp );
            cost += *--urn.end() - *urn.begin();
            urn.erase( urn.begin() );
            urn.erase( --urn.end() );
        }
        printf( "%lld\n", cost );
    }

    return 0;
}