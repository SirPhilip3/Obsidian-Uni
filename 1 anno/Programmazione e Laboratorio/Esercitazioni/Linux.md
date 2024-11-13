---
publish: true
---
## Filesystem

![[Immagine 2023-03-04 114650.png]]

## Commands

+ __pwd__ : prints the path of the current directory
+ __ls__ : list all the elements of the current directory
	+ __-l__ : long format for __ls__ (permission, size etc)
	+ __-a__ : show all files, including hidden ones
+ __man__ : shows the manual for a command (example: `man ls`)
+ __cd__ : change directory
	+ __cd . .__  : goes back 1 directory
	+ __cd --__  : returns to the home directory
+ __mkdir__ : create a directory
+ __rmdir__ : removes only empty directory
+ __rm__ : removes files
	+ __-r__ : removes it recursively (example: `rm -r file1 file2 dir1 dir2`)
	+ __-f___ : the operation skips all warnings
	```ad-danger
	With -rf options you can delete all your Filesystem
	```
+ __mv__ : command move, examples:
	+ __rename with mv__ : `mv old_filename new_filename
	+ __move files__ : `mv /home/prog2021/filename /path/`
	+ __move and rename__ : `mv /home/prog2021/old_filename /path/new_filename` 
	```ad-danger
	If new_filename already exist it will be overwritten
	```
+ __cp__ : copy of a file or of a directory, examples:
	+ `cp old_name new_name`
	+ `cp file dir_name/`
	+ `cp old_name dir_name/new_name`  
	```ad-danger
	If new_filename already exist it will be overwritten
	```
+ __nano__ : creates a file, and edit it
+ __less__ : only display a file
+ __head__ : Show the first 10 lines of a file
	+ __-n__ : show the first n lines (example: `head -n 20 filename`)
+ __tail__ : Show the last 10 lines of a file
	+ __-n__ : show the last n lines (example: `tail-n 20 filename`)
+ __cat__ : concatenate files (example: `cat file1.txt file2.txt > file3.txt`)
	```ad-danger
	If file3.txt already exist it will be overwritten
	```
	+ __>__ : redirects the output of a `cat` towards another file 
	+ __>>__ : appends content
+ __grep__ : Selects lines matching a specified PATTERN in a file (example: `grep PATTERN filename.txt`)
+ __|__ : allows the output of a command to be the input of another command (example: `grep pippo filename.txt | head` : returns the first 10 lines of filename.txt that contains the word _pippo_)
+ __wc__ : prints the number of lines, word and character of a file
	+ __-l__ : prints only the lines
	+ __-w__ : prints only the words
	+ __-c__ : prints only the characters