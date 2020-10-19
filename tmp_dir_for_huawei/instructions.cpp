#include "instructions.hpp"

Instruction::Instruction( )
{}

Instruction::Instruction( Word wrd )
{
    DecodeAndFillFields(wrd);
}


void Instruction::DecodeAndFillFields( Word wrd )
{
    m_rs1 = GetBits<19, 15>(wrd);
    m_rs2 = GetBits<24, 20>(wrd);
    m_rd = GetBits<11, 7>(wrd);
    Word funct3 = GetBits<14,12>(wrd);


    switch (GetBits<6, 0>(wrd))
    {
        case 0x33:
            Word funct7 = GetBits<31, 25>(wrd);

            if (funct3 == 0 && funct7 == 0)
                m_insn = ADD;
            else if (funct3 == 0 && funct7 == 0x20)
                m_insn = SUB;
            else if (funct3 == 0x3 && funct7 == 0)
                m_insn = XOR;
            else if (funct3 == 0x5 && funct7 == 0)
                m_insn = OR;

            break;

        case 0x03:
            m_imm = GetBits<31, 20>(wrd);

            switch (funct3)
            {
                case 0x00:
                    m_insn = LB;
                    break;
                case 0x01:
                    m_insn = LH;
                    break;
                case 0x02:
                    m_insn = LW;
                    break;
                case 0x04:
                    m_insn = LBU;
                    break;
                case 0x05:
                    m_insn = LHU;
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
                    m_insn = BEQ;
                    break;
                case 0x01:
                    m_insn = BNE;
                    break;
                case 0x04:
                    m_insn = BNE;
                    break;
                case 0x05:
                    m_insn = BGE;
                    break;
                case 0x06:
                    m_insn = BLTU;
                    break;
                default:
                    std::cout << "Unknown command\n";
            }

            break;

        case 0x13:

            m_imm = GetBits<31, 20>(wrd);

            switch (funct3)
            {
                case 0x00:
                    m_insn = ADDI;
                    break;
                case 0x01:
                    m_insn = SLTI;
                    break;
                case 0x03:
                    m_insn = SLTIU;
                    break;
                case 0x04:
                    m_insn = XORI;
                    break;
                case 0x05:
                    m_insn = ORI;
                    break;
                case 0x06:
                    m_insn = ANDI;
                default:
                    std::cout << "Unknown command\n";
            }

            break;

        default:

            std::cout << "Unknown command\n";
    }
}

void Instruction::exec( ) const
{
    InsnMap[m_insn]( *this );
}


const RegId & Instruction::rs1() const
{ return m_rs1; }

const RegId & Instruction::rs2() const
{ return m_rs2; }

const RegId & Instruction::rd() const
{ return m_rd; }

const Word & Instruction::imm() const
{ return m_imm; }

const InsnId & Instruction::insn() const
{ return m_insn; }

const bool & Instruction::branch() const
{ return m_branch; }


void do_ADDI(const Instruction & insn)
{

}

void do_SLTI(const Instruction & insn)
{

}

void do_ANDI(const Instruction & insn)
{

}

void do_ORI(const Instruction & insn)
{

}

void do_XORI(const Instruction & insn)
{

}

//! Integer Register - Register operations

void do_ADD(const Instruction & insn)
{

}

void do_SUB(const Instruction & insn)
{

}

void do_SLT(const Instruction & insn)
{

}

void do_SLTU(const Instruction & insn)
{

}

void do_AND(const Instruction & insn)
{

}

void do_OR(const Instruction & insn)
{

}

void do_XOR(const Instruction & insn)
{

}
