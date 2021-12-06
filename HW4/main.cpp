#include "DayOfYearSet.h"

using namespace Atakan;

void TestFunction(DayOfYearSet& SetA,DayOfYearSet& SetB);
void TestFunction2(DayOfYearSet SetA,DayOfYearSet SetB);

int main()
{
	DayOfYearSet Set1;
	Set1.add(13,11);//Adds
	Set1.add(10,10);//Adds
	Set1.add(10,14);//Dont adds
	cout << Set1;


	DayOfYearSet Set2;
	Set2.add(13,11);//Dont adds because of duplicate
	Set2.add(15,11);
	cout << Set2;

	Set1.add(1,2);
	cout << Set1;

	Set1.remove(1);//Removes element from elemnt number
	cout << Set1;

	DayOfYearSet Set3 = Set1 + Set2;//Union Set
	cout << Set3;

	DayOfYearSet Set4 = Set3 - Set1;//Difference Set
	cout << Set4;

	DayOfYearSet Set5 = Set1 ^ Set2;//Intersection Set
	cout << Set5;

	DayOfYearSet Set6 = !Set3;//Complement Set
	cout << Set6;

	ofstream outfile;
	outfile.open("SetExample.txt");//Save to text
	outfile << Set6;
	cout << "Set 6 is saved to txt file." << endl;

	bool DeMorgan = (!(Set3 + Set2)) == ((!Set3) ^ (!Set2));//De Morgan Rule
	if (DeMorgan == true)
	{
		cout << "De Morgan rule approved" << endl;
	}
	else
		cout << "De Morgan isn't working" << endl;
	
	DayOfYearSet SetA,SetB;
	TestFunction(SetA,SetB);//With reference
	TestFunction2(SetA,SetB);//With value

	cout << "There is " << SetA.getTotalDates() << " dates in all Sets" << endl;

}

void TestFunction(DayOfYearSet& SetA,DayOfYearSet& SetB)
{
	SetA.add(10,10);
	SetA.add(12,12);
	SetB.add(15,1);
	SetB.add(12,12);

	DayOfYearSet SetC = SetA + SetB;
	cout << SetC;
}

void TestFunction2(DayOfYearSet SetA,DayOfYearSet SetB)
{
	DayOfYearSet SetC = SetA ^ SetB;
	cout << SetC;
}
