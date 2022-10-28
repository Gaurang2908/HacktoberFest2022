import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        float weight;
        int height;

        System.out.println("Enter your height(centimeters):");
        height = scan.nextInt();
        System.out.println("Enter your weight(kilograms):");
        weight = scan.nextFloat();
        float heightToMeter = height/100f;

        float result = weight/(heightToMeter*heightToMeter);

        if(result < 18.5f)
            System.out.println("You are underweight with a Body Mass Index of: " + result);
        if (result >= 18.5f && result <= 24.9f)
            System.out.println("You have normal healthy weight with a Body Mass Index of: " + result);
        if (result >= 25f && result <= 29.9f)
            System.out.println("You are overweight with a Body Mass Index of: " + result);
        if (result >= 30f)
            System.out.println("You have reached obesity with a Body Mass Index of: "+ result);
    }
}