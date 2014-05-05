#include<cstdio>
inline unsigned int bit( int i ) { return 1 << i; }

int main()
{
    unsigned int target, high, low;

    while( scanf( "%d %d %d", &target, &low, &high ) != EOF )
    {
        unsigned int ans = 0;
        for( int i = 31; i >= 0; --i )
            if( ( ans | bit( i ) ) > high );
            else if( ( ans | bit( i ) ) - 1 < low )
                ans |= bit( i );
            else//
                if( !( target & bit( i ) ) )
                    ans |= bit( i );
        printf( "%u\n", ans );
    }

	return 0;
}