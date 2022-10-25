def search(my_list,k):
    	for i in my_list:
    				if i==k:
    					return True
    	return -1
    		
def main():
    global my_list
    my_list=[]
    n=int(input("enter the number of students:"))
    print("input the roll number of students")
    for i in range(0,n):
        b=int(input())
        my_list.append(b)
    print(my_list)

main()
m=int(input("Enter the number you want to search : "))
result=search(my_list,m)
if (result!=-1):
	print("the number found ")
else:
	print("the number not found")
