/**
 * Author - Debag101
 * Purpose - Finding the area and perimeter of a rectangle
 * Date - 07.05.2023
 * */

//Importing the classes required for input from prebuilt java.io package
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

//Our class named appropriately for purpose of code
public class RectangularMensuration
{
	//The Area() function receives 2 double type params width 
	public double Area(double w, double h)
	{
		double Area = w * h; //return area by formula (width * height)
		return Area;
	}
	//The Perimeter() function receives 2 double type params width and height 
	public double Perimeter(double w, double h)
	{
		double Perimeter = 2 * (w + h); //return perimeter by formula 2(width + height)
		return Perimeter;
	}

	//The main method()
	public static void main(String[] args)throws IOException {
		
		//Defining and initializing variables to store dimensions of rectangle
		double width = 0, height = 0;
		//BufferedReader object allocation
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		//Object of our class to call methods
		RectangularMensuration obj = new RectangularMensuration();

		try//Putting input in try catch to catch NumberFormatException
		{
			System.out.println("(-) Enter the width of the rectangle => ");
			width = Double.parseDouble(reader.readLine());//Getting width

			System.out.println("(-) Enter the height of the rectangle => ");
			height = Double.parseDouble(reader.readLine());//Getting height
		}
		catch(Exception NumberFormatException)//Catching exception
		{
			System.err.println("(-) Please enter numeric values only !\n(-) Encountered NumberFormatException!");
			System.exit(1);
		}
		//Printing result
		System.out.printf("For dimensions %f cm x %f cm the area is %f cm^2 and perimeter is %f cm",width,height,obj.Area(width,height),obj.Perimeter(width,height));

	}
}
