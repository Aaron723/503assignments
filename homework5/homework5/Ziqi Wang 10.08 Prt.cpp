#include<iostream>
using namespace std;
//recursion function we use for print string.
int prtSeq_Square_Interger(int, int);

int main()
{
	int n;//the length of string
	
	cout << "Please enter the length of sequence" << endl;
	cin >> n;

	int count = n;
	prtSeq_Square_Interger(count, n);
	cout << endl;
	return 0;
}

int prtSeq_Square_Interger(int count, int n)
{
	//first, we need to print the odd part of the string, if the string has even number, we need to make it odd.

	if (n % 2 == 0)
	{
		return prtSeq_Square_Interger(count - 1, n+1); //count-1 means starting with odd part. n+1 means when print even part because if we use n-1, we can't print out the last even number.
	}
	
	if (count==-1)//after print the odd part, we set the count and print even part.
	{
		count = 2;
		return prtSeq_Square_Interger(count, n);
	}

		if (count==n+1)//stop print
					return 0;
		if (count % 2 != 0)//first print the odd part.
		{
			cout << count*count << ",";

					return prtSeq_Square_Interger(count - 2, n);//reverse , printing start from n.
		
	
					return 0;
		}
		if (count % 2 == 0)//then, print the even part
		{
			cout << count * count << ",";
			return prtSeq_Square_Interger(count +2, n);
			return 0;
		}
	}	
	
