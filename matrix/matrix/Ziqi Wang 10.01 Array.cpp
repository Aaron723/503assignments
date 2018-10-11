#include<iostream>;
#include<vector>;
#include <iomanip>
using namespace std;

const int Maxsize = 10;

//list of the functions
double  **Addition(double **,double** , int, int);
double  **Substraction(double**, double**, int, int);
double  **Multiplication(double**, double**, int, int, int);
double Determinant(double**);
double  **Transpose(double**, int, int);
double  **Inverse(double**);

double  **Inputmatrix(int, int);

void Output(double**, int, int);

int main()
{
	int a_row, a_column, b_row, b_column;

	double **arry1;
	double **arry2;
	double **arry3;
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

			arry1 = Inputmatrix(a_row, a_column);

			cout << "\n\nPlease enter the row and column of the martix b(no more than 10)" << endl;
			cin >> b_row >> b_column;

			arry2 = Inputmatrix(b_row, b_column);

			if (a_row != b_row || a_column != b_column)  //if the condition is not fullfilled, quit
			{
				cout << "It's not available!" << endl;
				break;
			}

			arry3 = Addition(arry1, arry2, a_row, a_column);
			Output(arry3, a_row, a_column);

			break;
			//a-b
		case 2:
			cout << "Please enter the row and column of the martix a" << endl;
			cin >> a_row >> a_column;

			arry1 = Inputmatrix(a_row, a_column);

			cout << "\n\nPlease enter the row and column of the martix b" << endl;
			cin >> b_row >> b_column;


			if (a_row != b_row || a_column != b_column)//if the condition is not fullfilled, quit
			{
				cout << "It's not available!" << endl;
				break;
			}

			arry2 = Inputmatrix(b_row, b_column);



			arry3 = Substraction(arry1, arry2, a_row, a_column);
			Output(arry3, a_row, a_column);

			break;
			//a*b
		case 3:
			cout << "Please enter the row and column of the martix a" << endl;
			cin >> a_row >> a_column;

			arry1 = Inputmatrix(a_row, a_column);

			cout << "\n\nPlease enter the row and column of the martix b" << endl;
			cin >> b_row >> b_column;

			if (a_column != b_row)//if the condition is not fullfilled, quit
			{
				cout << "It's not available" << endl;
				break;
			}

			arry2 = Inputmatrix(b_row, b_column);



			arry3 = Multiplication(arry1, arry2, a_row, a_column, b_column);
			Output(arry3, a_row, b_column);


			break;
			//|a|
		case 4:

			double deter;

			cout << "Please enter the row and column of the martix a" << endl;
			cin >> a_row >> a_column;

			arry1 = Inputmatrix(a_row, a_column);

			deter = Determinant(arry1);

			cout << deter << endl;
			break;
			//transpose a 
		case 5:

			cout << "Please enter the row and column of the martix a" << endl;
			cin >> a_row >> a_column;

			arry1 = Inputmatrix(a_row, a_column);

			arry2 = Transpose(arry1, a_row, a_column);

			Output(arry2, a_column, a_row);
			break;
			//inverse a
		case 6:

			cout << "Please enter a 3X3 matrix" << endl;

			arry1 = Inputmatrix(3, 3);

			arry2 = Inverse(arry1);

			Output(arry2, 3, 3);
			break;

		case 0:     //if he entered 0, that means he wants to quit
			break;

		default:

			cout << "It's not available!" << endl;




		}
		cout << "if you want to quit, please enter 0, if not, please enter a number from 1 to 6" << endl;
	}







}

double **Inputmatrix(int a_row, int a_coloum)
{
	//define a matrix and input ,I use **vec_a to dynamically create a 2 dimensinal array




	double **vec_a;

	vec_a =new double*[a_row];



	for (int i = 0; i != a_row; i++)
	{
		vec_a[i] = new double[a_coloum];
	}

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

	return (double **)vec_a;

}




double **Addition(double **vec_a, double **vec_b, int a_row, int a_coloum)
{

	double **vec_c;


	vec_c = new double*[a_row];



	for (int i = 0; i != a_row; i++)
	{
		vec_c[i] = new double[a_coloum];
	}



	for (int i = 0; i != a_row; i++)                //add this two matrix
	{
		for (int j = 0; j != a_coloum; j++)
		{

			vec_c[i][j] = vec_a[i][j]+vec_b[i][j];



		}

	}

	return (double**)vec_c;

}



