#include <iostream>
#include "iterator.hpp"
#include "visitor.hpp"
#include "header/factory.hpp"
#include "header/add.hpp"
#include "header/op.hpp"

int main(int argc, char** argv) {
    Parse* p = new Parse();
    Base* b = p->parse(argv, argc);
    Add* dummy = new Add(b, new Op(5));

    CountVisitor* count = new CountVisitor();
    PreorderIterator* preorder = new PreorderIterator(dummy);

    preorder->first();
    while (!preorder->is_done()) {
        preorder->current()->accept(count);
        preorder->next();
    }

    printf("number of +: %i\n", count->add_count());
    printf("number of operands: %i\n", count->op_count() - 1); // subtract the dummy

    std::cout << b->stringify() << " = " << b->evaluate() << std::endl;
    return 0;
}

