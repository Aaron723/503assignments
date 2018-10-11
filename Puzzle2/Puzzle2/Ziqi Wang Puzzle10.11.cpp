#include<iostream>

using namespace std;

//the function we use for judging if the string is sovlable.
bool Puzzle_jump(int [] , int);


int main()
{

	int n;
	int Str[1000];/*I set a big number to make sure I can cover the sequence, then I ask user to input the length they want to input*/
	cout << "Pleaser enter the length of the string(>0)." << endl;

	cin >> n;
	
	//fill out the string with positive integer
	for (int i = 0; i != n - 1; i++)
	{
		cout << "Please enter [" << i << "] in the string" << endl;

		cin >> Str[i];
		//if the interger is not positive, output error and ask user to put again
		if (Str[i] <= 0)
		{
			cout << "Error! Element in the string should be positive, please renter the element!" << endl;
			Str[i] = 0;
			i--;

		}

	}
	//for the rest of the string, I set all the element to(-1)
	for (int i = n; i != 1000; i++)
	{
		Str[i] = -1;
	}
	//the last element must be 0.
	Str[n - 1] = 0;
	
	
	//output string

	for (int i = 0; i != n; i++)
	{
		cout << Str[i] << ",";

	}
	cout << endl;
	bool result;
	result = Puzzle_jump(Str, 0);

	if (result)
	{
		cout << "It can be solved" << endl;
	}
	else
		cout << "It can't be solved" << endl;
		

	return 0;
}
bool Puzzle_jump(int arr[], int current)
{
	int i = current;//current index
	int Dup_arr[1000];/*I set a array to save the element in the orginal sring, because when I go through a element(node),
					  I will set it to(-1) to avoid hit it once again.*/
	Dup_arr[i] = arr[i];//set the elemnt in the duplicate array.

	/*I set the function first jump to right, when you can't jump to right elemnt, jump to left, if both of them is not available,
	return to the former node and switch again*/
	if (arr[current + Dup_arr[current]]>0)//if the next element we go is in the array, and we haven't hit it(element>0), then we can go to the right.
	{
		arr[current] = -1;//set the current node to(-1)
		Puzzle_jump(arr, current + Dup_arr[current]);//go to the right node.
	}
	if (arr[current + Dup_arr[current]]==0)//if we hit the goal
	{
		arr[0] = -2;/*here I use a little trick, if we hit the goal, I just set the first element to(-2),
					because it must exist when you have a sequence, then, I add the condition in if statement.
					If we hit the goal once, we just jump back to the former node over and over till we goes back to arr[0]*/
	}
	if (arr[current + Dup_arr[current]]<0&&arr[0]!=-2)/*if we can't jump to the right node and we haven't hit the the goal, we detect if we can jump to the left node*/
	{
		arr[current] = -1;//set the current node to(-1)
		if (current- Dup_arr[current] >= 0&&arr[current - Dup_arr[current]]>0)/*the left node is in the sequence and we haven't been to it.*/
		{

			 Puzzle_jump(arr, current- Dup_arr[current]);//jump to the left
		}
	}
	if (current == 0&&arr[Dup_arr[current]]==-1&&arr[0]!=-2)//if we tried every way and we still go back to the head, it means the sequence can't be solved.
	{
		return false;
	}
	else if (arr[0] == -2)//we reached the goal.
	{
		return true;
	}
}
