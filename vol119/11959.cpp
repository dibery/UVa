#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

inline bool same_dice( const string, const string );
void rotate_to_top( char*, int ), turn_side( char* );

int main()
{
    char dice[ 2 ][ 7 ] = { 0 };
    bool identical = false;
    int t;
    cin >> t;

    while( t-- )
    {
        cin >> dice[ 0 ] >> dice[ 1 ];  //dice[ 0 ] won't be modified
        for( int i = 1; i <= 6; ++i )
        {
            rotate_to_top( dice[ 1 ], i );//cout<<"rotated "<<dice[1]<<endl;
            for( int i = 0; i < 4; ++i )
            {
                identical = same_dice( dice[ 0 ], dice[ 1 ] );
                if( identical )
                    goto result;
                turn_side( dice[ 1 ] );
            }
        }
result:
        cout << ( identical? "Equal" : "Not Equal" ) << endl;
    }

    return 0;
}

inline bool same_dice( const string one, const string two ){ return ( one == two ); }

void rotate_to_top( char *dice, int target_top )
{
    char tmp = dice[ 0 ];
    if( target_top == 2 )
    {
        swap( dice[ 0 ], dice[ 1 ] );
        swap( dice[ 2 ], dice[ 4 ] );
    }
    else if( target_top == 3 )
    {
        dice[ 0 ] = dice[ 4 ];
        dice[ 4 ] = dice[ 1 ];
        dice[ 1 ] = dice[ 2 ];
        dice[ 2 ] = tmp;
    }
    else if( target_top == 4 )
    {
        dice[ 0 ] = dice[ 3 ];
        dice[ 3 ] = dice[ 1 ];
        dice[ 1 ] = dice[ 5 ];
        dice[ 5 ] = tmp;
    }
    else if( target_top == 5 || target_top == 6 )
    {
        dice[ 0 ] = dice[ 3 ];
        dice[ 3 ] = dice[ 1 ];
        dice[ 1 ] = dice[ 5 ];
        dice[ 5 ] = tmp;
    }
}

void turn_side( char *dice )
{
    char tmp = dice[ 2 ] ;
    dice[ 2 ] = dice[ 3 ];
    dice[ 3 ] = dice[ 4 ];
    dice[ 4 ] = dice[ 5 ];
    dice[ 5 ] = tmp;
}
