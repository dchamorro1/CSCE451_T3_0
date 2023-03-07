#include <iostream> 
#include "interpreter.h"

// Esolangs are fun! Gur xrl
// They are the bane of my existance!  vf he
// Here are some examples Piet, BF, Whitespace, lama! ona zhyyre

#define RUN_PROG(prog,offset,v) execute_bf((instruction_t*)prog,offset,v)

const unsigned short PROGRAMS[][] = {
    // rand1, 42
    // rand2, 56
    // rand3, 12
    // a, 548
    // rand4, 159
    // b, 693
    // c, 928
    // hint1, 
    // rand5
    // hint2
    // rand6
}
void level_3() {
    // TODO: 
    // - generate programs
    // - write xor
    // - write from_hex

    // get input
    string key;
    cout << "Key: " << endl;
    cin >> key;

    // v = rand1
    // if successfull
    //      v = rand1 xor rand2
    // else
    //      v = rand1 xor rand3

    vector<unsigned short> v;
    vector<unsigned short> v2;
    if(!RUN_PROG(PROGRAMS[0], 42,v)) {
        RUN_PROG(PROGRAMS[1],56,v2);
    } else {
        RUN_PROG(PROGRAMS[2],12,v2);
    }
    v = xor(v,v2);


    // v2 = a
    // if successfull
    //      v2 = a xor b offset 693
    // else
    //      v2 = a xor b offset 159

    vector<unsigned short> v3;
    if(!RUN_PROG(PROGRAMS[3],548,v2)) {
        RUN_PROG(PROGRAMS[5],693,v3);
    } else {
        RUN_PROG(PROGRAMS[5],159,v3);
    }
    v2 = xor(v2,v3);

    // v = v xor v2

    // v3 = c
    // if successfull
    //      v3 = c xor hint1
    // else
    //      v3 = c xor hint2

    // v4 = v^v2^v3 
    //              = (rand1^rand3)^(a^b^rand1^rand3)^(c^hint1)
    //              = a^b^c^hint1

    // v5 = hint1
    // final answer = v4^v5 = a^b^c 
}


void main() {
    level_3();
}