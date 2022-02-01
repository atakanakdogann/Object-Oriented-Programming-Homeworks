import java.util.*;
/**
 * @author Atakan Akdogan
 * @version 2022.1.0
 * 1801042612
 * The main class
 */

public class main
{

	/**
	 * Main Method.
	 * Some tests and file-writings.
	 * @param args -
	 */
	public static void main(String[] args) 
	{
		DayOfYearSet set1 = new DayOfYearSet();
		DayOfYearSet set2 = new DayOfYearSet();
		// Addition
		set1.add(10,12);
		set1.add(11,20);
		set1.add(3,2);
		set1.add(4,5);

		set2.add(5,12);
		set2.add(3,2);
		set2.add(4,3);

		// Difference check
		DayOfYearSet difSet = new DayOfYearSet();
		difSet = set1.differenceSet(set2);
		System.out.println("Difference Set");
		System.out.printf("%s",difSet.toString());

		// Delete check
		System.out.println("Before delete 5-4");
		System.out.printf("%s",set1.toString());
		set1.remove(4,5);
		System.out.println("After delete 5-4");
		System.out.printf("%s",set1.toString());
		
		// Using De Morgan Rules
		DayOfYearSet set3 = new DayOfYearSet();
		set3 = set1.unionSet(set2);
		set3 = set3.complementSet();

		set1 = set1.complementSet();
		set2 = set2.complementSet();
		DayOfYearSet set4 = new DayOfYearSet();
		set4 = set3.intersectionSet(set2);
		// De Morgan finished
		if (set4.equals(set3)) {
			System.out.println("DeMorgan approved");
		}
		//File Writing
		set4.writeToFile("file.txt");
		//Alive Set Control
		System.out.printf("There is %d sets alive",set4.aliveSets());		
  
	}
}
