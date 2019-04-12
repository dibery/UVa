#include<cstdio>
#define a3 2*num[j]-num[i]

int main()
{
    int n;

    while( scanf( "%d:", &n ) && n )
    {
        int num[ n ], order[ n ];
        bool anti = true;
        for( int i = 0; i < n; ++i )
            scanf( "%d", num+i ), order[ num[ i ] ] = i;
        for( int i = 0; i < n-2 && anti; ++i )
            for( int j = i+1; j < n-1 && anti; ++j )
                if( a3 >= 0 && a3 < n && order[ a3 ] > j )
                    anti = false;
        puts( anti? "yes" : "no" );
    }

    return 0;
}