#include<iostream>
using namespace std;
typedef struct fragment
{
    double up, down;
} fragment;

int main()
{
    struct fragment left, middle, right;
    double up, down;
    while( cin >> up >> down )
    {
        if( up == 1 && down == 1 )
            break;
        left.up = 0;
        left.down = 1;
        right.up = 1;
        right.down = 0;
        middle.up = 1;
        middle.down = 1;
        while( up != middle.up || down != middle.down )
            if( up/down < middle.up/middle.down )
            {
                right.up = middle.up;
                right.down = middle.down;
                middle.up = right.up + left.up;
                middle.down = right.down + left.down;
                cout << 'L';
            }
            else if( up/down > middle.up/middle.down )
            {
                left.up = middle.up;
                left.down = middle.down;
                middle.up = right.up + left.up;
                middle.down = right.down + left.down;
                cout << 'R';
            }
        cout << endl;
    }
}
