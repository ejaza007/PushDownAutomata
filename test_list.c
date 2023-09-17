// C code list unit-tests.
//
// Modified by <your-name-here>
//
#include "list.h"

#include <assert.h>
#include <stdio.h>

int main () {

    struct list_node *node = NULL;
    assert(peekList(node) == '\0');

    node = generate_list_node('2');
    assert(node->item == '2');
    assert(node->next == NULL);



     node = generate_list_node('2');
     assert(node->item == '2');
     assert(node->next == NULL);

      node = listPop(node);
      assert(node == NULL);

      node = insert(node, 'a');
      assert(peekList(node) == 'a');

      node = insert(node, 'b');
      node = insert(node, 'c');

      display_list(node);

    assert(node->item == 'a');
    assert(node->next->item == 'b');
    assert(node->next->next->item == 'c');

    node = delete_last(node);
    assert(node->item == 'a');
    assert(node->next->item == 'b');

    node = delete_last(node);
    assert(node->item == 'a');



    node = insert(node, 'b');
    assert(node->next->item == 'b');


    return 0;
}
