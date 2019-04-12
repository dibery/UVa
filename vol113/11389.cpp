#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp( int a, int b ) { return a > b; }

int main()
{
    int driver, work, over;

    while( cin >> driver >> work >> over && driver )
    {
        vector<int>morning( driver, 0 ), evening( driver, 0 );
        int pay = 0;
        for( int i = 0; i < driver; ++i )
            cin >> morning[ i ];
        for( int i = 0; i < driver; ++i )
            cin >> evening[ i ];
        sort( morning.begin(), morning.end(), cmp );
        sort( evening.begin(), evening.end() );
        for( int i = 0, now; i < driver; ++i )
        {
            now = morning.back();
            pay += ( now + evening.back() - work < 0? 0 : now + evening.back() - work ) * over;
            evening.pop_back();
            morning.pop_back();
        }
        cout << pay << endl;
    }

    return 0;
}
