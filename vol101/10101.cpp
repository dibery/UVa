#include<iostream>
#include<cstdio>
using namespace std;
const long long int kuti = 10000000, lakh = 100000, hajr = 1000, shata = 100, kuti2 = kuti * kuti, lakh2 = kuti * lakh, hajr2 = kuti * hajr, shata2 = kuti * shata;
void print( long long int num )
{
    bool over = false;
    if( num - num / kuti2 * kuti2 >= 0 && num / kuti2 )
    {
        over = true;
        cout << num / kuti2 << " kuti ";
        num -= num / kuti2 * kuti2;
        num -= num / kuti2 * kuti2;
    }
    if( num - num / lakh2 * lakh2 >= 0 && num / lakh2 )
    {
        over = true;
        cout << num / lakh2 << " lakh ";
        num -= num / lakh2 * lakh2;
    }
    if( num - num / hajr2 * hajr2 >= 0 && num / hajr2 )
    {
        over = true;
        cout << num / hajr2 << " hajar ";
        num -= num / hajr2 * hajr2;
    }
    if( num - num / shata2 * shata2 >= 0 && num / shata2 )
    {
        over = true;
        cout << num / shata2 << " shata ";
        num -= num / shata2 * shata2;
    }

    if( over && !( num - num / kuti * kuti >= 0 && num / kuti ) )
        cout << "kuti";
    if( num && !( num - num / kuti * kuti >= 0 && num / kuti ) && over )
        cout << ' ';

    if( num - num / kuti * kuti >= 0 && num / kuti )
    {
        cout << num / kuti << " kuti";
        num -= num / kuti * kuti;
        num -= num / kuti * kuti;
        if( num )
            cout << ' ';
    }
    if( num - num / lakh * lakh >= 0 && num / lakh )
    {
        cout << num / lakh << " lakh";
        num -= num / lakh * lakh;
        if( num )
            cout << ' ';
    }
    if( num - num / hajr * hajr >= 0 && num / hajr )
    {
        cout << num / hajr << " hajar";
        num -= num / hajr * hajr;
        if( num )
            cout << ' ';
    }
    if( num - num / shata * shata >= 0 && num / shata )
    {
        cout << num / shata << " shata";
        num -= num / shata * shata;
        if( num )
            cout << ' ';
    }
    if( num )
        cout << num;
    cout << endl;
}

int main()
{
    long long int num;
    int test = 0;
    while( cin >> num )
    {
        printf( "%4d. ", ++test );
        if( num )
            print( num );
        else
            cout << 0 << endl;
    }

    return 0;
}
