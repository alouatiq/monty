# Monty Interpreter

This project is an interpreter for Monty bytecodes files (.m files). Monty is a simple scripting language that is first compiled into bytecode and then executed.

## Stracture
```
monty/
│
├── bytecodes/
│   └── 00.m      # Monty bytecode files (test files)
├── include/
│   └── monty.h   # Header file with all function prototypes and structures
├── src/
│   ├── main.c    # Main function to drive the interpreter
│   ├── push.c    # Implementation for push opcode
│   ├── pall.c    # Implementation for pall opcode
│   ├── pint.c    # Implementation for pint opcode
│   ├── pop.c     # Implementation for pop opcode
│   ├── swap.c    # Implementation for swap opcode
│   ├── add.c     # Implementation for add opcode
│   ├── nop.c     # Implementation for nop opcode
│   └── errors.c  # Functions for error handling
├── README.md     # Mandatory project README
└── Makefile      # Optional but helpful for compiling
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
