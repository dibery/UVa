#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    unsigned int in;
    while( cin >> in && in )
    {
        unsigned int a = sqrt( in );
        cout << ( a*a == in? "yes\n" : "no\n" );
    }
    return 0;
}
