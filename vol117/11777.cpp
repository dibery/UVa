#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int test, term1, term2, final, attend, t1, t2, t3, total;
    cin >> test;

    for( int i = 1; i <= test; ++i )
    {
        cin >> term1 >> term2 >> final >> attend >> t1 >> t2 >> t3;
        total = term1 + term2 + final + attend + ( t1+t2+t3 - min( t1, min( t2, t3 ) ) ) / 2;
        cout << "Case " << i << ": ";
        if( total >= 90 )
            cout << "A\n";
        else if( total >= 80 )
            cout << "B\n";
        else if( total >= 70 )
            cout << "C\n";
        else if( total >= 60 )
            cout << "D\n";
        else
            cout << "F\n";
    }
    return 0;
}
