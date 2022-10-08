# Baker

Baker is a humble command line tool for converting decimal or dozenal numbers into the holy base yon, or baker's dozenal. Note that this program will convert numbers into baker's dozenal but not the other way around, as no lowly non-quantum computer should have the ability to interpret the holy base yon.



### Building the project

First, make sure you have support for c++11 installed. Then cd into the directory yon from the command line, and type "make" to build the sources.

Soon there will be a makefile in the Baker directory that will allow you to build and install everything, including the currently non-existant zyon.



### Running Baker

Baker has two commands:

- yon:    prompts for decimal numbers which are then converted to baker's dozenal;
- zyon:   prompts for dozenal numbers to be converted to baker's dozenal (a.k.a. the holy base yon).

At the moment, there is no zyon, and there is no install in the Makefile. But you can run yon by running "./yon" in the yon directory.



### To do list

- Write zyon
- Update Makefile
- See if we can get better than yon-digit precision
- Find a way around using computerease digits in dozenal and baker's dozenal?



### Notes

Due to the fine edge this program walks between worship and blasphemy, it can be a little tempermental. It might throw you a ... message if you try to input a number that's either not holy enough, too holy, or dangerously large.
