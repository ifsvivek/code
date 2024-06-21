import pyautogui
from PIL import ImageGrab
import time


def check_for_dark_theme(img_data):
    for i in range(70, 100):
        for j in range(505, 515):
            if img_data[i, j] < 50:
                return True
            else:
                return False


def dodge(img_data, game_mode):
    # detecting cactus
    for i in range(310, 380):
        for j in range(480, 490):
            # if we are in dark mode
            if game_mode == 'dark':
                # img_data[i, j] = 255
                if img_data[i, j] >= 170:
                    pyautogui.keyDown('up')
                    time.sleep(0.25)
                    return
            # if we are in light mode
            # elif game_mode == 'light':
            #     img_data[i, j] = 0
            #     if 170 <= img_data[i, j] < 200:
            #         pyautogui.keyDown('up')
            #         return

    # detecting bird
    for i in range(310, 430):
        for j in range(420, 478):
            # img_data[i, j] = 255
            if img_data[i, j] >= 170:
                pyautogui.keyDown('down')
                time.sleep(0.3)
                return

            # if we are in light mode
            # elif game_mode == 'light':
            #     img_data[i, j] = 0
            #     if 170 <= img_data[i, j] < 200: 
            #         pyautogui.keyDown('down')
            #         return


time.sleep(3)
pyautogui.keyDown('up')

while True:
    image = ImageGrab.grab().convert('L')
    image_data = image.load()
    dark_theme = check_for_dark_theme(img_data=image_data)
    if dark_theme:
        mode = 'dark'
        dodge(img_data=image_data, game_mode=mode)
    else:
        mode = 'light'
        dodge(img_data=image_data, game_mode=mode)


# image = ImageGrab.grab().convert('L')
# image_data = image.load()
# mode = 'dark'
# dodge(img_data=image_data, game_mode=mode)
# image.show()                     