#include <iostream>
#include "Matrix4.h"
#include "Matrix3.h"
using namespace std;

void main()
{
	Matrix4 test(2, 5, 4, 2, 5, 1, 8, 1, 7, 0, 0, 6, 4, 7, 3, 9);

	
	float as = test.det4();

	cout << as << endl;

	system("pause");
}