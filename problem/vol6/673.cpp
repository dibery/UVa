#include<iostream>
#include<stack>
#include<cstdlib>
using namespace std;

int main()
{
    int test, i;
    char word[ 130 ], tmp[ 10 ];
    stack<char> put;
    cin.getline( tmp, 10 );
    test = atoi( tmp );

    while( test-- )
    {
        bool wrong = false;
        cin.getline( word, 130 );
        for( i = 0; word[ i ] && !wrong; ++i )
        {
            if( word[ i ] == '(' || word[ i ] == '[' )
                put.push( word[ i ] );
            else//
                if( word[ i ] == ')' )
                    if( put.empty() || put.top() != '(' )
                       wrong = true;
                    else
                        put.pop();
                else
                    if( put.empty() || put.top() != '[' )
                       wrong = true;
                    else
                        put.pop();
        }
        cout << ( ( wrong || !put.empty() )? "No" : "Yes" ) << endl;
        while( !put.empty() )
            put.pop();
    }
    return 0;
}
