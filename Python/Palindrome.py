def palindromeMethod1(num):
     x1 = num[::-1]
     if x1 == x:
       print('palindrome')
    else:
       print('not a palindrome')
          
def palindromeMethod2(x):
     # Method - 2 ( Reverse the number and compare )
     ori = x
     tempcopy = 0
     while(x > 0 ):
         tempcopy = tempcopy*10 + x % 10
         x = x//10
     if tempcopy == ori:
          print("Palindrome")
     else:
          print("not a Palindrome")
     
 
print(pal('Srishti'))
