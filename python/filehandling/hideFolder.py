import os
path = input("Path to Folder to hide: ")
is_hidden = False
if os.path.exists(path):
    folder_attributes = os.stat(path).st_file_attributes
    is_hidden = folder_attributes & 2 != 0
if is_hidden:
    os.system('attrib -h +s "{}"'.format(path))
    print("Show: ".format(path))
else:
    os.system('attrib +h +s "{}"'.format(path))
    print("Hide: ".format(path))
