#Develop a program to backing Up a given Folder (Folder in a current working directory) into a ZIP 
#File by using relevant modules and suitable methods.

import zipfile, os

def backup_folder(folder_name, zip_file):
    with zipfile.ZipFile(zip_file, 'w') as zipf:
        for file_path in (os.path.join(root, file) for root, dirs, files in os.walk(folder_name) for file in files):
            zipf.write(file_path)

backup_folder('python', 'python.zip')