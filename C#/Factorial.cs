using System;

/// <summary>
/// Calculates Factorial of a number using recursion.
/// </summary>
internal class Factorial
{
    /* Usage
    private static void Main(string[] args)
    {
        int result = Calculate(5);

        Console.WriteLine(result); // 120
    }
    */

    private static int Calculate(int number)
    {
        if (number == 0)
            return 1;

        return number * Calculate(number - 1);
    }
}