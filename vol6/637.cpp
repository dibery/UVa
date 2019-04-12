#include<iostream>
using namespace std;
const char *status[] = { "front", "back" };
struct node
{
    int sheet, num[ 2 ];
    string face;
};

int main()
{
    int n;

    while( cin >> n && n )   //13 pages
    {
        if( n == 1 )
        {
            cout << "Printing order for 1 pages:\nSheet 1, front: Blank, 1\n";
            continue;
        }
        int sheet = n / 4;
        if( n % 4 != 0 )
            sheet = ( n / 4 * 4 + 4 ) / 4;  //8 side, 4 sheets
        int side = sheet * 2;
        node book[ side ];
        for( int i = 0; i < side; ++i )
        {
            book[ i ].face = status[ i % 2 ];
            book[ i ].sheet = i / 2 + 1;
            book[ i ].num[ 0 ] = book[ i ].num[ 1 ] = -1;
        }
        for( int i = 1; i <= side; ++i )
            book[ i-1 ].num[ i % 2 ] = i;
        for( int i = side+1; i <= n; ++i )
            book[ sheet * 4 - i ].num[ i % 2 ] = i;
        cout << "Printing order for " << n << " pages:\n";
        for( int i = 0; i < side; ++i )
        {
            cout << "Sheet " << book[ i ].sheet << ", " << book[ i ].face << ( book[ i ].face == "front"? ": " : " : " );
            if( book[ i ].num[ 0 ] == -1 )
                cout << "Blank";
            else
                cout << book[ i ].num[ 0 ];
            cout << ", ";
            if( book[ i ].num[ 1 ] == -1 )
                cout << "Blank";
            else
                cout << book[ i ].num[ 1 ];
            cout << endl;
        }
    }

    return 0;
}
