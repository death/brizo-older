/** @file types.h \brief Miscelleneous Brizo types. */
// $Workfile: types.h $
//
// Brizo Disassembler by DEATH, 2003-2004
//
// Disassembler types.
//
// $Author: Death $
// $Revision: 11 $
// $Date: 11/22/04 21:33 $
//
// $NoKeywords: $
//
#ifndef BRIZO_INC_TYPES_H
#define BRIZO_INC_TYPES_H

#include "opcode.h"
#include "brizo.h"

namespace Brizo_DE20041115
{

/// Displacement type
enum DisplacementType
{
    DT_8BIT,
    DT_16BIT,
    DT_32BIT
};

/// ModR/M data
struct ModRm
{
    unsigned char mod;          ///< MOD field
    unsigned char reg;          ///< REG field
    unsigned char rm;           ///< R/M field
};

/// Operand value type
enum OperandValueType
{
    OVT_NONE,                   ///< No value
    OVT_REGISTER,               ///< Register
    OVT_IMM8,                   ///< 8-bit immediate
    OVT_IMM16,                  ///< 16-bit immediate
    OVT_IMM32,                  ///< 32-bit immediate
    OVT_MEM_ADDR_1,             ///< MemAddr1Type
    OVT_REL_OFF,                ///< Relative offset
    OVT_OFF,                    ///< Offset
    OVT_SOURCE,                 ///< Source (DS:ESI)
    OVT_DESTINATION,            ///< Destination (ES:EDI)
    OVT_MEM_ADDR_2,             ///< MemAddr2Type
    OVT_MEM_ADDR_3,             ///< MemAddr3Type
    OVT_DIRECT                  ///< Segment and offset
};

/// Memory addressing type 1
enum MemAddr1Type
{
    MA1_BX_SI,                  ///< BX+SI
    MA1_BX_DI,                  ///< BX+DI
    MA1_BP_SI,                  ///< BP+SI
    MA1_BP_DI,                  ///< BP+DI
    MA1_SI,                     ///< SI
    MA1_DI,                     ///< DI
    MA1_DISP16,                 ///< 16-bit displacement
    MA1_BX,                     ///< BX

    MA1_EAX,                    ///< EAX
    MA1_ECX,                    ///< ECX
    MA1_EDX,                    ///< EDX
    MA1_EBX,                    ///< EBX
    MA1_SIB,                    ///< Scale-Index-Byte
    MA1_DISP32,                 ///< 32-bit displacement
    MA1_ESI,                    ///< ESI
    MA1_EDI                     ///< EDI
};

/// Memory addressing type 2
enum MemAddr2Type
{
    MA2_BX_SI_DISP8,            ///< BX+SI+8-bit displacement
    MA2_BX_DI_DISP8,            ///< BX+DI+8-bit displacement
    MA2_BP_SI_DISP8,            ///< BP+SI+8-bit displacement
    MA2_BP_DI_DISP8,            ///< BP+DI+8-bit displacement
    MA2_SI_DISP8,               ///< SI+8-bit displacement
    MA2_DI_DISP8,               ///< DI+8-bit displacement
    MA2_BP_DISP8,               ///< BP+8-bit displacement
    MA2_BX_DISP8,               ///< BX+8-bit displacement

    MA2_EAX_DISP8,              ///< EAX+8-bit displacement
    MA2_ECX_DISP8,              ///< ECX+8-bit displacement
    MA2_EDX_DISP8,              ///< EDX+8-bit displacement
    MA2_EBX_DISP8,              ///< EBX+8-bit displacement
    MA2_SIB_DISP8,              ///< Scale-Index-Byte+8-bit displacement
    MA2_EBP_DISP8,              ///< EBP+8-bit displacement
    MA2_ESI_DISP8,              ///< ESI+8-bit displacement
    MA2_EDI_DISP8               ///< EDI+8-bit displacement
};

/// Memory addressing type 3
enum MemAddr3Type
{
    MA3_BX_SI_DISP16,           ///< BX+SI+16-bit displacement
    MA3_BX_DI_DISP16,           ///< BX+DI+16-bit displacement
    MA3_BP_SI_DISP16,           ///< BP+SI+16-bit displacement
    MA3_BP_DI_DISP16,           ///< BP+DI+16-bit displacement
    MA3_SI_DISP16,              ///< SI+16-bit displacement
    MA3_DI_DISP16,              ///< DI+16-bit displacement
    MA3_BP_DISP16,              ///< BP+16-bit displacement
    MA3_BX_DISP16,              ///< BX+16-bit displacement

    MA3_EAX_DISP32,             ///< EAX+32-bit displacement
    MA3_ECX_DISP32,             ///< ECX+32-bit displacement
    MA3_EDX_DISP32,             ///< EDX+32-bit displacement
    MA3_EBX_DISP32,             ///< EBX+32-bit displacement
    MA3_SIB_DISP32,             ///< Scale-Index-Byte+32-bit displacement
    MA3_EBP_DISP32,             ///< EBP+32-bit displacement
    MA3_ESI_DISP32,             ///< ESI+32-bit displacement
    MA3_EDI_DISP32              ///< EDI+32-bit displacement
};

/// Scale-Index-Base data
struct SIB
{
    Register base;              ///< Base (register)
    Register index;             ///< Index (register)
    int scale;                  ///< Scale
};

/// Memory address
struct MemoryAddress
{
    /// Memory address type
    union {
        MemAddr1Type ma1;
        MemAddr2Type ma2;
        MemAddr3Type ma3;
    };
    unsigned int disp;          ///< Displacement value
    SIB sib;                    ///< Scale-Index-Base data
};

/// Direct address
struct DirectAddress
{
    unsigned short seg;         ///< Segment
    unsigned int off;           ///< Offset
};

/// Operand value
struct OperandValue
{
    OperandValueType type;      ///< Operand value type
    /// The operand's value
    union {
        Register reg;           ///< Register
        unsigned int imm;       ///< Immediate
        signed int relOff;      ///< Relative offset
        unsigned int off;       ///< Offset
        MemoryAddress ma;       ///< Memory address
        DirectAddress dir;      ///< Direct memory address
    } Value;
};

/// Address/Operand size decoding mode
enum DecodeMode
{
    DM_16BIT,                   ///< 16-bit mode
    DM_32BIT                    ///< 32-bit mode
};

}

#endif // BRIZO_INC_TYPES_H
