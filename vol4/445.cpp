#include<cctype>
#include<iostream>
using namespace std;
void transform( int &n )
{
    n = 0;
    while( isdigit( cin.peek() ) )
        n += cin.get() - '0';
}

int main()
{
    char status;
    int quant = 0, line = 0;

    while( isprint( status = cin.peek() ) || status == '\n' )
        if( isdigit( status ) )
        {
            transform( quant );
            cin >> status;
            if( line + quant > 132 )
                quant = 132 - line;
            line += quant;
            if( status == 'b' )
                status = ' ';
            for( int i = 0; i < quant; ++i )
                cout << status;
        }
        else if( status == '!' || status == '\n' )
        {
            cin.get();
            cout << endl;
            line = 0;
        }

    return 0;
}