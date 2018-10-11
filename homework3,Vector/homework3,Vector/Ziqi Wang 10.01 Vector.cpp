#include<iostream>;
#include<vector>;
#include <iomanip>
using namespace std;

//list of the functions
vector<vector<double>> Addition(vector<vector<double>>, vector<vector<double>>, int, int);
vector<vector<double>> Substraction(vector<vector<double>>, vector<vector<double>>, int, int);
vector<vector<double>> Multiplication(vector<vector<double>>, vector<vector<double>>, int, int, int);
double Determinant(vector<vector<double>>);
vector<vector<double>> Transpose(vector<vector<double>>, int, int);
vector<vector<double>> Inverse(vector<vector<double>>);

vector<vector<double>> Inputmatrix(int, int);

void Output(vector<vector<double>>, int, int);

int main()
{
	int a_row, a_column, b_row, b_column;

	vector<vector<double>>vec_a;
	vector<vector<double>>vec_b;
	vector<vector<double>>vec_c;

	int i = 6;

	while (i != 0)
	{
		cout << "Please enter your choice" << "\nChoice1(Addition)" << "\nChoice2(Subtraction)"
			<< "\nChoice3(Multiplication)" << "\nChoice4(Determinant)" << "\nChoice5(Transpose)" << "\nChoice6(Inverse)" << endl;

		cin >> i;
		switch (i)//ask user which function he/she wants to use
			{
			//a+b
			case 1:
				//enter 2 matrix
				cout << "Please enter the row and column of the martix a(no more than 10)" << endl;
				cin >> a_row >> a_column;

				vec_a=Inputmatrix(a_row, a_column);

				cout << "\n\nPlease enter the row and column of the martix b(no more than 10)" << endl;
				cin >> b_row >> b_column;

				vec_b = Inputmatrix(b_row, b_column);

				if (a_row != b_row || a_column != b_column)  //if the condition is not fullfilled, quit
				{
					cout << "It's not available!" << endl;
					break;
				}

				vec_c = Addition(vec_a, vec_b, a_row, a_column);
				Output(vec_c, a_row, a_column);

				break;
				//a-b
			case 2:
				cout << "Please enter the row and column of the martix a" << endl;
				cin >> a_row >> a_column;

				vec_a = Inputmatrix(a_row, a_column);

				cout << "\n\nPlease enter the row and column of the martix b" << endl;
				cin >> b_row >> b_column;


				if (a_row != b_row || a_column != b_column)//if the condition is not fullfilled, quit
				{
					cout << "It's not available!" << endl;
					break;
				}

				vec_b = Inputmatrix(b_row, b_column);



				vec_c = Substraction(vec_a, vec_b, a_row, a_column);
				Output(vec_c, a_row, a_column);
				
				break;
			//a*b
			case 3:
				cout << "Please enter the row and column of the martix a" << endl;
				cin >> a_row >> a_column;

				vec_a = Inputmatrix(a_row, a_column);

				cout << "\n\nPlease enter the row and column of the martix b" << endl;
				cin >> b_row >> b_column;

				if (a_column != b_row)//if the condition is not fullfilled, quit
				{
					cout << "It's not available" << endl;
					break;
				}

				vec_b = Inputmatrix(b_row, b_column);

				

				vec_c = Multiplication(vec_a, vec_b, a_row,a_column,b_column);
				Output(vec_c, a_row, b_column);

				
				break;
			//|a|
			case 4:

				double deter;

				cout << "Please enter the row and column of the martix a" << endl;
				cin >> a_row >> a_column;

				vec_a = Inputmatrix(a_row, a_column);

				deter=Determinant(vec_a);

				cout << deter << endl;
				break;
			//transpose a 
			case 5:

				cout << "Please enter the row and column of the martix a" << endl;
				cin >> a_row >> a_column;

				vec_a = Inputmatrix(a_row, a_column);

				vec_c=Transpose(vec_a,a_row,a_column);

				Output(vec_c, a_column, a_row);
				break;
			//inverse a
			case 6:

				cout << "Please enter a 3X3 matrix" << endl;

				vec_a = Inputmatrix(3, 3);

				vec_c=Inverse(vec_a);

				Output(vec_c, 3, 3);
				break;

			case 0:     //if he entered 0, that means he wants to quit
				break;

			default:

				cout << "It's not available!" << endl;


				

			}
		cout << "if you want to quit, please enter 0, if not, please enter a number from 1 to 6" << endl;
	}

	
	




}

vector<vector<double>> Inputmatrix(int a_row,int a_coloum)
{
               //define a matrix and input 


	

	vector<vector<double> > vec_a(a_row, vector<double>(a_coloum));

	for (int i = 0; i != a_row; i++)
	{
		for (int j = 0; j != a_coloum; j++)
		{
			double c;
			cout << "Please enter [" << i << "][" << j << "]" << endl;

			cin >> c;


			vec_a[i][j] = c;

		}
	}

	return vec_a;

}




