import pyautogui
import cv2
import numpy as np
import time

# Define the area to check on the screen (top-left corner and width/height)
width, height = 80, 80  # Rectangle width and height

# Define the color range for red (BGR values)
lower_red = np.array([160, 50, 50], dtype=np.uint8)
upper_red = np.array([180, 255, 255], dtype=np.uint8)

# Initial delay between each screenshot (in seconds)
delay = 0.0001

i = 0
start_time = time.time()
while True:
    x, y = 250 + i, 600
    # Take a screenshot of the defined area
    screenshot = pyautogui.screenshot(region=(x, y, width, height))

    # Convert the screenshot to a numpy array and then to BGR format directly
    image = np.array(screenshot)[:, :, ::-1]

    # Create a mask to isolate the red color
    mask = cv2.inRange(image, lower_red, upper_red)

    # Check if there are any red pixels in the mask
    red_pixels = np.count_nonzero(mask)

    # If there's a red object in the area, press the space bar
    if red_pixels > 0:
        pyautogui.press("up")
        # Adjust 'i' based on game progress or obstacles passed
        i = min(i + 3, 250)  # Example adjustment, tweak based on actual game behavior

    # Exit the loop on 'q' key press (this part is for demonstration and will not work in this script)
    # if cv2.waitKey(1) == ord("q"):
    #     cv2.destroyAllWindows()
    #     break

    # Decrease the delay as the game progresses
    elapsed_time = time.time() - start_time
    delay = max(0.001, 0.01 - elapsed_time / 100.0)

    # Wait for the delay before taking the next screenshot
    time.sleep(delay)
