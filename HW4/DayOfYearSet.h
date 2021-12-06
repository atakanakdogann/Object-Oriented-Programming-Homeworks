#ifndef DAYOFYEARSET_H_
#define DAYOFYEARSET_H_

#include <iostream>
#include <vector>
#include <fstream>

namespace Atakan{
	using std::ostream;
	using std::ofstream;
	using std::vector;
	using std::endl;
	using std::cout;

	class DayOfYearSet{
	public:
		class DayOfYear{
		public:
			inline void setDay(int day_value){Day = day_value;};
			inline void setMonth(int month_value){Month = month_value;};
			inline int getDay(){return Day;};
			inline int getMonth(){return Month;};
			DayOfYear();	
		private:
			int Day;
			int Month;
		};
		DayOfYearSet();
		DayOfYearSet(vector<DayOfYear> Set);
		void print()const;
		bool isValid(int day_value,int month_value)const;
		void add(int day_value,int month_value);
		void remove(int element_number);
		inline int size(){return date_counter;};
		static int getTotalDates();

		DayOfYear& operator[] (int index);
		friend DayOfYearSet operator+(const DayOfYearSet& Set1,const DayOfYearSet& Set2);
		friend DayOfYearSet operator-(const DayOfYearSet& Set1,const DayOfYearSet& Set2);
		friend DayOfYearSet operator^(const DayOfYearSet& Set1,const DayOfYearSet& Set2);
		friend DayOfYearSet operator!(const DayOfYearSet& Set1);
		friend bool operator==(const DayOfYearSet& Set1,const DayOfYearSet& Set2);
		friend bool operator!=(const DayOfYearSet& Set1,const DayOfYearSet& Set2);
		friend ostream& operator<<(ostream& output,const DayOfYearSet& Set);
	private:
		static int total_counter; 
		DayOfYear* Dates;
		static int set_counter;
		int set_number;
		int date_counter = 0;
	};

}


#endif