#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Prototypes for opcodes */
void push(stack_t **stack, unsigned int line_number, int n);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

void sub(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

/* New prototypes for rotl, rotr, stack, and queue */
void rotl(stack_t **stack, unsigned int line_number);    /* Rotate left (top to bottom) */
void rotr(stack_t **stack, unsigned int line_number);    /* Rotate right (bottom to top) */
void stack_op(stack_t **stack, unsigned int line_number); /* Switch to stack (LIFO) mode */
void queue_op(stack_t **stack, unsigned int line_number); /* Switch to queue (FIFO) mode */

/* Global Variable to Track Mode */
extern int is_stack;  /* 1 for stack (LIFO), 0 for queue (FIFO) */

/* Error handling */
void handle_error(char *message, unsigned int line_number);

#endif /* MONTY_H */
