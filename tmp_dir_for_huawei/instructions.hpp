class Instruction
{
    RegId m_rs1{};
    RegId m_rs2{};
    RegId m_rd{};
    Word m_imm{};
    InsnId m_insn{kInvalidId};
    bool m_branch{};

    using do_insn = void(*)(const Instruction &);

    static std::unordered_map<InsnId, do_insn> =
            {
                    {ADDI, do_ADDI},
                    {ANDI, do_ANDI},
                    {SLTI, do_SLTI},
                    {ORI, do_ORI},
                    {XORI, do_XORI},

                    {ADD, doADD},
                    {SUB, do_SUB},
                    {AND, do_AND},
                    {SLT, do_SLT},
                    {SLTU, do_SLTU},
                    {OR, do_OR},
                    {XOR, do_XOR},

                    //** continued **//
            };


public:

    Instruction( );
    Instruction( Word wrd );

    void DecodeAndFillFields( Word wrd );
    void exec( ) const;


    const RegId & rs1() const;
    const RegId & rs2() const;
    const RegId & rd() const;
    const Word & imm() const;
    const InsnId & insn() const;
    const bool & branch() const;
};

void do_ADDI(const Instruction & insn);
void do_SLTI(const Instruction & insn);
void do_ANDI(const Instruction & insn);
void do_ORI(const Instruction & insn);
void do_XORI(const Instruction & insn);

//! Integer Register - Register operations

void do_ADD(const Instruction & insn);
void do_SUB(const Instruction & insn);
void do_SLT(const Instruction & insn);
void do_SLTU(const Instruction & insn);
void do_AND(const Instruction & insn);
void do_OR(const Instruction & insn);
void do_XOR(const Instruction & insn);
