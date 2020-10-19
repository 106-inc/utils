#include <iostream>


//! typedefs

typedef Word uint_32_t;
typedef RegVal uint32_t;
typedef RegId uint8_t;

static constexpr kRegFileSize = 32;
static constexpr kWordSize = 4;


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



class Instruction
{
  RegId m_rs1 {};
  RegId m_rs2 {};
  RegId m_rd {};
  Word m_imm {};
  InsnId m_insn {kInvalidId};
  bool m_branch {};

public:

  bool Decode(Word wrd)
  {

    if (GetBits<6, 0>(wrd) == 0x33)
    {
      m_rs1 = GetBits<19, 15>(wrd);
      m_rs2 = GetBits<24,20>(wrd);
      m_rd = GetBits<11, 7>(wrd);
      Word funct3 = GetBits<14,12>(wrd);
      Word funct7 = GetBits<31, 25>(wrd);

      if (funct3 == 0 && funct7 == 0)
        m_insn = ;//ADD

      if (funct3 == 0 && funct7 == 0x20)
        m_insn = ;//SUB

      if (funct3 == 0x3 && funct7 == 0)
        m_insn = ;//XOR

      if (funct3 == 0x5 && funct7 == 0)
        m_insn = ;//OR
    }

    if (GetBits<6, 0>(wrd) == 0x03)
    {
      m_rs1 = GetBits<19, 15>(wrd);
      m_rd = GetBits<11, 7>(wrd);
      Word funct3 = GetBits<14,12>(wrd);
      m_imm = GetBits<31, 20>(wrd);


      if (funct3 == 0x00)
        m_insn = ;//LB

      if (funct3 == 0x01)
        m_insn = ;//LH

      if (funct3 == 0x02)
        m_insn = ;//LW

      if (funct3 == 0x04)
        m_insn = ;//LBU

      if (funct3 == 0x05)
        m_insn = ;//LHU

    }

    if (GetBits<6, 0>(wrd) == 0x63)
    {
      m_rs1 = GetBits<19, 15>(wrd);
      m_rs2 = GetBits<24,20>(wrd);
      m_rd = GetBits<11, 7>(wrd);

      Word funct3 = GetBits<14,12>(wrd);

      m_imm = (GetBits<31, 20>(wrd) << 5) | GetBits<11,7>(wrd);

      if (funct3 == 0x00)
        m_insn = ;//BEQ

      if (funct3 == 0x01)
        m_insn = ;//BNE

      if (funct3 == 0x04)
        m_insn = ;//BLT

      if (funct3 == 0x05)
        m_insn = ;//BGE

      if (funct3 == 0x06)
        m_insn = ;//BLTU
    }

    if (GetBits<6, 0>(wrd) == 0x13)
    {
      m_rs1 = GetBits<19, 15>(wrd);
      m_rd = GetBits<11, 7>(wrd);
      Word funct3 = GetBits<14,12>(wrd);
      m_imm = GetBits<31, 20>(wrd);

      if (funct3 == 0x00)
        m_insn = ;//ADDI

      if (funct3 == 0x02)
        m_insn = ;//SLTI

      if (funct3 == 0x03)
        m_insn = ;//SLTIU

      if (funct3 == 0x04)
        m_insn = ;//XORI
      if (funct3 == 0x05)

        m_insn = ;//ORI
      if (funct3 == 0x06)
        m_insn = ;//ANDI
    }
  }

  RegId rs1() {return m_rs1;}
  RegId rs2() {return m_rs2;}
  RegId rd() {return m_rd;}
  Word imm() {return m_imm;}
  InsnId insn() {return m_insn;}
  bool branch() {return m_branch;}
};


//! Instructions file of emulator RISC - V !//

//! Integer Register - Immediate instr


void ADDI(Hart* hart, const Instruction& insn)
{

}

void SLTI(Hart* hart, const Instruction& insn)
{

}

void ANDI(Hart* hart, const Instruction& insn)
{

}

void ORI(Hart* hart, const Instruction& insn)
{

}

void XORI(Hart* hart, const Instruction& insn)
{

}

//! Integer Register - Register operations

void ADD(Hart* hart, const Instruction& insn)
{

}

void SUB(Hart* hart, const Instruction& insn)
{

}

void SLT(Hart* hart, const Instruction& insn)
{

}

void SLTU(Hart* hart, const Instruction& insn)
{

}

void AND(Hart* hart, const Instruction& insn)
{

}

void OR(Hart* hart, const Instruction& insn)
{

}

void XOR(Hart* hart, const Instruction& insn)
{

}
