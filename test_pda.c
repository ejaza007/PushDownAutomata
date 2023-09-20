#include <stdio.h>
#include <assert.h>
#include "pda.h"
#include "stack.h"
#include "list.h"



int main() {
    // Test PDA1
    assert(PDA1("ab") == 1);
    assert(PDA1("aabb") == 1);
    assert(PDA1("aabbba") == 0);
    assert(PDA1("b") == 0);
    assert(PDA1("") == 1);

    // Test PDA2
    assert(PDA2("(())") == 1);
    assert(PDA2("((()))") == 1);
    assert(PDA2("())(") == 0);
    assert(PDA2(")(") == 0);
    assert(PDA2("") == 1);

    // Test PDA3

    assert(PDA3("{ ix iy { iy x y } y}") == 1);
    assert(PDA3("{ ix iz { iz x z } z}") == 1);
    assert(PDA3("{ix x y}") == 0);
    assert(PDA3("{ix ix ix x}") == 1);
    assert(PDA3("{{{ix}") == 0);





    printf("All tests passed!\n");



    return 0;
}
