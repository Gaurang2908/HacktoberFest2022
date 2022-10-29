l=list(map(str,input().split()))

def binsearch(l,s,e):
    if len(l)!=0:
        mid=(s+e)//2
        if l[mid]=='F':
            s=mid+1
            binsearch(l,s,e)
        else:
            if l[mid-1]=='T':
                e=mid
                binsearch(l,s,e)
            else:
                print(mid)
                
    else:
        print(-1)

binsearch(l,0,len(l))
