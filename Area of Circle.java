import java.util.Scanner;

public class Ex12AreaofCircle{

    public static void main(String args[]){
		
		Scanner userIn = new Scanner(System.in);
		
		System.out.println("Enter radius of circle: ");
		float radius = userIn.nextFloat();
	    
	    	double a=area(radius);
		System.out.println("The area of the circle is: " + a);
        
    }
	
	public double area(float r)
	{
		double ar=Math.PI * radius * radius;
		return ar;
	}
}



