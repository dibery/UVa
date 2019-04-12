#include<iostream>
#include<list>
using namespace std;

int main()
{
    int in;
    list<int>factor;

    while( cin >> in && in )
    {
        cout << in << " = ";
        if( in < 0 )
        {
            factor.push_back( -1 );
            in = -in;
        }
        for( int i = 2; i < 46340 && in != 1; ++i )
            while( in % i == 0 )
            {
                in /= i;
                factor.push_back( i );
            }
        if( in != 1 )
            factor.push_back( in );
        cout << factor.front();
        factor.pop_front();
        while( !factor.empty() )
        {
            cout << " x " << factor.front();
            factor.pop_front();
        }
        cout << endl;
    }

    return 0;
}
