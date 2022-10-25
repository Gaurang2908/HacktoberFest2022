####### Queue Implementation #######

#Developer : Akhil S Kumar
#Date Created : 13/10/2022
#https://www.github.com/akhil-s-kumar

n = int(input("Enter the maximum limit of list: ")) #Limit of list
queue  = [] #Empty list
cont = "y" or "Y" #Body loop
while cont.lower() == "y" or cont.upper() == "Y":
    print("Press 1 for Enqueue")  #Option1
    print("Press 2 for Dequeue")  #Option2
    print("Press 3 for Peek")     #Option3
    print("Press 4 for Display Queue")   #Option4
    print("Press 5 for Exit")   #Option5
    m = int(input("Enter your choice: ")) #User choice
    
    if m is 1:  #Enqueue (Adding of elements into the empty list)
        element = int(input("Enter item: "))
        if len(queue) < n:
            queue.append(element)            
        else :
            print("OverFlow")
              
    elif m is 2:  #Deletion of first element in the list (FIFO)
        if len(queue)>0:
            b = queue.pop(0)
            print("Dequeued element is ",b)
        else :    
            print("UnderFlow! Queue is empty!")

    elif m is 3:  #First element in the list
        if queue == []:
            print("Queue is Empty")
        else:
            print("ForeMost item is ",queue[0])

    elif m is 4:  #Disply of queue
        if queue == []:
            print("Queue is Empty!")
        else:
           print(queue[0]," <- Front end")
           for a in queue[1:len(queue)-1]:
                 print(a)              
           print(queue[len(queue)-1], "<- Rear end")
            
    elif m is 5: #Exit
        break

    else:
        print("Invalid! Press the correct option.")
    
    cont = input("Do you want to continue? (y/n)") #Continue loop
    if cont == "n":
        break