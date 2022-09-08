# Simple Shell Project In C

 ## This is a ReadMe file for a custom simple UNIX command line interpreter written in C programming language.

---

### Table of Contents

- [Description]
- [How To Use]
- [Authors]

---

## Description

This repository contains the source codes for a Simple UNIX command line interpreter program written in C programming language. This project is done as part of our Software Engineering training given by ALX.

#### Technologies

- C

---

## **How To Use**


### *In order to initialize the program, please run the code below in a UNIX shell environment
 
   ./hsh
```
### *Here is the list of supported built-in commands*
```html
    Commands that are found at the <b>/bin/<b> path.
    exit - Exits the shell.
    env - Prints the current environment.
    setenv - Initializes a new environment or modifies an existing one.
    unsetenv - Removes an environment variable.
    cd - Changes current directory of the process.
    alias - Prints a list of all alliases
    help - Prints the help documentation.
    history - Prints list of executed command history
```
### *Special conditions handled include the following:-*
```html
    - Ctrl+C will not exit the shell, instead it is treated as Enter.
    - ; command separator.
    - || and && command-line logical operators.
    - $? and $$ variables.

---


## Authors

- Bereket Bayou
