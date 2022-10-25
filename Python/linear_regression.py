
import numpy as np

#np.hstack((np.ones((len(x),1)),x.reshape(-1,1)))


def hyp(X,Theta):
  return X.dot(Theta)

def d_cost(x,y,theta):
  x= x.reshape(-1,1)
  y=y.reshape(-1,1)
  x = np.hstack((np.ones((x.shape[0],1)), x))
  h = hyp(x,theta)
  print(h)
  return (1/(2*(h.shape[0]))) * (np.sum((h - y)**2))



def gd(x,y,t,alpha):
  x= x.reshape(-1,1)
  xt = np.hstack((np.ones((x.shape[0],1)), x))
  y = y.reshape(-1,1)
  m = y.shape[0]
  for i in range(3):
      h = hyp(xt,t)
      diff  = h -y
      delta = (1/m) * (diff.transpose().dot(xt))
      k = (alpha * delta)
      t = t - k

if __name__=="__main__":
  x=np.array([1,2,3,4,7])
  y= np.array([10,20,25,35,50])
  t = np.zeros((2,1))
  d_cost(x,y,t)
  gd(x,y,t,0.01)

