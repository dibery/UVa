#include<iostream>
using namespace std;

int main()
{
    long long int in;

    while( cin >> in && in >= 0 )
        cout << ( in? in*(in+1) / 2 + 1 : 1 ) << endl;

	return 0;
}