**General Tips and Configuration**

* **Enable Long Paths:**
  - Open Registry Editor (search for "regedit" in the Start menu).
  - Navigate to `HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\FileSystem`.
  - Double-click the `LongPathsEnabled` value and set it to `1`.
  - Restart your computer for changes to take effect.

* **Set Git User Information:**
  - Open a terminal window.
  - Run the following commands, replacing `Your Name` and `youremail@yourdomain.com` with your actual information:
    ```bash
    git config --global user.name "Your Name"
    git config --global user.email "youremail@yourdomain.com"
    ```

* **Customize Discord Profile Picture (CSS Example):**
  - Create a CSS file with the desired styling information.
  - Host the CSS file on a publicly accessible server.
  - In your Discord client, right-click your profile picture and choose "Inspect" (or "Inspect Element").
  - Find the element corresponding to your profile picture and add the following line to its style attribute, replacing `"https://gh.ifsvivek.tech/discordpfp/main.css"` with the actual URL of your hosted CSS file:
    
    ```css
    @import url("https://gh.ifsvivek.tech/discordpfp/main.css");
    ```


* **CPU Parking Guide:**

    - Follow the steps below to modify CPU parking settings. 
    - Open the Registry Editor. You can do this by searching for "regedit" in the Start menu.
    - Navigate to the following registry key:

    ```
    HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Power\PowerSettings\54533251-82be-4824-96c1-47b60b740d00\0cc5b647-c1df-4637-891a-dec35c318583
    ```
    - Locate the value named "Attributes" and set its data to 0.

* **Remove AMD Software from Right-Click menu**
  
    - Open the Registry Editor. You can do this by searching for "regedit" in the Start menu.
    - Navigate to the following key:
    ```
    HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Shell Extensions\Blocked
    ```
    - Right-click on the "Blocked" key and select "New" -> "DWORD (32-bit) Value".
    - Name the new value `{6767B3BC-8FF7-11EC-B909-0242AC120002}`.
    - Double-click the newly created value and set the data to be blank (leave the "Value data" field empty).
    - Navigate to the following key:
    ```
    HKEY_CLASSES_ROOT\Directory\Background\shellex\ContextMenuHandlers\ACE
    ```
    - Right-click on the "ACE" key and select "Delete".


* **Hiding and Unhiding Apps using adb shell**
    - Note: This gist requires your device to be connected to your computer via USB with USB debugging enabled.
    - Hiding an App:
    ```bash
    adb shell pm hide com.example.packagename
    ```
    - Unhiding an App:
    ```bash
    adb shell pm unhide com.example.packagename
    ```