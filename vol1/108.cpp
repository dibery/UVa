#include<iostream>
using namespace std;
int Kadane( int *array ), size;

int main()
{
    while( cin >> size )
    {
        int num[ size ][ size ], max = 0, sum = 0, calc[ size ];

        for( int i = 0; i < size; i++ )
        {
            for( int j = 0; j < size; j++ )
                cin >> num[ i ][ j ];
            calc[ i ] = 0;
        }

        for( int i = 0; i < size; i++ )
        {
            for( int j = i; j < size; j++ )
            {
                for( int k = 0; k < size; k++ )
                    calc[ k ] += num[ j ][ k ];
                if( Kadane( calc ) > max )
                    max = Kadane( calc );
            }
            for( int k = 0; k < size; k++ )
                calc[ k ] = 0;
        }
        cout << max << endl;
    }
    return 0;
}

int Kadane( int *array )
{
    int sum = 0, max = 0;
    for( int i = 0; i < size; i++ )
    {
        sum += array[ i ];
        if( sum > max )
            max = sum;
        if( sum < 0 )
            sum = 0;
    }
    return max;
}
