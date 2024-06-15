import cv2
import pyautogui

# Define the area to check on the screen (top-left corner and width/height)
x, y = 200, 655  # Top-left corner coordinates
width, height = 80, 80  # Rectangle width and height

# Define the color range for red (BGR values)
lower_red = (160, 50, 50)
upper_red = (180, 255, 255)

# Capture the screen continuously
while True:
    # Take a screenshot of the defined area
    screenshot = pyautogui.screenshot(region=(x, y, width, height))

    # Convert the screenshot to OpenCV image format
    image = cv2.cvtColor(screenshot, cv2.COLOR_BGR2RGB)

    # Create a mask to isolate the red color
    mask = cv2.inRange(image, lower_red, upper_red)

    # Check if there are any red pixels in the mask
    red_pixels = cv2.countNonZero(mask)

    # If there's a red object in the area, click at the specified location
    if red_pixels > 0:
        pyautogui.click(x=300, y=150)  # Adjust these coordinates as needed

    # Exit the loop on 'q' key press
    if cv2.waitKey(1) == ord('q'):
        cv2.destroyAllWindows()
        break
