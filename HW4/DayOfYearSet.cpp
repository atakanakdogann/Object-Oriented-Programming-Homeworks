#include "DayOfYearSet.h"

namespace Atakan{
	int DayOfYearSet::set_counter = 0;//Static int initializations
	int DayOfYearSet::total_counter = 0;

	DayOfYearSet::DayOfYear::DayOfYear()//Constructors
	{
	}

	DayOfYearSet::DayOfYearSet()
	{
		Dates = new DayOfYear [365];
		set_counter++; 
		set_number = set_counter;
		
	}

	DayOfYearSet::DayOfYearSet(vector<DayOfYear> Set)
	{

	}

	bool DayOfYearSet::isValid(int day_value,int month_value)const
	{

		if (day_value <= 0 || month_value <= 0 || month_value > 12){//Controls - and month > 12
			return false;
		}


		if (month_value == 2){//February only
			if (day_value > 28)		return false;
		}
		else if (month_value == 1 || month_value == 3 || month_value == 5 || 	//Months which has 31 days
					month_value == 7 || month_value == 8 || month_value == 10 || month_value == 12){
			if (day_value > 31)		return false;
		}
		else if (month_value == 4 || month_value == 6 || month_value == 9 || month_value == 11){//Months which has 31 days
			if (day_value >30)		return false;
		}

		for (int i = 0; i < date_counter; i++)
		{
			if (Dates[i].getDay() == day_value && Dates[i].getMonth() == month_value)	//Duplicate control
			{
				return false;
			}
		}

		return true;
	}

	void DayOfYearSet::add(int day_value,int month_value)//If inputs are valid adds to the set
	{
		if (isValid(day_value,month_value))
		{
			Dates[date_counter].setDay(day_value);
			Dates[date_counter].setMonth(month_value);
			date_counter++;
			total_counter++;
		}
		
	}

	void DayOfYearSet::remove(int element_number)
	{
		for (auto i = element_number; i < size(); i++)//Removes from set
		{
			Dates[i] = Dates[i+1];
		}
		date_counter--;
		total_counter--;
	}

	int DayOfYearSet::getTotalDates()
	{
		return total_counter;		//Static function
	}

	void DayOfYearSet::print() const
	{
		for (int i = 0; i < date_counter; i++)		//prints dates
		{
			cout << Dates[i].getDay() << "  "
			 	 << Dates[i].getMonth() << endl;
		}
		cout << endl;
		
	}

	DayOfYearSet::DayOfYear& DayOfYearSet::operator[](int index)//Operator []
	{
		return Dates[index];
	}

	DayOfYearSet operator+(const DayOfYearSet& Set1,const DayOfYearSet& Set2)//Operator +
	{
		int a = 0;
		DayOfYearSet UnionSet;
		for (int i = 0; i < Set1.date_counter; i++)
		{
			UnionSet.Dates[i] = Set1.Dates[i];
			UnionSet.date_counter++;
		}
		for (int i = Set1.date_counter; i < Set1.date_counter + Set2.date_counter;i++)
		{
			if (UnionSet.isValid(Set2.Dates[i-Set1.date_counter].getDay(),Set2.Dates[i-Set1.date_counter].getMonth()))
			{
				UnionSet.Dates[i-a] = Set2.Dates[i-Set1.date_counter];
				UnionSet.date_counter++;
			}
			else
				a++;
		}
		return UnionSet;

	}

	DayOfYearSet operator-(const DayOfYearSet& Set1,const DayOfYearSet& Set2)//Operator -
	{
		DayOfYearSet DifSet;
		for (int i = 0; i < Set1.date_counter; i++)
		{
			if (Set2.isValid(Set1.Dates[i].getDay(),Set1.Dates[i].getMonth()))
			{
				DifSet.Dates[DifSet.date_counter] = Set1.Dates[i];
				DifSet.date_counter++;
			}
		}
		return DifSet;
	}

	DayOfYearSet operator^(const DayOfYearSet& Set1,const DayOfYearSet& Set2)//Operator ^
	{
		DayOfYearSet intSet;
		for (int i = 0; i < Set1.date_counter; i++)
		{
			if (Set2.isValid(Set1.Dates[i].getDay(),Set1.Dates[i].getMonth()) == false)
			{
				intSet.Dates[intSet.date_counter] = Set1.Dates[i];
				intSet.date_counter++;
			}
		}
		return intSet;
	}

	DayOfYearSet operator!(const DayOfYearSet& Set1)//Operator !
	{
		DayOfYearSet CompSet;
		DayOfYearSet temp;
		for (auto i = 1; i < 13; i++)
		{
			for (decltype(i) j = 1; j < 32; j++)
			{
				temp.add(j,i);	
			}
		}

		CompSet = temp - Set1;
		CompSet.set_number-=2;
		CompSet.set_counter-=2;
		return CompSet;
	}
	bool operator==(const DayOfYearSet& Set1,const DayOfYearSet& Set2)//Operator ==
	{
		int eq_counter = 0;
		if (Set1.date_counter != Set2.date_counter)
		{
			return false;
		}
		for (int i = 0; i < Set1.date_counter; i++)
		{
			if (Set1.isValid(Set2.Dates[i].getDay(),Set2.Dates[i].getMonth()) == false)
			{
				eq_counter++;
			}
		}
		if (eq_counter == Set1.date_counter)
		{
			return true;
		}
		else
			return false;
		

	}

	bool operator!=(const DayOfYearSet& Set1,const DayOfYearSet& Set2)//Operator !=
	{
		if (Set1.date_counter != Set2.date_counter)
		{
			return true;
		}

		for (int i = 0; i < Set1.date_counter; i++)
		{
			if (Set1.isValid(Set2.Dates[i].getDay(),Set2.Dates[i].getMonth()) == true)
			{
				return true;
			}
		}
		return false;
	}

	ostream& operator<<(ostream& output,const DayOfYearSet& Set)//Operator <<
	{
		output << "Set number is: " << Set.set_number << endl
			   << "In this Set, I have " << Set.date_counter << " dates" << endl;

		for (int i = 0; i < Set.date_counter; i++)
		{
			output << Set.Dates[i].getDay() << "  "
			 	 << Set.Dates[i].getMonth() << endl;
		}
		cout << endl;
		return output;
	}
}
