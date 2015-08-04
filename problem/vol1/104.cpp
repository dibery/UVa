#include<iostream>
#include<list>
using namespace std;

int main()
{
    int size, prev[ 20 ][ 20 ][ 20 ];    //stage,begin,end;
    double gain[ 20 ][ 20 ][ 20 ];
    for( int i = 0; i < 20; ++i )
        gain[ 0 ][ i ][ i ] = 1.0;

    while( cin >> size )
    {
        for( int i = 1; i < size; ++i )
            for( int j = 0; j < size; ++j )
                for( int k = 0; k < size; ++k )
                    gain[ i ][ j ][ k ] = 0.0;
        for( int i = 0; i < size; ++i )
            for( int j = 0; j < size; ++j )
                if( i != j )
                    cin >> gain[ 0 ][ i ][ j ];
        int stage, begin, middle, end;
        for( stage = 1; stage < size; ++stage )
            for( begin = 0; begin < size; ++begin )
                for( middle = 0; middle < size; ++middle )
                    for( end = 0; end < size; ++end )
                        if( gain[ stage-1 ][ begin ][ middle ] * gain[ 0 ][ middle ][ end ] > gain[ stage ][ begin ][ end ] )
                        {
                            gain[ stage ][ begin ][ end ] = gain[ stage-1 ][ begin ][ middle ] * gain[ 0 ][ middle ][ end ];
                            prev[ stage ][ begin ][ end ] = middle;
                        }
        for( stage = 1; stage < size; ++stage )
            for( begin = 0; begin < size; ++begin )
                if( gain[ stage ][ begin ][ begin ] > 1.01 )
                    goto next;
next:
        if( stage == size )
            cout << "no arbitrage sequence exists" << endl;
        else
        {
            list<int> output;
            for( int i = stage, find = begin; i > 0; --i )
            {
                output.push_front( prev[ i ][ begin ][ find ] );
                find = prev[ i ][ begin ][ find ];
            }
            output.push_front( begin );
            output.push_back( begin );
            for( list<int>::iterator it = output.begin(); it != output.end(); ++it )
                cout << ( it == output.begin()? "" : " " ) << *it+1;
            cout << endl;
        }
    }
}