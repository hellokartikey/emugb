#include "common.hxx"

class CPU {
public:
    // AF = [A [xxxxCHNZ]]
    union {
        word AF;
        struct {
            struct {
                byte   : 4;
                byte c : 1;
                byte h : 1;
                byte n : 1;
                byte z : 1;
            };
            byte A;
        };
    };

    // BC = [B C]
    union {
        word BC;
        struct { byte C; byte B; };
    };

    // DE = [D E]
    union {
        word DE;
        struct { byte E; byte D; };
    };

    // HL = [H L]
    union {
        word HL;
        struct { byte L; byte H; };
    };

    word SP;
    word PC;

    CPU();
};
