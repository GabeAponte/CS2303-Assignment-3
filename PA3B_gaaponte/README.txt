Gabriel Aponte, gaaponte
PA3B README.txt

How to run program in command line:
	Download PA3B_gaaponte.zip and unzip it. Open the terminal and navigate to the folder where you unzipped the folder. 
Type the comand "make into the command line. This will compile the program. Now, navigate to the to the saem folder
inside the terminal again, but this time type the command "./structest.c". This will run the program.

How to run program in eclipse:
	Download PA3B_gaaponte.zip and unzip it. Open eclipse snd click on the File within the header on the top
left. Then click on "Import..". You will be presented with a drop down menue. Click on "General" and then
"Existing projects into workspace". Once you do this, browse the directory and find the unziped file and
select it. Now you can build the project and click run. 

Description of program:
	This program is a simple way to show how structs work in C and what you can do with them. 
In mystruct.c I created a stuct called employees that had fields of birth year, starting year and 
name for a employee. I then created a function that makes random employees by filling in those fields with
random data. I then used that function to create a function that makes a random array of employees. I also
wrote functions that duplicate pointers to employees using shallow copying and deep copying. Lastly, I wrote
a function that freed and pointers from the memory they were allocated.
structest.c contains all the tests for these functions to prove they work.