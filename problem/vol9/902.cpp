#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
using namespace std;
int pw;
char str[ 1000000 ], tmp[ 11 ] = { 0 }, ans[ 11 ] = { 0 };

int main()
{
    while( scanf( "%d %s", &pw, str ) != EOF )
    {
        map<long long int, int> freq;
        int len = strlen( str ), maxi = 0;
        for( int i = 0; i+pw <= len; ++i )
        {
            strncpy( tmp, str+i, pw );
            tmp[ pw ] = 0;
            ++freq[ strtoll( tmp, NULL, 36 ) ];
        }
        for( int i = 0; i+pw <= len; ++i )
        {
            strncpy( tmp, str+i, pw );
            tmp[ pw ] = 0;
            if( freq[ strtoll( tmp, NULL, 36 ) ] > maxi )
            {
                maxi = freq[ strtoll( tmp, NULL, 36 ) ];
                strcpy( ans, tmp );
            }
        }
        puts( ans );
    }

    return 0;
}
