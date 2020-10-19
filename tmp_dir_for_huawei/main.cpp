#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

typedef Word uint_32_t;
typedef RegVal uint32_t;
typedef RegId uint8_t;

static constexpr kRegFileSize = 32; //не понял, зачем именно так объявлять, еще на занятии прогуглил и так и не понял :D
static constexpr kWordSize = 4;

template<int high, int low> Word GetBits()
{
    return (word << low) & (1 << (high - low + 1) - 1);
}

template<> Word SignExtend(Word wrd)
{
    //не понял, как эта тема работает, как у вас было тоже вспомнить на смог :(
}

enum InsnId
{
  ADDI, ANDI, SLTI, ORI, XORI, SLTIU,

  ADD, AND, SLT, SLTU, SUB, AND, OR, XOR,

  LB, LH, LW, LBU,

  BEQ, BNE, BLT, BGE, BLTU,

  INV_ID
};


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

    Instruction( )
    {}

    Instruction( Word wrd )
    {
        DecodeAndFillFields(wrd);
    }

    void DecodeAndFillFields( Word wrd )
    {
      m_rs1 = GetBits<19, 15>(wrd);
      m_rs2 = GetBits<24, 20>(wrd);
      m_rd = GetBits<11, 7>(wrd);
      Word funct3 = GetBits<14,12>(wrd);

        if (GetBits<6, 0>(wrd) == 0x33)
        {
            Word funct7 = GetBits<31, 25>(wrd);

            if (funct3 == 0 && funct7 == 0)
                m_insn = ADD;

            else if (funct3 == 0 && funct7 == 0x20)
                m_insn = SUB;

            else if (funct3 == 0x3 && funct7 == 0)
                m_insn = XOR;

            else if (funct3 == 0x5 && funct7 == 0)
                m_insn = OR;
        }

        if (GetBits<6, 0>(wrd) == 0x03)
        {
            m_imm = GetBits<31, 20>(wrd);

            if (funct3 == 0x00)
              m_insn = LB;
            if (funct3 == 0x01)
              m_insn = LH;
            if (funct3 == 0x02)
              m_insn = LW;
            if (funct3 == 0x04)
              m_insn = LBU;
            if (funct3 == 0x05)
              m_insn = LHU;

        }

        if (GetBits<6, 0>(wrd) == 0x63)
        {
            m_imm = (GetBits<31, 20>(wrd) << 5) | GetBits<11,7>(wrd);

            if (funct3 == 0x00)
              m_insn = BEQ;
            if (funct3 == 0x01)
              m_insn = BNE;
            if (funct3 == 0x04)
              m_insn = BLT;
            if (funct3 == 0x05)
              m_insn = BGE;
            if (funct3 == 0x06)
              m_insn = BLTU;
        }

        if (GetBits<6, 0>(wrd) == 0x13)
        {
          m_imm = GetBits<31, 20>(wrd);

            if (funct3 == 0x00)
              m_insn = ADDI;
            if (funct3 == 0x02)
              m_insn = SLTI;
            if (funct3 == 0x03)
              m_insn = SLTIU;
            if (funct3 == 0x04)
              m_insn = XORI;
            if (funct3 == 0x05)
              m_insn = ORI;
            if (funct3 == 0x06)
              m_insn = ANDI;
        }
    }


    void exec( )
    {
        InsnMap[m_insn]( *this );
    }

    const RegId & rs1() const
    { return m_rs1; }

    const RegId & rs2() const
    { return m_rs2; }

    const RegId & rd() const
    { return m_rd; }

    const Word & imm() const
    { return m_imm; }

    const InsnId & insn() const
    { return m_insn; }

    const bool & branch() const
    { return m_branch; }
};




class Hart
{
    RegVal m_reg[kRegFileSize] {};
    RegVal m_pc {};
    RegVal m_nextpc {};
    Memory* m_mem;

public:

    Memory* mem();
    void run();
};


class Memory
{

public:
    bool read(Word * result, ...);
    bool write(Word wrd, ...);
};

class BasicBlock
{
    //?? не разобрался в анордеред мэп
};

void Hart::run()
{
    bool complete = false;

    while(!complete)
    {
        std::vector<Instruction> BasicBlock;
        bool branch = false;

        while (!branch)
        {
            Word wrd;

            Instruction insn;

            //....
        }
    }
}

        //! Instructions file of emulator RISC - V !//

        //! Integer Register - Immediate instr
