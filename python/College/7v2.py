import os
import zipfile

def backup_to_zip(folder):
    folder = os.path.abspath(folder)
    number = 1
    while True:
        zip_filename = os.path.basename(folder) + '_' + str(number) + '.zip'
        if not os.path.exists(zip_filename):
            break
        number += 1
    print(f'Creating {zip_filename}...')
    with zipfile.ZipFile(zip_filename, 'w') as zip_file:
        for foldername, subfolders, filenames in os.walk(folder):
            print(f'Adding files in {foldername}...')
            for filename in filenames:
                file_path = os.path.join(foldername, filename)
                zip_file.write(file_path, arcname=os.path.relpath(file_path, folder))
    print('Done.')

backup_to_zip('python')