N = 4
  

ld = [0] * 30
  

rd = [0] * 30
  

cl = [0] * 30
  

def printSolution(board): 
    for i in range(N):
        for j in range(N):
            print(board[i][j], end = " ")
        print() 
  

def solveNQUtil(board, col): 
      

    if (col >= N):
        return True
          

    for i in range(N):
          
     
        if ((ld[i - col + N - 1] != 1 and 
             rd[i + col] != 1) and cl[i] != 1):
                   
 
            board[i][col] = 1
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 1
              

            if (solveNQUtil(board, col + 1)):
                return True
                  

            board[i][col] = 0 # BACKTRACK 
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 0
              
       
    return False
      

def solveNQ():
    board = [[0, 0, 0, 0], 
             [0, 0, 0, 0],
             [0, 0, 0, 0],
             [0, 0, 0, 0]]
    if (solveNQUtil(board, 0) == False):
        printf("Solution does not exist")
        return False
    printSolution(board)
    return True
      

solveNQ() 
