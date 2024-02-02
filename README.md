# TCP Client-Server Model
This document is provided as a guide to understand, compile, and run the accompanying software. The code is for a simple client-server socket connection model, and is implemented in the C language, with the use of UNIX/Linux libraries in mind. The libraries include all macros needed to create sockets for communication remotely across a network.

As the Linux system was in mind during production of the code, it is intended to be compiled and executed using the GNU Compiler Collection (gcc) in the Ubuntu/Linux environment.
The execution commands in the terminal command line are as follows:

`gcc -oExecutable Filename.c`

Where: `Executable` is the name given to the executable file created during compilation,
 `Filename.c` is the name of the file containing the script written in a    	   	  text editor.
The program is then executed as follows:

`./Executable`

As this is a client-server model, it is required that both files are executed simultaneously, in two separate terminal windows, with the server file executed first, followed by the client.