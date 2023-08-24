# User Manual

## Before running the software (Installation)
Download the most recent release from GitHub [here](https://github.com/Maxomann/TDMon/releases). Unpack the downloaded .zip file into a folder, somewhere on your computer.
The software requires the "Microsoft Visual C++ Redistributable packages for Visual Studio 2015, 2017, 2019, and 2022" to be installed on the system, before starting `TDMon.exe`. Otherwise ".dll not found" errors may arise. The releases of TDMon are bundled with a file called `vc_redist.x64.exe`. Please run this file to install the redistributables.

To run the software, please open `TDMon.exe`.

## While running the software
If any operation fails, errors are displayed in the console window.

### Setup
In the main menu, after opening the application, please click the "setup" button to enter the setup.
Here, please enter two things:
- The path to the technical debt dataset on your computer. You can download the technical debt dataset (V2) from [here](https://github.com/clowee/The-Technical-Debt-Dataset/releases/tag/2.0.1). Please make sure to download the `td_V2.db` file, not the source code. If you store the dataset on the desktop, a valid input for the path would be: `C:\Users\[username]\Desktop\td_V2.db`. It does not matter where you store the database, as long as the path you enter in the setup is valid.
- The user identifier from the databse which should be used to construct the TD-Mon. A selection of valid inputs here is:
	- jcamachorodriguez
	- ashutoshc
	- vihangk1
	- pvary
	- jking3
	- navis
	- lirui
	- szehon
	- hanm
	- aihuaxu

Then press "accept".

### Viewing the TD-Mon
Press the "View my TD-Mon" button. To refresh the data, please press the "refresh" button in the top-right corner. **Please note: by default, the TD-Mon is only updated automatically when you view it for the very first time. In any subsequent access (even after restarting the application!), you need to press the refresh button to update the TD-Mon. This is so that you do not have to enter your setup information every time you want to see your TD-Mon.**
