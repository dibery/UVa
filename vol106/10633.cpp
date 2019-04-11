#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    unsigned long long int in;
    //freopen("test.txt","r",stdin);

    while( cin >> in && in )
    {
        unsigned long long int ori = in * 10 / 9;
        while( (ori-1) - (ori-1)/10 == in )
            --ori;
        while( (ori+1) - (ori+1)/10 == in )
            cout << ori++ << ' ';
        cout << ori << endl;
    }
    return 0;
}
