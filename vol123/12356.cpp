#include<cstdio>
#include<cstring>
struct node
{
    int left, right;
};

int main()
{
    int army, dead, from, to;

    while( scanf( "%d %d", &army, &dead ) && army )
    {
        node man[ army+1 ];
        for( int i = 1; i <= army; ++i )
            man[ i ].left = i-1, man[ i ].right = i+1;
        man[ army ].right = 0;
        for( int i = 0; i < dead; ++i )
        {
            scanf( "%d %d", &from, &to );
            man[ man[ from ].left ].right = man[ to ].right;
            man[ man[ to ].right ].left = man[ from ].left;
            if( man[ from ].left )
                printf( "%d ", man[ from ].left );
            else
                printf( "* " );
            if( man[ to ].right )
                printf( "%d\n", man[ to ].right );
            else
                printf( "*\n" );
        }
        puts( "-" );
    }

	return 0;
}