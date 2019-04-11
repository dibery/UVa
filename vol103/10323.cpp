#include<iostream>
using namespace std;
inline long long int Fact( int a )
{
    long long int back = 1;
    for( int i = 2; i <= a; ++i )
        back *= i;
    return back;
}

int main()
{
    int fact;

    while( cin >> fact )
        if( fact <= 7 && fact >= 0 )
            cout << "Underflow!\n";
        else if( fact >= 14 )
            cout << "Overflow!\n";
        else if( fact > 7 && fact < 14 )
            cout << Fact( fact ) << endl;
        else//
            if( fact % 2 == 0 )
                cout << "Underflow!\n";
            else
                cout << "Overflow!\n";

	return 0;
}