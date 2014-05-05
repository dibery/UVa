#include<iostream>
#include<cstring>
using namespace std;
typedef struct test
{
    string comp, left, right;
} test;

int main()
{
    int totaltest;
    cin >> totaltest;

    for( int time = 0; time < totaltest; ++time )
    {
        register test trial[ 3 ];    //3 outcomes

        for( int n = 0; n < 3; ++n )    //input
            cin >> trial[ n ].left >> trial[ n ].right >> trial[ n ].comp;

        register char target, islight;
        for( target = 'A'; target <= 'L'; ++target )
            for( islight = 0; islight <= 1; ++islight )
                if( islight )  //the fake coin is light
                    for( register short i = 0; i < 3; ++i )
                    {
                        if( strchr( trial[ i ].left.c_str(), target ) == NULL && strchr( trial[ i ].right.c_str(), target ) != NULL && trial[ i ].comp != "up" )
                            break;
                        if( strchr( trial[ i ].left.c_str(), target ) != NULL && strchr( trial[ i ].right.c_str(), target ) == NULL && trial[ i ].comp != "down" )
                            break;
                        if( !( (strchr( trial[ i ].left.c_str(), target ) == NULL) ^ (strchr( trial[ i ].right.c_str(), target)  == NULL) ) && trial[ i ].comp != "even" )
                            break;
                        if( i == 2 )
                            goto output;
                    }
                else    //the fake coin is heavy
                    for( register short i = 0; i < 3; ++i )
                    {
                        if( strchr( trial[ i ].left.c_str(), target ) == NULL && strchr( trial[ i ].right.c_str(), target ) != NULL && trial[ i ].comp != "down" )
                            break;
                        if( strchr( trial[ i ].left.c_str(), target ) != NULL && strchr( trial[ i ].right.c_str(), target ) == NULL && trial[ i ].comp != "up" )
                            break;
                        if( !( (strchr( trial[ i ].left.c_str(), target ) == NULL) ^ (strchr( trial[ i ].right.c_str(), target)  == NULL) ) && trial[ i ].comp != "even" )
                            break;
                        if( i == 2 )
                            goto output;
                    }
output:
        cout << target << " is the counterfeit coin and it is " << ( islight? "light.\n" : "heavy.\n" );
    }
    return 0;
}
