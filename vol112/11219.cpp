#include<iostream>
using namespace std;

int main()
{
    int by, bm, bd, ey, em, ed, test, age;
    char no;
    cin >> test;

    for( int i = 1; i <= test; ++i )
    {
        cin >> ed >> no >> em >> no >> ey >> bd >> no >> bm >> no >> by;
        age = ey - by;
        if( em < bm || em == bm && ed < bd )
            --age;
        cout << "Case #" << i << ':';
        if( age < 0 )
            cout << " Invalid birth date";
        else if( age > 130 )
            cout << " Check birth date";
        else
            cout << ' ' << age;
        if( i != test )
            cout << endl;
    }
    return 0;
}