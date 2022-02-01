import java.util.*;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

/**
 * @author Atakan Akdogan
 * @version 2022.1.0
 * DayOfYearSet class
 * Class has one inner class named DayOfYear
 * Class has also some constructors and methods
 */

public class DayOfYearSet
{
	/**
	 * DayOfYear class
	 * Class has getter and setter methods for variables day and month
	 */
	public static class DayOfYear{
		private int day;
		private int month;
		
		/**
		 * Setter for month.
		 * @param month_value
		 * Sets for month.
		 */
		public void setMonth(int month_value)
		{
			month = month_value;
		}
		/**
		 * Setter for day.
		 * @param day_value
		 * Sets for day.
		 */
		public void setDay(int day_value)
		{
			day = day_value;
		}
		/**
		 * Getter for month.
		 * @return month
		 */
		public int getMonth()
		{
			return month;
		}
		/**
		 * Getter for day.
		 * @return day
		 */
		public int getDay()
		{
			return day;
		}
	}

	/** 
	 * DayOfYearSet Constructor.
	 * Constructor takes tempSet parameter.
	 * uses set_number for only managing which set is which number
	 * uses date_counter for managing how many DayOfYear object that tempSet has
	 * uses toArray for copying indexes. It is sufficient to send toArray only index[0]
	 * @param tempSet
	 * tempSet has some random DayOfYear objects
	 */
	public DayOfYearSet(ArrayList<DayOfYear> tempSet)
	{
		set_number = set_counter;
		set_counter++;
		Dates = tempSet.toArray(new DayOfYear[0]);
		date_counter = tempSet.size();
	}

	/**
	 * DayOfYearSet Constructor.
	 * Constructor has no parameter.
	 * This constructor does only set_number initialization.
	 */
	public DayOfYearSet()
	{
		set_number = set_counter;
		set_counter++;
	}

