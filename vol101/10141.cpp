#include<cstdio>
#include<cstring>

int main()
{
    bool first = true;
    int thing, firm, has, t = 0;
    double price;
    char tmp[ 1000 ], name[ 1000 ], ans[ 1000 ];

    while( scanf( "%d %d\n", &thing, &firm ) && thing )
    {
        int opt_has = 0;
        double opt_p = 1e12;
        for( int i = 0; i < thing; ++i )
            gets( tmp );
        for( int i = 0; i < firm; ++i )
        {
            gets( name );
            scanf( "%lf %d\n", &price, &has );
            for( int i = 0; i < has; ++i )
                gets( tmp );
            if( opt_has < has || opt_has == has && opt_p > price )
            {
                strcpy( ans, name );
                opt_has = has;
                opt_p = price;
            }
        }
        if( !first )
            puts( "" );
        else
            first = false;
        printf( "RFP #%d\n%s\n", ++t, ans );
    }

    return 0;
}
