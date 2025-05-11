#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
#define MAX_STACK_SIZE 100

// The stack array
int stack[MAX_STACK_SIZE];
// The stack pointer, points to the next available slot
int sp = 0;

// Enum for instruction opcodes
typedef enum {
  PUSH,
  POP,
  ADD,
  SUB,
  PRINT,
  HALT
} Instruction;

// Structure to represent an instruction
typedef struct {
  Instruction opcode;
  int operand; // Used by PUSH instruction
} Instruction_t;

// The program to be executed (a sequence of instructions)
Instruction_t program[] = {
  {PUSH, 10},
  {PUSH, 20},
  {ADD},
  {PRINT},
  {PUSH, 5},
  {SUB},
  {PRINT},
  {HALT}
};

// The program counter, points to the current instruction
int pc = 0;

// Function to push a value onto the stack
void push(int value) {
  if (sp < MAX_STACK_SIZE) {
    stack[sp++] = value;
  } else {
    fprintf(stderr, "Stack overflow!\n");
    exit(1);
  }
}

// Function to pop a value from the stack
int pop() {
  if (sp > 0) {
    return stack[--sp];
  } else {
    fprintf(stderr, "Stack underflow!\n");
    exit(1);
  }
}

// The main interpreter loop
void interpret() {
  Instruction_t instruction;
  int val1, val2;

  while (1) {
    // Fetch the instruction
    instruction = program[pc++];

    // Decode and execute the instruction
    switch (instruction.opcode) {
      case PUSH:
        push(instruction.operand);
        break;
      case POP:
        pop(); // Discard the popped value
        break;
      case ADD:
        val1 = pop();
        val2 = pop();
        push(val1 + val2);
        break;
      case SUB:
        val1 = pop();
        val2 = pop();
        push(val2 - val1); // Note the order for subtraction
        break;
      case PRINT:
        printf("Output: %d\n", pop());
        break;
      case HALT:
        printf("Halt.\n");
        return; // Stop execution
      default:
        fprintf(stderr, "Unknown instruction: %d\n", instruction.opcode);
        exit(1);
    }
  }
}

int main() {
  interpret();
  return 0;
}
