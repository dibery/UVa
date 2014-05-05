#include<iostream>
using namespace std;
inline int one( int n )
{
    int i = 1;
    while( i < n )
        i = i * 10 + 1;
    return i;
}
inline int Len( int n )
{
    int i = 1, back = 1;
    while( i < n && ++back )
        i = i * 10 + 1;
    return back;
}

int main()
{
    int n;

    while( cin >> n )
    {
        int all1 = one( n ) % n, len = Len( n );
        while( all1 )
        {
            all1 = ( all1 * 10 + 1 ) % n;
            ++len;
        }
        cout << len << endl;
    }

	return 0;
}