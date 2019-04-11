#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
        int size, num[ 30 ], t = 0;

        while( scanf( "%d", &size ) == 1 )
        {
                bool is = true;
                set<int> add;
                for( int i = 0; i < size; ++i )
                        scanf( "%d", num + i );
                add.insert( num, num+2 ), add.insert( num[ 0 ] + num[ 1 ] );
                is &= is_sorted( num, num + size ) & unique( num, num + size ) == num + size;
                for( int i = 2; i < size && is; ++i )
                {
                    set<int> tmp;
                    for( set<int>::iterator it = add.begin(); it != add.end(); ++it )
                        tmp.insert( *it + num[ i ] );
                    is &= add.find( num[ i ] ) == add.end();
                    add.insert( tmp.begin(), tmp.end() );
                    add.insert( num[ i ] );
                }
                printf( "Case #%d:", ++t );
                for( int i = 0; i < size; ++i )
                        printf( " %d", num[ i ] );
                puts( is? "\nThis is an A-sequence." : "\nThis is not an A-sequence." );
        }
}
