#include<cstdio>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int t, kind = 0;
    double total = 0;
    char tmp[ 32 ], *check;
    string in, all[ 10000 ];
    map<string,int>species;
    scanf( "%d\n\n", &t );

    while( t )
    {
        if( gets( tmp ) && *tmp )
        {
            in = tmp;
            ++species[ in ];
            ++total;
            if( species[ in ] == 1 )
                all[ kind++ ] = in;
        }
        else
        {
            sort( all, all+kind );
            for( int i = 0; i < kind; ++i )
                printf( "%s %.4f\n", all[ i ].c_str(), species[ all[ i ] ] / total * 100 );
            printf( --t? "\n" : "" );
            total = kind = 0;
            species.clear();
        }
    }

	return 0;
}