vector<vector<double>> Addition(vector<vector<double>> vec_a, vector<vector<double>> vec_b, int a_row, int a_coloum)
{

	vector<vector<double>> vec_c(a_row, vector<double>(a_coloum));

	
		for (int i = 0; i != a_row; i++)                //add this two matrix
		{
			for (int j = 0; j != a_coloum; j++)
			{

				vec_c[i][j] = vec_a[i][j] + vec_b[i][j];

				

			}
			
		}

		return vec_c;

}



vector<vector<double>> Substraction(vector<vector<double>> vec_a, vector<vector<double>> vec_b, int a_row, int a_coloum)
{

	

	

	vector<vector<double> >vec_c(a_row, vector<double>(a_coloum));

	
		for (int i = 0; i != a_row; i++)	      //matrix a minus matrix b
		{
			for (int j = 0; j != a_coloum; j++)
			{

				vec_c[i][j] = vec_a[i][j] - vec_b[i][j];

				

			}
			
		}

		return vec_c;
}


vector<vector<double>> Multiplication(vector<vector<double>> vec_a, vector<vector<double>> vec_b, int a_row, int a_coloum, int b_coloum)
{

	

	vector<vector<double> >vec_c(a_row, vector<double>(b_coloum));

	
	
		for (int i = 0; i != a_row; i++)	//calculus the Multiplication
		{
			for (int j = 0; j != b_coloum; j++)
			{

				for (int k = 0; k != a_coloum; k++)
				{
					vec_c[i][j] += vec_a[i][k] * vec_b[k][j];
				}

			}
		}

		return vec_c;
}

double Determinant(vector<vector<double>>vec_a)
{

	

	vector<vector<double> > f(3, vector<double>(3));
	
	f = vec_a;

	

	double deter1, deter2, deter;	//calculus the determinant

	deter1 = f[0][0] * f[1][1] * f[2][2] + f[0][1] * f[1][2] * f[0][2] + f[0][2] * f[0][1] * f[2][1];

	deter2 = f[2][0] * f[1][1] * f[0][2] + f[0][1] * f[1][0] * f[2][2] + f[0][0] * f[2][1] * f[1][2];

	deter = deter1 - deter2;



	return deter;

}
vector<vector<double>> Transpose(vector<vector<double>>vec_a, int a_row, int a_coloum)
{
	vector<vector<double>> vec_c(a_coloum, vector<double>(a_row));


	// get the transpose matrix
	for (int i = 0; i != a_coloum; i++)
	{
		for (int j = 0; j != a_row; j++)
		{
			

			vec_c[i][j] = vec_a[j][i];

			

			

		}
	}

	return vec_c;

}

vector<vector<double>> Inverse(vector<vector<double>>vec_a)
{
	

	vector<vector<double> > a(3, vector<double>(3));

	a = vec_a;
	
	//calculus the inverse matrix
	double deter1, deter2, deter3;

	deter1 = a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[0][2] + a[2][0] * a[0][1] * a[2][1];

	deter2 = a[2][0] * a[1][1] * a[0][2] + a[0][1] * a[1][0] * a[2][2] + a[0][0] * a[2][1] * a[1][2];

	deter3 = deter1 - deter2;


	vector<vector<double> > c(3, vector<double>(3));

	c[0][0] = (a[1][1] * a[2][2] - a[2][1] * a[1][2])/deter3;

	c[0][1] = (a[2][1] * a[0][2] - a[0][1] * a[2][2]) / deter3;

	c[0][2] = (a[0][1] * a[1][2] - a[1][1] * a[0][2]) / deter3;

	c[1][0] = (a[2][0] * a[1][2] - a[1][0] * a[2][2]) / deter3;

	c[1][1] = (a[0][0] * a[2][2] - a[2][0] * a[0][2]) / deter3;

	c[1][2] = (a[1][0] * a[0][2] - a[0][0] * a[1][2]) / deter3;

	c[2][0] = (a[1][0] * a[2][1] - a[2][0] * a[1][1]) / deter3;

	c[2][1] = (a[2][0] * a[0][1] - a[0][0] * a[2][1]) / deter3;

	c[2][2] = (a[0][0] * a[1][1] - a[1][0] * a[0][1]) / deter3;

	
	return c;
}

void Output(vector<vector<double> >vec_a, int a_row, int a_column)
{
	for (int i = 0; i != a_row; i++)
		{
			for (int j = 0; j != a_column; j++)
			{
				cout << "    " << vec_a[i][j];

				
			}
			cout << endl;
		}
}
