#include "main.hpp"
#include "syntax.hpp"
#include "vm.hpp"

int main(int argc, char *argv[]) {  //
    arg(0, argv[0]);
    for (int i = 1; i < argc; i++) {  //
        arg(i, argv[i]);
        yyfile = argv[i];
        assert(yyin = fopen(yyfile, "r"));
        yyparse();
        fclose(yyin);
        yyfile = nullptr;
    }
    if (debug) fprintf(stderr, "\n\n");
    dump();
    return vm();
}

void arg(int argc, char *argv) {  //
    fprintf(stderr, "%i: %s\n", argc, argv);
}
