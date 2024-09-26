# Monty Interpreter

This project is an interpreter for Monty bytecodes files (.m files). Monty is a simple scripting language that is first compiled into bytecode and then executed.

## Stracture
```
monty/
│
├── add.c               # Implementation of the add opcode
├── div.c               # Implementation of the div opcode
├── global.c            # Definition of the global variable `is_stack`
├── main.c              # Entry point of the Monty interpreter
├── mod.c               # Implementation of the mod opcode
├── mul.c               # Implementation of the mul opcode
├── nop.c               # Implementation of the nop opcode
├── pall.c              # Implementation of the pall opcode
├── pchar.c             # Implementation of the pchar opcode
├── pint.c              # Implementation of the pint opcode
├── pop.c               # Implementation of the pop opcode
├── pstr.c              # Implementation of the pstr opcode
├── push.c              # Implementation of the push opcode
├── queue.c             # Switches the mode to FIFO (queue)
├── rotl.c              # Rotates the stack to the top
├── rotr.c              # Rotates the stack to the bottom
├── stack.c             # Switches the mode to LIFO (stack)
├── sub.c               # Implementation of the sub opcode
├── swap.c              # Implementation of the swap opcode
├── monty.h             # Header file with structure definitions and function prototypes
├── README.md           # Project description and instructions
├── Makefile            # Makefile to compile the project
└── test.m              # Example Monty bytecode file

```

## Usage

To compile:

```
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

To run the interpreter:

```
./monty file.m
```

Opcodes Implemented

```
push
pall
pint
pop
swap
add
nop
```

### 3. **Makefile** (Optional but helpful):
```Makefile
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c89

all: monty

monty: *.c
    $(CC) $(CFLAGS) -o monty *.c

clean:
    rm -f monty
```

### 4. Compiling the Project
To compile your project, run:

```
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

### 5. Running the Project
After compiling, you can run the Monty interpreter using the provided Monty bytecode files in the bytecodes/ folder:

```
./monty bytecodes/00.m
```
