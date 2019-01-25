# privledgeEscalation

This repository contains a number of examples of privledge escalation from a normal user to a superuser, by utilizing flaws in setuid applications. Each of these example programs contains a different exploitable vulnerability.  
**Do you think you can find them?**

**Note: I have only tested these programs under Linux, and in general they are only meant for *Nix based operating systems. If you want to use these to play with privledge escalation on Windows, you will have to setup the environment differently than how I describe below.

## Setup
In order to be exploitable, these files must be compiled under a superuser. We are going to use `root` but any higher privledged accound should work. Additionally, the binaries must have the `setuid` bit set, so that the program runs as the user that owns it, not the user that is executing it.

1) Create a binary owned by the `root` user
  - Switch to the `root` user via the `su` command
  - Compile the C files with any compiler you like, ie: `gcc <file>.c`
2) Set the file permissions so your user account can run the programs
  - The easiest way is using `chmod o+x <binary>` but I wouldn't recommend leaving that file sitting on your computer after you finish
  - Instead, I recommend [creating a new group and adding your user to that group](https://www.techrepublic.com/article/how-to-create-users-and-groups-in-linux-from-the-command-line/)
  - Once your user account is a part of that group, you can change the group owner on the binaries via [`chgrp`](https://linux.die.net/man/1/chgrp)
  - Lastly give the group execute permissions: `chmod g+x <binary>`
  - Now, instead of any account on your machine having a doorway to escalate privledges, only the user account is able to.
3) Set the `setuid` bit on your binaries
  - This step needs to be last, because any attempt to `chmod` or `chgrp` the binary files will unset the `setuid` bit (for good reason)
  - Run `chmod u+s <binary>` on the compiled programs. Now any time they are run, the program will have root privledges instead of the privledges of the invoking user
4) Switch back to the user account
  - If you used `su` to login as root, you should be able to run `exit` to return to the previous shell
  - Otherwise, `su <user>`

You're ready to start hacking! Good luck on finding the privledge escalation tricks.

### Program Information
[`read.c`](read.c) - Easy - Try to find a way to view a file you don't have read permissions for, like `/etc/shadow`  
[`pingSys.c`](pingSys.c) - Not Hard - Try to find a way to run other commands, like spawning a shell  
[`chkmsgs.c`](chkmsgs.c) - Head Scratcher - You're going to want to find a way to spawn a shell again, think outside the box

If you're stumped, I suppose you could check the [solutions](solutions/) folder for answers, but I promise it's less fun.
