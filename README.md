# pre_shell_project
A mini project that we're supposed to finish, as it's a part of understanding how to do the a simple shell.
# Process
- a process refers to a program in execution, it's a running instance of a program.
it is make up of the program instruction, data read from files, other programs or
input from a system user.
# Process types
**Foreground processes (interactive processes)
- They're initialized and controlled through a terminal session. a user has to 
start such a processes.
** Background processes (non-interactive/automatic processes)
- They're processes not connected to a terminal, they don't expect any user input.
# Process Creation
***a proces is created when an existing process copies itself in memory.
***There are 2 conventional ways used for creating a new process:
- using the System() Function: it's simple, but inefficient and risky (has security risks).
- using fork() and exec() Function: it's a bit advanced, but greatly flexible, fast and secure.
