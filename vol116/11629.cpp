#include<iostream>
#include<map>
using namespace std;

int main()
{
	int party, guess, integer, decimal, ans;
	string name, op;
	char nope;

	while( cin >> party >> guess )
	{
		map<string,double> bolt;

		for( int i = 0; i < party; ++i )
			cin >> name >> integer >> nope >> decimal, bolt[ name ] = integer * 10 + decimal;
		for( int i = 0, sum = 0; i < guess; ++i, sum = 0 )
		{
			do
			{
				cin >> name >> op;
				sum += bolt[ name ];
			} while( op == "+" );
		cin >> ans;
		ans *= 10;

		cout << "Guess #" << i+1 << " was ";
		if( op == ">" && sum <= ans || op == "<" && sum >= ans || op == "<=" && sum > ans || op == ">=" && sum < ans || op == "=" && sum != ans )
			cout << "in";
		cout << "correct.\n";
		}
	}
}
