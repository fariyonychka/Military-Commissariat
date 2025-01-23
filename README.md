User manual
1.Software components
Basic technologies and tools:
- Developed in the programming language: C++ using the C++/CLI extension to work with the .NET Framework.
- Development environment: Visual Studio 2022 is an integrated development environment for C++/CLI and Windows Forms.
- Libraries and APIs:
+ .NET Framework: for creating a graphical user interface (Windows Forms) and integrating with C++ code.
. MSCLR (Microsoft Common Language Runtime): for interaction between C++ and .NET components.
. STL (Standard Template Library): used to store and process data in the form of vectors and containers.
. Windows API: for accessing basic functions of the Windows operating system (for example, processing form events, saving files).
Compilation and configuration tools:
- Compiler: Visual Studio C++ compiler for C++ code and C++/CLI compilation into .NET applications.
- Libraries for working with files:
. <fstream>: a standard C++ library for reading and writing to text files.
. msclr::interop: for converting between C++ and C++/CLI types.
External dependencies:
- Visual Studio Tools for Windows Forms: a set of tools for working with graphical interfaces on the Windows platform.
2. Installing the software
System requirements:
- Operating system: Windows 11.
- Software: Visual Studio 2022 with C++/CLI and WinForms support.
Installation steps:
1.	Download and install Visual Studio 2022 from the official website https://visualstudio.microsoft.com/.
2.	During the installation, select C++/CLI and Windows Forms support (you can configure it through the ‘Workload’ in the Visual Studio Installer).
3.	Clone or open the project in Visual Studio 2022.
4.	To start working with the application, run the Military Commissariat.exe executable file.
3. Setting up the software
You do not need to configure the software. It is completely ready for use.
4. Basic functions of the software
1. Reading data from a file 
- Use the ‘Open’ menu item to import all the data of military enlistment offices from a .txt text file into the table.
- 2. Reading data from the keyboard 
- Use ‘+’ to open a form with fields for data entry.
- Enter the data in the specified fields and click ‘Save’.
 3. Calculating average costs (button1)
- Clicking on the button button1 calls up the function of calculating the average costs for all military enlistment offices.
- The result is displayed in a new form, where the user can see the average costs for the enlistment offices.
 
4. Sorting military enlistment offices (button2)
- The button2 button allows you to sort military enlistment offices by the number of employees.
- After sorting, the data table is updated automatically.
5. Search for military enlistment offices by criterion (button3, button4, button5)
- button3: Search for military enlistment offices with less than 50% of the number of employees.
- button4: Search for military enlistment offices where the cost per employee is higher than the average for all military enlistment offices.
- button5: Search for 4 military enlistment offices with more than average number of employees, but less than average cost per employee.
- The search results are displayed in new forms with details of the relevant military enlistment offices.
- 6. General information about military enlistment offices (button6)
- Button6 shows general information about all military enlistment offices, including total costs per employee, number of employees and number of assigned employees.
- The result is displayed in a new form where the user can see the general data.
7. Save data (Save menu)
- Use the ‘Save’ menu item to export all the data of military enlistment offices to a .txt file.
8. Closing the application
 - When you try to close the program, if there are unsaved changes, the program will ask if you want to save the changes before exiting. If you select ‘Yes’, select the file to save, the changes will be saved and the program will close.

Structure of the input file
The name of the military enlistment office, street, house number, number of employees, number of enlisted persons, and costs per person should be entered on a new line, without any punctuation.
The name of the military enlistment office and the street can be written in Latin or Cyrillic characters.
The number of employees, the number of assigned personnel, and the cost per person should contain only numbers.
The house number may contain a letter.
