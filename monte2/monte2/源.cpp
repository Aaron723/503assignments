#include<iostream>;
#include<time.h>;
#include<cmath>;
#include   <stdlib.h>;
using namespace std;

void main()
{
	int i, point_incircle, point_outcircule;

	point_incircle = 0;
	point_outcircule = 0;

	srand(time(0));

	double k = 10000;
	double x, y, pi_here, pi_est;
	pi_here = 3.14;

	for (i = 0;; i++)
	{


		x = rand() / k;
		y = rand() / k;
		cout << "x= " << x << " ";
		cout << "y= " << y << " ";
		cout << "i= " << i + 1 << "\n";




		if ((x*x + y * y) <= 10.89000)
		{
			++point_incircle;
		}
		else
			++point_outcircule;

		pi_est = 4 * point_incircle / (point_incircle + point_outcircule);

		if (fabs(pi_est - pi_here) <= 0.1)
			break;

		if (i == 4)
			break;
	}

	cout << "the estimate value of pi is: " << pi_est << endl;


}