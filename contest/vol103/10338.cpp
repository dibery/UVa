#include<iostream>
using namespace std;
unsigned long long int fact[ 21 ] = { 1 };

int main()
{
    int size, j;
    char word[ 21 ];
    for( int i = 1; i <= 20; ++i )
        fact[ i ] = i * fact[ i-1 ];
    cin >> size;

    for( int i = 1; i <= size; ++i )
    {
        int stat[ 26 ] = { 0 };
        cin >> word;
        for( j = 0; word[ j ]; ++j )
            ++stat[ word[ j ]-'A' ];
        long long int ans = fact[ j ];
        for( j = 0; j < 26; ++j )
            ans /= fact[ stat[ j ] ];
        cout << "Data set " << i << ": " << ans << endl;
    }
    return 0;
}
