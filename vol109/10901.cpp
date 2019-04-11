#include<cstdio>
#include<cstring>
#include<queue>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
class car
{
public:
    int time, serial;
    bool operator() ( const car &a, const car &b ) { return a.serial > b.serial; }
    car( int t = 0, int s = 0 ) { time = t; serial = s; }
};

int main()
{
    int t, capacity, transfer, command, arrive;
    scanf( "%d", &t );

    while( t-- )
    {
        int time = 0;
        char side[ 6 ];
        bool onleft = true;
        priority_queue<car,vector<car>,car>output;
        queue<car> left, right;
        vector<car>ferry;

        scanf( "%d %d %d", &capacity, &transfer, &command );
        for( int i = 0; i < command; ++i )
        {
            scanf( "%d %s", &arrive, side );
            if( *side == 'l' )
                left.push( car( arrive, i ) );
            else
                right.push( car( arrive, i ) );
        }

        while( !left.empty() || !right.empty() )
        {
            int L = ( left.empty()? INT_MAX : left.front().time ), R = ( right.empty()? INT_MAX : right.front().time );
            if( onleft )
            {
                if( L <= R || !left.empty() && time >= left.front().time )
                {
                    time = max( time, left.front().time );
                    while( !left.empty() && ferry.size() < capacity && time >= left.front().time )
                    {
                        ferry.push_back( left.front() );
                        left.pop();
                    }
                    onleft = false;
                    time += transfer;
                    for( int i = 0; i < ferry.size(); ++i )
                        output.push( car( time, ferry[ i ].serial ) );
                    ferry.clear();
                }
                else
                {
                    time = max( right.front().time, time ) + transfer;
                    while( !right.empty() && ferry.size() < capacity && time >= right.front().time )
                    {
                        ferry.push_back( right.front() );
                        right.pop();
                    }
                    time += transfer;
                    for( int i = 0; i < ferry.size(); ++i )
                        output.push( car( time, ferry[ i ].serial ) );
                    ferry.clear();
                }
            }
            else
            {
                if( L >= R || !right.empty() && time >= right.front().time )
                {
                    time = max( time, right.front().time );
                    while( !right.empty() && ferry.size() < capacity && time >= right.front().time )
                    {
                        ferry.push_back( right.front() );
                        right.pop();
                    }
                    onleft = true;
                    time += transfer;
                    for( int i = 0; i < ferry.size(); ++i )
                        output.push( car( time, ferry[ i ].serial ) );
                    ferry.clear();
                }
                else
                {
                    time = max( left.front().time, time ) + transfer;
                    while( !left.empty() && ferry.size() < capacity && time >= left.front().time )
                    {
                        ferry.push_back( left.front() );
                        left.pop();
                    }
                    time += transfer;
                    for( int i = 0; i < ferry.size(); ++i )
                        output.push( car( time, ferry[ i ].serial ) );
                    ferry.clear();
                }
            }
        }
        while( !output.empty() )
        {
            printf( "%d\n", output.top().time );
            output.pop();
        }
        if( t )
            puts( "" );
    }

    return 0;
}
