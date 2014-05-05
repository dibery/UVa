#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int male, female, in;
    char tmp[ 3 ];
    register int t = 0, i, young = 100;

    while( scanf( "%d %d\n", &male, &female ) && male )
        if( male <= female )
        {
            printf( "Case %d: 0\n", ++t );
            for( i = female+male; i; --i )
                gets( tmp );
        }
        else
        {
            for( i = male; i; --i )
            {
                scanf( "%d\n", &in );
                if( in < young )
                    young = in;
            }
            for( i = female; i; --i )
                gets( tmp );
            printf( "Case %d: %d %d\n", ++t, male-female, young );
            young = 100;
        }

    return 0;
}
