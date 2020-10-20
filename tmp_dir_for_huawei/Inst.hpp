#include <unordered_map>
#include "../Derzhavin/Common.hpp"

class Inst
{
    RegId m_rs1{};
    RegId m_rs2{};
    RegId m_rd{};
    Word m_imm{};
    InsnId m_insn{InsnId::INV_ID};
    bool m_branch{};

    using do_insn = void(*)(const Hart & hart , const Inst &);

    static std::unordered_map<InsnId, do_insn> ops;


public:

    Inst( );
    Inst( Word wrd );

    void DecodeAndFillFields( Word wrd );
    void exec( const Hart & hart ) const;


    const RegId & rs1() const;
    const RegId & rs2() const;
    const RegId & rd() const;
    const Word & imm() const;
    const InsnId & insn() const;
    const bool & branch() const;
};

void do_ADDI(const Hart & hart, const Inst & insn);
void do_SLTI(const Hart & hart, const Inst & insn);
void do_ANDI(const Hart & hart, const Inst & insn);
void do_ORI (const Hart & hart, const Inst & insn);
void do_XORI(const Hart & hart, const Inst & insn);

//! Integer Register - Register operations

void do_ADD (const Hart & hart, const Inst & insn);
void do_SUB (const Hart & hart, const Inst & insn);
void do_SLT (const Hart & hart, const Inst & insn);
void do_SLTU(const Hart & hart, const Inst & insn);
void do_AND (const Hart & hart, const Inst & insn);
void do_OR  (const Hart & hart, const Inst & insn);
void do_XOR (const Hart & hart, const Inst & insn);
/////////////////////////////////////////


// Static member initialization
std::unordered_map<InsnId, Inst::do_insn>Inst::ops
{
    {InsnId::ADDI, do_ADDI},
    {InsnId::ANDI, do_ANDI},
    {InsnId::SLTI, do_SLTI},
    {InsnId::ORI, do_ORI},
    {InsnId::XORI, do_XORI},

    {InsnId::ADD, do_ADD},
    {InsnId::SUB, do_SUB},
    {InsnId::AND, do_AND},
    {InsnId::SLT, do_SLT},
    {InsnId::SLTU, do_SLTU},
    {InsnId::OR, do_OR},
    {InsnId::XOR, do_XOR},

//** to be continued... **//
};
///////////////////////////////////////////////////