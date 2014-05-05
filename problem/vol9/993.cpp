#include<cstdio>
#include<list>

int main()
{
    int t, num, dig[] = { 9, 8, 6, 4, 2, 3, 5, 7 };
    scanf( "%d", &t );

    while( t-- )
    {
        std::list<int> ans;
        scanf( "%d", &num );
        if( num == 1 )
        {
            puts( "1" );
            continue;
        }
        if( !num )
        {
            puts( "10" );
            continue;
        }
        for( int i = 0; i < 8; ++i )
            while( num % dig[ i ] == 0 )
            {
                num /= dig[ i ];
                ans.push_back( dig[ i ] );
            }
        if( ans.empty() || num != 1 )
        {
            puts( "-1" );
            continue;
        }
        ans.sort();
        while( !ans.empty() )
        {
            printf( "%d", ans.front() );
            ans.pop_front();
        }
        puts( "" );
    }

    return 0;
}
