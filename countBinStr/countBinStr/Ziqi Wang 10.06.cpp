#include<iostream>

using namespace std;
//function we will use
int countBinStr(int);

int main()
{
	int n, counter;
	cout << "Please enter the length you want in the binary number" << endl;

	cin >> n;

	counter = countBinStr(n);

	cout << "the number of string is: " << counter << endl;

	return 0;
}
//recursive function we use
int countBinStr(int n)
{
	/*after I observe the number of binary string, it's 2,3,5,8,13,21 which is similar to fibonacci sequnence.*/
	int j = 2, count = 0;
	//The first two element should write first.moreover, if I do not initialize count, the complier will send error message.
	if (n <= 2)
	{
		return j + n-1;// the first two elements of the sequence is 2,3
	}
	else if (n > 2)
	{
		return countBinStr(n - 1) + countBinStr(n - 2);		//when n>2, we can use recursion.
	}

	

}