double **Substraction(double **vec_a, double **vec_b, int a_row, int a_coloum)
{


	double **vec_c;


	vec_c = new double*[a_row];



	for (int i = 0; i != a_row; i++)
	{
		vec_c[i] = new double[a_coloum];
	}



	for (int i = 0; i != a_row; i++)                
	{
		for (int j = 0; j != a_coloum; j++)
		{

			vec_c[i][j] = vec_a[i][j] - vec_b[i][j];



		}

	}

	return (double**)vec_c;
}


double **Multiplication(double **vec_a, double **vec_b, int a_row, int a_coloum, int b_coloum)
{



	double **vec_c;


	vec_c = new double*[a_row];



	for (int i = 0; i != a_row; i++)
	{
		vec_c[i] = new double[a_coloum];
	}





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

	return (double**)vec_c;
}

double Determinant(double **vec_a)
{



	double **f;


	f = new double*[3];



	for (int i = 0; i != 3; i++)
	{
		f[i] = new double[3];
	}

	for (int i = 0; i != 3; i++)
	{
		for (int j = 0; j != 3; j++)
		{



			f[i][j] = vec_a[i][j];

		}
	}



	double deter1, deter2, deter;	//calculus the determinant

	deter1 = f[0][0] * f[1][1] * f[2][2] + f[0][1] * f[1][2] * f[0][2] + f[0][2] * f[0][1] * f[2][1];

	deter2 = f[2][0] * f[1][1] * f[0][2] + f[0][1] * f[1][0] * f[2][2] + f[0][0] * f[2][1] * f[1][2];

	deter = deter1 - deter2;




	return deter;

}
double **Transpose(double **vec_a, int a_row, int a_coloum)
{
	double **vec_c;


	vec_c = new double*[a_row];



	for (int i = 0; i != a_row; i++)
	{
		vec_c[i] = new double[a_coloum];
	}




	// get the transpose matrix
	for (int i = 0; i != a_coloum; i++)
	{
		for (int j = 0; j != a_row; j++)
		{


			vec_c[i][j]=vec_a[j][i];





		}
	}

	return (double**) vec_c;

}

double ** Inverse(double **vec_a)
{


	double **a;


	a = new double*[3];



	for (int i = 0; i != 3; i++)
	{
		a[i] = new double[3];
	}



	for (int i = 0; i != 3; i++)
	{
		for (int j = 0; j != 3; j++)
		{
			


			a[i][j]=vec_a[i][j];

		}
	}

	//calculus the inverse matrix
	double deter1, deter2, deter3;

	deter1 = a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[0][2] + a[2][0] * a[0][1] * a[2][1];

	deter2 = a[2][0] * a[1][1] * a[0][2] + a[0][1] * a[1][0] * a[2][2] + a[0][0] * a[2][1] * a[1][2];

	deter3 = deter1 - deter2;


	double **c;


	c = new double*[3];



	for (int i = 0; i != 3; i++)
	{
		c[i] = new double[3];
	}



	c[0][0] = (a[1][1] * a[2][2] - a[2][1] * a[1][2]) / deter3;

	c[0][1] = (a[2][1] * a[0][2] - a[0][1] * a[2][2]) / deter3;

	c[0][2] = (a[0][1] * a[1][2] - a[1][1] * a[0][2]) / deter3;

	c[1][0] = (a[2][0] * a[1][2] - a[1][0] * a[2][2]) / deter3;

	c[1][1] = (a[0][0] * a[2][2] - a[2][0] * a[0][2]) / deter3;

	c[1][2] = (a[1][0] * a[0][2] - a[0][0] * a[1][2]) / deter3;

	c[2][0] = (a[1][0] * a[2][1] - a[2][0] * a[1][1]) / deter3;

	c[2][1] = (a[2][0] * a[0][1] - a[0][0] * a[2][1]) / deter3;

	c[2][2] = (a[0][0] * a[1][1] - a[1][0] * a[0][1]) / deter3;


	return (double**)c;
}

void Output(double **vec_a, int a_row, int a_column)
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
