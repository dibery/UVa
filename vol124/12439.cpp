#include<iostream>
using namespace std;
int days[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isleap(int year)
{
    if( year % 400 == 0 )
        return true;
    if( year % 4 == 0 && year % 100 != 0 )
        return true;
    return false;
}

int main()
{
    int test, date, year, month;
    int date2, year2, month2;
    string in,in2;
    char no;
    cin >> test;

    for( int i = 0; i < test; ++i )
    {
        int total = 0;
        cin >> in >> date >> no >> year;
        if( in == "January" )
            month = 1;
        else if( in == "February" )
            month = 2;
        else if( in == "March" )
            month = 3;
        else if( in == "April" )
            month = 4;
        else if( in == "May" )
            month = 5;
        else if( in == "June" )
            month = 6;
        else if( in == "July" )
            month = 7;
        else if( in == "August" )
            month = 8;
        else if( in == "September" )
            month = 9;
        else if( in == "October" )
            month = 10;
        else if( in == "November" )
            month = 11;
        else
            month = 12;
        cin >> in2 >> date2 >> no >> year2;
        if( in2 == "January" )
            month2 = 1;
        else if( in2 == "February" )
            month2 = 2;
        else if( in2 == "March" )
            month2 = 3;
        else if( in2 == "April" )
            month2 = 4;
        else if( in2 == "May" )
            month2 = 5;
        else if( in2 == "June" )
            month2 = 6;
        else if( in2 == "July" )
            month2 = 7;
        else if( in2 == "August" )
            month2 = 8;
        else if( in2 == "September" )
            month2 = 9;
        else if( in2 == "October" )
            month2 = 10;
        else if( in2 == "November" )
            month2 = 11;
        else
            month2 = 12;
        int cal = year - year % 4, cal2 = year2 - year2 % 4;
        total += ( cal2 - cal ) / 4 ;
        int hun = year - year % 100, hun2 = year2 - year2 % 100;
        total -= ( hun2 - hun ) / 100 ;
        int f = year - year % 400, f2 = year2 - year2 % 400;
        total += ( f2 - f ) / 400 ;
        if( isleap(year) && month <= 2 )
            ++total;
        if( isleap(year2) && month2<2 || isleap(year2) && month2==2 && date2!=29)
            --total;
        cout << "Case " << i+1 << ": " << total << endl;
    }

    return 0;
}
