#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
    int taken, cate, tmp, size;

    while( scanf( "%d", &taken ) && taken )
    {
        scanf( "%d", &cate );
        vector<int> fred, course[ cate ];
        int requires[ 100 ] = { 0 };
        bool pass = true;

        for( int i = 0; i < taken; ++i )
        {
            scanf( "%d", &tmp );
            fred.push_back( tmp );
        }
        for( int i = 0; i < cate; ++i )
        {
            scanf( "%d %d", &size, requires+i );
            for( int k = 0; k < size; ++k )
            {
                scanf( "%d", &tmp );
                course[ i ].push_back( tmp );
            }
        }
        while( !fred.empty() )
        {
            for( int i = 0; i < cate; ++i )
                if( find( course[ i ].begin(), course[ i ].end(), fred.back() ) != course[ i ].end() )
                    --requires[ i ];
            fred.pop_back();
        }
        for( int i = 0; i < cate && pass; ++i )
            if( requires[ i ] > 0 )
                pass = false;
        puts( pass? "yes" : "no" );
    }

	return 0;
}