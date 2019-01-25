## read.c

This one works pretty much just like `cat`. The program open a file, reads the contents and prints it out. Pass in a file you don't have permissions to read, and you will be able to read it.

`read /etc/shadow`

**Why does this work?**  
This is fundamentally how the setuid bit works. When the program is run, it runs with root privledges. This means when the file is accessed and checks the permissions on what is accessing it, the file sees root privledges because the program itself has root privledges. Anything that root can read, you can read by running this program, and root can read everything.
