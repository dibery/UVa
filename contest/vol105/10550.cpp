#include<iostream>
using namespace std;

int main()
{
    int start, a, b, c, degree;

    while( cin >> start >> a >> b >> c && ( start || a || b || c ) )
    {
        degree = 1080;
        if( start >= a )
            degree += ( start - a ) * 9;
        else
            degree += 360 - ( a - start ) * 9;
        if( b >= a )
            degree += ( b - a ) * 9;
        else
            degree += 360 - ( a - b ) * 9;
        if( b >= c )
            degree += ( b - c ) * 9;
        else
            degree += 360 - ( c - b ) * 9;
        cout << degree << endl;
    }
    return 0;
}
