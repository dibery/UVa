#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int sec;

    while( cin >> sec && sec )
    {
        int lim = ceil( sqrt( sec ) ), corner = lim * lim - lim + 1;
        if( lim % 2 == 1 )
            if( sec >= corner )
                cout << lim*lim - sec + 1 << ' ' << lim << endl;
            else
                cout << lim << ' ' << sec - ( lim-1 ) * ( lim-1 ) << endl;
        else//
            if( sec >= corner )
                cout << lim << ' ' << lim * lim - sec + 1 << endl;
            else
                cout << sec - ( lim-1 ) * ( lim-1 ) << ' ' << lim << endl;
    }

    return 0;
}
