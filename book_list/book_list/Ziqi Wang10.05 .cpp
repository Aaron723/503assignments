#include<iostream>

#include <iomanip>
using namespace std;
//list of the function we want to use
void insert(int[20], int, int);
void Print(int[20], int);
void insert_certain(int[20], int, int, int);
int find_linear(int[20], int, int);
int find_binary(int[20], int, int, bool);
void delete_item_position(int[20], int, int);
void delete_item_isbn(int[20], int, int);
void sort_list_selection(int[20], int);
void sorted_list_bubble(int[20], int);

int main()
{

	int i = 6, counter = 0;//		initialize a counter to record the length of array, i is the choice user want to put
	bool sorted = false;		//indicate the array is sorted or not
	int book_list[20];		//define the max length of book list
	
	while (i != 0)
	{
			//ask users to input their choice, if they input 0, quit.
		cout << "Choice1, insert a new book at the end\n" << "Choice2, insert a book in the certain position\n" << "Choice3, find a book(unsorted)\n"
			<< "Choice4, sort the list and find a book\n" << "Choice5, delete a book in a certain position\n" << "Choice6, delete a book using ISBN\n"
			<< "Choice7, sort the list(selection sort)\n"<< "Choice8, Sort the list(bubble sort)\n" <<"when you enter 0, quit\n"<< endl;
			
		cin >> i;

		switch (i)
		{
		case 1:

			int ISBN1;

			cout << "Please enter the ISBN number of the book you want to buy" << endl;

			cin >> ISBN1;

			insert(book_list,counter, ISBN1);	//insert a book to the end of the list
			counter++;							//every time insert a book, the length of book +1

			Print(book_list, counter);			//after insert a book, print the list.

			break;
		case 2:
			int ISBN2;
			int position2;			//the position user want to put this book
			cout << "Please enter the position you want to insert and ISBN" << endl;

			cin >> position2 >> ISBN2;

			insert_certain(book_list, counter, ISBN2, position2);
			counter++;			//every time insert a book, the length of book +1
			Print(book_list, counter);	//after insert a book, print the list.

			break;
		case 3:			//use binary search to search a book in the list(using ISBN number) and output the position of the book, if the book isn't in the list, output error.
			int position3;
			int ISBN3;
			cout << "Please enter the ISBN number" << endl;
			cin >> ISBN3;

			position3 = find_linear(book_list, ISBN3, counter);
			if (position3 != -1)
			{
				cout << "The position is " << position3 << endl;
			}
			else
				cout << "This book is not in the list!" << endl;

			break;

		case 4:			/*using binary search to find a book in a sorted list, and output the position of the book, if the list isn't sorted or the book isn't in the list
						output error*/

			int position4;
			int ISBN4;
			cout << "Please enter the ISBN number" << endl;
			cin >> ISBN4;

			position4 = find_binary(book_list, ISBN4, counter, sorted);

			if (position4 != -1)
			{
				cout << "The position is " << position4 << endl;
			}
			else
				cout << "This book is not in the list!" << endl;


			break;
		case 5:			//delete a book using it's position, after that, print booklist.
			int position5;
			cout << "Please enter the position of the book" << endl;
			cin >> position5;

			delete_item_position(book_list, counter, position5);

			counter--;
			Print(book_list, counter);

			break;
		case 6:			//delete a book using it's ISBN number, after that, print booklist.
			int ISBN6;
			cout << "Please enter the ISBN number" << endl;
			cin >> ISBN6;
			delete_item_isbn(book_list, counter, ISBN6);
			counter--;
			Print(book_list, counter);
			break;
		case 7:			//sort booklist using selection, after that, print booklist
			sort_list_selection(book_list, counter);
			sorted = true;		//record that the list is sorted, and can use binary search to find a book.
			Print(book_list, counter);
			break;
		case 8:			//sort booklist using bubbling, after that, print booklist
			sorted_list_bubble(book_list, counter);
			sorted = true;		////record that the list is sorted, and can use binary search to find a book.
			Print(book_list, counter);
			break;
		case 0:
			break;

		default:
			cout << "It's not available!" << endl;
		}

	}

	return 0;

}
void insert(int book_list[20], int counter, int ISBN)
{
	
	

	if (counter == 20)			// if the list is full, output error.
	{
		cout << "The list is full, can't add more book!" << endl;
	}
	else
		*(book_list + counter) = ISBN;
}

void Print(int book_list[20], int counter)
{
	
	for (int i = 0; i!=counter; i++)
	{
		cout << setw(5) <<book_list[i];
	}

	cout << endl;
}

void insert_certain(int book_list[20], int counter, int ISBN, int position)
{
	if (counter == 20)// if the list is full, output error.
	{
		cout << "the list is full, can't add more book!" << endl;			
	}
	else if (position > counter)
	{
		cout << "the position you enter beyond the range!" << endl;

	}
	else
	{
		for (int i = counter - 1; i != position - 1; i--)			//move elements to the next position so that the new can be inserted.
		{
			*(book_list + i + 1) = *(book_list + i);
		}

		*(book_list + position) = ISBN;

	}
}
int find_linear(int book_list[20], int ISBN, int counter)
{
	int position = -1;		//if the book isn't in the list, return -1.
	for (int i = 0; i != counter; i++)			//linear search
	{
		if (*(book_list + i) == ISBN)
		{
			position = i;
			break;
		}
	}

	return position;
}
int find_binary(int book_list[20], int ISBN, int counter, bool sorted)
{
	if (sorted == false)
	{
		cout << "this list hasn't been sorted, can't find!" << endl;
		return -1;			
	}
	else
	{
		int low = 0, high = counter - 1, i;

		

		while (low <= high)			//binary search
		{
			
			i = (low + high) / 2;

			if (*(book_list + i) == ISBN)
				break;
			else if (*(book_list + i) > ISBN)
			{
				low = i + 1;
			}
			else if (*(book_list + i) < ISBN)
			{
				high = i - 1;
			}
		}

		if (low > high)
		{
			i = -1;
		}
		return i;
	}
}

void delete_item_position(int book_list[20], int counter, int position)
{
	if (position >= counter)
	{
		cout << "This book is not in the list!" << endl;
	}
	else
		for (int i = position; i != counter; i++)
		{
			*(book_list + i) = *(book_list + i + 1);
		}
}

void delete_item_isbn(int book_list[20], int counter, int ISBN)
{
	int position = -1;

	for (int i = 0; i != counter; i++)
	{
		if (*(book_list + i) == ISBN)			//first, find the position of the book
		{
			position = i;
			break;
		}
	}

	if (position = -1)
	{
		cout << "This book is not in the list" << endl;
	}
	else
	{
		for (int i = position; i != counter; i++)			//then, similar with delete with position
		{
			*(book_list + i) = *(book_list + i + 1);
		}
	}

}

void sort_list_selection(int book_list[20], int counter)
{
	for (int j = 0; j != counter - 1; j++)
	{
		for (int i = j+1; i != counter; i++)
			{
				int t;

				if (*(book_list + i) < *(book_list+j))
				{
					t = *(book_list+j);

					*(book_list+j) = *(book_list + i);

					*(book_list + i) = t;

				}
			}
	}
	
}
void sorted_list_bubble(int book_list[20], int counter)
{
	for (int i = counter - 1; i != 0; i--)
	{
		for (int j = 0; j != i; j++)
		{
			if (*(book_list + j) > *(book_list + j + 1))
			{
				int t;

				t = *(book_list + j);

				*(book_list + j) = *(book_list + j + 1);
				*(book_list + j + 1) = t;

			}
		}
	}
}
