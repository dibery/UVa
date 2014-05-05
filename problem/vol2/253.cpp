#include<iostream>
using namespace std;

inline bool same_dice( const string, const string );
void rotate_to_top( char*, int ), turn_side( char* );

int main()
{
    char dice[ 2 ][ 7 ] = { 0 };
    bool identical = false;

    while( cin >> dice[ 0 ][ 0 ] )
    {
        for( int i = 1; i < 12; ++i )
            cin.get( dice[ i/6 ][ i%6 ] );  //dice[ 0 ] won't be modified
        cin.get();
        for( int i = 1; i <= 6; ++i )
        {
            rotate_to_top( dice[ 1 ], i );
            for( int i = 0; i < 4; ++i )
            {
                identical = same_dice( dice[ 0 ], dice[ 1 ] );
                if( identical )
                    goto result;
                turn_side( dice[ 1 ] );
            }
        }
result:
        cout << ( identical? "TRUE" : "FALSE" ) << endl;
    }

    return 0;
}

inline bool same_dice( const string one, const string two )
{
    return ( one == two );
}

void rotate_to_top( char *dice, int target_top )
{
    char tmp = dice[ 0 ];
    if( target_top == 2 || target_top == 6 )
    {
        dice[ 0 ] = dice[ 1 ];
        dice[ 1 ] = dice[ 5 ];
        dice[ 5 ] = dice[ 4 ];
        dice[ 4 ] = tmp;
    }
    else if( target_top == 3 )
    {
        dice[ 0 ] = dice[ 2 ];
        dice[ 2 ] = dice[ 5 ];
        dice[ 5 ] = dice[ 3 ];
        dice[ 3 ] = tmp;
    }
    else if( target_top == 4 )
    {
        dice[ 0 ] = dice[ 5 ];
        dice[ 5 ] = tmp;
        tmp = dice[ 2 ];
        dice[ 2 ] = dice[ 3 ];
        dice[ 3 ] = tmp;
    }
    else if( target_top == 5 )
    {
        dice[ 0 ] = dice[ 3 ];
        dice[ 3 ] = dice[ 5 ];
        dice[ 5 ] = dice[ 2 ];
        dice[ 2 ] = tmp;
    }
}

void turn_side( char *dice )
{
    char tmp = dice[ 1 ] ;
    dice[ 1 ] = dice[ 2 ];
    dice[ 2 ] = dice[ 4 ];
    dice[ 4 ] = dice[ 3 ];
    dice[ 3 ] = tmp;
}
