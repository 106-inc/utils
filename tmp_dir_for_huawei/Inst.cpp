#include "Inst.hpp"

Inst::Inst( )
{}

Inst::Inst( Word wrd )
{
    DecodeAndFillFields(wrd);
}


void Inst::DecodeAndFillFields( Word wrd )
{
    m_rs1 = GetBits<19, 15>(wrd);
    m_rs2 = GetBits<24, 20>(wrd);
    m_rd = GetBits<11, 7>(wrd);
    Word funct3 = GetBits<14,12>(wrd);

    // Just initialization for future
    Word funct7{};

    switch (GetBits<6, 0>(wrd))
    {
        case 0x33:
            funct7 = GetBits<31, 25>(wrd);

            if (funct3 == 0 && funct7 == 0)
                m_insn = InsnId::ADD;
            else if (funct3 == 0 && funct7 == 0x20)
                m_insn = InsnId::SUB;
            else if (funct3 == 0x3 && funct7 == 0)
                m_insn = InsnId::XOR;
            else if (funct3 == 0x5 && funct7 == 0)
                m_insn = InsnId::OR;

            break;

        case 0x03:
            m_imm = GetBits<31, 20>(wrd);

            switch (funct3)
            {
                case 0x00:
                    m_insn = InsnId::LB;
                    break;
                case 0x01:
                    m_insn = InsnId::LH;
                    break;
                case 0x02:
                    m_insn = InsnId::LW;
                    break;
                case 0x04:
                    m_insn = InsnId::LBU;
                    break;
                case 0x05:
                    m_insn = InsnId::LHU;
                    break;
                default:
                    std::cout << "Unknown command\n";
            }

            break;

        case 0x63:

            m_imm = (GetBits<31, 20>(wrd) << 5) | GetBits<11,7>(wrd);

            switch (funct3)
            {
                case 0x00:
                    m_insn = InsnId::BEQ;
                    break;
                case 0x01:
                    m_insn = InsnId::BNE;
                    break;
                case 0x04:
                    m_insn = InsnId::BNE;
                    break;
                case 0x05:
                    m_insn = InsnId::BGE;
                    break;
                case 0x06:
                    m_insn = InsnId::BLTU;
                    break;
                default:
                    std::cout << "Unknown command\n";
            }
            m_branch = 1;
            break;

        case 0x13:

            m_imm = GetBits<31, 20>(wrd);

            switch (funct3)
            {
                case 0x00:
                    m_insn = InsnId::ADDI;
                    break;
                case 0x01:
                    m_insn = InsnId::SLTI;
                    break;
                case 0x03:
                    m_insn = InsnId::SLTIU;
                    break;
                case 0x04:
                    m_insn = InsnId::XORI;
                    break;
                case 0x05:
                    m_insn = InsnId::ORI;
                    break;
                case 0x06:
                    m_insn = InsnId::ANDI;
                default:
                    std::cout << "Unknown command\n";
            }

            break;

        default:

            std::cout << "Unknown command\n";
    }
}

void Inst::exec( const Hart & ) const
{
    ops[m_insn]( const Hart &, *this );
}


const RegId & Inst::rs1() const
{ return m_rs1; }

const RegId & Inst::rs2() const
{ return m_rs2; }

const RegId & Inst::rd() const
{ return m_rd; }

const Word & Inst::imm() const
{ return m_imm; }

const InsnId & Inst::insn() const
{ return m_insn; }

const bool & Inst::branch() const
{ return m_branch; }


void do_ADDI(const Hart &, const Inst & insn)
{

}

void do_SLTI(const Hart &, const Inst & insn)
{

}

void do_ANDI(const Hart &, const Inst & insn)
{

}

void do_ORI(const Hart &, const Inst & insn)
{

}

void do_XORI(const Hart &, const Inst & insn)
{

}

//! Integer Register - Register operations

void do_ADD(const Hart &, const Inst & insn)
{

}

void do_SUB(const Hart &, const Inst & insn)
{

}

void do_SLT(const Hart &, const Inst & insn)
{

}

void do_SLTU(const Hart &, const Inst & insn)
{

}

void do_AND(const Hart &, const Inst & insn)
{

}

void do_OR(const Hart &, const Inst & insn)
{

}

void do_XOR(const Hart &, const Inst & insn)
{

}
