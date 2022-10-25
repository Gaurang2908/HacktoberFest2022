import string
word = input().rstrip()
length = len(word)

vowels = {i : False for i in string.ascii_uppercase}

for i in "AEIOU":
    vowels[i] = True

player1_points = 0
player2_points = 0

for start in range(length):
    if vowels[word[start]]:
       bob_points += length - start
    else:
       stuart_points += length - start

if player1_points > player2_points:
    print("Player1", player1_points)
elif player1_points < player2_points:
    print("player2", player2_points)
else:
    print("Draw")
