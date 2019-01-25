## pingSys.c

This file pings any IP you send it four times, printing the results. The interesting thing is though, the file concatenates whatever it you send in as the second parameter.

**If you were looking for a hint stop reading now**

In Linux and similar operating systems, you can chain commands using semicolon. By sending in a string containing a semicolon, the program ends up running two or more commands sequentially, even though it was only intended to run `ping`.

`pingSys "127.0.0.1; /bin/bash"`

**Why does this work?**  
The program sees `"127.0.0.1 /bin/bash"` as one argument, and as such it concatenates the entire expression to the end of `ping -c 4`. The program is running as root, and so when it executes `/bin/bash` after running `ping` the bash terminal has root privledges. By doing this you've just logged in as `root` without ever actually logging in.