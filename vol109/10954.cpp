#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    unsigned int in, sum, a, b, size;
    priority_queue< unsigned int, vector<unsigned int>, greater<unsigned int> >process;

    while( scanf( "%u", &size ) && size )
    {
        sum = 0;
        for( int i = 0; i < size; ++i )
        {
            scanf( "%u", &in );
            process.push( in );
        }
        while( process.size() > 1 )
        {
            a = process.top();
            process.pop();
            b = process.top();
            process.pop();
            sum += a+b;
            process.push( a+b );
        }
        process.pop();
        printf( "%u\n", sum );
    }

	return 0;
}