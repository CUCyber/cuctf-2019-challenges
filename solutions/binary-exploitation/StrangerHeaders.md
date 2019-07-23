# Stranger Headers Solution

After attempting to run and use tools like GDB, R2, and strings to analyze the binary or quickly find the flag, it becomes clear that there is no way to execute or disassemble the binary. Using the hint from the name of the challenge, you must then review the ELF header. Using the first Wikipedia link, it becomes clear that the e_type was modified. Changing the e_type back to 0x02 makes the program executable and displays the flag.
