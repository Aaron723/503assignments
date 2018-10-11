#include<iostream>
using namespace std;

int main()
{
	int candidate[] = { 0,0,0,0,0 };	//create an array to show candidates
	int vote, max, counter, i,sig;
	max = -1;
	sig = 1;

	for (i = 0; i != 20; i++)	//to get 20 votes from different voters
	{
		cout << "Please enter the number of candidate that you want to vote(0~4),and press return.\n";

		cin >> vote;

		candidate[vote]++;

		if (vote == -1&&i>0)	//if the voter input the wrong number, he/she can input"-1"to remove the wrong vote
		{
			i--;
			candidate[vote]--;

			cout << "successfully remove the wrong vote\n";

			continue;
		}
		if (vote == -1 && i == 0)		//if the voter input"-1" at the beginning, the program will go wrong.
		{
			cout << "Can't remove a vote at the begining!" << "\n";
		}
	}

	for (int j = 0; j != 5; j++)		//using loop to find the max vote number.
	{
		if (candidate[j] > max)
		{
			max = candidate[j];
			counter = j;

		}
		


	}

	int sum = 0;		

	for (int n = 0; n != 5; n++)
	{
	cout << "candidate " << n << " received " << candidate[n] << "votes\n";


	sum += candidate[n];

	}

	cout << "the whole votes number is: " << sum<<"\n";		//to show the whole number of votes.and it can detect once the program bugged.

	for (int k = 0; k != 5; k++)		//detect if there are two or more candidate whose vote number is the same.
	{
	
	if (max == candidate[k] && k != counter)
		{
			cout << "there is no winner\n";
			sig = 0;
			break;
		}
	}
	if (sig == 1)		//sitting up a signal to show if there has a winner or not.
	{
		cout << "the winner is: " << counter << "\n";



	}
	cout << "Thanks for using!" << endl;		//refresh the cout register

	return 0;
}