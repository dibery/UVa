#include<cstdio>
#include<list>
using namespace std;
struct money
{
    int month;
    double rate;
} in;

int main()
{
    double payment, loan, car, downpay;
    int duration, dep, time;
    list<money> record;

    while( scanf( "%d %lf %lf %d", &duration, &downpay, &loan, &dep ) && duration >= 0 )
    {
        time = 0;
        car = downpay + loan;
        payment = loan / duration;
        for( int i = 0; i < dep; ++i )
        {
            scanf( "%d %lf", &in.month, &in.rate );
            record.push_back( in );
        }   //depreciation rate
        car -= car * record.front().rate;
        in = record.front();
        record.pop_front();
        while( car <= loan && ++time )
        {
            if( time == record.front().month )
            {
                in = record.front();
                record.pop_front();
            }
            car -= car * in.rate;
            loan -= payment;
        }
        printf( "%d month%s\n", time, time == 1? "" : "s" );
        record.clear();
    }

    return 0;
}
