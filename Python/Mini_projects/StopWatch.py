import time
print('Press Enter to begin, Press Enter again to stop')
if input()=='':
    starttime = time.time()
    print('Started')
    while True:
            val=input() #For ENTER
            if val=='':
                print('Stopped')
                endtime = time.time()
                print('Total Time:', round(endtime - starttime, 2),'secs')
                break
                          
