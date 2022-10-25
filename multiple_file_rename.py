from fileinput import filename
import os

paths = (os.path.join(root, filename)
        for root, _, filenames in os.walk("STS")
        for filename in filenames)

for path in paths:
    # the '#' in the example below will be replaced by the '-' in the filenames in the directory
    newname = path.replace(str(path)[4:15], '')
    if newname != path:
        os.rename(path, newname)
 