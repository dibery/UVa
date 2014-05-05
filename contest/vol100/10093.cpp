#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;
inline int transform( int a )
{
    if( isdigit( a ) )
        return a-'0';
    else if( isupper( a ) )
        return a-'A'+10;
    else
        return a-'a'+36;
}

int main()
{
    string input;
    int s, len, sum, base;

    while( cin >> input )
    {
        int max = -1;
        char *num = new char[ input.size()+1 ];
        strcpy( num, input.c_str() );
        sum = 0;
        len = strlen( num );
        for( int i = 0; i < len; ++i )
            if( isalnum( num[ i ] ) )
            {
                if( transform( num[ i ] ) > max )
                    max = transform( num[ i ] );
                sum += transform( num[ i ] );
            }
        if( max == 0 )
            max = 1;
        for( base = max+1; base <= 62 && sum % ( base-1 ); ++base );
        if( base >= 63 )
            cout << "such number is impossible!\n";
        else
            cout << base << endl;
        delete[] num;
    }

	return 0;
}