#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    int t, tmp;
    char delim;
    string n;
    scanf( "%d", &t );

    while( t-- )
    {
        vector<int> input;
        while( scanf( "%d%c", &tmp, &delim ) )
        {
            input.push_back( tmp );
            if( delim == '\n' )
                break;
        }
        vector<int> order( input.size(), 0 );
        for( int i = input.size()-1; i >= 0; --i )
            order[ input[ i ]-1 ] = i;
        vector<string> num;
        for( int i = input.size(); i; --i )
        {
            cin >> n;
            num.push_back( n );
        }
        for( int i = 0; i < order.size(); ++i )
            cout << num[ order[ i ] ] << endl;
        if( t )
            puts( "" );
    }

	return 0;
}