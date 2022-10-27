import math

def longestUniqueSubsttr(str):
	test = ""
	# Result
	maxLength = -1
	
	if (len(str) == 0):
		return 0
	elif(len(str) == 1):
		return 1
	for c in list(str):
		current = "".join(c)
		
	
		if (current in test):
			test = test[test.index(current) + 1:]
		test = test + "".join(c)
		maxLength = max(len(test), maxLength)
	return maxLength


string = "geeksforgeeks"
print("The input string is", string)
length = longestUniqueSubsttr(string)
print("The length of the longest non-repeating character substring is", length)

