year=int(input("Enter the year:"))
if (year % 400 == 0 or (year%4==0 and year%100!=0)):  #For a year to be leap year, it is necessary that it is divisible by 4 and 400 but not by 100 only.
    print(year,"is a leap year.")
else:
    print(year,"is not a leap year.")