	/**
	 * Validity method.
	 * Method is returning true or false according to validity.
	 * If clauses controls days according to months. 
	 * If clauses seperated due to months has 28-30-31
	 * @param month_value
	 * Entered Month value.
	 * @param day_value
	 * Entered Day value.
	 * @return true or false.
	 */
	public boolean isValid(int month_value,int day_value)
	{
		if (day_value <= 0 || month_value <= 0 || month_value > 12) {
			return false;
		}

		if (month_value == 2) {
			if (day_value > 28) {
				return false;
			}
		}
		else if (month_value == 1 || month_value == 3 || month_value == 5 || month_value == 7 || month_value == 8 || month_value == 10 || month_value == 12) {
			if (day_value > 31) {
				return false;
			}
		}
		else if (month_value == 4 || month_value == 6 || month_value == 9 || month_value == 11) {
			if (day_value > 30) {
				return false;
			}
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
	/**
	 * Adds to the Set Method.
	 * if entered month and day values are valid acc. to the isValid method, adds to the Dates array.
	 * date_counter conts how many dates object Set has.
	 * @param month_value
	 * Entered month value.
	 * @param day_value
	 * Entered day value.
	 */
	public void add(int month_value,int day_value)
	{
		
		if (isValid(month_value,day_value)) 
		{
			Dates[date_counter] = new DayOfYearSet.DayOfYear();
			Dates[date_counter].setDay(day_value);
			Dates[date_counter].setMonth(month_value);
			date_counter++;	
		}		
	}
	/**
	 * Removes from Set Method.
	 * In first loop and if clause,checks for if entered values exists in Set.
	 * If exists, dates after the this date moves to the left. 
	 * @param month_value
	 * Entered month value.
	 * @param day_value
	 * Entered day value.
	 */
	public void remove(int month_value,int day_value)
	{
		for (int i = 0; i<date_counter; i++) {
			if (Dates[i].getDay() == day_value && Dates[i].getMonth() == month_value) {
				for (int j = i; j < date_counter-1; j++) {
					Dates[j].setDay(Dates[j+1].getDay());
					Dates[j].setMonth(Dates[j+1].getMonth());
				}
				date_counter-=1;
				return;
			}
		}
	}
	/**
	 * String builder and returns to String Method.
	 * Appends Dates objects to end of string by using getters.
	 */
	@Override
	public String toString()
	{
		StringBuilder str = new StringBuilder();

		str.append("This is Set number "+ String.valueOf(set_number) + "\n");
		str.append("Set has" + String.valueOf(date_counter) + "Dates\nThese Dates are:\n");
		for (int i = 0;i < date_counter ; i++ ) {
			str.append(String.valueOf(Dates[i].getDay()) + "-");
			str.append(String.valueOf(Dates[i].getMonth()) + "\n");
		}
		return str.toString();
	}
	/**
	 * Equality check Method.
	 * First controls Sets date counter. If Sets don't have same date objects, returns false.
	 * I used var temp is for counting how many same Dates objects that Sets has.
	 * If temp is equals to date_counters, returns false,else true.
	 * @param otherSet
	 * otherSet is different DayOfYearSet object for comparison.
	 * @return true or false.
	 */
	public boolean equals(DayOfYearSet otherSet)
	{
		var temp = 0;
		if (date_counter != otherSet.date_counter) {
			return false;
		}
		for (int i = 0; i<date_counter; i++) {
			for (int j = 0; j<date_counter; j++) {
				if(Dates[i].getDay() == otherSet.Dates[j].getDay() && Dates[i].getMonth() == otherSet.Dates[j].getMonth())
				{
					temp++;
				}
			}
		}
		if (temp == date_counter) {
			return true;
		}
		return false;
	}
	/**
	 * Size Method.
	 * @return date_counter
	 */
	public int size()
	{
		return date_counter;
	}
	/**
	 * Intersection Set Method.
	 * I used some trick here. I used isValid function for is there any same object with the otherSet.
	 * If there is, isValid method returns false and when false returned, I added these items to intSet.
	 * @param otherSet
	 * otherSet is different DayOfYearSet object for find intersections.
	 * @return intSet
	 */
	public DayOfYearSet intersectionSet(DayOfYearSet otherSet)
	{
		DayOfYearSet intSet = new DayOfYearSet();
		for (int i = 0; i < date_counter; i++)
		{
			if (otherSet.isValid(Dates[i].getMonth(),Dates[i].getDay()) == false)
			{
				intSet.Dates[intSet.date_counter] = Dates[i];
				intSet.date_counter++;
			}
		}
		return intSet;
	}
	/**
	 * Difference Set Method.
	 * I used same trick with intersection Set method.
	 * If isValid method returns true when I send this.Dates object to otherSets isValid, I added to the diffSet.
	 * @param otherSet
	 *  otherSet is different DayOfYearSet object for find differences.
	 * @return diffSet.
	 */
	public DayOfYearSet differenceSet(DayOfYearSet otherSet)
	{
		DayOfYearSet diffSet = new DayOfYearSet();
		for (int i = 0; i < date_counter; i++)
		{
			if (otherSet.isValid(Dates[i].getMonth(),Dates[i].getDay()))
			{
				diffSet.Dates[diffSet.date_counter] =Dates[i];
				diffSet.date_counter++;
			}
		}
		return diffSet;
	}
	/**
	 * Union Set Method.
	 * First I copied all items in Dates object.
	 * After according to the isValid method, I added otherSet's items.
	 * @param otherSet
	 *  otherSet is different DayOfYearSet object for find union set.
	 * @return uniSet
	 */
	public DayOfYearSet unionSet(DayOfYearSet otherSet)
	{
		var a = 0;
		DayOfYearSet uniSet = new DayOfYearSet();
		for (int i = 0; i < date_counter; i++)
		{
			uniSet.Dates[i] = Dates[i];
			uniSet.date_counter++;
		}
		for (int i = date_counter; i < date_counter + otherSet.date_counter;i++)
		{
			if (uniSet.isValid(otherSet.Dates[i-date_counter].getMonth(),otherSet.Dates[i-date_counter].getDay()))
			{
				uniSet.Dates[i-a] = otherSet.Dates[i-date_counter];
				uniSet.date_counter++;
			}
			else
				a++;
		}
		return uniSet;
	}
	/**
	 * Complement Set Method.
	 * I initialized a temp Set which has 365 dates.
	 * After, in loop I chechked every otherSet item with 365 date tempSet object.
	 * If loop item doesnt have in otherSet Dates array, I added this item to compSet  
	 * @return compSet
	 */
	public DayOfYearSet complementSet()
	{
		var tmp = 0;
		DayOfYearSet tempSet = new DayOfYearSet();
		DayOfYearSet compSet = new DayOfYearSet();
		for (int i = 1; i < 13;i++ ) 
		{
			for (int j = 1; j<32; j++) 
			{
				tempSet.add(i,j);
			}
		}

		for (int i = 0; i<365; i++) {
			for (int j = 0; j<date_counter; j++) {
				if (tempSet.Dates[i].getDay() == Dates[j].getDay() && tempSet.Dates[i].getMonth() == Dates[j].getMonth()) {
					tmp++;
				}
			}
			if (tmp == 0) {
				compSet.add(tempSet.Dates[i].getMonth(),tempSet.Dates[i].getDay());
			}
			tmp = 0;
		}


		return compSet;
	}
	/**
	 * Alive Set Method.
	 * @return static set_counter
	 */
	public static int aliveSets()
	{
		return set_counter;
	}

	/**
	 * File Writing Method.
	 * This method writes to the file.
	 * Also error checking to some errors.
	 * @param fileName name for file
	 */
	public void writeToFile(String fileName)
	{
		try {
            File fileObject = new File(fileName);
            FileWriter file = new FileWriter(fileName);
            for(int i = 0; i<date_counter; i++){
                file.write(Dates[i].getDay() + "-" + Dates[i].getMonth() + "\n");
            }
            file.close();
            System.out.println("Set is written to text file"); 
        } 
        catch (IOException exception) {
            System.out.println("Warning! There is an error");
            exception.printStackTrace();
        }
	}

	private int set_number;
	private static int set_counter = 0;
	private int date_counter = 0;
	private DayOfYearSet.DayOfYear Dates[] = new DayOfYearSet.DayOfYear[365];
}