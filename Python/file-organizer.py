# Program to organize files in a directory

import os
from pathlib import Path

DIRS = {
    'Docs': ['.doc', '.docx'],
    'Videos': ['.mp4', '.mov', '.mkv'],
    'Music': ['.mp3', '.wav'],
    'Images': ['.jpeg', '.jpg', '.png', '.gif'],
    'Pdf': ['.pdf'],
    'Excel': ['.xls', '.xlsx'],
    'Exceutable': ['.exe'],
}

def findLocation(ext):
    for cat, extentions in DIRS.items():
        for extention in extentions:
            if extention == ext:
                return cat
    return 'Others'


def organize():
    for item in os.scandir():
        if item.is_dir():
            continue
        filepath = Path(item)
        ext = filepath.suffix.lower()
        
        if ext == '.py':
            continue
        
        dir = findLocation(ext)
        dir_path = Path(dir)
        
        if dir_path.is_dir()!=True:
            dir_path.mkdir()
        
        filepath.rename(dir_path.joinpath(filepath))

organize()