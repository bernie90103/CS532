CS532 - Lab 4
===============

Files
-----
lab4.c      Appends the complete contents of file2 to the end of file1.
README.txt  Build, execution, and testing instructions.

Requirements
------------
- A UNIX-like environment, such as the course server or GitHub Codespaces.
- GCC.

Compile
-------
gcc -Wall -Wextra -Wpedantic -std=c11 -o lab4 lab4.c

Run
---
./lab4 <file1> <file2>

Example
-------
./lab4 file1 file2

After a successful run, file1 contains its original data followed by all data
from file2. File2 is opened read-only and remains unchanged.

Behavior and Error Handling
---------------------------
- Exactly two filenames must be supplied.
- File1 and file2 must be different files.
- File1 must already exist and be writable.
- File2 must already exist and be readable.
- The program reports open, read, write, and close errors.
- The program handles files larger than its 4096-byte buffer.
- The program does not insert an extra newline between the two files.

Suggested Test
--------------
printf 'Hello World! This is file one!\n' > file1
printf 'Hello World! This is file two!\n' > file2
./lab4 file1 file2
cat file1
cat file2

Expected file1:
Hello World! This is file one!
Hello World! This is file two!

Expected file2:
Hello World! This is file two!

Submission
----------
Submit lab4.c and README.txt to Canvas. Do not submit the executable or object
files.
