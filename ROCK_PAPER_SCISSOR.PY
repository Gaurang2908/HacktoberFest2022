import random
txt=".....ROCK /PAPER /SCISSOR....."
print(txt.center(100))
print("This is a Rock Paper Scissor game. you will have 10 chances to play and win. so,let's start the game.")
comp_win=0
you_win=0
chance=1
tie=0
while True:
    comp=random.choice(["r","p","s"])
    print("choose any one :")
    print("r for rock")
    print("p for paper")
    print("s for scissor")
    choice=input()
    print("computer turn")
    print(comp)
    if choice==comp:
        print("game tie")
        tie+=1
    elif comp=="r" and choice=="p":
        print("u win ")
        you_win+=1
    elif comp=="p" and choice=="s":
        print("u win ")
        you_win+=1
    elif comp=="s" and choice=="r":
        you_win+=1
    elif comp == "p" and choice == "r":
        print("computer win ")
        comp_win+= 1
    elif comp == "s" and choice == "p":
        print("computer win ")
        comp_win+= 1
    elif comp == "r" and choice == "s":
        print("computer win")
        comp_win+=1
    else:
        print("invalid input")
    chance=chance+1
    if chance>10:
        break
if you_win>5:
    print("\t\t\t\t\tcongrats!! you won.")
    print("\t\t\t\t\tyour score :"+str(you_win))
    print("\t\t\t\t\tcomp score :" + str(comp_win))
    print("\t\t\t\t\ttie :" + str(tie))
elif you_win<5:
    print("\t\t\t\t\tcomputer won")
    print("\t\t\t\t\tcomp score :"+str(comp_win))
    print("\t\t\t\t\tyour score :" + str(you_win))
    print("\t\t\t\t\ttie :"+str(tie))
else:
    print("\t\t\t\t\tgame tie")
    print("\t\t\t\t\tyour score :" + str(you_win))
    print("\t\t\t\t\tcomputer score :" + str(comp_win))
    print("\t\t\t\t\ttie :"+str(tie))
