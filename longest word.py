txt = input("Enter the text:")
txt=txt.split(" ")
l={}
a=[]
for i in txt:
     b=len(i)
     l[b]=i
     a.append(b)
a=sorted(a)
print(l[a[-1]])