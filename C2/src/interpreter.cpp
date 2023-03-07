#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

#define OP_END          0
#define OP_INC_DP       1
#define OP_DEC_DP       2
#define OP_INC_VAL      3
#define OP_DEC_VAL      4
#define OP_OUT          5
#define OP_IN           6
#define OP_JMP_FWD      7
#define OP_JMP_BCK      8

#define SUCCESS         0
#define FAILURE         1

#define PROGRAM_SIZE    4096
#define STACK_SIZE      512
#define DATA_SIZE       65535

#define STACK_PUSH(A)   (STACK[SP++] = A)
#define STACK_POP()     (STACK[--SP])
#define STACK_EMPTY()   (SP == 0)
#define STACK_FULL()    (SP == STACK_SIZE)

using namespace std;

struct instruction_t {
    unsigned short op;
    unsigned short operand;
};

// static struct instruction_t PROGRAM[PROGRAM_SIZE];
static unsigned short STACK[STACK_SIZE];
static unsigned int SP = 0;

// unsigned short PROGRAM[] = {3,0,3,0,3,0,3,0,3,0,3,0,7,38,1,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,1,0,3,0,3,0,3,0,3,0,3,0,1,0,3,0,3,0,2,0,2,0,2,0,4,0,8,6,1,0,3,0,3,0,5,0,4,0,4,0,4,0,5,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,5,0,5,0,3,0,3,0,3,0,5,0,1,0,3,0,3,0,5,0,2,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,5,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,5,0,3,0,3,0,3,0,5,0,4,0,4,0,4,0,4,0,4,0,4,0,5,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,5,0,1,0,1,0,4,0,4,0,5,0,0,0};
unsigned short PROGRAM[] = {303,0,303,0,303,0,303,0,303,0,303,0,307,38,301,0,303,0,303,0,303,0,303,0,303,0,303,0,303,0,303,0,303,0,303,0,303,0,303,0,303,0,303,0,303,0,303,0,303,0,301,0,303,0,303,0,303,0,303,0,303,0,301,0,303,0,303,0,302,0,302,0,302,0,304,0,308,6,301,0,303,0,303,0,305,0,304,0,304,0,304,0,305,0,303,0,303,0,303,0,303,0,303,0,303,0,303,0,305,0,305,0,303,0,303,0,303,0,305,0,301,0,303,0,303,0,305,0,302,0,303,0,303,0,303,0,303,0,303,0,303,0,303,0,303,0,305,0,304,0,304,0,304,0,304,0,304,0,304,0,304,0,304,0,305,0,303,0,303,0,303,0,305,0,304,0,304,0,304,0,304,0,304,0,304,0,305,0,304,0,304,0,304,0,304,0,304,0,304,0,304,0,304,0,305,0,301,0,301,0,304,0,304,0,305,0,300,0};



int execute_bf(instruction_t* PROGRAM, unsigned short offset, vector<unsigned short> &result) {
    unsigned short data[DATA_SIZE], pc = 0;
    unsigned int ptr = DATA_SIZE;
    unsigned int i = 0;
    while (--ptr) { data[ptr] = 0; }
    while (PROGRAM[pc].op != OP_END && ptr < DATA_SIZE) {
        switch (PROGRAM[pc].op-offset) {
            case OP_INC_DP: ptr++; break;
            case OP_DEC_DP: ptr--; break;
            case OP_INC_VAL: data[ptr]++; break;
            case OP_DEC_VAL: data[ptr]--; break;
            case OP_OUT: result.push_back(data[ptr]); break;
            case OP_IN: data[ptr] = (unsigned int)getchar(); break;
            case OP_JMP_FWD: if(!data[ptr]) { pc = PROGRAM[pc].operand; } break;
            case OP_JMP_BCK: if(data[ptr]) { pc = PROGRAM[pc].operand; } break;
            default: return FAILURE;
        }
        pc++;
    }
    return ptr != DATA_SIZE ? SUCCESS : FAILURE;
}

int main() {
    vector<unsigned short> v;
    execute_bf((instruction_t*)PROGRAM, 300, v);
    
    string a{v.begin(), v.end()};
    cout << a << endl;
}