#include<iostream>
#include<cmath>
#include<list>
using namespace std;

int main()
{
    double in, *tmp = new double;

    while( cin >> in )
    {
        list<int> ans;
        for( int i = in * 2; i > in; --i )
            if( modf( i * in / ( i - in ), tmp ) == 0 )
                ans.push_front( i );
        cout << ans.size() << endl;
        while( !ans.empty() )
        {
            cout << "1/" << in << " = 1/" << (long long int) ( ans.front() * in / ( ans.front() - in ) ) << " + 1/" << ans.front() << endl;
            ans.pop_front();
        }
    }
    return 0;
}
