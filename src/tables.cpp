/** @file tables.cpp \brief Brizo instruction decoder's tables */
// $Workfile: tables.cpp $
//
// Brizo Disassembler by DEATH, 2003-2004
//
// Disassembler tables.
//
// $Author: Death $
// $Revision: 20 $
// $Date: 11/22/04 1:54 $
//
// $NoKeywords: $
//
#include "stdafx.h"
#include <brizo/opcode.h>

namespace Brizo_DE20041115
{

/// Prefix tables
extern const Prefix PrefixTable[] = {
    {0, PG_LOCK_REP, P_LOCK},
    {1, PG_LOCK_REP, P_REPNE},
    {2, PG_LOCK_REP, P_REPE},
    {3, PG_SEG_BRANCH, P_SEG_CS},
    {4, PG_SEG_BRANCH, P_SEG_SS},
    {5, PG_SEG_BRANCH, P_SEG_DS},
    {6, PG_SEG_BRANCH, P_SEG_ES},
    {7, PG_SEG_BRANCH, P_SEG_FS},
    {8, PG_SEG_BRANCH, P_SEG_GS},
//  {PG_SEG_BRANCH, P_BRANCH_NOT_TAKEN},
//  {PG_SEG_BRANCH, P_BRANCH_TAKEN},
    {9, PG_OP_OVERRIDE, P_OVERRIDE_OP},
    {10, PG_ADDR_OVERRIDE, P_OVERRIDE_ADDR}
};

/// Prefix table length
extern const std::size_t PrefixTableLength = sizeof(PrefixTable) / sizeof(Prefix);

/// No operand
#define NOOP REG_NONE, AM_NONE, OT_NONE
/// Make operand
/// @param a Addressing mode
/// @param o Operand type
#define MKOP(a, o) (REG_NONE), ((AddressingMode)a), ((OperandType)o)
/// Make register
/// @param r Register
#define MKREG(r) (r), (AM_NONE), (OT_NONE)
/// Unknown operand
#define UNKOP O_UNKNOWN, {NOOP, NOOP, NOOP}

/// Opcode table
extern const Opcode OpcodeTable[] = {
    {OF_1BYTE, 0x0000, 0x00, P_NONE, O_ADD      , {MKOP('E', 'b')   , MKOP('G', 'b')    , NOOP          }}, // 00
    {OF_1BYTE, 0x0001, 0x00, P_NONE, O_ADD      , {MKOP('E', 'v')   , MKOP('G', 'v')    , NOOP          }}, // 01
    {OF_1BYTE, 0x0002, 0x00, P_NONE, O_ADD      , {MKOP('G', 'b')   , MKOP('E', 'b')    , NOOP          }}, // 02
    {OF_1BYTE, 0x0003, 0x00, P_NONE, O_ADD      , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 03
    {OF_1BYTE, 0x0004, 0x00, P_NONE, O_ADD      , {MKREG(REG_AL)    , MKOP('I', 'b')    , NOOP          }}, // 04
    {OF_1BYTE, 0x0005, 0x00, P_NONE, O_ADD      , {MKREG(REG_E_AX)  , MKOP('I', 'v')    , NOOP          }}, // 05
    {OF_1BYTE, 0x0006, 0x00, P_NONE, O_PUSH     , {MKREG(REG_ES)    , NOOP              , NOOP          }}, // 06
    {OF_1BYTE, 0x0007, 0x00, P_NONE, O_POP      , {MKREG(REG_ES)    , NOOP              , NOOP          }}, // 07
    {OF_1BYTE, 0x0008, 0x00, P_NONE, O_OR       , {MKOP('E', 'b')   , MKOP('G', 'b')    , NOOP          }}, // 08
    {OF_1BYTE, 0x0009, 0x00, P_NONE, O_OR       , {MKOP('E', 'v')   , MKOP('G', 'v')    , NOOP          }}, // 09
    {OF_1BYTE, 0x000A, 0x00, P_NONE, O_OR       , {MKOP('G', 'b')   , MKOP('E', 'b')    , NOOP          }}, // 0A
    {OF_1BYTE, 0x000B, 0x00, P_NONE, O_OR       , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0B
    {OF_1BYTE, 0x000C, 0x00, P_NONE, O_OR       , {MKREG(REG_AL)    , MKOP('I', 'b')    , NOOP          }}, // 0C
    {OF_1BYTE, 0x000D, 0x00, P_NONE, O_OR       , {MKREG(REG_E_AX)  , MKOP('I', 'v')    , NOOP          }}, // 0D
    {OF_1BYTE, 0x000E, 0x00, P_NONE, O_PUSH     , {MKREG(REG_CS)    , NOOP              , NOOP          }}, // 0E
    // 0F - Two-byte opcodes

    {OF_1BYTE, 0x0010, 0x00, P_NONE, O_ADC      , {MKOP('E', 'b')   , MKOP('G', 'b')    , NOOP          }}, // 10
    {OF_1BYTE, 0x0011, 0x00, P_NONE, O_ADC      , {MKOP('E', 'v')   , MKOP('G', 'v')    , NOOP          }}, // 11
    {OF_1BYTE, 0x0012, 0x00, P_NONE, O_ADC      , {MKOP('G', 'b')   , MKOP('E', 'b')    , NOOP          }}, // 12
    {OF_1BYTE, 0x0013, 0x00, P_NONE, O_ADC      , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 13
    {OF_1BYTE, 0x0014, 0x00, P_NONE, O_ADC      , {MKREG(REG_AL)    , MKOP('I', 'b')    , NOOP          }}, // 14
    {OF_1BYTE, 0x0015, 0x00, P_NONE, O_ADC      , {MKREG(REG_E_AX)  , MKOP('I', 'v')    , NOOP          }}, // 15
    {OF_1BYTE, 0x0016, 0x00, P_NONE, O_PUSH     , {MKREG(REG_SS)    , NOOP              , NOOP          }}, // 16
    {OF_1BYTE, 0x0017, 0x00, P_NONE, O_POP      , {MKREG(REG_SS)    , NOOP              , NOOP          }}, // 17
    {OF_1BYTE, 0x0018, 0x00, P_NONE, O_SBB      , {MKOP('E', 'b')   , MKOP('G', 'b')    , NOOP          }}, // 18
    {OF_1BYTE, 0x0019, 0x00, P_NONE, O_SBB      , {MKOP('E', 'v')   , MKOP('G', 'v')    , NOOP          }}, // 19
    {OF_1BYTE, 0x001A, 0x00, P_NONE, O_SBB      , {MKOP('G', 'b')   , MKOP('E', 'b')    , NOOP          }}, // 1A
    {OF_1BYTE, 0x001B, 0x00, P_NONE, O_SBB      , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 1B
    {OF_1BYTE, 0x001C, 0x00, P_NONE, O_SBB      , {MKREG(REG_AL)    , MKOP('I', 'b')    , NOOP          }}, // 1C
    {OF_1BYTE, 0x001D, 0x00, P_NONE, O_SBB      , {MKREG(REG_E_AX)  , MKOP('I', 'v')    , NOOP          }}, // 1D
    {OF_1BYTE, 0x001E, 0x00, P_NONE, O_PUSH     , {MKREG(REG_DS)    , NOOP              , NOOP          }}, // 1E
    {OF_1BYTE, 0x001F, 0x00, P_NONE, O_POP      , {MKREG(REG_DS)    , NOOP              , NOOP          }}, // 1F

    {OF_1BYTE, 0x0020, 0x00, P_NONE, O_AND      , {MKOP('E', 'b')   , MKOP('G', 'b')    , NOOP          }}, // 20
    {OF_1BYTE, 0x0021, 0x00, P_NONE, O_AND      , {MKOP('E', 'v')   , MKOP('G', 'v')    , NOOP          }}, // 21
    {OF_1BYTE, 0x0022, 0x00, P_NONE, O_AND      , {MKOP('G', 'b')   , MKOP('E', 'b')    , NOOP          }}, // 22
    {OF_1BYTE, 0x0023, 0x00, P_NONE, O_AND      , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 23
    {OF_1BYTE, 0x0024, 0x00, P_NONE, O_AND      , {MKREG(REG_AL)    , MKOP('I', 'b')    , NOOP          }}, // 24
    {OF_1BYTE, 0x0025, 0x00, P_NONE, O_AND      , {MKREG(REG_E_AX)  , MKOP('I', 'v')    , NOOP          }}, // 25
    {OF_1BYTE, 0x0026, 0x00, P_NONE, UNKOP}     ,                                                           // 26
    {OF_1BYTE, 0x0027, 0x00, P_NONE, O_DAA      , {NOOP             , NOOP              , NOOP          }}, // 27
    {OF_1BYTE, 0x0028, 0x00, P_NONE, O_SUB      , {MKOP('E', 'b')   , MKOP('G', 'b')    , NOOP          }}, // 28
    {OF_1BYTE, 0x0029, 0x00, P_NONE, O_SUB      , {MKOP('E', 'v')   , MKOP('G', 'v')    , NOOP          }}, // 29
    {OF_1BYTE, 0x002A, 0x00, P_NONE, O_SUB      , {MKOP('G', 'b')   , MKOP('E', 'b')    , NOOP          }}, // 2A
    {OF_1BYTE, 0x002B, 0x00, P_NONE, O_SUB      , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 2B
    {OF_1BYTE, 0x002C, 0x00, P_NONE, O_SUB      , {MKREG(REG_AL)    , MKOP('I', 'b')    , NOOP          }}, // 2C
    {OF_1BYTE, 0x002D, 0x00, P_NONE, O_SUB      , {MKREG(REG_E_AX)  , MKOP('I', 'v')    , NOOP          }}, // 2D
    {OF_1BYTE, 0x002E, 0x00, P_NONE, UNKOP}     ,                                                           // 2E
    {OF_1BYTE, 0x002F, 0x00, P_NONE, O_DAS      , {NOOP             , NOOP              , NOOP          }}, // 2F

    {OF_1BYTE, 0x0030, 0x00, P_NONE, O_XOR      , {MKOP('E', 'b')   , MKOP('G', 'b')    , NOOP          }}, // 30
    {OF_1BYTE, 0x0031, 0x00, P_NONE, O_XOR      , {MKOP('E', 'v')   , MKOP('G', 'v')    , NOOP          }}, // 31
    {OF_1BYTE, 0x0032, 0x00, P_NONE, O_XOR      , {MKOP('G', 'b')   , MKOP('E', 'b')    , NOOP          }}, // 32
    {OF_1BYTE, 0x0033, 0x00, P_NONE, O_XOR      , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 33
    {OF_1BYTE, 0x0034, 0x00, P_NONE, O_XOR      , {MKREG(REG_AL)    , MKOP('I', 'b')    , NOOP          }}, // 34
    {OF_1BYTE, 0x0035, 0x00, P_NONE, O_XOR      , {MKREG(REG_E_AX)  , MKOP('I', 'v')    , NOOP          }}, // 35
    {OF_1BYTE, 0x0036, 0x00, P_NONE, UNKOP}     ,                                                           // 36
    {OF_1BYTE, 0x0037, 0x00, P_NONE, O_AAA      , {NOOP             , NOOP              , NOOP          }}, // 37
    {OF_1BYTE, 0x0038, 0x00, P_NONE, O_CMP      , {MKOP('E', 'b')   , MKOP('G', 'b')    , NOOP          }}, // 38
    {OF_1BYTE, 0x0039, 0x00, P_NONE, O_CMP      , {MKOP('E', 'v')   , MKOP('G', 'v')    , NOOP          }}, // 39
    {OF_1BYTE, 0x003A, 0x00, P_NONE, O_CMP      , {MKOP('G', 'b')   , MKOP('E', 'b')    , NOOP          }}, // 3A
    {OF_1BYTE, 0x003B, 0x00, P_NONE, O_CMP      , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 3B
    {OF_1BYTE, 0x003C, 0x00, P_NONE, O_CMP      , {MKREG(REG_AL)    , MKOP('I', 'b')    , NOOP          }}, // 3C
    {OF_1BYTE, 0x003D, 0x00, P_NONE, O_CMP      , {MKREG(REG_E_AX)  , MKOP('I', 'v')    , NOOP          }}, // 3D
    {OF_1BYTE, 0x003E, 0x00, P_NONE, UNKOP}     ,                                                           // 3E
    {OF_1BYTE, 0x003F, 0x00, P_NONE, O_AAS      , {NOOP             , NOOP              , NOOP          }}, // 3F

    {OF_1BYTE, 0x0040, 0x00, P_NONE, O_INC      , {MKREG(REG_E_AX)  , NOOP              , NOOP          }}, // 40
    {OF_1BYTE, 0x0041, 0x00, P_NONE, O_INC      , {MKREG(REG_E_CX)  , NOOP              , NOOP          }}, // 41
    {OF_1BYTE, 0x0042, 0x00, P_NONE, O_INC      , {MKREG(REG_E_DX)  , NOOP              , NOOP          }}, // 42
    {OF_1BYTE, 0x0043, 0x00, P_NONE, O_INC      , {MKREG(REG_E_BX)  , NOOP              , NOOP          }}, // 43
    {OF_1BYTE, 0x0044, 0x00, P_NONE, O_INC      , {MKREG(REG_E_SP)  , NOOP              , NOOP          }}, // 44
    {OF_1BYTE, 0x0045, 0x00, P_NONE, O_INC      , {MKREG(REG_E_BP)  , NOOP              , NOOP          }}, // 45
    {OF_1BYTE, 0x0046, 0x00, P_NONE, O_INC      , {MKREG(REG_E_SI)  , NOOP              , NOOP          }}, // 46
    {OF_1BYTE, 0x0047, 0x00, P_NONE, O_INC      , {MKREG(REG_E_DI)  , NOOP              , NOOP          }}, // 47
    {OF_1BYTE, 0x0048, 0x00, P_NONE, O_DEC      , {MKREG(REG_E_AX)  , NOOP              , NOOP          }}, // 48
    {OF_1BYTE, 0x0049, 0x00, P_NONE, O_DEC      , {MKREG(REG_E_CX)  , NOOP              , NOOP          }}, // 49
    {OF_1BYTE, 0x004A, 0x00, P_NONE, O_DEC      , {MKREG(REG_E_DX)  , NOOP              , NOOP          }}, // 4A
    {OF_1BYTE, 0x004B, 0x00, P_NONE, O_DEC      , {MKREG(REG_E_BX)  , NOOP              , NOOP          }}, // 4B
    {OF_1BYTE, 0x004C, 0x00, P_NONE, O_DEC      , {MKREG(REG_E_SP)  , NOOP              , NOOP          }}, // 4C
    {OF_1BYTE, 0x004D, 0x00, P_NONE, O_DEC      , {MKREG(REG_E_BP)  , NOOP              , NOOP          }}, // 4D
    {OF_1BYTE, 0x004E, 0x00, P_NONE, O_DEC      , {MKREG(REG_E_SI)  , NOOP              , NOOP          }}, // 4E
    {OF_1BYTE, 0x004F, 0x00, P_NONE, O_DEC      , {MKREG(REG_E_DI)  , NOOP              , NOOP          }}, // 4F

    {OF_1BYTE, 0x0050, 0x00, P_NONE, O_PUSH     , {MKREG(REG_E_AX)  , NOOP              , NOOP          }}, // 50
    {OF_1BYTE, 0x0051, 0x00, P_NONE, O_PUSH     , {MKREG(REG_E_CX)  , NOOP              , NOOP          }}, // 51
    {OF_1BYTE, 0x0052, 0x00, P_NONE, O_PUSH     , {MKREG(REG_E_DX)  , NOOP              , NOOP          }}, // 52
    {OF_1BYTE, 0x0053, 0x00, P_NONE, O_PUSH     , {MKREG(REG_E_BX)  , NOOP              , NOOP          }}, // 53
    {OF_1BYTE, 0x0054, 0x00, P_NONE, O_PUSH     , {MKREG(REG_E_SP)  , NOOP              , NOOP          }}, // 54
    {OF_1BYTE, 0x0055, 0x00, P_NONE, O_PUSH     , {MKREG(REG_E_BP)  , NOOP              , NOOP          }}, // 55
    {OF_1BYTE, 0x0056, 0x00, P_NONE, O_PUSH     , {MKREG(REG_E_SI)  , NOOP              , NOOP          }}, // 56
    {OF_1BYTE, 0x0057, 0x00, P_NONE, O_PUSH     , {MKREG(REG_E_DI)  , NOOP              , NOOP          }}, // 57
    {OF_1BYTE, 0x0058, 0x00, P_NONE, O_POP      , {MKREG(REG_E_AX)  , NOOP              , NOOP          }}, // 58
    {OF_1BYTE, 0x0059, 0x00, P_NONE, O_POP      , {MKREG(REG_E_CX)  , NOOP              , NOOP          }}, // 59
    {OF_1BYTE, 0x005A, 0x00, P_NONE, O_POP      , {MKREG(REG_E_DX)  , NOOP              , NOOP          }}, // 5A
    {OF_1BYTE, 0x005B, 0x00, P_NONE, O_POP      , {MKREG(REG_E_BX)  , NOOP              , NOOP          }}, // 5B
    {OF_1BYTE, 0x005C, 0x00, P_NONE, O_POP      , {MKREG(REG_E_SP)  , NOOP              , NOOP          }}, // 5C
    {OF_1BYTE, 0x005D, 0x00, P_NONE, O_POP      , {MKREG(REG_E_BP)  , NOOP              , NOOP          }}, // 5D
    {OF_1BYTE, 0x005E, 0x00, P_NONE, O_POP      , {MKREG(REG_E_SI)  , NOOP              , NOOP          }}, // 5E
    {OF_1BYTE, 0x005F, 0x00, P_NONE, O_POP      , {MKREG(REG_E_DI)  , NOOP              , NOOP          }}, // 5F

    {OF_1BYTE, 0x0060, 0x00, P_NONE, O_PUSHA    , {NOOP             , NOOP              , NOOP          }}, // 60
    {OF_1BYTE, 0x0061, 0x00, P_NONE, O_POPA     , {NOOP             , NOOP              , NOOP          }}, // 61
    {OF_1BYTE, 0x0062, 0x00, P_NONE, O_BOUND    , {MKOP('G', 'v')   , MKOP('M', 'a')    , NOOP          }}, // 62
    {OF_1BYTE, 0x0063, 0x00, P_NONE, O_ARPL     , {MKOP('E', 'w')   , MKOP('G', 'w')    , NOOP          }}, // 63
    {OF_1BYTE, 0x0064, 0x00, P_NONE, UNKOP}     ,                                                           // 64
    {OF_1BYTE, 0x0065, 0x00, P_NONE, UNKOP}     ,                                                           // 65
    {OF_1BYTE, 0x0066, 0x00, P_NONE, UNKOP}     ,                                                           // 66
    {OF_1BYTE, 0x0067, 0x00, P_NONE, UNKOP}     ,                                                           // 67
    {OF_1BYTE, 0x0068, 0x00, P_NONE, O_PUSH     , {MKOP('I', 'v')   , NOOP              , NOOP          }}, // 68
    {OF_1BYTE, 0x0069, 0x00, P_NONE, O_IMUL     , {MKOP('G', 'v')   , MKOP('E', 'v')    , MKOP('I', 'v')}}, // 69
    {OF_1BYTE, 0x006A, 0x00, P_NONE, O_PUSH     , {MKOP('I', 'b')   , NOOP              , NOOP          }}, // 6A
    {OF_1BYTE, 0x006B, 0x00, P_NONE, O_IMUL     , {MKOP('G', 'v')   , MKOP('E', 'v')    , MKOP('I', 'b')}}, // 6B
    {OF_1BYTE, 0x006C, 0x00, P_NONE, O_INS      , {MKOP('Y', 'b')   , MKREG(REG_DX)     , NOOP          }}, // 6C
    {OF_1BYTE, 0x006D, 0x00, P_NONE, O_INS      , {MKOP('Y', 'v')   , MKREG(REG_DX)     , NOOP          }}, // 6D
    {OF_1BYTE, 0x006E, 0x00, P_NONE, O_OUTS     , {MKREG(REG_DX)    , MKOP('X', 'b')    , NOOP          }}, // 6E
    {OF_1BYTE, 0x006F, 0x00, P_NONE, O_OUTS     , {MKREG(REG_DX)    , MKOP('X', 'v')    , NOOP          }}, // 6F

    {OF_1BYTE, 0x0070, 0x00, P_NONE, O_JO       , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // 70
    {OF_1BYTE, 0x0071, 0x00, P_NONE, O_JNO      , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // 71
    {OF_1BYTE, 0x0072, 0x00, P_NONE, O_JB       , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // 72
    {OF_1BYTE, 0x0073, 0x00, P_NONE, O_JNB      , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // 73
    {OF_1BYTE, 0x0074, 0x00, P_NONE, O_JZ       , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // 74
    {OF_1BYTE, 0x0075, 0x00, P_NONE, O_JNZ      , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // 75
    {OF_1BYTE, 0x0076, 0x00, P_NONE, O_JBE      , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // 76
    {OF_1BYTE, 0x0077, 0x00, P_NONE, O_JNBE     , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // 77
    {OF_1BYTE, 0x0078, 0x00, P_NONE, O_JS       , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // 78
    {OF_1BYTE, 0x0079, 0x00, P_NONE, O_JNS      , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // 79
    {OF_1BYTE, 0x007A, 0x00, P_NONE, O_JP       , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // 7A
    {OF_1BYTE, 0x007B, 0x00, P_NONE, O_JNP      , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // 7B
    {OF_1BYTE, 0x007C, 0x00, P_NONE, O_JL       , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // 7C
    {OF_1BYTE, 0x007D, 0x00, P_NONE, O_JNL      , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // 7D
    {OF_1BYTE, 0x007E, 0x00, P_NONE, O_JLE      , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // 7E
    {OF_1BYTE, 0x007F, 0x00, P_NONE, O_JNLE     , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // 7F

    // Group 1.1
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0080, 0x00, P_NONE,  O_ADD       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // 80-000
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0080, 0x01, P_NONE,  O_OR        , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // 80-001
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0080, 0x02, P_NONE,  O_ADC       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // 80-010
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0080, 0x03, P_NONE,  O_SBB       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // 80-011
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0080, 0x04, P_NONE,  O_AND       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // 80-100
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0080, 0x05, P_NONE,  O_SUB       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // 80-101
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0080, 0x06, P_NONE,  O_XOR       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // 80-110
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0080, 0x07, P_NONE,  O_CMP       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // 80-111

    // Group 1.2
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0081, 0x00, P_NONE,  O_ADD       , {MKOP('E', 'v')   , MKOP('I', 'v')    , NOOP          }}, // 81-000
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0081, 0x01, P_NONE,  O_OR        , {MKOP('E', 'v')   , MKOP('I', 'v')    , NOOP          }}, // 81-001
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0081, 0x02, P_NONE,  O_ADC       , {MKOP('E', 'v')   , MKOP('I', 'v')    , NOOP          }}, // 81-010
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0081, 0x03, P_NONE,  O_SBB       , {MKOP('E', 'v')   , MKOP('I', 'v')    , NOOP          }}, // 81-011
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0081, 0x04, P_NONE,  O_AND       , {MKOP('E', 'v')   , MKOP('I', 'v')    , NOOP          }}, // 81-100
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0081, 0x05, P_NONE,  O_SUB       , {MKOP('E', 'v')   , MKOP('I', 'v')    , NOOP          }}, // 81-101
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0081, 0x06, P_NONE,  O_XOR       , {MKOP('E', 'v')   , MKOP('I', 'v')    , NOOP          }}, // 81-110
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0081, 0x07, P_NONE,  O_CMP       , {MKOP('E', 'v')   , MKOP('I', 'v')    , NOOP          }}, // 81-111

    // Group 1.3
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0082, 0x00, P_NONE,  O_ADD       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // 82-000
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0082, 0x01, P_NONE,  O_OR        , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // 82-001
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0082, 0x02, P_NONE,  O_ADC       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // 82-010
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0082, 0x03, P_NONE,  O_SBB       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // 82-011
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0082, 0x04, P_NONE,  O_AND       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // 82-100
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0082, 0x05, P_NONE,  O_SUB       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // 82-101
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0082, 0x06, P_NONE,  O_XOR       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // 82-110
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0082, 0x07, P_NONE,  O_CMP       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // 82-111

    // Group 1.4
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0083, 0x00, P_NONE,  O_ADD       , {MKOP('E', 'v')   , MKOP('I', 'b')    , NOOP          }}, // 83-000
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0083, 0x01, P_NONE,  O_OR        , {MKOP('E', 'v')   , MKOP('I', 'b')    , NOOP          }}, // 83-001
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0083, 0x02, P_NONE,  O_ADC       , {MKOP('E', 'v')   , MKOP('I', 'b')    , NOOP          }}, // 83-010
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0083, 0x03, P_NONE,  O_SBB       , {MKOP('E', 'v')   , MKOP('I', 'b')    , NOOP          }}, // 83-011
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0083, 0x04, P_NONE,  O_AND       , {MKOP('E', 'v')   , MKOP('I', 'b')    , NOOP          }}, // 83-100
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0083, 0x05, P_NONE,  O_SUB       , {MKOP('E', 'v')   , MKOP('I', 'b')    , NOOP          }}, // 83-101
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0083, 0x06, P_NONE,  O_XOR       , {MKOP('E', 'v')   , MKOP('I', 'b')    , NOOP          }}, // 83-110
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x0083, 0x07, P_NONE,  O_CMP       , {MKOP('E', 'v')   , MKOP('I', 'b')    , NOOP          }}, // 83-111

    {OF_1BYTE, 0x0084, 0x00, P_NONE, O_TEST     , {MKOP('E', 'b')   , MKOP('G', 'b')    , NOOP          }}, // 84
    {OF_1BYTE, 0x0085, 0x00, P_NONE, O_TEST     , {MKOP('E', 'v')   , MKOP('G', 'v')    , NOOP          }}, // 85
    {OF_1BYTE, 0x0086, 0x00, P_NONE, O_XCHG     , {MKOP('E', 'b')   , MKOP('G', 'b')    , NOOP          }}, // 86
    {OF_1BYTE, 0x0087, 0x00, P_NONE, O_XCHG     , {MKOP('E', 'v')   , MKOP('G', 'v')    , NOOP          }}, // 87
    {OF_1BYTE, 0x0088, 0x00, P_NONE, O_MOV      , {MKOP('E', 'b')   , MKOP('G', 'b')    , NOOP          }}, // 88
    {OF_1BYTE, 0x0089, 0x00, P_NONE, O_MOV      , {MKOP('E', 'v')   , MKOP('G', 'v')    , NOOP          }}, // 89
    {OF_1BYTE, 0x008A, 0x00, P_NONE, O_MOV      , {MKOP('G', 'b')   , MKOP('E', 'b')    , NOOP          }}, // 8A
    {OF_1BYTE, 0x008B, 0x00, P_NONE, O_MOV      , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 8B
    {OF_1BYTE, 0x008C, 0x00, P_NONE, O_MOV      , {MKOP('E', 'w')   , MKOP('S', 'w')    , NOOP          }}, // 8C
    {OF_1BYTE, 0x008D, 0x00, P_NONE, O_LEA      , {MKOP('G', 'v')   , MKOP('M', 0)      , NOOP          }}, // 8D
    {OF_1BYTE, 0x008E, 0x00, P_NONE, O_MOV      , {MKOP('S', 'w')   , MKOP('E', 'w')    , NOOP          }}, // 8E
    {OF_1BYTE, 0x008F, 0x00, P_NONE, O_POP      , {MKOP('E', 'v')   , NOOP              , NOOP          }}, // 8F

    // NOTE: Intel's IA32 specification volume 2 does not state this opcode in its
    // opcode map. My sexy KeybJunky however, pointed out about its existence.
    {OF_1BYTE | OF_USEPREFIX, 0x0090, 0x00, P_REPE, O_PAUSE, {NOOP  , NOOP              , NOOP          }}, // (F3) 90
    {OF_1BYTE, 0x0090, 0x00, P_NONE, O_NOP      , {NOOP             , NOOP              , NOOP          }}, // 90

    {OF_1BYTE, 0x0091, 0x00, P_NONE, O_XCHG     , {MKREG(REG_E_AX)  , MKREG(REG_E_CX)   , NOOP          }}, // 91
    {OF_1BYTE, 0x0092, 0x00, P_NONE, O_XCHG     , {MKREG(REG_E_AX)  , MKREG(REG_E_DX)   , NOOP          }}, // 92
    {OF_1BYTE, 0x0093, 0x00, P_NONE, O_XCHG     , {MKREG(REG_E_AX)  , MKREG(REG_E_BX)   , NOOP          }}, // 93
    {OF_1BYTE, 0x0094, 0x00, P_NONE, O_XCHG     , {MKREG(REG_E_AX)  , MKREG(REG_E_SP)   , NOOP          }}, // 94
    {OF_1BYTE, 0x0095, 0x00, P_NONE, O_XCHG     , {MKREG(REG_E_AX)  , MKREG(REG_E_BP)   , NOOP          }}, // 95
    {OF_1BYTE, 0x0096, 0x00, P_NONE, O_XCHG     , {MKREG(REG_E_AX)  , MKREG(REG_E_SI)   , NOOP          }}, // 96
    {OF_1BYTE, 0x0097, 0x00, P_NONE, O_XCHG     , {MKREG(REG_E_AX)  , MKREG(REG_E_DI)   , NOOP          }}, // 97
    {OF_1BYTE, 0x0098, 0x00, P_NONE, O_CBW      , {NOOP             , NOOP              , NOOP          }}, // 98
    {OF_1BYTE, 0x0099, 0x00, P_NONE, O_CWD      , {NOOP             , NOOP              , NOOP          }}, // 99
    {OF_1BYTE, 0x009A, 0x00, P_NONE, O_CALLF    , {MKOP('A', 'p')   , NOOP              , NOOP          }}, // 9A
    {OF_1BYTE, 0x009B, 0x00, P_NONE, O_FWAIT    , {NOOP             , NOOP              , NOOP          }}, // 9B
    {OF_1BYTE, 0x009C, 0x00, P_NONE, O_PUSHF    , {NOOP             , NOOP              , NOOP          }}, // 9C
    {OF_1BYTE, 0x009D, 0x00, P_NONE, O_POPF     , {NOOP             , NOOP              , NOOP          }}, // 9D
    {OF_1BYTE, 0x009E, 0x00, P_NONE, O_SAHF     , {NOOP             , NOOP              , NOOP          }}, // 9E
    {OF_1BYTE, 0x009F, 0x00, P_NONE, O_LAHF     , {NOOP             , NOOP              , NOOP          }}, // 9F

    {OF_1BYTE, 0x00A0, 0x00, P_NONE, O_MOV      , {MKREG(REG_AL)    , MKOP('O', 'b')    , NOOP          }}, // A0
    {OF_1BYTE, 0x00A1, 0x00, P_NONE, O_MOV      , {MKREG(REG_E_AX)  , MKOP('O', 'v')    , NOOP          }}, // A1
    {OF_1BYTE, 0x00A2, 0x00, P_NONE, O_MOV      , {MKOP('O', 'b')   , MKREG(REG_AL)     , NOOP          }}, // A2
    {OF_1BYTE, 0x00A3, 0x00, P_NONE, O_MOV      , {MKOP('O', 'v')   , MKREG(REG_E_AX)   , NOOP          }}, // A3
    {OF_1BYTE, 0x00A4, 0x00, P_NONE, O_MOVS     , {MKOP('X', 'b')   , MKOP('Y', 'b')    , NOOP          }}, // A4
    {OF_1BYTE, 0x00A5, 0x00, P_NONE, O_MOVS     , {MKOP('X', 'v')   , MKOP('Y', 'v')    , NOOP          }}, // A5
    {OF_1BYTE, 0x00A6, 0x00, P_NONE, O_CMPS     , {MKOP('X', 'b')   , MKOP('Y', 'b')    , NOOP          }}, // A6
    {OF_1BYTE, 0x00A7, 0x00, P_NONE, O_CMPS     , {MKOP('X', 'v')   , MKOP('Y', 'v')    , NOOP          }}, // A7
    {OF_1BYTE, 0x00A8, 0x00, P_NONE, O_TEST     , {MKREG(REG_AL)    , MKOP('I', 'b')    , NOOP          }}, // A8
    {OF_1BYTE, 0x00A9, 0x00, P_NONE, O_TEST     , {MKREG(REG_E_AX)  , MKOP('I', 'v')    , NOOP          }}, // A9
    {OF_1BYTE, 0x00AA, 0x00, P_NONE, O_STOS     , {MKOP('Y', 'b')   , MKREG(REG_AL)     , NOOP          }}, // AA
    {OF_1BYTE, 0x00AB, 0x00, P_NONE, O_STOS     , {MKOP('Y', 'v')   , MKREG(REG_E_AX)   , NOOP          }}, // AB
    {OF_1BYTE, 0x00AC, 0x00, P_NONE, O_LODS     , {MKREG(REG_AL)    , MKOP('X', 'b')    , NOOP          }}, // AC
    {OF_1BYTE, 0x00AD, 0x00, P_NONE, O_LODS     , {MKREG(REG_E_AX)  , MKOP('X', 'v')    , NOOP          }}, // AD
    {OF_1BYTE, 0x00AE, 0x00, P_NONE, O_SCAS     , {MKREG(REG_AL)    , MKOP('Y', 'b')    , NOOP          }}, // AE
    // Intel IA32 Specification Volume II had a mistake concering the following
    // instruction (it used X addressing mode)
    {OF_1BYTE, 0x00AF, 0x00, P_NONE, O_SCAS     , {MKREG(REG_E_AX)  , MKOP('Y', 'v')    , NOOP          }}, // AF

    {OF_1BYTE, 0x00B0, 0x00, P_NONE, O_MOV      , {MKREG(REG_AL)    , MKOP('I', 'b')    , NOOP          }}, // B0
    {OF_1BYTE, 0x00B1, 0x00, P_NONE, O_MOV      , {MKREG(REG_CL)    , MKOP('I', 'b')    , NOOP          }}, // B1
    {OF_1BYTE, 0x00B2, 0x00, P_NONE, O_MOV      , {MKREG(REG_DL)    , MKOP('I', 'b')    , NOOP          }}, // B2
    {OF_1BYTE, 0x00B3, 0x00, P_NONE, O_MOV      , {MKREG(REG_BL)    , MKOP('I', 'b')    , NOOP          }}, // B3
    {OF_1BYTE, 0x00B4, 0x00, P_NONE, O_MOV      , {MKREG(REG_AH)    , MKOP('I', 'b')    , NOOP          }}, // B4
    {OF_1BYTE, 0x00B5, 0x00, P_NONE, O_MOV      , {MKREG(REG_CH)    , MKOP('I', 'b')    , NOOP          }}, // B5
    {OF_1BYTE, 0x00B6, 0x00, P_NONE, O_MOV      , {MKREG(REG_DH)    , MKOP('I', 'b')    , NOOP          }}, // B6
    {OF_1BYTE, 0x00B7, 0x00, P_NONE, O_MOV      , {MKREG(REG_BH)    , MKOP('I', 'b')    , NOOP          }}, // B7
    {OF_1BYTE, 0x00B8, 0x00, P_NONE, O_MOV      , {MKREG(REG_E_AX)  , MKOP('I', 'v')    , NOOP          }}, // B8
    {OF_1BYTE, 0x00B9, 0x00, P_NONE, O_MOV      , {MKREG(REG_E_CX)  , MKOP('I', 'v')    , NOOP          }}, // B9
    {OF_1BYTE, 0x00BA, 0x00, P_NONE, O_MOV      , {MKREG(REG_E_DX)  , MKOP('I', 'v')    , NOOP          }}, // BA
    {OF_1BYTE, 0x00BB, 0x00, P_NONE, O_MOV      , {MKREG(REG_E_BX)  , MKOP('I', 'v')    , NOOP          }}, // BB
    {OF_1BYTE, 0x00BC, 0x00, P_NONE, O_MOV      , {MKREG(REG_E_SP)  , MKOP('I', 'v')    , NOOP          }}, // BC
    {OF_1BYTE, 0x00BD, 0x00, P_NONE, O_MOV      , {MKREG(REG_E_BP)  , MKOP('I', 'v')    , NOOP          }}, // BD
    {OF_1BYTE, 0x00BE, 0x00, P_NONE, O_MOV      , {MKREG(REG_E_SI)  , MKOP('I', 'v')    , NOOP          }}, // BE
    {OF_1BYTE, 0x00BF, 0x00, P_NONE, O_MOV      , {MKREG(REG_E_DI)  , MKOP('I', 'v')    , NOOP          }}, // BF

    // Group 2.5
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C0, 0x00, P_NONE,  O_ROL       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // C0-000
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C0, 0x01, P_NONE,  O_ROR       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // C0-001
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C0, 0x02, P_NONE,  O_RCL       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // C0-010
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C0, 0x03, P_NONE,  O_RCR       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // C0-011
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C0, 0x04, P_NONE,  O_SHL       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // C0-100
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C0, 0x05, P_NONE,  O_SHR       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // C0-101
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C0, 0x06, P_NONE,  UNKOP}      ,                                                           // C0-110
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C0, 0x07, P_NONE,  O_SAR       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // C0-111

    // Group 2.6
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C1, 0x00, P_NONE,  O_ROL       , {MKOP('E', 'v')   , MKOP('I', 'b')    , NOOP          }}, // C1-000
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C1, 0x01, P_NONE,  O_ROR       , {MKOP('E', 'v')   , MKOP('I', 'b')    , NOOP          }}, // C1-001
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C1, 0x02, P_NONE,  O_RCL       , {MKOP('E', 'v')   , MKOP('I', 'b')    , NOOP          }}, // C1-010
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C1, 0x03, P_NONE,  O_RCR       , {MKOP('E', 'v')   , MKOP('I', 'b')    , NOOP          }}, // C1-011
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C1, 0x04, P_NONE,  O_SHL       , {MKOP('E', 'v')   , MKOP('I', 'b')    , NOOP          }}, // C1-100
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C1, 0x05, P_NONE,  O_SHR       , {MKOP('E', 'v')   , MKOP('I', 'b')    , NOOP          }}, // C1-101
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C1, 0x06, P_NONE,  UNKOP}      ,                                                           // C1-110
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C1, 0x07, P_NONE,  O_SAR       , {MKOP('E', 'v')   , MKOP('I', 'b')    , NOOP          }}, // C1-111

    {OF_1BYTE, 0x00C2, 0x00, P_NONE, O_RETN     , {MKOP('I', 'w')   , NOOP              , NOOP          }}, // C2
    {OF_1BYTE, 0x00C3, 0x00, P_NONE, O_RETN     , {NOOP             , NOOP              , NOOP          }}, // C3
    {OF_1BYTE, 0x00C4, 0x00, P_NONE, O_LES      , {MKOP('G', 'v')   , MKOP('M', 'p')    , NOOP          }}, // C4
    {OF_1BYTE, 0x00C5, 0x00, P_NONE, O_LDS      , {MKOP('G', 'v')   , MKOP('M', 'p')    , NOOP          }}, // C5

    // Group 11.1
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C6, 0x00, P_NONE,  O_MOV       , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // C6-000
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C6, 0x01, P_NONE,  UNKOP}      ,                                                           // C6-001
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C6, 0x02, P_NONE,  UNKOP}      ,                                                           // C6-010
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C6, 0x03, P_NONE,  UNKOP}      ,                                                           // C6-011
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C6, 0x04, P_NONE,  UNKOP}      ,                                                           // C6-100
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C6, 0x05, P_NONE,  UNKOP}      ,                                                           // C6-101
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C6, 0x06, P_NONE,  UNKOP}      ,                                                           // C6-110
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C6, 0x07, P_NONE,  UNKOP}      ,                                                           // C6-111

    // Group 11.2
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C7, 0x00, P_NONE,  O_MOV       , {MKOP('E', 'v')   , MKOP('I', 'v')    , NOOP          }}, // C7-000
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C7, 0x01, P_NONE,  UNKOP}      ,                                                           // C7-001
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C7, 0x02, P_NONE,  UNKOP}      ,                                                           // C7-010
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C7, 0x03, P_NONE,  UNKOP}      ,                                                           // C7-011
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C7, 0x04, P_NONE,  UNKOP}      ,                                                           // C7-100
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C7, 0x05, P_NONE,  UNKOP}      ,                                                           // C7-101
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C7, 0x06, P_NONE,  UNKOP}      ,                                                           // C7-110
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00C7, 0x07, P_NONE,  UNKOP}      ,                                                           // C7-111

    {OF_1BYTE, 0x00C8, 0x00, P_NONE, O_ENTER    , {MKOP('I', 'w')   , MKOP('I', 'b')    , NOOP          }}, // C8
    {OF_1BYTE, 0x00C9, 0x00, P_NONE, O_LEAVE    , {NOOP             , NOOP              , NOOP          }}, // C9
    {OF_1BYTE, 0x00CA, 0x00, P_NONE, O_RETF     , {MKOP('I', 'w')   , NOOP              , NOOP          }}, // CA
    {OF_1BYTE, 0x00CB, 0x00, P_NONE, O_RETF     , {NOOP             , NOOP              , NOOP          }}, // CB
    {OF_1BYTE, 0x00CC, 0x00, P_NONE, O_INT3     , {NOOP             , NOOP              , NOOP          }}, // CC
    {OF_1BYTE, 0x00CD, 0x00, P_NONE, O_INT      , {MKOP('I', 'b')   , NOOP              , NOOP          }}, // CD
    {OF_1BYTE, 0x00CE, 0x00, P_NONE, O_INTO     , {NOOP             , NOOP              , NOOP          }}, // CE
    {OF_1BYTE, 0x00CF, 0x00, P_NONE, O_IRET     , {NOOP             , NOOP              , NOOP          }}, // CF


    // Group 2.1
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D0, 0x00, P_NONE,  O_ROL       , {MKOP('E', 'b')   , MKREG(REG_VAL_1)  , NOOP          }}, // D0-000
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D0, 0x01, P_NONE,  O_ROR       , {MKOP('E', 'b')   , MKREG(REG_VAL_1)  , NOOP          }}, // D0-001
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D0, 0x02, P_NONE,  O_RCL       , {MKOP('E', 'b')   , MKREG(REG_VAL_1)  , NOOP          }}, // D0-010
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D0, 0x03, P_NONE,  O_RCR       , {MKOP('E', 'b')   , MKREG(REG_VAL_1)  , NOOP          }}, // D0-011
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D0, 0x04, P_NONE,  O_SHL       , {MKOP('E', 'b')   , MKREG(REG_VAL_1)  , NOOP          }}, // D0-100
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D0, 0x05, P_NONE,  O_SHR       , {MKOP('E', 'b')   , MKREG(REG_VAL_1)  , NOOP          }}, // D0-101
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D0, 0x06, P_NONE,  UNKOP}      ,                                                           // D0-110
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D0, 0x07, P_NONE,  O_SAR       , {MKOP('E', 'b')   , MKREG(REG_VAL_1)  , NOOP          }}, // D0-111

    // Group 2.2
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D1, 0x00, P_NONE,  O_ROL       , {MKOP('E', 'v')   , MKREG(REG_VAL_1)  , NOOP          }}, // D1-000
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D1, 0x01, P_NONE,  O_ROR       , {MKOP('E', 'v')   , MKREG(REG_VAL_1)  , NOOP          }}, // D1-001
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D1, 0x02, P_NONE,  O_RCL       , {MKOP('E', 'v')   , MKREG(REG_VAL_1)  , NOOP          }}, // D1-010
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D1, 0x03, P_NONE,  O_RCR       , {MKOP('E', 'v')   , MKREG(REG_VAL_1)  , NOOP          }}, // D1-011
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D1, 0x04, P_NONE,  O_SHL       , {MKOP('E', 'v')   , MKREG(REG_VAL_1)  , NOOP          }}, // D1-100
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D1, 0x05, P_NONE,  O_SHR       , {MKOP('E', 'v')   , MKREG(REG_VAL_1)  , NOOP          }}, // D1-101
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D1, 0x06, P_NONE,  UNKOP}      ,                                                           // D1-110
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D1, 0x07, P_NONE,  O_SAR       , {MKOP('E', 'v')   , MKREG(REG_VAL_1)  , NOOP          }}, // D1-111

    // Group 2.3
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D2, 0x00, P_NONE,  O_ROL       , {MKOP('E', 'b')   , MKREG(REG_CL)     , NOOP          }}, // D2-000
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D2, 0x01, P_NONE,  O_ROR       , {MKOP('E', 'b')   , MKREG(REG_CL)     , NOOP          }}, // D2-001
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D2, 0x02, P_NONE,  O_RCL       , {MKOP('E', 'b')   , MKREG(REG_CL)     , NOOP          }}, // D2-010
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D2, 0x03, P_NONE,  O_RCR       , {MKOP('E', 'b')   , MKREG(REG_CL)     , NOOP          }}, // D2-011
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D2, 0x04, P_NONE,  O_SHL       , {MKOP('E', 'b')   , MKREG(REG_CL)     , NOOP          }}, // D2-100
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D2, 0x05, P_NONE,  O_SHR       , {MKOP('E', 'b')   , MKREG(REG_CL)     , NOOP          }}, // D2-101
    // According to HIEW, the following instruction is SAL. According to Intel's
    // specification, however, it is undefined.
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D2, 0x06, P_NONE,  UNKOP}      ,                                                           // D2-110
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D2, 0x07, P_NONE,  O_SAR       , {MKOP('E', 'b')   , MKREG(REG_CL)     , NOOP          }}, // D2-111

    // Group 2.4
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D3, 0x00, P_NONE,  O_ROL       , {MKOP('E', 'v')   , MKREG(REG_CL)     , NOOP          }}, // D3-000
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D3, 0x01, P_NONE,  O_ROR       , {MKOP('E', 'v')   , MKREG(REG_CL)     , NOOP          }}, // D3-001
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D3, 0x02, P_NONE,  O_RCL       , {MKOP('E', 'v')   , MKREG(REG_CL)     , NOOP          }}, // D3-010
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D3, 0x03, P_NONE,  O_RCR       , {MKOP('E', 'v')   , MKREG(REG_CL)     , NOOP          }}, // D3-011
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D3, 0x04, P_NONE,  O_SHL       , {MKOP('E', 'v')   , MKREG(REG_CL)     , NOOP          }}, // D3-100
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D3, 0x05, P_NONE,  O_SHR       , {MKOP('E', 'v')   , MKREG(REG_CL)     , NOOP          }}, // D3-101
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D3, 0x06, P_NONE,  UNKOP}      ,                                                           // D3-110
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00D3, 0x07, P_NONE,  O_SAR       , {MKOP('E', 'v')   , MKREG(REG_CL)     , NOOP          }}, // D3-111

    {OF_1BYTE, 0x00D4, 0x00, P_NONE, O_AAM      , {MKOP('I', 'b')   , NOOP              , NOOP          }}, // D4
    {OF_1BYTE, 0x00D5, 0x00, P_NONE, O_AAD      , {MKOP('I', 'b')   , NOOP              , NOOP          }}, // D5
    {OF_1BYTE, 0x00D6, 0x00, P_NONE, UNKOP}     ,                                                           // D6
    {OF_1BYTE, 0x00D7, 0x00, P_NONE, O_XLAT     , {NOOP             , NOOP              , NOOP          }}, // D7

    // FPU Instructions are decoded using a separate routine
    /*
    {OF_1BYTE, 0x00D8, 0x00, P_NONE, O_ESC      , {NOOP             , NOOP              , NOOP          }}, // D8
    {OF_1BYTE, 0x00D9, 0x00, P_NONE, O_ESC      , {NOOP             , NOOP              , NOOP          }}, // D9
    {OF_1BYTE, 0x00DA, 0x00, P_NONE, O_ESC      , {NOOP             , NOOP              , NOOP          }}, // DA
    {OF_1BYTE, 0x00DB, 0x00, P_NONE, O_ESC      , {NOOP             , NOOP              , NOOP          }}, // DB
    {OF_1BYTE, 0x00DC, 0x00, P_NONE, O_ESC      , {NOOP             , NOOP              , NOOP          }}, // DC
    {OF_1BYTE, 0x00DD, 0x00, P_NONE, O_ESC      , {NOOP             , NOOP              , NOOP          }}, // DD
    {OF_1BYTE, 0x00DE, 0x00, P_NONE, O_ESC      , {NOOP             , NOOP              , NOOP          }}, // DE
    {OF_1BYTE, 0x00DF, 0x00, P_NONE, O_ESC      , {NOOP             , NOOP              , NOOP          }}, // DF
    */

    {OF_1BYTE, 0x00E0, 0x00, P_NONE, O_LOOPNE   , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // E0
    {OF_1BYTE, 0x00E1, 0x00, P_NONE, O_LOOPE    , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // E1
    {OF_1BYTE, 0x00E2, 0x00, P_NONE, O_LOOP     , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // E2
    {OF_1BYTE, 0x00E3, 0x00, P_NONE, O_JCXZ     , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // E3
    {OF_1BYTE, 0x00E4, 0x00, P_NONE, O_IN       , {MKREG(REG_AL)    , MKOP('I', 'b')    , NOOP          }}, // E4
    {OF_1BYTE, 0x00E5, 0x00, P_NONE, O_IN       , {MKREG(REG_E_AX)  , MKOP('I', 'b')    , NOOP          }}, // E5
    {OF_1BYTE, 0x00E6, 0x00, P_NONE, O_OUT      , {MKOP('I', 'b')   , MKREG(REG_AL)     , NOOP          }}, // E6
    {OF_1BYTE, 0x00E7, 0x00, P_NONE, O_OUT      , {MKOP('I', 'b')   , MKREG(REG_E_AX)   , NOOP          }}, // E7
    {OF_1BYTE, 0x00E8, 0x00, P_NONE, O_CALL     , {MKOP('J', 'v')   , NOOP              , NOOP          }}, // E8
    {OF_1BYTE, 0x00E9, 0x00, P_NONE, O_JMP      , {MKOP('J', 'v')   , NOOP              , NOOP          }}, // E9
    {OF_1BYTE, 0x00EA, 0x00, P_NONE, O_JMP      , {MKOP('A', 'p')   , NOOP              , NOOP          }}, // EA
    {OF_1BYTE, 0x00EB, 0x00, P_NONE, O_JMP      , {MKOP('J', 'b')   , NOOP              , NOOP          }}, // EB
    {OF_1BYTE, 0x00EC, 0x00, P_NONE, O_IN       , {MKREG(REG_AL)    , MKREG(REG_DX)     , NOOP          }}, // EC
    {OF_1BYTE, 0x00ED, 0x00, P_NONE, O_IN       , {MKREG(REG_E_AX)  , MKREG(REG_DX)     , NOOP          }}, // ED
    {OF_1BYTE, 0x00EE, 0x00, P_NONE, O_OUT      , {MKREG(REG_DX)    , MKREG(REG_AL)     , NOOP          }}, // EE
    {OF_1BYTE, 0x00EF, 0x00, P_NONE, O_OUT      , {MKREG(REG_DX)    , MKREG(REG_E_AX)   , NOOP          }}, // EF

    {OF_1BYTE, 0x00F0, 0x00, P_NONE, UNKOP},                                                                // F0
    {OF_1BYTE, 0x00F1, 0x00, P_NONE, UNKOP},                                                                // F1
    {OF_1BYTE, 0x00F2, 0x00, P_NONE, UNKOP},                                                                // F2
    {OF_1BYTE, 0x00F3, 0x00, P_NONE, UNKOP},                                                                // F3
    {OF_1BYTE, 0x00F4, 0x00, P_NONE, O_HLT      , {NOOP             , NOOP              , NOOP          }}, // F4
    {OF_1BYTE, 0x00F5, 0x00, P_NONE, O_CMC      , {NOOP             , NOOP              , NOOP          }}, // F5

    // Group 3.1
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00F6, 0x00, P_NONE,  O_TEST      , {MKOP('E', 'b')   , MKOP('I', 'b')    , NOOP          }}, // F6-000
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00F6, 0x01, P_NONE,  UNKOP}      ,                                                           // F6-001
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00F6, 0x02, P_NONE,  O_NOT       , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // F6-010
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00F6, 0x03, P_NONE,  O_NEG       , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // F6-011
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00F6, 0x04, P_NONE,  O_MUL       , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // F6-100
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00F6, 0x05, P_NONE,  O_IMUL      , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // F6-101
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00F6, 0x06, P_NONE,  O_DIV       , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // F6-110
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00F6, 0x07, P_NONE,  O_IDIV      , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // F6-111

    // Group 3.2
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00F7, 0x00, P_NONE,  O_TEST      , {MKOP('E', 'v')   , MKOP('I', 'v')    , NOOP          }}, // F7-000
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00F7, 0x01, P_NONE,  UNKOP}      ,                                                           // F7-001
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00F7, 0x02, P_NONE,  O_NOT       , {MKOP('E', 'v')   , NOOP              , NOOP          }}, // F7-010
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00F7, 0x03, P_NONE,  O_NEG       , {MKOP('E', 'v')   , NOOP              , NOOP          }}, // F7-011
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00F7, 0x04, P_NONE,  O_MUL       , {MKOP('E', 'v')   , NOOP              , NOOP          }}, // F7-100
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00F7, 0x05, P_NONE,  O_IMUL      , {MKOP('E', 'v')   , NOOP              , NOOP          }}, // F7-101
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00F7, 0x06, P_NONE,  O_DIV       , {MKOP('E', 'v')   , NOOP              , NOOP          }}, // F7-110
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00F7, 0x07, P_NONE,  O_IDIV      , {MKOP('E', 'v')   , NOOP              , NOOP          }}, // F7-111

    {OF_1BYTE, 0x00F8, 0x00, P_NONE, O_CLC      , {NOOP             , NOOP              , NOOP          }}, // F8
    {OF_1BYTE, 0x00F9, 0x00, P_NONE, O_STC      , {NOOP             , NOOP              , NOOP          }}, // F9
    {OF_1BYTE, 0x00FA, 0x00, P_NONE, O_CLI      , {NOOP             , NOOP              , NOOP          }}, // FA
    {OF_1BYTE, 0x00FB, 0x00, P_NONE, O_STI      , {NOOP             , NOOP              , NOOP          }}, // FB
    {OF_1BYTE, 0x00FC, 0x00, P_NONE, O_CLD      , {NOOP             , NOOP              , NOOP          }}, // FC
    {OF_1BYTE, 0x00FD, 0x00, P_NONE, O_STD      , {NOOP             , NOOP              , NOOP          }}, // FD

    // Group 4
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00FE, 0x00, P_NONE,  O_INC       , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // FE-000
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00FE, 0x01, P_NONE,  O_DEC       , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // FE-001
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00FE, 0x02, P_NONE,  UNKOP}      ,                                                           // FE-010
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00FE, 0x03, P_NONE,  UNKOP}      ,                                                           // FE-011
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00FE, 0x04, P_NONE,  UNKOP}      ,                                                           // FE-100
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00FE, 0x05, P_NONE,  UNKOP}      ,                                                           // FE-101
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00FE, 0x06, P_NONE,  UNKOP}      ,                                                           // FE-110
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00FE, 0x07, P_NONE,  UNKOP}      ,                                                           // FE-111

    // Group 5
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00FF, 0x00, P_NONE,  O_INC       , {MKOP('E', 'v')   , NOOP              , NOOP          }}, // FF-000
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00FF, 0x01, P_NONE,  O_DEC       , {MKOP('E', 'v')   , NOOP              , NOOP          }}, // FF-001
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00FF, 0x02, P_NONE,  O_CALL      , {MKOP('E', 'v')   , NOOP              , NOOP          }}, // FF-010
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00FF, 0x03, P_NONE,  O_CALLF     , {MKOP('E', 'p')   , NOOP              , NOOP          }}, // FF-011
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00FF, 0x04, P_NONE,  O_JMP       , {MKOP('E', 'v')   , NOOP              , NOOP          }}, // FF-100
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00FF, 0x05, P_NONE,  O_JMP       , {MKOP('E', 'p')   , NOOP              , NOOP          }}, // FF-101
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00FF, 0x06, P_NONE,  O_PUSH      , {MKOP('E', 'v')   , NOOP              , NOOP          }}, // FF-110
    {OF_1BYTE | OF_MRMBITS | OF_MODBOTH, 0x00FF, 0x07, P_NONE,  UNKOP}      ,                                                           // FF-111

    // Two-byte opcodes

    // NOTE: Older IA32 specification says SLDT takes Ev, new IA32 specification says
    // SLDT takes Ew.
    {OF_2BYTE | OF_MRMBITS | OF_MODBOTH, 0x000F, 0x00, P_NONE,  O_SLDT      , {MKOP('E', 'w')   , NOOP              , NOOP          }}, // 0F 00-000
    {OF_2BYTE | OF_MRMBITS | OF_MODBOTH, 0x000F, 0x01, P_NONE,  O_STR       , {MKOP('E', 'v')   , NOOP              , NOOP          }}, // 0F 00-001
    {OF_2BYTE | OF_MRMBITS | OF_MODBOTH, 0x000F, 0x02, P_NONE,  O_LLDT      , {MKOP('E', 'w')   , NOOP              , NOOP          }}, // 0F 00-010
    {OF_2BYTE | OF_MRMBITS | OF_MODBOTH, 0x000F, 0x03, P_NONE,  O_LTR       , {MKOP('E', 'w')   , NOOP              , NOOP          }}, // 0F 00-011
    {OF_2BYTE | OF_MRMBITS | OF_MODBOTH, 0x000F, 0x04, P_NONE,  O_VERR      , {MKOP('E', 'w')   , NOOP              , NOOP          }}, // 0F 00-100
    {OF_2BYTE | OF_MRMBITS | OF_MODBOTH, 0x000F, 0x05, P_NONE,  O_VERW      , {MKOP('E', 'w')   , NOOP              , NOOP          }}, // 0F 00-101
    {OF_2BYTE | OF_MRMBITS | OF_MODBOTH, 0x000F, 0x06, P_NONE,  UNKOP}      ,                                                           // 0F 00-110
    {OF_2BYTE | OF_MRMBITS | OF_MODBOTH, 0x000F, 0x07, P_NONE,  UNKOP}      ,                                                           // 0F 00-111

    {OF_2BYTE | OF_MRMBITS | OF_MODMEM , 0x010F, 0x00, P_NONE,  O_SGDT      , {MKOP('M', 's')   , NOOP              , NOOP          }}, // 0F 01-000 [mem]
    {OF_2BYTE | OF_MRMBITS | OF_MODMEM , 0x010F, 0x01, P_NONE,  O_SIDT      , {MKOP('M', 's')   , NOOP              , NOOP          }}, // 0F 01-001 [mem]
    // NOTE: Stupid Intel used the same opcode and the same MOD/REG bits to have
    // different instructions
    {OF_2BYTE | OF_MRMBITS | OF_MOD11  , 0x010F, 0x01, P_NONE,  O_MONITOR   , {NOOP             , NOOP              , NOOP          }}, // 0F 01-001 [11] (RM=000)
    {OF_2BYTE | OF_MRMBITS | OF_MOD11  , 0x010F, 0x01, P_NONE,  O_MWAIT     , {NOOP             , NOOP              , NOOP          }}, // 0F 01-001 [11] (RM=001)
    {OF_2BYTE | OF_MRMBITS | OF_MODMEM , 0x010F, 0x02, P_NONE,  O_LGDT      , {MKOP('M', 's')   , NOOP              , NOOP          }}, // 0F 01-010 [mem]
    {OF_2BYTE | OF_MRMBITS | OF_MODMEM , 0x010F, 0x03, P_NONE,  O_LIDT      , {MKOP('M', 's')   , NOOP              , NOOP          }}, // 0F 01-011 [mem]
    {OF_2BYTE | OF_MRMBITS | OF_MODBOTH, 0x010F, 0x04, P_NONE,  O_SMSW      , {MKOP('E', 'w')   , NOOP              , NOOP          }}, // 0F 01-100
    {OF_2BYTE | OF_MRMBITS | OF_MODBOTH, 0x010F, 0x05, P_NONE,  UNKOP}      ,                                                           // 0F 01-101
    {OF_2BYTE | OF_MRMBITS | OF_MODBOTH, 0x010F, 0x06, P_NONE,  O_LMSW      , {MKOP('E', 'w')   , NOOP              , NOOP          }}, // 0F 01-110
    {OF_2BYTE | OF_MRMBITS | OF_MODMEM , 0x010F, 0x07, P_NONE,  O_INVLPG    , {MKOP('M', 'b')   , NOOP              , NOOP          }}, // 0F 01-111 [mem]

    {OF_2BYTE, 0x020F, 0x00, P_NONE, O_LAR      , {MKOP('G', 'v')   , MKOP('E', 'w')    , NOOP          }}, // 0F 02
    {OF_2BYTE, 0x030F, 0x00, P_NONE, O_LSL      , {MKOP('G', 'v')   , MKOP('E', 'w')    , NOOP          }}, // 0F 03
    {OF_2BYTE, 0x040F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 04
    {OF_2BYTE, 0x050F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 05
    {OF_2BYTE, 0x060F, 0x00, P_NONE, O_CLTS     , {NOOP             , NOOP              , NOOP          }}, // 0F 06
    {OF_2BYTE, 0x070F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 07
    {OF_2BYTE, 0x080F, 0x00, P_NONE, O_INVD     , {NOOP             , NOOP              , NOOP          }}, // 0F 08
    {OF_2BYTE, 0x090F, 0x00, P_NONE, O_WBINVD   , {NOOP             , NOOP              , NOOP          }}, // 0F 09
    {OF_2BYTE, 0x0A0F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 0A
    {OF_2BYTE, 0x0B0F, 0x00, P_NONE, O_UD2      , {NOOP             , NOOP              , NOOP          }}, // 0F 0B
    {OF_2BYTE, 0x0C0F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 0C
    {OF_2BYTE, 0x0D0F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 0D
    {OF_2BYTE, 0x0E0F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 0E
    {OF_2BYTE, 0x0F0F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 0F

    // NOTE: Opcodes that have the OF_USEPREFIX flag must come BEFORE the same
    // opcodes without the flag.
    {OF_2BYTE | OF_USEPREFIX, 0x100F, 0x00, P_REPE, O_MOVSS, {MKOP('V', 'ss'), MKOP('W', 'ss'), NOOP    }}, // (F3) 0F 10
    {OF_2BYTE | OF_USEPREFIX, 0x100F, 0x00, P_OVERRIDE_OP, O_MOVUPD, {MKOP('V', 'pd'), MKOP('W', 'pd'), NOOP }}, // (66) 0F 10
    {OF_2BYTE | OF_USEPREFIX, 0x100F, 0x00, P_REPNE, O_MOVSD, {MKOP('V', 'sd'), MKOP('W', 'sd'), NOOP   }}, // (F2) 0F 10
    {OF_2BYTE, 0x100F, 0x00, P_NONE, O_MOVUPS   , {MKOP('V', 'ps')  , MKOP('W', 'ps')   , NOOP          }}, // 0F 10

    {OF_2BYTE | OF_USEPREFIX, 0x110F, 0x00, P_REPE, O_MOVSS, {MKOP('W', 'ss'), MKOP('V', 'ss'), NOOP    }}, // (F3) 0F 11
    {OF_2BYTE | OF_USEPREFIX, 0x110F, 0x00, P_OVERRIDE_OP, O_MOVUPD, {MKOP('W', 'pd'), MKOP('V', 'pd'), NOOP }}, // (66) 0F 11
    // Intel IA32 Specification Volume II had a mistake concering the following
    // instruction (operands were Vsd, Wsd -> same as (F2) 0F 10)
    {OF_2BYTE | OF_USEPREFIX, 0x110F, 0x00, P_REPNE, O_MOVSD, {MKOP('W', 'sd'), MKOP('V', 'sd'), NOOP   }}, // (F2) 0F 11
    {OF_2BYTE, 0x110F, 0x00, P_NONE, O_MOVUPS   , {MKOP('W', 'ps')  , MKOP('V', 'ps')   , NOOP          }}, // 0F 11

    {OF_2BYTE | OF_USEPREFIX, 0x120F, 0x00, P_REPE, O_MOVSLDUP, {MKOP('V', 'dq'), MKOP('W', 'dq'), NOOP }}, // (F3) 0F 12
    {OF_2BYTE | OF_USEPREFIX, 0x120F, 0x00, P_REPNE, O_MOVDDUP, {MKOP('V', 'dq'), MKOP('W', 'q'), NOOP }}, // (F2) 0F 12
    {OF_2BYTE | OF_USEPREFIX | OF_MRM_LEQ_BF, 0x120F, 0x00, P_OVERRIDE_OP, O_MOVLPD, {MKOP('V', 'q'), MKOP('W', 's'), NOOP }}, // (66) 0F 12 <= BF
    {OF_2BYTE | OF_USEPREFIX | OF_MRM_G_BF, 0x120F, 0x00, P_OVERRIDE_OP, O_MOVHLPS, {MKOP('V', 'q'), MKOP('V', 'q'), NOOP }}, // (66) 0F 12 > BF
    // Intel IA32 specification defines the next instruction's operands as 'Wq', 'Vq'
    // but they are supposed to be 'Vq', 'Wq'
    {OF_2BYTE | OF_MRM_LEQ_BF,  0x120F, 0x00, P_NONE, O_MOVLPS, {MKOP('V', 'q'), MKOP('W', 'q'), NOOP   }}, // 0F 12 <= BF
    {OF_2BYTE | OF_MRM_G_BF,    0x120F, 0x00, P_NONE, O_MOVHLPS, {MKOP('V', 'q'), MKOP('W', 'q'), NOOP  }}, // 0F 12 > BF

    // Intel IA32 specification defines the next instruction's operands as 'Vq', 'Wq'
    // but they are supposed to be 'Wq', 'Vq'
    // TODO: Intel now says these have 'Mq', 'Vq'.
    {OF_2BYTE | OF_USEPREFIX, 0x130F, 0x00, P_OVERRIDE_OP, O_MOVLPD, {MKOP('W', 'q'), MKOP('V', 'q'), NOOP }}, // (66) 0F 13
    {OF_2BYTE, 0x130F, 0x00, P_NONE, O_MOVLPS, {MKOP('W', 'q') , MKOP('V', 'q') , NOOP          }}, // 0F 13

    {OF_2BYTE | OF_USEPREFIX, 0x140F, 0x00, P_OVERRIDE_OP, O_UNPCKLPD, {MKOP('V', 'pd'), MKOP('W', 'q'), NOOP }}, // (66) 0F 14
    {OF_2BYTE, 0x140F, 0x00, P_NONE, O_UNPCKLPS, {MKOP('V', 'ps') , MKOP('W', 'q') , NOOP           }}, // 0F 14

    {OF_2BYTE | OF_USEPREFIX, 0x150F, 0x00, P_OVERRIDE_OP, O_UNPCKHPD, {MKOP('V', 'pd'), MKOP('W', 'q'), NOOP }}, // (66) 0F 15
    {OF_2BYTE, 0x150F, 0x00, P_NONE, O_UNPCKHPS, {MKOP('V', 'ps') , MKOP('W', 'q') , NOOP           }}, // 0F 15

    {OF_2BYTE | OF_USEPREFIX, 0x160F, 0x00, P_REPE, O_MOVSHDUP, {MKOP('V', 'dq'), MKOP('W', 'dq'), NOOP }}, // (F2) 0F 16
    {OF_2BYTE | OF_USEPREFIX | OF_MRM_LEQ_BF, 0x160F, 0x00, P_OVERRIDE_OP, O_MOVHPD, {MKOP('V', 'q'), MKOP('W', 'q'), NOOP }}, // (66) 0F 16 <= BF
    {OF_2BYTE | OF_USEPREFIX | OF_MRM_G_BF, 0x160F, 0x00, P_OVERRIDE_OP, O_MOVLHPS, {MKOP('V', 'q'), MKOP('V', 'q'), NOOP }}, // (66) 0F 16 > BF
    {OF_2BYTE | OF_MRM_LEQ_BF,  0x160F, 0x00, P_NONE, O_MOVHPS, {MKOP('V', 'q'), MKOP('W', 'q'), NOOP   }}, // 0F 16 <= BF
    {OF_2BYTE | OF_MRM_G_BF,    0x160F, 0x00, P_NONE, O_MOVLHPS, {MKOP('V', 'q'), MKOP('V', 'q'), NOOP  }}, // 0F 16 > BF

    {OF_2BYTE | OF_USEPREFIX, 0x170F, 0x00, P_OVERRIDE_OP, O_MOVHPD, {MKOP('W', 'q'), MKOP('V', 'q'), NOOP }}, // (66) 0F 17
    {OF_2BYTE, 0x170F, 0x00, P_NONE, O_MOVHPS, {MKOP('W', 'q') , MKOP('V', 'q') , NOOP          }}, // 0F 17

    // NOTE: Instruction groups that have the MOD bits to set to memory addressing
    // have 'Ev' operands
    {OF_2BYTE | OF_MRMBITS | OF_MODMEM, 0x180F, 0x00, P_NONE,   O_PREFETCHNTA       , {MKOP('E', 'v')   , NOOP      , NOOP }},  // 0F 18-000 [mem]
    {OF_2BYTE | OF_MRMBITS | OF_MODMEM, 0x180F, 0x01, P_NONE,   O_PREFETCHT0        , {MKOP('E', 'v')   , NOOP      , NOOP }},  // 0F 18-001 [mem]
    {OF_2BYTE | OF_MRMBITS | OF_MODMEM, 0x180F, 0x02, P_NONE,   O_PREFETCHT1        , {MKOP('E', 'v')   , NOOP      , NOOP }},  // 0F 18-010 [mem]
    {OF_2BYTE | OF_MRMBITS | OF_MODMEM, 0x180F, 0x03, P_NONE,   O_PREFETCHT2        , {MKOP('E', 'v')   , NOOP      , NOOP }},  // 0F 18-011 [mem]
    // 20050429
    {OF_2BYTE | OF_MRMBITS | OF_MODBOTH, 0x180F, 0x04, P_NONE,  UNKOP}      ,                                                   // 0F 18-100
    {OF_2BYTE | OF_MRMBITS | OF_MODBOTH, 0x180F, 0x05, P_NONE,  UNKOP}      ,                                                   // 0F 18-101
    {OF_2BYTE | OF_MRMBITS | OF_MODBOTH, 0x180F, 0x06, P_NONE,  UNKOP}      ,                                                   // 0F 18-110
    {OF_2BYTE | OF_MRMBITS | OF_MODBOTH, 0x180F, 0x07, P_NONE,  UNKOP}      ,                                                   // 0F 18-111

    {OF_2BYTE, 0x190F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 19
    {OF_2BYTE, 0x1A0F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 1A
    {OF_2BYTE, 0x1B0F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 1B
    {OF_2BYTE, 0x1C0F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 1C
    {OF_2BYTE, 0x1D0F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 1D
    {OF_2BYTE, 0x1E0F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 1E
    {OF_2BYTE, 0x1F0F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 1F

    {OF_2BYTE, 0x200F, 0x00, P_NONE, O_MOV      , {MKOP('R', 'd')   , MKOP('C', 'd')    , NOOP          }}, // 0F 20
    {OF_2BYTE, 0x210F, 0x00, P_NONE, O_MOV      , {MKOP('R', 'd')   , MKOP('D', 'd')    , NOOP          }}, // 0F 21
    {OF_2BYTE, 0x220F, 0x00, P_NONE, O_MOV      , {MKOP('C', 'd')   , MKOP('R', 'd')    , NOOP          }}, // 0F 22
    {OF_2BYTE, 0x230F, 0x00, P_NONE, O_MOV      , {MKOP('D', 'd')   , MKOP('R', 'd')    , NOOP          }}, // 0F 23
    {OF_2BYTE, 0x240F, 0x00, P_NONE, O_MOV      , {MKOP('R', 'd')   , MKOP('T', 'd')    , NOOP          }}, // 0F 24
    {OF_2BYTE, 0x250F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 25
    {OF_2BYTE, 0x260F, 0x00, P_NONE, O_MOV      , {MKOP('T', 'd')   , MKOP('R', 'd')    , NOOP          }}, // 0F 26
    {OF_2BYTE, 0x270F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 27

    {OF_2BYTE | OF_USEPREFIX, 0x280F, 0x00, P_OVERRIDE_OP, O_MOVAPD, {MKOP('V', 'pd'), MKOP('W', 'pd'), NOOP }}, // (66) 0F 28
    {OF_2BYTE, 0x280F, 0x00, P_NONE, O_MOVAPS, {MKOP('V', 'ps') , MKOP('W', 'ps') , NOOP            }}, // 0F 28

    {OF_2BYTE | OF_USEPREFIX, 0x290F, 0x00, P_OVERRIDE_OP, O_MOVAPD, {MKOP('W', 'pd'), MKOP('V', 'pd'), NOOP }}, // (66) 0F 29
    {OF_2BYTE, 0x290F, 0x00, P_NONE, O_MOVAPS, {MKOP('W', 'ps') , MKOP('V', 'ps') , NOOP            }}, // 0F 29

    {OF_2BYTE | OF_USEPREFIX, 0x2A0F, 0x00, P_OVERRIDE_OP, O_CVTPI2PD   , {MKOP('V', 'pd')  , MKOP('Q', 'dq')   , NOOP          }}, // (66) 0F 2A
    {OF_2BYTE | OF_USEPREFIX, 0x2A0F, 0x00, P_REPE, O_CVTSI2SS  , {MKOP('V', 'ss')  , MKOP('E', 'd')    , NOOP          }}, // (F3) 0F 2A
    {OF_2BYTE | OF_USEPREFIX, 0x2A0F, 0x00, P_REPNE, O_CVTSI2SD , {MKOP('V', 'sd')  , MKOP('E', 'd')    , NOOP          }}, // (F2) 0F 2A
    {OF_2BYTE, 0x2A0F, 0x00, P_NONE, O_CVTPI2PS , {MKOP('V', 'ps')  , MKOP('Q', 'q')    , NOOP          }}, // 0F 2A

    {OF_2BYTE | OF_USEPREFIX, 0x2B0F, 0x00, P_OVERRIDE_OP, O_MOVNTPD, {MKOP('W', 'pd')  , MKOP('V', 'pd'), NOOP         }}, // (66) 0F 2B
    {OF_2BYTE, 0x2B0F, 0x00, P_NONE, O_MOVNTPS  , {MKOP('W', 'ps')  , MKOP('V', 'ps')   , NOOP          }}, // 0F 2B

    // NOTE: This is a special case, as the MOD bits of the ModR/M refer to the seconda operand and
    // not the first (the first is always a register)
    // TODO: Intel defines other operand/addressingmode types.
    {OF_2BYTE | OF_USEPREFIX, 0x2C0F, 0x00, P_OVERRIDE_OP, O_CVTTPD2PI, {MKOP('Q', 'dq'), MKOP('W', 'pd'), NOOP         }}, // (66) 0F 2C
    {OF_2BYTE | OF_USEPREFIX, 0x2C0F, 0x00, P_REPE, O_CVTTSS2SI, {MKOP('G', 'd'), MKOP('W', 'ss'), NOOP         }}, // (F3) 0F 2C
    {OF_2BYTE | OF_USEPREFIX, 0x2C0F, 0x00, P_REPNE, O_CVTTSD2SI, {MKOP('G', 'd'), MKOP('W', 'sd'), NOOP            }}, // (F2) 0F 2C
    {OF_2BYTE, 0x2C0F, 0x00, P_NONE, O_CVTTPS2PI, {MKOP('Q', 'q')   , MKOP('W', 'ps')   , NOOP          }}, // 0F 2C

    {OF_2BYTE | OF_USEPREFIX, 0x2D0F, 0x00, P_OVERRIDE_OP, O_CVTPD2PI, {MKOP('Q', 'dq'), MKOP('W', 'pd'), NOOP          }}, // (66) 0F 2D
    {OF_2BYTE | OF_USEPREFIX, 0x2D0F, 0x00, P_REPE, O_CVTSS2SI, {MKOP('G', 'd'), MKOP('W', 'ss'), NOOP          }}, // (F3) 0F 2D
    {OF_2BYTE | OF_USEPREFIX, 0x2D0F, 0x00, P_REPNE, O_CVTSD2SI, {MKOP('G', 'd'), MKOP('W', 'sd'), NOOP         }}, // (F2) 0F 2D
    {OF_2BYTE, 0x2D0F, 0x00, P_NONE, O_CVTPS2PI, {MKOP('Q', 'q')    , MKOP('W', 'ps')   , NOOP          }}, // 0F 2D

    {OF_2BYTE | OF_USEPREFIX, 0x2E0F, 0x00, P_OVERRIDE_OP, O_UCOMISD    , {MKOP('V', 'sd')  , MKOP('W', 'sd')   , NOOP          }}, // (66) 0F 2E
    {OF_2BYTE, 0x2E0F, 0x00, P_NONE, O_UCOMISS  , {MKOP('V', 'ss')  , MKOP('W', 'ss')   , NOOP          }}, // 0F 2E

    {OF_2BYTE | OF_USEPREFIX, 0x2F0F, 0x00, P_OVERRIDE_OP, O_COMISD , {MKOP('V', 'sd')  , MKOP('W', 'sd')   , NOOP          }}, // (66) 0F 2F
    {OF_2BYTE, 0x2F0F, 0x00, P_NONE, O_COMISS   , {MKOP('V', 'ps')  , MKOP('W', 'ps')   , NOOP          }}, // 0F 2F

    {OF_2BYTE, 0x300F, 0x00, P_NONE, O_WRMSR    , {NOOP             , NOOP              , NOOP          }}, // 0F 30
    {OF_2BYTE, 0x310F, 0x00, P_NONE, O_RDTSC    , {NOOP             , NOOP              , NOOP          }}, // 0F 31
    {OF_2BYTE, 0x320F, 0x00, P_NONE, O_RDMSR    , {NOOP             , NOOP              , NOOP          }}, // 0F 32
    {OF_2BYTE, 0x330F, 0x00, P_NONE, O_RDPMC    , {NOOP             , NOOP              , NOOP          }}, // 0F 33
    {OF_2BYTE, 0x340F, 0x00, P_NONE, O_SYSENTER , {NOOP             , NOOP              , NOOP          }}, // 0F 34
    {OF_2BYTE, 0x350F, 0x00, P_NONE, O_SYSEXIT  , {NOOP             , NOOP              , NOOP          }}, // 0F 35
    {OF_2BYTE, 0x360F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 36
    {OF_2BYTE, 0x370F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 37

    {OF_2BYTE, 0x380F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 38
    {OF_2BYTE, 0x390F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 39
    {OF_2BYTE, 0x3A0F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 3A
    {OF_2BYTE, 0x3B0F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 3B
    // NOTE: This instruction appears in the Intel specification tables, but not in
    // HIEW or IDA's disassemblers.
    // TODO: Now it doesn't. What the fuck?
    {OF_2BYTE, 0x3C0F, 0x00, P_NONE, O_MOVNTI   , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F 3C
    {OF_2BYTE, 0x3D0F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 3D
    {OF_2BYTE, 0x3E0F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 3E
    {OF_2BYTE, 0x3F0F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F 3F

    {OF_2BYTE, 0x400F, 0x00, P_NONE, O_CMOVO    , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F 40
    {OF_2BYTE, 0x410F, 0x00, P_NONE, O_CMOVNO   , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F 41
    {OF_2BYTE, 0x420F, 0x00, P_NONE, O_CMOVB    , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F 42
    {OF_2BYTE, 0x430F, 0x00, P_NONE, O_CMOVAE   , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F 43
    {OF_2BYTE, 0x440F, 0x00, P_NONE, O_CMOVE    , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F 44
    {OF_2BYTE, 0x450F, 0x00, P_NONE, O_CMOVNE   , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F 45
    {OF_2BYTE, 0x460F, 0x00, P_NONE, O_CMOVBE   , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F 46
    {OF_2BYTE, 0x470F, 0x00, P_NONE, O_CMOVA    , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F 47

    {OF_2BYTE, 0x480F, 0x00, P_NONE, O_CMOVS    , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F 48
    {OF_2BYTE, 0x490F, 0x00, P_NONE, O_CMOVNS   , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F 49
    {OF_2BYTE, 0x4A0F, 0x00, P_NONE, O_CMOVP    , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F 4A
    {OF_2BYTE, 0x4B0F, 0x00, P_NONE, O_CMOVNP   , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F 4B
    {OF_2BYTE, 0x4C0F, 0x00, P_NONE, O_CMOVL    , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F 4C
    {OF_2BYTE, 0x4D0F, 0x00, P_NONE, O_CMOVNL   , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F 4D
    {OF_2BYTE, 0x4E0F, 0x00, P_NONE, O_CMOVLE   , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F 4E
    {OF_2BYTE, 0x4F0F, 0x00, P_NONE, O_CMOVNLE  , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F 4F

    // NOTE: The HIEW disassembler doesn't interpret the following two instructions
    // correctly, the IDA disassembler does.
    // TODO: Intel now uses 'Gd' instead of 'Ed'.
    {OF_2BYTE | OF_USEPREFIX, 0x500F, 0x00, P_OVERRIDE_OP, O_MOVMSKPD       , {MKOP('E', 'd')       , MKOP('V', 'pd')   , NOOP          }}, // (66) 0F 50
    {OF_2BYTE, 0x500F, 0x00, P_NONE, O_MOVMSKPS , {MKOP('E', 'd')   , MKOP('V', 'ps')   , NOOP          }}, // 0F 50

    {OF_2BYTE | OF_USEPREFIX, 0x510F, 0x00, P_OVERRIDE_OP   , O_SQRTPD      , {MKOP('V', 'pd')  , MKOP('W', 'pd')   , NOOP          }}, // (66) 0F 51
    {OF_2BYTE | OF_USEPREFIX, 0x510F, 0x00, P_REPE          , O_SQRTSS      , {MKOP('V', 'ss')  , MKOP('W', 'ss')   , NOOP          }}, // (F3) 0F 51
    {OF_2BYTE | OF_USEPREFIX, 0x510F, 0x00, P_REPNE         , O_SQRTSD      , {MKOP('V', 'sd')  , MKOP('W', 'sd')   , NOOP          }}, // (F2) 0F 51
    {OF_2BYTE, 0x510F, 0x00, P_NONE, O_SQRTPS   , {MKOP('V', 'ps')  , MKOP('W', 'ps')   , NOOP          }}, // 0F 51

    {OF_2BYTE | OF_USEPREFIX, 0x520F, 0x00, P_REPE          , O_RSQRTSS     , {MKOP('V', 'ss')  , MKOP('W', 'ss')   , NOOP          }}, // (F3) 0F 52
    {OF_2BYTE, 0x520F, 0x00, P_NONE, O_RSQRTPS  , {MKOP('V', 'ps')  , MKOP('W', 'ps')   , NOOP          }}, // 0F 52

    {OF_2BYTE | OF_USEPREFIX, 0x530F, 0x00, P_REPE          , O_RCPSS       , {MKOP('V', 'ss')  , MKOP('W', 'ss')   , NOOP          }}, // (F3) 0F 53
    {OF_2BYTE, 0x530F, 0x00, P_NONE, O_RCPPS    , {MKOP('V', 'ps')  , MKOP('W', 'ps')   , NOOP          }}, // 0F 53

    {OF_2BYTE | OF_USEPREFIX, 0x540F, 0x00, P_OVERRIDE_OP   , O_ANDPD       , {MKOP('V', 'pd')  , MKOP('W', 'pd')   , NOOP          }}, // (66) 0F 54
    {OF_2BYTE, 0x540F, 0x00, P_NONE, O_ANDPS    , {MKOP('V', 'ps')  , MKOP('W', 'ps')   , NOOP          }}, // 0F 54

    {OF_2BYTE | OF_USEPREFIX, 0x550F, 0x00, P_OVERRIDE_OP   , O_ANDNPD      , {MKOP('V', 'pd')  , MKOP('W', 'pd')   , NOOP          }}, // (66) 0F 55
    {OF_2BYTE, 0x550F, 0x00, P_NONE, O_ANDNPS   , {MKOP('V', 'ps')  , MKOP('W', 'ps')   , NOOP          }}, // 0F 55

    {OF_2BYTE | OF_USEPREFIX, 0x560F, 0x00, P_OVERRIDE_OP   , O_ORPD        , {MKOP('V', 'pd')  , MKOP('W', 'pd')   , NOOP          }}, // (66) 0F 56
    {OF_2BYTE, 0x560F, 0x00, P_NONE, O_ORPS     , {MKOP('V', 'ps')  , MKOP('W', 'ps')   , NOOP          }}, // 0F 56

    {OF_2BYTE | OF_USEPREFIX, 0x570F, 0x00, P_OVERRIDE_OP   , O_XORPD       , {MKOP('V', 'pd')  , MKOP('W', 'pd')   , NOOP          }}, // (66) 0F 57
    {OF_2BYTE, 0x570F, 0x00, P_NONE, O_XORPS    , {MKOP('V', 'ps')  , MKOP('W', 'ps')   , NOOP          }}, // 0F 57

    {OF_2BYTE | OF_USEPREFIX, 0x580F, 0x00, P_OVERRIDE_OP   , O_ADDPD       , {MKOP('V', 'pd')  , MKOP('W', 'pd')   , NOOP          }}, // (66) 0F 58
    {OF_2BYTE | OF_USEPREFIX, 0x580F, 0x00, P_REPE          , O_ADDSS       , {MKOP('V', 'ss')  , MKOP('W', 'ss')   , NOOP          }}, // (F3) 0F 58
    {OF_2BYTE | OF_USEPREFIX, 0x580F, 0x00, P_REPNE         , O_ADDSD       , {MKOP('V', 'sd')  , MKOP('W', 'sd')   , NOOP          }}, // (F2) 0F 58
    {OF_2BYTE, 0x580F, 0x00, P_NONE, O_ADDPS    , {MKOP('V', 'ps')  , MKOP('W', 'ps')   , NOOP          }}, // 0F 58

    {OF_2BYTE | OF_USEPREFIX, 0x590F, 0x00, P_OVERRIDE_OP   , O_MULPD       , {MKOP('V', 'pd')  , MKOP('W', 'pd')   , NOOP          }}, // (66) 0F 59
    {OF_2BYTE | OF_USEPREFIX, 0x590F, 0x00, P_REPE          , O_MULSS       , {MKOP('V', 'ss')  , MKOP('W', 'ss')   , NOOP          }}, // (F3) 0F 59
    {OF_2BYTE | OF_USEPREFIX, 0x590F, 0x00, P_REPNE         , O_MULSD       , {MKOP('V', 'sd')  , MKOP('W', 'sd')   , NOOP          }}, // (F2) 0F 59
    {OF_2BYTE, 0x590F, 0x00, P_NONE, O_MULPS    , {MKOP('V', 'ps')  , MKOP('W', 'ps')   , NOOP          }}, // 0F 59

    {OF_2BYTE | OF_USEPREFIX, 0x5A0F, 0x00, P_OVERRIDE_OP   , O_CVTPD2PS    , {MKOP('V', 'ps')  , MKOP('W', 'pd')   , NOOP          }}, // (66) 0F 5A
    {OF_2BYTE | OF_USEPREFIX, 0x5A0F, 0x00, P_REPE          , O_CVTSS2SD    , {MKOP('V', 'ss')  , MKOP('W', 'ss')   , NOOP          }}, // (F3) 0F 5A
    {OF_2BYTE | OF_USEPREFIX, 0x5A0F, 0x00, P_REPNE         , O_CVTSD2SS    , {MKOP('V', 'sd')  , MKOP('W', 'sd')   , NOOP          }}, // (F2) 0F 5A
    {OF_2BYTE, 0x5A0F, 0x00, P_NONE, O_CVTPS2PD , {MKOP('V', 'pd')  , MKOP('W', 'ps')   , NOOP          }}, // 0F 5A

    {OF_2BYTE | OF_USEPREFIX, 0x5B0F, 0x00, P_OVERRIDE_OP   , O_CVTPS2DQ    , {MKOP('V', 'dq')  , MKOP('W', 'ps')   , NOOP          }}, // (66) 0F 5B
    {OF_2BYTE | OF_USEPREFIX, 0x5B0F, 0x00, P_REPE          , O_CVTTPS2DQ   , {MKOP('V', 'dq')  , MKOP('W', 'ps')   , NOOP          }}, // (F3) 0F 5B
    {OF_2BYTE, 0x5B0F, 0x00, P_NONE, O_CVTDQ2PS , {MKOP('V', 'ps')  , MKOP('W', 'dq')   , NOOP          }}, // 0F 5B

    {OF_2BYTE | OF_USEPREFIX, 0x5C0F, 0x00, P_OVERRIDE_OP   , O_SUBPD       , {MKOP('V', 'pd')  , MKOP('W', 'pd')   , NOOP          }}, // (66) 0F 5C
    {OF_2BYTE | OF_USEPREFIX, 0x5C0F, 0x00, P_REPE          , O_SUBSS       , {MKOP('V', 'ss')  , MKOP('W', 'ss')   , NOOP          }}, // (F3) 0F 5C
    {OF_2BYTE | OF_USEPREFIX, 0x5C0F, 0x00, P_REPNE         , O_SUBSD       , {MKOP('V', 'sd')  , MKOP('W', 'sd')   , NOOP          }}, // (F2) 0F 5C
    {OF_2BYTE, 0x5C0F, 0x00, P_NONE, O_SUBPS    , {MKOP('V', 'ps')  , MKOP('W', 'ps')   , NOOP          }}, // 0F 5C

    {OF_2BYTE | OF_USEPREFIX, 0x5D0F, 0x00, P_OVERRIDE_OP   , O_MINPD       , {MKOP('V', 'pd')  , MKOP('W', 'pd')   , NOOP          }}, // (66) 0F 5D
    {OF_2BYTE | OF_USEPREFIX, 0x5D0F, 0x00, P_REPE          , O_MINSS       , {MKOP('V', 'ss')  , MKOP('W', 'ss')   , NOOP          }}, // (F3) 0F 5D
    {OF_2BYTE | OF_USEPREFIX, 0x5D0F, 0x00, P_REPNE         , O_MINSD       , {MKOP('V', 'sd')  , MKOP('W', 'sd')   , NOOP          }}, // (F2) 0F 5D
    {OF_2BYTE, 0x5D0F, 0x00, P_NONE, O_MINPS    , {MKOP('V', 'ps')  , MKOP('W', 'ps')   , NOOP          }}, // 0F 5D

    {OF_2BYTE | OF_USEPREFIX, 0x5E0F, 0x00, P_OVERRIDE_OP   , O_DIVPD       , {MKOP('V', 'pd')  , MKOP('W', 'pd')   , NOOP          }}, // (66) 0F 5E
    {OF_2BYTE | OF_USEPREFIX, 0x5E0F, 0x00, P_REPE          , O_DIVSS       , {MKOP('V', 'ss')  , MKOP('W', 'ss')   , NOOP          }}, // (F3) 0F 5E
    {OF_2BYTE | OF_USEPREFIX, 0x5E0F, 0x00, P_REPNE         , O_DIVSD       , {MKOP('V', 'sd')  , MKOP('W', 'sd')   , NOOP          }}, // (F2) 0F 5E
    {OF_2BYTE, 0x5E0F, 0x00, P_NONE, O_DIVPS    , {MKOP('V', 'ps')  , MKOP('W', 'ps')   , NOOP          }}, // 0F 5E

    {OF_2BYTE | OF_USEPREFIX, 0x5F0F, 0x00, P_OVERRIDE_OP   , O_MAXPD       , {MKOP('V', 'pd')  , MKOP('W', 'pd')   , NOOP          }}, // (66) 0F 5F
    {OF_2BYTE | OF_USEPREFIX, 0x5F0F, 0x00, P_REPE          , O_MAXSS       , {MKOP('V', 'ss')  , MKOP('W', 'ss')   , NOOP          }}, // (F3) 0F 5F
    {OF_2BYTE | OF_USEPREFIX, 0x5F0F, 0x00, P_REPNE         , O_MAXSD       , {MKOP('V', 'sd')  , MKOP('W', 'sd')   , NOOP          }}, // (F2) 0F 5F
    {OF_2BYTE, 0x5F0F, 0x00, P_NONE, O_MAXPS    , {MKOP('V', 'ps')  , MKOP('W', 'ps')   , NOOP          }}, // 0F 5F

    {OF_2BYTE | OF_USEPREFIX, 0x600F, 0x00, P_OVERRIDE_OP   , O_PUNPCKLBW   , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F 60
    {OF_2BYTE, 0x600F, 0x00, P_NONE, O_PUNPCKLBW, {MKOP('P', 'q')   , MKOP('Q', 'd')    , NOOP          }}, // 0F 60

    {OF_2BYTE | OF_USEPREFIX, 0x610F, 0x00, P_OVERRIDE_OP   , O_PUNPCKLWD   , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F 61
    {OF_2BYTE, 0x610F, 0x00, P_NONE, O_PUNPCKLWD, {MKOP('P', 'q')   , MKOP('Q', 'd')    , NOOP          }}, // 0F 61

    {OF_2BYTE | OF_USEPREFIX, 0x620F, 0x00, P_OVERRIDE_OP   , O_PUNPCKLDQ   , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F 62
    {OF_2BYTE, 0x620F, 0x00, P_NONE, O_PUNPCKLDQ, {MKOP('P', 'q')   , MKOP('Q', 'd')    , NOOP          }}, // 0F 62

    {OF_2BYTE | OF_USEPREFIX, 0x630F, 0x00, P_OVERRIDE_OP   , O_PACKSSWB    , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F 63
    {OF_2BYTE, 0x630F, 0x00, P_NONE, O_PACKSSWB , {MKOP('P', 'q')   , MKOP('Q', 'd')    , NOOP          }}, // 0F 63

    {OF_2BYTE | OF_USEPREFIX, 0x640F, 0x00, P_OVERRIDE_OP   , O_PCMPGTB     , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F 64
    {OF_2BYTE, 0x640F, 0x00, P_NONE, O_PCMPGTB  , {MKOP('P', 'q')   , MKOP('Q', 'd')    , NOOP          }}, // 0F 64

    {OF_2BYTE | OF_USEPREFIX, 0x650F, 0x00, P_OVERRIDE_OP   , O_PCMPGTW     , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F 65
    {OF_2BYTE, 0x650F, 0x00, P_NONE, O_PCMPGTW  , {MKOP('P', 'q')   , MKOP('Q', 'd')    , NOOP          }}, // 0F 65

    {OF_2BYTE | OF_USEPREFIX, 0x660F, 0x00, P_OVERRIDE_OP   , O_PCMPGTD     , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F 66
    {OF_2BYTE, 0x660F, 0x00, P_NONE, O_PCMPGTD  , {MKOP('P', 'q')   , MKOP('Q', 'd')    , NOOP          }}, // 0F 66

    {OF_2BYTE | OF_USEPREFIX, 0x670F, 0x00, P_OVERRIDE_OP   , O_PACKUSWB    , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F 67
    {OF_2BYTE, 0x670F, 0x00, P_NONE, O_PACKUSWB , {MKOP('P', 'q')   , MKOP('Q', 'd')    , NOOP          }}, // 0F 67

    {OF_2BYTE | OF_USEPREFIX, 0x680F, 0x00, P_OVERRIDE_OP   , O_PUNPCKHBW   , {MKOP('P', 'dq')  , MKOP('Q', 'dq')   , NOOP          }}, // (66) 0F 68
    {OF_2BYTE, 0x680F, 0x00, P_NONE, O_PUNPCKHBW, {MKOP('P', 'q')   , MKOP('Q', 'd')    , NOOP          }}, // 0F 68

    {OF_2BYTE | OF_USEPREFIX, 0x690F, 0x00, P_OVERRIDE_OP   , O_PUNPCKHWD   , {MKOP('P', 'dq')  , MKOP('Q', 'dq')   , NOOP          }}, // (66) 0F 69
    {OF_2BYTE, 0x690F, 0x00, P_NONE, O_PUNPCKHWD, {MKOP('P', 'q')   , MKOP('Q', 'd')    , NOOP          }}, // 0F 69

    {OF_2BYTE | OF_USEPREFIX, 0x6A0F, 0x00, P_OVERRIDE_OP   , O_PUNPCKHDQ   , {MKOP('P', 'dq')  , MKOP('Q', 'dq')   , NOOP          }}, // (66) 0F 6A
    {OF_2BYTE, 0x6A0F, 0x00, P_NONE, O_PUNPCKHDQ, {MKOP('P', 'q')   , MKOP('Q', 'd')    , NOOP          }}, // 0F 6A

    {OF_2BYTE | OF_USEPREFIX, 0x6B0F, 0x00, P_OVERRIDE_OP   , O_PACKSSDW    , {MKOP('P', 'dq')  , MKOP('Q', 'dq')   , NOOP          }}, // (66) 0F 6B
    {OF_2BYTE, 0x6B0F, 0x00, P_NONE, O_PACKSSDW, {MKOP('P', 'q')    , MKOP('Q', 'd')    , NOOP          }}, // 0F 6B

    {OF_2BYTE | OF_USEPREFIX, 0x6C0F, 0x00, P_OVERRIDE_OP   , O_PUNPCKLQDQ  , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F 6C

    {OF_2BYTE | OF_USEPREFIX, 0x6D0F, 0x00, P_OVERRIDE_OP   , O_PUNPCKHQDQ  , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F 6D

    {OF_2BYTE | OF_USEPREFIX, 0x6E0F, 0x00, P_OVERRIDE_OP   , O_MOVD        , {MKOP('V', 'dq')  , MKOP('E', 'd')    , NOOP          }}, // (66) 0F 6E
    {OF_2BYTE, 0x6E0F, 0x00, P_NONE, O_MOVD     , {MKOP('P', 'd')   , MKOP('E', 'd')    , NOOP          }}, // 0F 6E

    {OF_2BYTE | OF_USEPREFIX, 0x6F0F, 0x00, P_OVERRIDE_OP   , O_MOVDQA      , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F 6F
    {OF_2BYTE | OF_USEPREFIX, 0x6F0F, 0x00, P_REPE          , O_MOVDQU      , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (F3) 0F 6F
    {OF_2BYTE, 0x6F0F, 0x00, P_NONE, O_MOVQ     , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F 6F

    {OF_2BYTE | OF_USEPREFIX, 0x700F, 0x00, P_OVERRIDE_OP   , O_PSHUFD      , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , MKOP('I', 'b')}}, // (66) 0F 70
    {OF_2BYTE | OF_USEPREFIX, 0x700F, 0x00, P_REPE          , O_PSHUFHW     , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , MKOP('I', 'b')}}, // (73) 0F 70
    {OF_2BYTE | OF_USEPREFIX, 0x700F, 0x00, P_REPNE         , O_PSHUFLW     , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , MKOP('I', 'b')}}, // (72) 0F 70
    {OF_2BYTE, 0x700F, 0x00, P_NONE, O_PSHUFW   , {MKOP('P', 'q')   , MKOP('Q', 'q')    , MKOP('I', 'b')}}, // 0F 70

    {OF_2BYTE | OF_MRMBITS | OF_USEPREFIX | OF_MOD11, 0x710F, 0x02, P_OVERRIDE_OP, O_PSRLW  , {MKOP('P', 'dq')  , MKOP('I', 'b')    , NOOP          }}, // (66) 0F 71-010 [11]
    {OF_2BYTE | OF_MRMBITS | OF_USEPREFIX | OF_MOD11, 0x710F, 0x04, P_OVERRIDE_OP, O_PSRAW  , {MKOP('P', 'dq')  , MKOP('I', 'b')    , NOOP          }}, // (66) 0F 71-100 [11]
    {OF_2BYTE | OF_MRMBITS | OF_USEPREFIX | OF_MOD11, 0x710F, 0x06, P_OVERRIDE_OP, O_PSLLW  , {MKOP('P', 'dq')  , MKOP('I', 'b')    , NOOP          }}, // (66) 0F 71-110 [11]
    {OF_2BYTE | OF_MRMBITS | OF_MOD11, 0x710F, 0x02, P_NONE, O_PSRLW    , {MKOP('P', 'q')   , MKOP('I', 'b')    , NOOP          }}, // 0F 71-010 [11]
    {OF_2BYTE | OF_MRMBITS | OF_MOD11, 0x710F, 0x04, P_NONE, O_PSRAW    , {MKOP('P', 'q')   , MKOP('I', 'b')    , NOOP          }}, // 0F 71-100 [11]
    {OF_2BYTE | OF_MRMBITS | OF_MOD11, 0x710F, 0x06, P_NONE, O_PSLLW    , {MKOP('P', 'q')   , MKOP('I', 'b')    , NOOP          }}, // 0F 71-110 [11]

    // Note: The Intel specification says the next several instructions have 'Wdq'
    // as first operand, however HIEW confirms the usage of 'Pdq' operand type
    // (like 0x710F)
    {OF_2BYTE | OF_MRMBITS | OF_USEPREFIX | OF_MOD11, 0x720F, 0x02, P_OVERRIDE_OP, O_PSRLD  , {MKOP('P', 'dq')  , MKOP('I', 'b')    , NOOP          }}, // (66) 0F 72-010 [11]
    {OF_2BYTE | OF_MRMBITS | OF_USEPREFIX | OF_MOD11, 0x720F, 0x04, P_OVERRIDE_OP, O_PSRAD  , {MKOP('P', 'dq')  , MKOP('I', 'b')    , NOOP          }}, // (66) 0F 72-100 [11]
    {OF_2BYTE | OF_MRMBITS | OF_USEPREFIX | OF_MOD11, 0x720F, 0x06, P_OVERRIDE_OP, O_PSLLD  , {MKOP('P', 'dq')  , MKOP('I', 'b')    , NOOP          }}, // (66) 0F 72-110 [11]
    {OF_2BYTE | OF_MRMBITS | OF_MOD11, 0x720F, 0x02, P_NONE, O_PSRLD    , {MKOP('P', 'q')   , MKOP('I', 'b')    , NOOP          }}, // 0F 72-010 [11]
    {OF_2BYTE | OF_MRMBITS | OF_MOD11, 0x720F, 0x04, P_NONE, O_PSRAD    , {MKOP('P', 'q')   , MKOP('I', 'b')    , NOOP          }}, // 0F 72-100 [11]
    {OF_2BYTE | OF_MRMBITS | OF_MOD11, 0x720F, 0x06, P_NONE, O_PSLLD    , {MKOP('P', 'q')   , MKOP('I', 'b')    , NOOP          }}, // 0F 72-110 [11]

    {OF_2BYTE | OF_MRMBITS | OF_USEPREFIX | OF_MOD11, 0x730F, 0x02, P_OVERRIDE_OP, O_PSRLQ  , {MKOP('P', 'dq')  , MKOP('I', 'b')    , NOOP          }}, // (66) 0F 73-010 [11]
    {OF_2BYTE | OF_MRMBITS | OF_USEPREFIX | OF_MOD11, 0x730F, 0x03, P_OVERRIDE_OP, O_PSRLDQ, {MKOP('P', 'dq')   , MKOP('I', 'b')    , NOOP          }}, // (66) 0F 73-011 [11]
    {OF_2BYTE | OF_MRMBITS | OF_USEPREFIX | OF_MOD11, 0x730F, 0x06, P_OVERRIDE_OP, O_PSLLQ  , {MKOP('P', 'dq')  , MKOP('I', 'b')    , NOOP          }}, // (66) 0F 73-110 [11]
    {OF_2BYTE | OF_MRMBITS | OF_USEPREFIX | OF_MOD11, 0x730F, 0x07, P_OVERRIDE_OP, O_PSLLDQ, {MKOP('P', 'dq')   , MKOP('I', 'b')    , NOOP          }}, // (66) 0F 73-111 [11]
    {OF_2BYTE | OF_MRMBITS | OF_MOD11, 0x730F, 0x02, P_NONE, O_PSRLQ    , {MKOP('P', 'q')   , MKOP('I', 'b')    , NOOP          }}, // 0F 73-010 [11]
    {OF_2BYTE | OF_MRMBITS | OF_MOD11, 0x730F, 0x06, P_NONE, O_PSLLQ    , {MKOP('P', 'q')   , MKOP('I', 'b')    , NOOP          }}, // 0F 73-110 [11]

    {OF_2BYTE | OF_USEPREFIX, 0x740F, 0x00, P_OVERRIDE_OP   , O_PCMPEQB     , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F 74
    {OF_2BYTE, 0x740F, 0x00, P_NONE, O_PCMPEQB  , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F 74

    {OF_2BYTE | OF_USEPREFIX, 0x750F, 0x00, P_OVERRIDE_OP   , O_PCMPEQW     , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F 75
    {OF_2BYTE, 0x750F, 0x00, P_NONE, O_PCMPEQW  , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F 75

    {OF_2BYTE | OF_USEPREFIX, 0x760F, 0x00, P_OVERRIDE_OP   , O_PCMPEQD     , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F 76
    {OF_2BYTE, 0x760F, 0x00, P_NONE, O_PCMPEQD  , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F 76

    {OF_2BYTE, 0x770F, 0x00, P_NONE, O_EMMS     , {NOOP             , NOOP              , NOOP          }}, // 0F 77

    {OF_2BYTE, 0x780F, 0x00, P_NONE, O_MMXUD    , {NOOP             , NOOP              , NOOP          }}, // 0F 78
    {OF_2BYTE, 0x790F, 0x00, P_NONE, O_MMXUD    , {NOOP             , NOOP              , NOOP          }}, // 0F 79
    {OF_2BYTE, 0x7A0F, 0x00, P_NONE, O_MMXUD    , {NOOP             , NOOP              , NOOP          }}, // 0F 7A
    {OF_2BYTE, 0x7B0F, 0x00, P_NONE, O_MMXUD    , {NOOP             , NOOP              , NOOP          }}, // 0F 7B

    {OF_2BYTE | OF_USEPREFIX, 0x7C0F, 0x00, P_OVERRIDE_OP, O_HADDPD, {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F 7C
    {OF_2BYTE | OF_USEPREFIX, 0x7C0F, 0x00, P_REPNE, O_HADDPS, {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (F2) 0F 7C
    {OF_2BYTE, 0x7C0F, 0x00, P_NONE, O_MMXUD    , {NOOP             , NOOP              , NOOP          }}, // 0F 7C

    {OF_2BYTE | OF_USEPREFIX, 0x7D0F, 0x00, P_OVERRIDE_OP, O_HSUBPD, {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F 7D
    {OF_2BYTE | OF_USEPREFIX, 0x7D0F, 0x00, P_REPNE, O_HSUBPS, {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (F2) 0F 7D
    {OF_2BYTE, 0x7D0F, 0x00, P_NONE, O_MMXUD    , {NOOP             , NOOP              , NOOP          }}, // 0F 7D

    {OF_2BYTE | OF_USEPREFIX, 0x7E0F, 0x00, P_OVERRIDE_OP   , O_MOVD    , {MKOP('E', 'd')   , MKOP('V', 'dq')   , NOOP          }}, // (66) 0F 7E
    {OF_2BYTE | OF_USEPREFIX, 0x7E0F, 0x00, P_REPE          , O_MOVQ    , {MKOP('V', 'q')   , MKOP('W', 'q')    , NOOP          }}, // (F3) 0F 7E
    {OF_2BYTE, 0x7E0F, 0x00, P_NONE, O_MOVD     , {MKOP('E', 'd')       , MKOP('P', 'd')    , NOOP          }}, // 0F 7E

    {OF_2BYTE | OF_USEPREFIX, 0x7F0F, 0x00, P_OVERRIDE_OP   , O_MOVDQA  , {MKOP('W', 'dq')      , MKOP('V', 'dq')   , NOOP          }}, // (66) 0F 7F
    {OF_2BYTE | OF_USEPREFIX, 0x7F0F, 0x00, P_REPE          , O_MOVDQU  , {MKOP('W', 'dq')      , MKOP('V', 'dq')   , NOOP          }}, // (F3) 0F 7F
    {OF_2BYTE, 0x7F0F, 0x00, P_NONE, O_MOVQ     , {MKOP('Q', 'q')       , MKOP('P', 'q')    , NOOP          }}, // 0F 7F

    {OF_2BYTE, 0x800F, 0x00, P_NONE, O_JO       , {MKOP('J', 'v')   , NOOP              , NOOP          }}, // 0F 80
    {OF_2BYTE, 0x810F, 0x00, P_NONE, O_JNO      , {MKOP('J', 'v')   , NOOP              , NOOP          }}, // 0F 81
    {OF_2BYTE, 0x820F, 0x00, P_NONE, O_JB       , {MKOP('J', 'v')   , NOOP              , NOOP          }}, // 0F 82
    {OF_2BYTE, 0x830F, 0x00, P_NONE, O_JNB      , {MKOP('J', 'v')   , NOOP              , NOOP          }}, // 0F 83
    {OF_2BYTE, 0x840F, 0x00, P_NONE, O_JZ       , {MKOP('J', 'v')   , NOOP              , NOOP          }}, // 0F 84
    {OF_2BYTE, 0x850F, 0x00, P_NONE, O_JNZ      , {MKOP('J', 'v')   , NOOP              , NOOP          }}, // 0F 85
    {OF_2BYTE, 0x860F, 0x00, P_NONE, O_JBE      , {MKOP('J', 'v')   , NOOP              , NOOP          }}, // 0F 86
    {OF_2BYTE, 0x870F, 0x00, P_NONE, O_JNBE     , {MKOP('J', 'v')   , NOOP              , NOOP          }}, // 0F 87
    {OF_2BYTE, 0x880F, 0x00, P_NONE, O_JS       , {MKOP('J', 'v')   , NOOP              , NOOP          }}, // 0F 88
    {OF_2BYTE, 0x890F, 0x00, P_NONE, O_JNS      , {MKOP('J', 'v')   , NOOP              , NOOP          }}, // 0F 89
    {OF_2BYTE, 0x8A0F, 0x00, P_NONE, O_JP       , {MKOP('J', 'v')   , NOOP              , NOOP          }}, // 0F 8A
    {OF_2BYTE, 0x8B0F, 0x00, P_NONE, O_JNP      , {MKOP('J', 'v')   , NOOP              , NOOP          }}, // 0F 8B
    {OF_2BYTE, 0x8C0F, 0x00, P_NONE, O_JL       , {MKOP('J', 'v')   , NOOP              , NOOP          }}, // 0F 8C
    {OF_2BYTE, 0x8D0F, 0x00, P_NONE, O_JNL      , {MKOP('J', 'v')   , NOOP              , NOOP          }}, // 0F 8D
    {OF_2BYTE, 0x8E0F, 0x00, P_NONE, O_JLE      , {MKOP('J', 'v')   , NOOP              , NOOP          }}, // 0F 8E
    {OF_2BYTE, 0x8F0F, 0x00, P_NONE, O_JNLE     , {MKOP('J', 'v')   , NOOP              , NOOP          }}, // 0F 8F

    {OF_2BYTE, 0x900F, 0x00, P_NONE, O_SETO     , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // 0F 90
    {OF_2BYTE, 0x910F, 0x00, P_NONE, O_SETNO    , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // 0F 91
    {OF_2BYTE, 0x920F, 0x00, P_NONE, O_SETB     , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // 0F 92
    {OF_2BYTE, 0x930F, 0x00, P_NONE, O_SETNB    , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // 0F 93
    {OF_2BYTE, 0x940F, 0x00, P_NONE, O_SETZ     , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // 0F 94
    {OF_2BYTE, 0x950F, 0x00, P_NONE, O_SETNZ    , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // 0F 95
    {OF_2BYTE, 0x960F, 0x00, P_NONE, O_SETBE    , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // 0F 96
    {OF_2BYTE, 0x970F, 0x00, P_NONE, O_SETNBE   , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // 0F 97
    {OF_2BYTE, 0x980F, 0x00, P_NONE, O_SETS     , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // 0F 98
    {OF_2BYTE, 0x990F, 0x00, P_NONE, O_SETNS    , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // 0F 99
    {OF_2BYTE, 0x9A0F, 0x00, P_NONE, O_SETP     , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // 0F 9A
    {OF_2BYTE, 0x9B0F, 0x00, P_NONE, O_SETNP    , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // 0F 9B
    {OF_2BYTE, 0x9C0F, 0x00, P_NONE, O_SETL     , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // 0F 9C
    {OF_2BYTE, 0x9D0F, 0x00, P_NONE, O_SETNL    , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // 0F 9D
    {OF_2BYTE, 0x9E0F, 0x00, P_NONE, O_SETLE    , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // 0F 9E
    {OF_2BYTE, 0x9F0F, 0x00, P_NONE, O_SETNLE   , {MKOP('E', 'b')   , NOOP              , NOOP          }}, // 0F 9F

    {OF_2BYTE, 0xA00F, 0x00, P_NONE, O_PUSH     , {MKREG(REG_FS)    , NOOP              , NOOP          }}, // 0F A0
    {OF_2BYTE, 0xA10F, 0x00, P_NONE, O_POP      , {MKREG(REG_FS)    , NOOP              , NOOP          }}, // 0F A1
    {OF_2BYTE, 0xA20F, 0x00, P_NONE, O_CPUID    , {NOOP             , NOOP              , NOOP          }}, // 0F A2
    {OF_2BYTE, 0xA30F, 0x00, P_NONE, O_BT       , {MKOP('E', 'v')   , MKOP('G', 'v')    , NOOP          }}, // 0F A3
    {OF_2BYTE, 0xA40F, 0x00, P_NONE, O_SHLD     , {MKOP('E', 'v')   , MKOP('G', 'v')    , MKOP('I', 'b')}}, // 0F A4
    {OF_2BYTE, 0xA50F, 0x00, P_NONE, O_SHLD     , {MKOP('E', 'v')   , MKOP('G', 'v')    , MKREG(REG_CL) }}, // 0F A5
    {OF_2BYTE, 0xA60F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F A6
    {OF_2BYTE, 0xA70F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F A7

    {OF_2BYTE, 0xA80F, 0x00, P_NONE, O_PUSH     , {MKREG(REG_GS)    , NOOP              , NOOP          }}, // 0F A8
    {OF_2BYTE, 0xA90F, 0x00, P_NONE, O_POP      , {MKREG(REG_GS)    , NOOP              , NOOP          }}, // 0F A9
    {OF_2BYTE, 0xAA0F, 0x00, P_NONE, O_RSM      , {NOOP             , NOOP              , NOOP          }}, // 0F AA
    {OF_2BYTE, 0xAB0F, 0x00, P_NONE, O_BTS      , {MKOP('E', 'v')   , MKOP('G', 'v')    , NOOP          }}, // 0F AB
    {OF_2BYTE, 0xAC0F, 0x00, P_NONE, O_SHRD     , {MKOP('E', 'v')   , MKOP('G', 'v')    , MKOP('I', 'b')}}, // 0F AC
    {OF_2BYTE, 0xAD0F, 0x00, P_NONE, O_SHRD     , {MKOP('E', 'v')   , MKOP('G', 'v')    , MKREG(REG_CL) }}, // 0F AD

    {OF_2BYTE | OF_MRMBITS | OF_MODMEM, 0xAE0F, 0x00, P_NONE, O_FXSAVE  , {MKOP('E', 'v')   , NOOP      , NOOP      }}, // 0F AE-000 [mem]
    {OF_2BYTE | OF_MRMBITS | OF_MODMEM, 0xAE0F, 0x01, P_NONE, O_FXRSTOR , {MKOP('E', 'v')   , NOOP      , NOOP      }}, // 0F AE-001 [mem]
    {OF_2BYTE | OF_MRMBITS | OF_MODMEM, 0xAE0F, 0x02, P_NONE, O_LDMXCSR , {MKOP('E', 'v')   , NOOP      , NOOP      }}, // 0F AE-010 [mem]
    {OF_2BYTE | OF_MRMBITS | OF_MODMEM, 0xAE0F, 0x03, P_NONE, O_STMXCSR , {MKOP('E', 'v')   , NOOP      , NOOP      }}, // 0F AE-011 [mem]
    {OF_2BYTE | OF_MRMBITS | OF_MODMEM, 0xAE0F, 0x07, P_NONE, O_CLFLUSH , {MKOP('E', 'v')   , NOOP      , NOOP      }}, // 0F AE-111 [mem]
    {OF_2BYTE | OF_MRMBITS | OF_MOD11,  0xAE0F, 0x05, P_NONE, O_LFENCE  , {NOOP             , NOOP      , NOOP      }}, // 0F AE-101 [11]
    {OF_2BYTE | OF_MRMBITS | OF_MOD11,  0xAE0F, 0x06, P_NONE, O_MFENCE  , {NOOP             , NOOP      , NOOP      }}, // 0F AE-110 [11]
    {OF_2BYTE | OF_MRMBITS | OF_MOD11,  0xAE0F, 0x07, P_NONE, O_SFENCE  , {NOOP             , NOOP      , NOOP      }}, // 0F AE-111 [11]

    {OF_2BYTE, 0xAF0F, 0x00, P_NONE, O_IMUL     , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F AF

    {OF_2BYTE, 0xB00F, 0x00, P_NONE, O_CMPXCHG  , {MKOP('E', 'b')   , MKOP('G', 'b')    , NOOP          }}, // 0F B0
    {OF_2BYTE, 0xB10F, 0x00, P_NONE, O_CMPXCHG  , {MKOP('E', 'v')   , MKOP('G', 'v')    , NOOP          }}, // 0F B1
    // NOTE: The Intel documentation 'forgot' the first operand of the following
    // opcodes, which is 'Gv'
    // TODO: Intel now amended this, but still has LSS/LFS/LGS taking one 'Mp'.
    {OF_2BYTE, 0xB20F, 0x00, P_NONE, O_LSS      , {MKOP('G', 'v')   , MKOP('M', 'p')    , NOOP          }}, // 0F B2
    {OF_2BYTE, 0xB30F, 0x00, P_NONE, O_BTR      , {MKOP('E', 'v')   , MKOP('G', 'v')    , NOOP          }}, // 0F B3
    {OF_2BYTE, 0xB40F, 0x00, P_NONE, O_LFS      , {MKOP('G', 'v')   , MKOP('M', 'p')    , NOOP          }}, // 0F B4
    {OF_2BYTE, 0xB50F, 0x00, P_NONE, O_LGS      , {MKOP('G', 'v')   , MKOP('M', 'p')    , NOOP          }}, // 0F B5
    {OF_2BYTE, 0xB60F, 0x00, P_NONE, O_MOVZX    , {MKOP('G', 'v')   , MKOP('E', 'b')    , NOOP          }}, // 0F B6
    {OF_2BYTE, 0xB70F, 0x00, P_NONE, O_MOVZX    , {MKOP('G', 'v')   , MKOP('E', 'w')    , NOOP          }}, // 0F B7

    {OF_2BYTE, 0xB80F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F B8
    // NOTE: This opcode is NOT UD2, but has the similiar effect of causing an
    // invalid opcode exception
    {OF_2BYTE, 0xB90F, 0x00, P_NONE, O_UD2      , {NOOP             , NOOP              , NOOP          }}, // 0F B9

    {OF_2BYTE | OF_MRMBITS | OF_MODBOTH, 0xBA0F, 0x04, P_NONE, O_BT         , {MKOP('E', 'v')           , MKOP('I', 'b')    , NOOP          }}, // 0F BA-100
    {OF_2BYTE | OF_MRMBITS | OF_MODBOTH, 0xBA0F, 0x05, P_NONE, O_BTS        , {MKOP('E', 'v')           , MKOP('I', 'b')    , NOOP          }}, // 0F BA-101
    {OF_2BYTE | OF_MRMBITS | OF_MODBOTH, 0xBA0F, 0x06, P_NONE, O_BTR        , {MKOP('E', 'v')           , MKOP('I', 'b')    , NOOP          }}, // 0F BA-110
    {OF_2BYTE | OF_MRMBITS | OF_MODBOTH, 0xBA0F, 0x07, P_NONE, O_BTC        , {MKOP('E', 'v')           , MKOP('I', 'b')    , NOOP          }}, // 0F BA-111

    {OF_2BYTE, 0xBB0F, 0x00, P_NONE, O_BTC      , {MKOP('E', 'v')   , MKOP('G', 'v')    , NOOP          }}, // 0F BB
    {OF_2BYTE, 0xBC0F, 0x00, P_NONE, O_BSF      , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F BC
    {OF_2BYTE, 0xBD0F, 0x00, P_NONE, O_BSR      , {MKOP('G', 'v')   , MKOP('E', 'v')    , NOOP          }}, // 0F BD
    {OF_2BYTE, 0xBE0F, 0x00, P_NONE, O_MOVSX    , {MKOP('G', 'v')   , MKOP('E', 'b')    , NOOP          }}, // 0F BE
    {OF_2BYTE, 0xBF0F, 0x00, P_NONE, O_MOVSX    , {MKOP('G', 'v')   , MKOP('E', 'w')    , NOOP          }}, // 0F BF

    {OF_2BYTE, 0xC00F, 0x00, P_NONE, O_XADD     , {MKOP('E', 'b')   , MKOP('G', 'b')    , NOOP          }}, // 0F C0
    {OF_2BYTE, 0xC10F, 0x00, P_NONE, O_XADD     , {MKOP('E', 'v')   , MKOP('G', 'v')    , NOOP          }}, // 0F C1

    // NOTE: HIEW doesn't disassemble the following instructions right. IDA,
    // however, does.
    {OF_2BYTE | OF_USEPREFIX, 0xC20F, 0x00, P_REPE          , O_CMPSS       , {MKOP('V', 'ss')  , MKOP('W', 'ss')   , MKOP('I', 'b')}}, // (F3) 0F C2
    {OF_2BYTE | OF_USEPREFIX, 0xC20F, 0x00, P_REPNE         , O_CMPSD       , {MKOP('V', 'sd')  , MKOP('W', 'sd')   , MKOP('I', 'b')}}, // (F2) 0F C2
    {OF_2BYTE | OF_USEPREFIX, 0xC20F, 0x00, P_OVERRIDE_OP   , O_CMPPD       , {MKOP('V', 'pd')  , MKOP('W', 'pd')   , MKOP('I', 'b')}}, // (66) 0F C2
    {OF_2BYTE, 0xC20F, 0x00, P_NONE, O_CMPPS    , {MKOP('V', 'ps')  , MKOP('W', 'ps')   , MKOP('I', 'b')}}, // 0F C2

    {OF_2BYTE, 0xC30F, 0x00, P_NONE, O_MOVNTI   , {MKOP('M', 'd')   , MKOP('G', 'd')    , NOOP          }}, // 0F C3

    {OF_2BYTE | OF_USEPREFIX, 0xC40F, 0x00, P_OVERRIDE_OP   , O_PINSRW      , {MKOP('V', 'dq')  , MKOP('E', 'd')    , MKOP('I', 'b')}}, // (66) 0F C4
    {OF_2BYTE, 0xC40F, 0x00, P_NONE, O_PINSRW   , {MKOP('P', 'q')   , MKOP('E', 'd')    , MKOP('I', 'b')}}, // 0F C4

    {OF_2BYTE | OF_USEPREFIX, 0xC50F, 0x00, P_OVERRIDE_OP   , O_PEXTRW      , {MKOP('G', 'd')   , MKOP('V', 'dq')   , MKOP('I', 'b')}}, // (66) 0F C5
    {OF_2BYTE, 0xC50F, 0x00, P_NONE, O_PEXTRW   , {MKOP('G', 'd')   , MKOP('P', 'q')    , MKOP('I', 'b')}}, // 0F C5

    {OF_2BYTE | OF_USEPREFIX, 0xC60F, 0x00, P_OVERRIDE_OP   , O_SHUFPD      , {MKOP('V', 'pd')  , MKOP('W', 'pd')   , MKOP('I', 'b')}}, // (66) 0F C6
    {OF_2BYTE, 0xC60F, 0x00, P_NONE, O_SHUFPS   , {MKOP('V', 'ps')  , MKOP('W', 'ps')   , MKOP('I', 'b')}}, // 0F C6

    {OF_2BYTE | OF_MRMBITS | OF_MODMEM , 0xC70F, 0x01, P_NONE, O_CMPXCHG8B  , {MKOP('M', 'q')           , NOOP              , NOOP          }}, // 0F C7-001 [mem]

    {OF_2BYTE, 0xC80F, 0x00, P_NONE, O_BSWAP    , {MKREG(REG_EAX)   , NOOP              , NOOP          }}, // 0F C8
    {OF_2BYTE, 0xC90F, 0x00, P_NONE, O_BSWAP    , {MKREG(REG_ECX)   , NOOP              , NOOP          }}, // 0F C9
    {OF_2BYTE, 0xCA0F, 0x00, P_NONE, O_BSWAP    , {MKREG(REG_EDX)   , NOOP              , NOOP          }}, // 0F CA
    {OF_2BYTE, 0xCB0F, 0x00, P_NONE, O_BSWAP    , {MKREG(REG_EBX)   , NOOP              , NOOP          }}, // 0F CB
    {OF_2BYTE, 0xCC0F, 0x00, P_NONE, O_BSWAP    , {MKREG(REG_ESP)   , NOOP              , NOOP          }}, // 0F CC
    {OF_2BYTE, 0xCD0F, 0x00, P_NONE, O_BSWAP    , {MKREG(REG_EBP)   , NOOP              , NOOP          }}, // 0F CD
    {OF_2BYTE, 0xCE0F, 0x00, P_NONE, O_BSWAP    , {MKREG(REG_ESI)   , NOOP              , NOOP          }}, // 0F CE
    {OF_2BYTE, 0xCF0F, 0x00, P_NONE, O_BSWAP    , {MKREG(REG_EDI)   , NOOP              , NOOP          }}, // 0F CF

    {OF_2BYTE | OF_USEPREFIX, 0xD00F, 0x00, P_OVERRIDE_OP   , O_ADDSUBPD    , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F D0
    {OF_2BYTE | OF_USEPREFIX, 0xD00F, 0x00, P_REPNE, O_ADDSUBPS, {MKOP('V', 'dq') , MKOP('W', 'dq'), NOOP }}, // (F2) 0F D0
    {OF_2BYTE, 0xD00F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F D0

    {OF_2BYTE | OF_USEPREFIX, 0xD10F, 0x00, P_OVERRIDE_OP   , O_PSRLW       , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F D1
    {OF_2BYTE, 0xD10F, 0x00, P_NONE, O_PSRLW    , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F D1

    {OF_2BYTE | OF_USEPREFIX, 0xD20F, 0x00, P_OVERRIDE_OP   , O_PSRLD       , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F D2
    {OF_2BYTE, 0xD20F, 0x00, P_NONE, O_PSRLD    , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F D2

    {OF_2BYTE | OF_USEPREFIX, 0xD30F, 0x00, P_OVERRIDE_OP   , O_PSRLQ       , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F D3
    {OF_2BYTE, 0xD30F, 0x00, P_NONE, O_PSRLQ    , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F D3

    {OF_2BYTE | OF_USEPREFIX, 0xD40F, 0x00, P_OVERRIDE_OP   , O_PADDQ       , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F D4
    {OF_2BYTE, 0xD40F, 0x00, P_NONE, O_PADDQ    , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F D4

    {OF_2BYTE | OF_USEPREFIX, 0xD50F, 0x00, P_OVERRIDE_OP   , O_PMULLW      , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F D5
    {OF_2BYTE, 0xD50F, 0x00, P_NONE, O_PMULLW   , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F D5

    {OF_2BYTE | OF_USEPREFIX, 0xD60F, 0x00, P_OVERRIDE_OP   , O_MOVQ        , {MKOP('W', 'q')   , MKOP('V', 'q')    , NOOP          }}, // (66) 0F D6
    // NOTE: Both IDA and HIEW don't disassemble these instructions.
    {OF_2BYTE | OF_USEPREFIX, 0xD60F, 0x00, P_REPE          , O_MOVQ2DQ     , {MKOP('V', 'dq')  , MKOP('Q', 'q')    , NOOP          }}, // (F3) 0F D6
    // TODO: Intel says the second operand is 'Vq'
    {OF_2BYTE | OF_USEPREFIX, 0xD60F, 0x00, P_REPNE         , O_MOVDQ2Q     , {MKOP('P', 'q')   , MKOP('W', 'q')    , NOOP          }}, // (F2) 0F D6

    // NOTE: The following instruction's second operand is stated 'Vdq' in Intel's
    // specification, but is considered 'Wdq' by HIEW and IDA.
    {OF_2BYTE | OF_USEPREFIX, 0xD70F, 0x00, P_OVERRIDE_OP   , O_PMOVMSKB    , {MKOP('G', 'd')   , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F D7
    {OF_2BYTE, 0xD70F, 0x00, P_NONE, O_PMOVMSKB , {MKOP('G', 'd')   , MKOP('P', 'q')    , NOOP          }}, // 0F D7

    {OF_2BYTE | OF_USEPREFIX, 0xD80F, 0x00, P_OVERRIDE_OP   , O_PSUBUSB     , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F D8
    {OF_2BYTE, 0xD80F, 0x00, P_NONE, O_PSUBUSB  , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F D8

    {OF_2BYTE | OF_USEPREFIX, 0xD90F, 0x00, P_OVERRIDE_OP   , O_PSUBUSW     , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F D9
    {OF_2BYTE, 0xD90F, 0x00, P_NONE, O_PSUBUSW  , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F D9

    {OF_2BYTE | OF_USEPREFIX, 0xDA0F, 0x00, P_OVERRIDE_OP   , O_PMINUB      , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F DA
    {OF_2BYTE, 0xDA0F, 0x00, P_NONE, O_PMINUB   , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F DA

    {OF_2BYTE | OF_USEPREFIX, 0xDB0F, 0x00, P_OVERRIDE_OP   , O_PAND        , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F DB
    {OF_2BYTE, 0xDB0F, 0x00, P_NONE, O_PAND     , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F DB

    {OF_2BYTE | OF_USEPREFIX, 0xDC0F, 0x00, P_OVERRIDE_OP   , O_PADDUSB     , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F DC
    {OF_2BYTE, 0xDC0F, 0x00, P_NONE, O_PADDUSB  , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F DC

    {OF_2BYTE | OF_USEPREFIX, 0xDD0F, 0x00, P_OVERRIDE_OP   , O_PADDUSW     , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F DD
    {OF_2BYTE, 0xDD0F, 0x00, P_NONE, O_PADDUSW  , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F DD

    {OF_2BYTE | OF_USEPREFIX, 0xDE0F, 0x00, P_OVERRIDE_OP   , O_PMAXUB      , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F DE
    {OF_2BYTE, 0xDE0F, 0x00, P_NONE, O_PMAXUB   , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F DE

    {OF_2BYTE | OF_USEPREFIX, 0xDF0F, 0x00, P_OVERRIDE_OP   , O_PANDN       , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F DF
    {OF_2BYTE, 0xDF0F, 0x00, P_NONE, O_PANDN    , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F DF

    {OF_2BYTE | OF_USEPREFIX, 0xE00F, 0x00, P_OVERRIDE_OP   , O_PAVGB       , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F E0
    {OF_2BYTE, 0xE00F, 0x00, P_NONE, O_PAVGB    , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F E0

    {OF_2BYTE | OF_USEPREFIX, 0xE10F, 0x00, P_OVERRIDE_OP   , O_PSRAW       , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F E1
    {OF_2BYTE, 0xE10F, 0x00, P_NONE, O_PSRAW    , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F E1

    {OF_2BYTE | OF_USEPREFIX, 0xE20F, 0x00, P_OVERRIDE_OP   , O_PSRAD       , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F E2
    {OF_2BYTE, 0xE20F, 0x00, P_NONE, O_PSRAD    , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F E2

    {OF_2BYTE | OF_USEPREFIX, 0xE30F, 0x00, P_OVERRIDE_OP   , O_PAVGW       , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F E3
    {OF_2BYTE, 0xE30F, 0x00, P_NONE, O_PAVGW    , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F E3

    {OF_2BYTE | OF_USEPREFIX, 0xE40F, 0x00, P_OVERRIDE_OP   , O_PMULHUW     , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F E4
    {OF_2BYTE, 0xE40F, 0x00, P_NONE, O_PMULHUW  , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F E4

    {OF_2BYTE | OF_USEPREFIX, 0xE50F, 0x00, P_OVERRIDE_OP   , O_PMULHW      , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F E5
    {OF_2BYTE, 0xE50F, 0x00, P_NONE, O_PMULHW   , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F E5

    {OF_2BYTE | OF_USEPREFIX, 0xE60F, 0x00, P_OVERRIDE_OP   , O_CVTTPD2DQ   , {MKOP('V', 'dq')  , MKOP('W', 'pd')   , NOOP          }}, // (66) 0F E6
    {OF_2BYTE | OF_USEPREFIX, 0xE60F, 0x00, P_REPE          , O_CVTDQ2PD    , {MKOP('V', 'pd')  , MKOP('W', 'dq')   , NOOP          }}, // (F3) 0F E6
    {OF_2BYTE | OF_USEPREFIX, 0xE60F, 0x00, P_REPNE         , O_CVTPD2DQ    , {MKOP('V', 'dq')  , MKOP('W', 'pq')   , NOOP          }}, // (F2) 0F E6

    // TODO: Intel now uses 'Mq', 'Vq' and 'Mdq', 'Vdq' for these two
    // instructions.
    {OF_2BYTE | OF_USEPREFIX, 0xE70F, 0x00, P_OVERRIDE_OP   , O_MOVNTDQ     , {MKOP('W', 'dq')  , MKOP('V', 'dq')   , NOOP          }}, // (66) 0F E7
    // Intel's specification defines the following instruction's operands as
    // 'Wq', 'Vq' but according to HIEW/IDA they are 'Qq', 'Pq'
    {OF_2BYTE, 0xE70F, 0x00, P_NONE, O_MOVNTQ   , {MKOP('Q', 'q')   , MKOP('P', 'q')    , NOOP          }}, // 0F E7

    {OF_2BYTE | OF_USEPREFIX, 0xE80F, 0x00, P_OVERRIDE_OP   , O_PSUBSB      , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F E8
    {OF_2BYTE, 0xE80F, 0x00, P_NONE, O_PSUBSB   , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F E8

    {OF_2BYTE | OF_USEPREFIX, 0xE90F, 0x00, P_OVERRIDE_OP   , O_PSUBSW      , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F E9
    {OF_2BYTE, 0xE90F, 0x00, P_NONE, O_PSUBSW   , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F E9

    {OF_2BYTE | OF_USEPREFIX, 0xEA0F, 0x00, P_OVERRIDE_OP   , O_PMINSW      , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F EA
    {OF_2BYTE, 0xEA0F, 0x00, P_NONE, O_PMINSW   , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F EA

    {OF_2BYTE | OF_USEPREFIX, 0xEB0F, 0x00, P_OVERRIDE_OP   , O_POR         , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F EB
    {OF_2BYTE, 0xEB0F, 0x00, P_NONE, O_POR      , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F EB

    {OF_2BYTE | OF_USEPREFIX, 0xEC0F, 0x00, P_OVERRIDE_OP   , O_PADDSB      , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F EC
    {OF_2BYTE, 0xEC0F, 0x00, P_NONE, O_PADDSB   , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F EC

    {OF_2BYTE | OF_USEPREFIX, 0xED0F, 0x00, P_OVERRIDE_OP   , O_PADDSW      , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F ED
    {OF_2BYTE, 0xED0F, 0x00, P_NONE, O_PADDSW   , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F ED

    {OF_2BYTE | OF_USEPREFIX, 0xEE0F, 0x00, P_OVERRIDE_OP   , O_PMAXSW      , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F EE
    {OF_2BYTE, 0xEE0F, 0x00, P_NONE, O_PMAXSW   , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F EE

    {OF_2BYTE | OF_USEPREFIX, 0xEF0F, 0x00, P_OVERRIDE_OP   , O_PXOR        , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F EF
    {OF_2BYTE, 0xEF0F, 0x00, P_NONE, O_PXOR     , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F EF

    {OF_2BYTE | OF_USEPREFIX, 0xF00F, 0x00, P_REPNE         , O_LDDQU       , {MKOP('V', 'dq')  , MKOP('M', 'dq')   , NOOP          }}, // (F2) 0F F0
    {OF_2BYTE, 0xF00F, 0x00, P_NONE, UNKOP}     ,                                                           // 0F F0

    {OF_2BYTE | OF_USEPREFIX, 0xF10F, 0x00, P_OVERRIDE_OP   , O_PSLLW       , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F F1
    {OF_2BYTE, 0xF10F, 0x00, P_NONE, O_PSLLW    , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F F1

    {OF_2BYTE | OF_USEPREFIX, 0xF20F, 0x00, P_OVERRIDE_OP   , O_PSLLD       , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F F2
    {OF_2BYTE, 0xF20F, 0x00, P_NONE, O_PSLLD    , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F F2

    {OF_2BYTE | OF_USEPREFIX, 0xF30F, 0x00, P_OVERRIDE_OP   , O_PSLLQ       , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F F3
    {OF_2BYTE, 0xF30F, 0x00, P_NONE, O_PSLLQ    , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F F3

    {OF_2BYTE | OF_USEPREFIX, 0xF40F, 0x00, P_OVERRIDE_OP   , O_PMULUDQ     , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F F4
    {OF_2BYTE, 0xF40F, 0x00, P_NONE, O_PMULUDQ  , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F F4

    {OF_2BYTE | OF_USEPREFIX, 0xF50F, 0x00, P_OVERRIDE_OP   , O_PMADDWD     , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F F5
    {OF_2BYTE, 0xF50F, 0x00, P_NONE, O_PMADDWD  , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F F5

    {OF_2BYTE | OF_USEPREFIX, 0xF60F, 0x00, P_OVERRIDE_OP   , O_PSADBW      , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F F6
    {OF_2BYTE, 0xF60F, 0x00, P_NONE, O_PSADBW   , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F F6

    {OF_2BYTE | OF_USEPREFIX, 0xF70F, 0x00, P_OVERRIDE_OP   , O_MASKMOVDQU  , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F F7
    {OF_2BYTE, 0xF70F, 0x00, P_NONE, O_MASKMOVQ , {MKOP('P', 'pi')  , MKOP('Q', 'pi')   , NOOP          }}, // 0F F7

    //
    {OF_2BYTE | OF_USEPREFIX, 0xF80F, 0x00, P_OVERRIDE_OP   , O_PSUBB       , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F F8
    {OF_2BYTE, 0xF80F, 0x00, P_NONE, O_PSUBB    , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F F8

    {OF_2BYTE | OF_USEPREFIX, 0xF90F, 0x00, P_OVERRIDE_OP   , O_PSUBW       , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F F9
    {OF_2BYTE, 0xF90F, 0x00, P_NONE, O_PSUBW    , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F F9

    {OF_2BYTE | OF_USEPREFIX, 0xFA0F, 0x00, P_OVERRIDE_OP   , O_PSUBD       , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F FA
    {OF_2BYTE, 0xFA0F, 0x00, P_NONE, O_PSUBD    , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F FA

    {OF_2BYTE | OF_USEPREFIX, 0xFB0F, 0x00, P_OVERRIDE_OP   , O_PSUBQ       , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F FB
    {OF_2BYTE, 0xFB0F, 0x00, P_NONE, O_PSUBQ    , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F FB

    {OF_2BYTE | OF_USEPREFIX, 0xFC0F, 0x00, P_OVERRIDE_OP   , O_PADDB       , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F FC
    {OF_2BYTE, 0xFC0F, 0x00, P_NONE, O_PADDB    , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F FC

    {OF_2BYTE | OF_USEPREFIX, 0xFD0F, 0x00, P_OVERRIDE_OP   , O_PADDW       , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F FD
    {OF_2BYTE, 0xFD0F, 0x00, P_NONE, O_PADDW    , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F FD

    {OF_2BYTE | OF_USEPREFIX, 0xFE0F, 0x00, P_OVERRIDE_OP   , O_PADDD       , {MKOP('V', 'dq')  , MKOP('W', 'dq')   , NOOP          }}, // (66) 0F FE
    {OF_2BYTE, 0xFE0F, 0x00, P_NONE, O_PADDD    , {MKOP('P', 'q')   , MKOP('Q', 'q')    , NOOP          }}, // 0F FE

    {OF_2BYTE, 0xFF0F, 0x00, P_NONE, UNKOP}                                                             // 0F FF
};

/// Opcode table length
extern const std::size_t OpcodeTableLength = sizeof(OpcodeTable) / sizeof(Opcode);

/// FPU opcode table for ModR/M <= 0xBF
extern const Opcode FPUOpcodeTableLow[] = {
    {OF_FPU, 0xD8, 0x00, P_NONE, O_FADD     , {MKOP('E', 'fd'), NOOP, NOOP}}, // D8-000
    {OF_FPU, 0xD8, 0x01, P_NONE, O_FMUL     , {MKOP('E', 'fd'), NOOP, NOOP}}, // D8-001
    {OF_FPU, 0xD8, 0x02, P_NONE, O_FCOM     , {MKOP('E', 'fd'), NOOP, NOOP}}, // D8-010
    {OF_FPU, 0xD8, 0x03, P_NONE, O_FCOMP    , {MKOP('E', 'fd'), NOOP, NOOP}}, // D8-011
    {OF_FPU, 0xD8, 0x04, P_NONE, O_FSUB     , {MKOP('E', 'fd'), NOOP, NOOP}}, // D8-100
    {OF_FPU, 0xD8, 0x05, P_NONE, O_FSUBR    , {MKOP('E', 'fd'), NOOP, NOOP}}, // D8-101
    {OF_FPU, 0xD8, 0x06, P_NONE, O_FDIV     , {MKOP('E', 'fd'), NOOP, NOOP}}, // D8-110
    {OF_FPU, 0xD8, 0x07, P_NONE, O_FDIVR    , {MKOP('E', 'fd'), NOOP, NOOP}}, // D8-111

    {OF_FPU, 0xD9, 0x00, P_NONE, O_FLD      , {MKOP('E', 'fd'), NOOP, NOOP}}, // D9-000
    {OF_FPU, 0xD9, 0x01, P_NONE, UNKOP}     ,                                 // D9-001
    {OF_FPU, 0xD9, 0x02, P_NONE, O_FST      , {MKOP('E', 'fd'), NOOP, NOOP}}, // D9-010
    {OF_FPU, 0xD9, 0x03, P_NONE, O_FSTP     , {MKOP('E', 'fd'), NOOP, NOOP}}, // D9-011
    {OF_FPU, 0xD9, 0x04, P_NONE, O_FLDENV   , {MKOP('E', 'fe'), NOOP, NOOP}}, // D9-100
    {OF_FPU, 0xD9, 0x05, P_NONE, O_FLDCW    , {MKOP('E', 'w' ), NOOP, NOOP}}, // D9-101
    {OF_FPU, 0xD9, 0x06, P_NONE, O_FSTENV   , {MKOP('E', 'fe'), NOOP, NOOP}}, // D9-110
    {OF_FPU, 0xD9, 0x07, P_NONE, O_FSTCW    , {MKOP('E', 'w' ), NOOP, NOOP}}, // D9-111

    {OF_FPU, 0xDA, 0x00, P_NONE, O_FIADD    , {MKOP('E', 'v' ), NOOP, NOOP}}, // DA-000
    {OF_FPU, 0xDA, 0x01, P_NONE, O_FIMUL    , {MKOP('E', 'v' ), NOOP, NOOP}}, // DA-001
    {OF_FPU, 0xDA, 0x02, P_NONE, O_FICOM    , {MKOP('E', 'v' ), NOOP, NOOP}}, // DA-010
    {OF_FPU, 0xDA, 0x03, P_NONE, O_FICOMP   , {MKOP('E', 'v' ), NOOP, NOOP}}, // DA-011
    {OF_FPU, 0xDA, 0x04, P_NONE, O_FISUB    , {MKOP('E', 'v' ), NOOP, NOOP}}, // DA-100
    {OF_FPU, 0xDA, 0x05, P_NONE, O_FISUBR   , {MKOP('E', 'v' ), NOOP, NOOP}}, // DA-101
    {OF_FPU, 0xDA, 0x06, P_NONE, O_FIDIV    , {MKOP('E', 'v' ), NOOP, NOOP}}, // DA-110
    {OF_FPU, 0xDA, 0x07, P_NONE, O_FIDIVR   , {MKOP('E', 'v' ), NOOP, NOOP}}, // DA-111

    {OF_FPU, 0xDB, 0x00, P_NONE, O_FILD     , {MKOP('E', 'v' ), NOOP, NOOP}}, // DB-000
    {OF_FPU, 0xDB, 0x01, P_NONE, O_FISTTP   , {MKOP('E', 'v' ), NOOP, NOOP}}, // DB-001
    {OF_FPU, 0xDB, 0x02, P_NONE, O_FIST     , {MKOP('E', 'v' ), NOOP, NOOP}}, // DB-010
    {OF_FPU, 0xDB, 0x03, P_NONE, O_FISTP    , {MKOP('E', 'v' ), NOOP, NOOP}}, // DB-011
    {OF_FPU, 0xDB, 0x04, P_NONE, UNKOP}     ,                                 // DB-100
    {OF_FPU, 0xDB, 0x05, P_NONE, O_FLD      , {MKOP('E', 'ft'), NOOP, NOOP}}, // DB-101
    {OF_FPU, 0xDB, 0x06, P_NONE, UNKOP}     ,                                 // DB-110
    {OF_FPU, 0xDB, 0x07, P_NONE, O_FSTP     , {MKOP('E', 'ft'), NOOP, NOOP}}, // DB-111

    {OF_FPU, 0xDC, 0x00, P_NONE, O_FADD     , {MKOP('E', 'fq'), NOOP, NOOP}}, // DC-000
    {OF_FPU, 0xDC, 0x01, P_NONE, O_FMUL     , {MKOP('E', 'fq'), NOOP, NOOP}}, // DC-001
    {OF_FPU, 0xDC, 0x02, P_NONE, O_FCOM     , {MKOP('E', 'fq'), NOOP, NOOP}}, // DC-010
    {OF_FPU, 0xDC, 0x03, P_NONE, O_FCOMP    , {MKOP('E', 'fq'), NOOP, NOOP}}, // DC-011
    {OF_FPU, 0xDC, 0x04, P_NONE, O_FSUB     , {MKOP('E', 'fq'), NOOP, NOOP}}, // DC-100
    {OF_FPU, 0xDC, 0x05, P_NONE, O_FSUBR    , {MKOP('E', 'fq'), NOOP, NOOP}}, // DC-101
    {OF_FPU, 0xDC, 0x06, P_NONE, O_FDIV     , {MKOP('E', 'fq'), NOOP, NOOP}}, // DC-110
    {OF_FPU, 0xDC, 0x07, P_NONE, O_FDIVR    , {MKOP('E', 'fq'), NOOP, NOOP}}, // DC-111

    {OF_FPU, 0xDD, 0x00, P_NONE, O_FLD      , {MKOP('E', 'fq'), NOOP, NOOP}}, // DD-000
    {OF_FPU, 0xDD, 0x01, P_NONE, O_FISTTP   , {MKOP('E', 'q') , NOOP, NOOP}}, // DD-001
    {OF_FPU, 0xDD, 0x02, P_NONE, O_FST      , {MKOP('E', 'fq'), NOOP, NOOP}}, // DD-010
    {OF_FPU, 0xDD, 0x03, P_NONE, O_FSTP     , {MKOP('E', 'fq'), NOOP, NOOP}}, // DD-011
    {OF_FPU, 0xDD, 0x04, P_NONE, O_FRSTOR   , {MKOP('E', 'fs'), NOOP, NOOP}}, // DD-100
    {OF_FPU, 0xDD, 0x05, P_NONE, UNKOP}     ,                                 // DD-101
    {OF_FPU, 0xDD, 0x06, P_NONE, O_FSAVE    , {MKOP('E', 'fs'), NOOP, NOOP}}, // DD-110
    {OF_FPU, 0xDD, 0x07, P_NONE, O_FSTSW    , {MKOP('E', 'w' ), NOOP, NOOP}}, // DD-111

    {OF_FPU, 0xDE, 0x00, P_NONE, O_FIADD    , {MKOP('E', 'w' ), NOOP, NOOP}}, // DE-000
    {OF_FPU, 0xDE, 0x01, P_NONE, O_FIMUL    , {MKOP('E', 'w' ), NOOP, NOOP}}, // DE-001
    {OF_FPU, 0xDE, 0x02, P_NONE, O_FICOM    , {MKOP('E', 'w' ), NOOP, NOOP}}, // DE-010
    {OF_FPU, 0xDE, 0x03, P_NONE, O_FICOMP   , {MKOP('E', 'w' ), NOOP, NOOP}}, // DE-011
    {OF_FPU, 0xDE, 0x04, P_NONE, O_FISUB    , {MKOP('E', 'w' ), NOOP, NOOP}}, // DE-100
    {OF_FPU, 0xDE, 0x05, P_NONE, O_FISUBR   , {MKOP('E', 'w' ), NOOP, NOOP}}, // DE-101
    {OF_FPU, 0xDE, 0x06, P_NONE, O_FIDIV    , {MKOP('E', 'w' ), NOOP, NOOP}}, // DE-110
    {OF_FPU, 0xDE, 0x07, P_NONE, O_FIDIVR   , {MKOP('E', 'w' ), NOOP, NOOP}}, // DE-111

    {OF_FPU, 0xDF, 0x00, P_NONE, O_FILD     , {MKOP('E', 'w' ), NOOP, NOOP}}, // DF-000
    {OF_FPU, 0xDF, 0x01, P_NONE, O_FISTTP   , {MKOP('E', 'w' ), NOOP, NOOP}}, // DF-001
    {OF_FPU, 0xDF, 0x02, P_NONE, O_FIST     , {MKOP('E', 'w' ), NOOP, NOOP}}, // DF-010
    {OF_FPU, 0xDF, 0x03, P_NONE, O_FISTP    , {MKOP('E', 'w' ), NOOP, NOOP}}, // DF-011
    {OF_FPU, 0xDF, 0x04, P_NONE, O_FBLD     , {MKOP('E', 'fb'), NOOP, NOOP}}, // DF-100
    {OF_FPU, 0xDF, 0x05, P_NONE, O_FILD     , {MKOP('E', 'q' ), NOOP, NOOP}}, // DF-101
    {OF_FPU, 0xDF, 0x06, P_NONE, O_FBSTP    , {MKOP('E', 'fb'), NOOP, NOOP}}, // DF-110
    {OF_FPU, 0xDF, 0x07, P_NONE, O_FISTP    , {MKOP('E', 'q' ), NOOP, NOOP}}  // DF-111
};

/// FPU opcode table for ModR/M <= 0xBF length
extern const std::size_t FPUOpcodeTableLowLength = sizeof(FPUOpcodeTableLow) / sizeof(Opcode);

/// FPU opcode table for ModR/M > 0xBF
extern const Opcode FPUOpcodeTableHigh[] = {
    {OF_FPU, 0xC0D8, 0x00, P_NONE, O_FADD       , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // D8 C0
    {OF_FPU, 0xC1D8, 0x00, P_NONE, O_FADD       , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // D8 C1
    {OF_FPU, 0xC2D8, 0x00, P_NONE, O_FADD       , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // D8 C2
    {OF_FPU, 0xC3D8, 0x00, P_NONE, O_FADD       , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // D8 C3
    {OF_FPU, 0xC4D8, 0x00, P_NONE, O_FADD       , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // D8 C4
    {OF_FPU, 0xC5D8, 0x00, P_NONE, O_FADD       , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // D8 C5
    {OF_FPU, 0xC6D8, 0x00, P_NONE, O_FADD       , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // D8 C6
    {OF_FPU, 0xC7D8, 0x00, P_NONE, O_FADD       , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // D8 C7

    {OF_FPU, 0xC8D8, 0x00, P_NONE, O_FMUL       , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // D8 C8
    {OF_FPU, 0xC9D8, 0x00, P_NONE, O_FMUL       , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // D8 C9
    {OF_FPU, 0xCAD8, 0x00, P_NONE, O_FMUL       , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // D8 CA
    {OF_FPU, 0xCBD8, 0x00, P_NONE, O_FMUL       , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // D8 CB
    {OF_FPU, 0xCCD8, 0x00, P_NONE, O_FMUL       , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // D8 CC
    {OF_FPU, 0xCDD8, 0x00, P_NONE, O_FMUL       , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // D8 CD
    {OF_FPU, 0xCED8, 0x00, P_NONE, O_FMUL       , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // D8 CE
    {OF_FPU, 0xCFD8, 0x00, P_NONE, O_FMUL       , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // D8 CF

    {OF_FPU, 0xD0D8, 0x00, P_NONE, O_FCOM       , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // D8 D0
    {OF_FPU, 0xD1D8, 0x00, P_NONE, O_FCOM       , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // D8 D1
    {OF_FPU, 0xD2D8, 0x00, P_NONE, O_FCOM       , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // D8 D2
    {OF_FPU, 0xD3D8, 0x00, P_NONE, O_FCOM       , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // D8 D3
    {OF_FPU, 0xD4D8, 0x00, P_NONE, O_FCOM       , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // D8 D4
    {OF_FPU, 0xD5D8, 0x00, P_NONE, O_FCOM       , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // D8 D5
    {OF_FPU, 0xD6D8, 0x00, P_NONE, O_FCOM       , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // D8 D6
    {OF_FPU, 0xD7D8, 0x00, P_NONE, O_FCOM       , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // D8 D7

    {OF_FPU, 0xD8D8, 0x00, P_NONE, O_FCOMP      , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // D8 D8
    {OF_FPU, 0xD9D8, 0x00, P_NONE, O_FCOMP      , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // D8 D9
    {OF_FPU, 0xDAD8, 0x00, P_NONE, O_FCOMP      , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // D8 DA
    {OF_FPU, 0xDBD8, 0x00, P_NONE, O_FCOMP      , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // D8 DB
    {OF_FPU, 0xDCD8, 0x00, P_NONE, O_FCOMP      , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // D8 DC
    {OF_FPU, 0xDDD8, 0x00, P_NONE, O_FCOMP      , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // D8 DD
    {OF_FPU, 0xDED8, 0x00, P_NONE, O_FCOMP      , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // D8 DE
    {OF_FPU, 0xDFD8, 0x00, P_NONE, O_FCOMP      , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // D8 DF

    {OF_FPU, 0xE0D8, 0x00, P_NONE, O_FSUB       , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // D8 E0
    {OF_FPU, 0xE1D8, 0x00, P_NONE, O_FSUB       , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // D8 E1
    {OF_FPU, 0xE2D8, 0x00, P_NONE, O_FSUB       , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // D8 E2
    {OF_FPU, 0xE3D8, 0x00, P_NONE, O_FSUB       , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // D8 E3
    {OF_FPU, 0xE4D8, 0x00, P_NONE, O_FSUB       , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // D8 E4
    {OF_FPU, 0xE5D8, 0x00, P_NONE, O_FSUB       , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // D8 E5
    {OF_FPU, 0xE6D8, 0x00, P_NONE, O_FSUB       , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // D8 E6
    {OF_FPU, 0xE7D8, 0x00, P_NONE, O_FSUB       , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // D8 E7

    {OF_FPU, 0xE8D8, 0x00, P_NONE, O_FSUBR      , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // D8 E8
    {OF_FPU, 0xE9D8, 0x00, P_NONE, O_FSUBR      , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // D8 E9
    {OF_FPU, 0xEAD8, 0x00, P_NONE, O_FSUBR      , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // D8 EA
    {OF_FPU, 0xEBD8, 0x00, P_NONE, O_FSUBR      , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // D8 EB
    {OF_FPU, 0xECD8, 0x00, P_NONE, O_FSUBR      , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // D8 EC
    {OF_FPU, 0xEDD8, 0x00, P_NONE, O_FSUBR      , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // D8 ED
    {OF_FPU, 0xEED8, 0x00, P_NONE, O_FSUBR      , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // D8 EE
    {OF_FPU, 0xEFD8, 0x00, P_NONE, O_FSUBR      , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // D8 EF

    {OF_FPU, 0xF0D8, 0x00, P_NONE, O_FDIV       , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // D8 F0
    {OF_FPU, 0xF1D8, 0x00, P_NONE, O_FDIV       , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // D8 F1
    {OF_FPU, 0xF2D8, 0x00, P_NONE, O_FDIV       , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // D8 F2
    {OF_FPU, 0xF3D8, 0x00, P_NONE, O_FDIV       , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // D8 F3
    {OF_FPU, 0xF4D8, 0x00, P_NONE, O_FDIV       , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // D8 F4
    {OF_FPU, 0xF5D8, 0x00, P_NONE, O_FDIV       , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // D8 F5
    {OF_FPU, 0xF6D8, 0x00, P_NONE, O_FDIV       , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // D8 F6
    {OF_FPU, 0xF7D8, 0x00, P_NONE, O_FDIV       , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // D8 F7

    {OF_FPU, 0xF8D8, 0x00, P_NONE, O_FDIVR      , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // D8 F8
    {OF_FPU, 0xF9D8, 0x00, P_NONE, O_FDIVR      , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // D8 F9
    {OF_FPU, 0xFAD8, 0x00, P_NONE, O_FDIVR      , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // D8 FA
    {OF_FPU, 0xFBD8, 0x00, P_NONE, O_FDIVR      , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // D8 FB
    {OF_FPU, 0xFCD8, 0x00, P_NONE, O_FDIVR      , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // D8 FC
    {OF_FPU, 0xFDD8, 0x00, P_NONE, O_FDIVR      , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // D8 FD
    {OF_FPU, 0xFED8, 0x00, P_NONE, O_FDIVR      , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // D8 FE
    {OF_FPU, 0xFFD8, 0x00, P_NONE, O_FDIVR      , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // D8 FF

    {OF_FPU, 0xC0D9, 0x00, P_NONE, O_FLD        , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // D9 C0
    {OF_FPU, 0xC1D9, 0x00, P_NONE, O_FLD        , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // D9 C1
    {OF_FPU, 0xC2D9, 0x00, P_NONE, O_FLD        , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // D9 C2
    {OF_FPU, 0xC3D9, 0x00, P_NONE, O_FLD        , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // D9 C3
    {OF_FPU, 0xC4D9, 0x00, P_NONE, O_FLD        , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // D9 C4
    {OF_FPU, 0xC5D9, 0x00, P_NONE, O_FLD        , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // D9 C5
    {OF_FPU, 0xC6D9, 0x00, P_NONE, O_FLD        , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // D9 C6
    {OF_FPU, 0xC7D9, 0x00, P_NONE, O_FLD        , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // D9 C7

    {OF_FPU, 0xC8D9, 0x00, P_NONE, O_FXCH       , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // D9 C8
    {OF_FPU, 0xC9D9, 0x00, P_NONE, O_FXCH       , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // D9 C9
    {OF_FPU, 0xCAD9, 0x00, P_NONE, O_FXCH       , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // D9 CA
    {OF_FPU, 0xCBD9, 0x00, P_NONE, O_FXCH       , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // D9 CB
    {OF_FPU, 0xCCD9, 0x00, P_NONE, O_FXCH       , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // D9 CC
    {OF_FPU, 0xCDD9, 0x00, P_NONE, O_FXCH       , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // D9 CD
    {OF_FPU, 0xCED9, 0x00, P_NONE, O_FXCH       , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // D9 CE
    {OF_FPU, 0xCFD9, 0x00, P_NONE, O_FXCH       , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // D9 CF

    {OF_FPU, 0xD0D9, 0x00, P_NONE, O_FNOP       , {NOOP          , NOOP          , NOOP}}, // D9 D0
    {OF_FPU, 0xD1D9, 0x00, P_NONE, UNKOP}       ,                                          // D9 D1
    {OF_FPU, 0xD2D9, 0x00, P_NONE, UNKOP}       ,                                          // D9 D2
    {OF_FPU, 0xD3D9, 0x00, P_NONE, UNKOP}       ,                                          // D9 D3
    {OF_FPU, 0xD4D9, 0x00, P_NONE, UNKOP}       ,                                          // D9 D4
    {OF_FPU, 0xD5D9, 0x00, P_NONE, UNKOP}       ,                                          // D9 D5
    {OF_FPU, 0xD6D9, 0x00, P_NONE, UNKOP}       ,                                          // D9 D6
    {OF_FPU, 0xD7D9, 0x00, P_NONE, UNKOP}       ,                                          // D9 D7

    {OF_FPU, 0xD8D9, 0x00, P_NONE, UNKOP}       ,                                          // D9 D8
    {OF_FPU, 0xD9D9, 0x00, P_NONE, UNKOP}       ,                                          // D9 D9
    {OF_FPU, 0xDAD9, 0x00, P_NONE, UNKOP}       ,                                          // D9 DA
    {OF_FPU, 0xDBD9, 0x00, P_NONE, UNKOP}       ,                                          // D9 DB
    {OF_FPU, 0xDCD9, 0x00, P_NONE, UNKOP}       ,                                          // D9 DC
    {OF_FPU, 0xDDD9, 0x00, P_NONE, UNKOP}       ,                                          // D9 DD
    {OF_FPU, 0xDED9, 0x00, P_NONE, UNKOP}       ,                                          // D9 DE
    {OF_FPU, 0xDFD9, 0x00, P_NONE, UNKOP}       ,                                          // D9 DF

    {OF_FPU, 0xE0D9, 0x00, P_NONE, O_FCHS       , {NOOP          , NOOP          , NOOP}}, // D9 E0
    {OF_FPU, 0xE1D9, 0x00, P_NONE, O_FABS       , {NOOP          , NOOP          , NOOP}}, // D9 E1
    {OF_FPU, 0xE2D9, 0x00, P_NONE, UNKOP}       ,                                          // D9 E2
    {OF_FPU, 0xE3D9, 0x00, P_NONE, UNKOP}       ,                                          // D9 E3
    {OF_FPU, 0xE4D9, 0x00, P_NONE, O_FTST       , {NOOP          , NOOP          , NOOP}}, // D9 E4
    {OF_FPU, 0xE5D9, 0x00, P_NONE, O_FXAM       , {NOOP          , NOOP          , NOOP}}, // D9 E5
    {OF_FPU, 0xE6D9, 0x00, P_NONE, UNKOP}       ,                                          // D9 E6
    {OF_FPU, 0xE7D9, 0x00, P_NONE, UNKOP}       ,                                          // D9 E7

    {OF_FPU, 0xE8D9, 0x00, P_NONE, O_FLD1       , {NOOP          , NOOP          , NOOP}}, // D9 E8
    {OF_FPU, 0xE9D9, 0x00, P_NONE, O_FLDL2T     , {NOOP          , NOOP          , NOOP}}, // D9 E9
    {OF_FPU, 0xEAD9, 0x00, P_NONE, O_FLDL2E     , {NOOP          , NOOP          , NOOP}}, // D9 EA
    {OF_FPU, 0xEBD9, 0x00, P_NONE, O_FLDPI      , {NOOP          , NOOP          , NOOP}}, // D9 EB
    {OF_FPU, 0xECD9, 0x00, P_NONE, O_FLDLG2     , {NOOP          , NOOP          , NOOP}}, // D9 EC
    {OF_FPU, 0xEDD9, 0x00, P_NONE, O_FLDLN2     , {NOOP          , NOOP          , NOOP}}, // D9 ED
    {OF_FPU, 0xEED9, 0x00, P_NONE, O_FLDZ       , {NOOP          , NOOP          , NOOP}}, // D9 EE
    {OF_FPU, 0xEFD9, 0x00, P_NONE, UNKOP}       ,                                          // D9 EF

    {OF_FPU, 0xF0D9, 0x00, P_NONE, O_F2XM1      , {NOOP          , NOOP          , NOOP}}, // D9 F0
    {OF_FPU, 0xF1D9, 0x00, P_NONE, O_FYL2X      , {NOOP          , NOOP          , NOOP}}, // D9 F1
    {OF_FPU, 0xF2D9, 0x00, P_NONE, O_FPTAN      , {NOOP          , NOOP          , NOOP}}, // D9 F2
    {OF_FPU, 0xF3D9, 0x00, P_NONE, O_FPATAN     , {NOOP          , NOOP          , NOOP}}, // D9 F3
    {OF_FPU, 0xF4D9, 0x00, P_NONE, O_FXTRACT    , {NOOP          , NOOP          , NOOP}}, // D9 F4
    {OF_FPU, 0xF5D9, 0x00, P_NONE, O_FPREM1     , {NOOP          , NOOP          , NOOP}}, // D9 F5
    {OF_FPU, 0xF6D9, 0x00, P_NONE, O_FDECSTP    , {NOOP          , NOOP          , NOOP}}, // D9 F6
    {OF_FPU, 0xF7D9, 0x00, P_NONE, O_FINCSTP    , {NOOP          , NOOP          , NOOP}}, // D9 F7

    {OF_FPU, 0xF8D9, 0x00, P_NONE, O_FPREM      , {NOOP          , NOOP          , NOOP}}, // D9 F8
    {OF_FPU, 0xF9D9, 0x00, P_NONE, O_FYL2XP1    , {NOOP          , NOOP          , NOOP}}, // D9 F9
    {OF_FPU, 0xFAD9, 0x00, P_NONE, O_FSQRT      , {NOOP          , NOOP          , NOOP}}, // D9 FA
    {OF_FPU, 0xFBD9, 0x00, P_NONE, O_FSINCOS    , {NOOP          , NOOP          , NOOP}}, // D9 FB
    {OF_FPU, 0xFCD9, 0x00, P_NONE, O_FRNDINT    , {NOOP          , NOOP          , NOOP}}, // D9 FC
    {OF_FPU, 0xFDD9, 0x00, P_NONE, O_FSCALE     , {NOOP          , NOOP          , NOOP}}, // D9 FD
    {OF_FPU, 0xFED9, 0x00, P_NONE, O_FSIN       , {NOOP          , NOOP          , NOOP}}, // D9 FE
    {OF_FPU, 0xFFD9, 0x00, P_NONE, O_FCOS       , {NOOP          , NOOP          , NOOP}}, // D9 FF

    {OF_FPU, 0xC0DA, 0x00, P_NONE, O_FCMOVB     , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DA C0
    {OF_FPU, 0xC1DA, 0x00, P_NONE, O_FCMOVB     , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // DA C1
    {OF_FPU, 0xC2DA, 0x00, P_NONE, O_FCMOVB     , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // DA C2
    {OF_FPU, 0xC3DA, 0x00, P_NONE, O_FCMOVB     , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // DA C3
    {OF_FPU, 0xC4DA, 0x00, P_NONE, O_FCMOVB     , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // DA C4
    {OF_FPU, 0xC5DA, 0x00, P_NONE, O_FCMOVB     , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // DA C5
    {OF_FPU, 0xC6DA, 0x00, P_NONE, O_FCMOVB     , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // DA C6
    {OF_FPU, 0xC7DA, 0x00, P_NONE, O_FCMOVB     , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // DA C7

    {OF_FPU, 0xC8DA, 0x00, P_NONE, O_FCMOVE     , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DA C8
    {OF_FPU, 0xC9DA, 0x00, P_NONE, O_FCMOVE     , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // DA C9
    {OF_FPU, 0xCADA, 0x00, P_NONE, O_FCMOVE     , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // DA CA
    {OF_FPU, 0xCBDA, 0x00, P_NONE, O_FCMOVE     , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // DA CB
    {OF_FPU, 0xCCDA, 0x00, P_NONE, O_FCMOVE     , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // DA CC
    {OF_FPU, 0xCDDA, 0x00, P_NONE, O_FCMOVE     , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // DA CD
    {OF_FPU, 0xCEDA, 0x00, P_NONE, O_FCMOVE     , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // DA CE
    {OF_FPU, 0xCFDA, 0x00, P_NONE, O_FCMOVE     , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // DA CF

    {OF_FPU, 0xD0DA, 0x00, P_NONE, O_FCMOVBE    , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DA D0
    {OF_FPU, 0xD1DA, 0x00, P_NONE, O_FCMOVBE    , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // DA D1
    {OF_FPU, 0xD2DA, 0x00, P_NONE, O_FCMOVBE    , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // DA D2
    {OF_FPU, 0xD3DA, 0x00, P_NONE, O_FCMOVBE    , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // DA D3
    {OF_FPU, 0xD4DA, 0x00, P_NONE, O_FCMOVBE    , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // DA D4
    {OF_FPU, 0xD5DA, 0x00, P_NONE, O_FCMOVBE    , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // DA D5
    {OF_FPU, 0xD6DA, 0x00, P_NONE, O_FCMOVBE    , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // DA D6
    {OF_FPU, 0xD7DA, 0x00, P_NONE, O_FCMOVBE    , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // DA D7

    {OF_FPU, 0xD8DA, 0x00, P_NONE, O_FCMOVU     , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DA D8
    {OF_FPU, 0xD9DA, 0x00, P_NONE, O_FCMOVU     , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // DA D9
    {OF_FPU, 0xDADA, 0x00, P_NONE, O_FCMOVU     , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // DA DA
    {OF_FPU, 0xDBDA, 0x00, P_NONE, O_FCMOVU     , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // DA DB
    {OF_FPU, 0xDCDA, 0x00, P_NONE, O_FCMOVU     , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // DA DC
    {OF_FPU, 0xDDDA, 0x00, P_NONE, O_FCMOVU     , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // DA DD
    {OF_FPU, 0xDEDA, 0x00, P_NONE, O_FCMOVU     , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // DA DE
    {OF_FPU, 0xDFDA, 0x00, P_NONE, O_FCMOVU     , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // DA DF

    {OF_FPU, 0xE0DA, 0x00, P_NONE, UNKOP}       ,                                          // DA E0
    {OF_FPU, 0xE1DA, 0x00, P_NONE, UNKOP}       ,                                          // DA E1
    {OF_FPU, 0xE2DA, 0x00, P_NONE, UNKOP}       ,                                          // DA E2
    {OF_FPU, 0xE3DA, 0x00, P_NONE, UNKOP}       ,                                          // DA E3
    {OF_FPU, 0xE4DA, 0x00, P_NONE, UNKOP}       ,                                          // DA E4
    {OF_FPU, 0xE5DA, 0x00, P_NONE, UNKOP}       ,                                          // DA E5
    {OF_FPU, 0xE6DA, 0x00, P_NONE, UNKOP}       ,                                          // DA E6
    {OF_FPU, 0xE7DA, 0x00, P_NONE, UNKOP}       ,                                          // DA E7

    {OF_FPU, 0xE8DA, 0x00, P_NONE, UNKOP}       ,                                          // DA E8
    {OF_FPU, 0xE9DA, 0x00, P_NONE, O_FUCOMPP    , {NOOP          , NOOP          , NOOP}}, // DA F9
    {OF_FPU, 0xEADA, 0x00, P_NONE, UNKOP}       ,                                          // DA EA
    {OF_FPU, 0xEBDA, 0x00, P_NONE, UNKOP}       ,                                          // DA EB
    {OF_FPU, 0xECDA, 0x00, P_NONE, UNKOP}       ,                                          // DA EC
    {OF_FPU, 0xEDDA, 0x00, P_NONE, UNKOP}       ,                                          // DA ED
    {OF_FPU, 0xEEDA, 0x00, P_NONE, UNKOP}       ,                                          // DA EE
    {OF_FPU, 0xEFDA, 0x00, P_NONE, UNKOP}       ,                                          // DA EF

    {OF_FPU, 0xF0DA, 0x00, P_NONE, UNKOP}       ,                                          // DA F0
    {OF_FPU, 0xF1DA, 0x00, P_NONE, UNKOP}       ,                                          // DA F1
    {OF_FPU, 0xF2DA, 0x00, P_NONE, UNKOP}       ,                                          // DA F2
    {OF_FPU, 0xF3DA, 0x00, P_NONE, UNKOP}       ,                                          // DA F3
    {OF_FPU, 0xF4DA, 0x00, P_NONE, UNKOP}       ,                                          // DA F4
    {OF_FPU, 0xF5DA, 0x00, P_NONE, UNKOP}       ,                                          // DA F5
    {OF_FPU, 0xF6DA, 0x00, P_NONE, UNKOP}       ,                                          // DA F6
    {OF_FPU, 0xF7DA, 0x00, P_NONE, UNKOP}       ,                                          // DA F7

    {OF_FPU, 0xF8DA, 0x00, P_NONE, UNKOP}       ,                                          // DA F8
    {OF_FPU, 0xF9DA, 0x00, P_NONE, UNKOP}       ,                                          // DA F9
    {OF_FPU, 0xFADA, 0x00, P_NONE, UNKOP}       ,                                          // DA FA
    {OF_FPU, 0xFBDA, 0x00, P_NONE, UNKOP}       ,                                          // DA FB
    {OF_FPU, 0xFCDA, 0x00, P_NONE, UNKOP}       ,                                          // DA FC
    {OF_FPU, 0xFDDA, 0x00, P_NONE, UNKOP}       ,                                          // DA FD
    {OF_FPU, 0xFEDA, 0x00, P_NONE, UNKOP}       ,                                          // DA FE
    {OF_FPU, 0xFFDA, 0x00, P_NONE, UNKOP}       ,                                          // DA FF

    {OF_FPU, 0xC0DB, 0x00, P_NONE, O_FCMOVNB    , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DB C0
    {OF_FPU, 0xC1DB, 0x00, P_NONE, O_FCMOVNB    , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // DB C1
    {OF_FPU, 0xC2DB, 0x00, P_NONE, O_FCMOVNB    , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // DB C2
    {OF_FPU, 0xC3DB, 0x00, P_NONE, O_FCMOVNB    , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // DB C3
    {OF_FPU, 0xC4DB, 0x00, P_NONE, O_FCMOVNB    , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // DB C4
    {OF_FPU, 0xC5DB, 0x00, P_NONE, O_FCMOVNB    , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // DB C5
    {OF_FPU, 0xC6DB, 0x00, P_NONE, O_FCMOVNB    , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // DB C6
    {OF_FPU, 0xC7DB, 0x00, P_NONE, O_FCMOVNB    , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // DB C7

    {OF_FPU, 0xC8DB, 0x00, P_NONE, O_FCMOVNE    , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DB C8
    {OF_FPU, 0xC9DB, 0x00, P_NONE, O_FCMOVNE    , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // DB C9
    {OF_FPU, 0xCADB, 0x00, P_NONE, O_FCMOVNE    , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // DB CA
    {OF_FPU, 0xCBDB, 0x00, P_NONE, O_FCMOVNE    , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // DB CB
    {OF_FPU, 0xCCDB, 0x00, P_NONE, O_FCMOVNE    , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // DB CC
    {OF_FPU, 0xCDDB, 0x00, P_NONE, O_FCMOVNE    , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // DB CD
    {OF_FPU, 0xCEDB, 0x00, P_NONE, O_FCMOVNE    , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // DB CE
    {OF_FPU, 0xCFDB, 0x00, P_NONE, O_FCMOVNE    , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // DB CF

    {OF_FPU, 0xD0DB, 0x00, P_NONE, O_FCMOVNBE   , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DB D0
    {OF_FPU, 0xD1DB, 0x00, P_NONE, O_FCMOVNBE   , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // DB D1
    {OF_FPU, 0xD2DB, 0x00, P_NONE, O_FCMOVNBE   , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // DB D2
    {OF_FPU, 0xD3DB, 0x00, P_NONE, O_FCMOVNBE   , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // DB D3
    {OF_FPU, 0xD4DB, 0x00, P_NONE, O_FCMOVNBE   , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // DB D4
    {OF_FPU, 0xD5DB, 0x00, P_NONE, O_FCMOVNBE   , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // DB D5
    {OF_FPU, 0xD6DB, 0x00, P_NONE, O_FCMOVNBE   , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // DB D6
    {OF_FPU, 0xD7DB, 0x00, P_NONE, O_FCMOVNBE   , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // DB D7

    {OF_FPU, 0xD8DB, 0x00, P_NONE, O_FCMOVNU    , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DB D8
    {OF_FPU, 0xD9DB, 0x00, P_NONE, O_FCMOVNU    , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // DB D9
    {OF_FPU, 0xDADB, 0x00, P_NONE, O_FCMOVNU    , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // DB DA
    {OF_FPU, 0xDBDB, 0x00, P_NONE, O_FCMOVNU    , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // DB DB
    {OF_FPU, 0xDCDB, 0x00, P_NONE, O_FCMOVNU    , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // DB DC
    {OF_FPU, 0xDDDB, 0x00, P_NONE, O_FCMOVNU    , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // DB DD
    {OF_FPU, 0xDEDB, 0x00, P_NONE, O_FCMOVNU    , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // DB DE
    {OF_FPU, 0xDFDB, 0x00, P_NONE, O_FCMOVNU    , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // DB DF

    {OF_FPU, 0xE0DB, 0x00, P_NONE, UNKOP}       ,                                          // DB E0
    {OF_FPU, 0xE1DB, 0x00, P_NONE, UNKOP}       ,                                          // DB E1
    {OF_FPU, 0xE2DB, 0x00, P_NONE, O_FCLEX      , {NOOP          , NOOP          , NOOP}}, // DB D2
    {OF_FPU, 0xE3DB, 0x00, P_NONE, O_FINIT      , {NOOP          , NOOP          , NOOP}}, // DB D3
    {OF_FPU, 0xE4DB, 0x00, P_NONE, UNKOP}       ,                                          // DB E4
    {OF_FPU, 0xE5DB, 0x00, P_NONE, UNKOP}       ,                                          // DB E5
    {OF_FPU, 0xE6DB, 0x00, P_NONE, UNKOP}       ,                                          // DB E6
    {OF_FPU, 0xE7DB, 0x00, P_NONE, UNKOP}       ,                                          // DB E7

    {OF_FPU, 0xE8DB, 0x00, P_NONE, O_FUCOMI     , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DB E8
    {OF_FPU, 0xE9DB, 0x00, P_NONE, O_FUCOMI     , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // DB E9
    {OF_FPU, 0xEADB, 0x00, P_NONE, O_FUCOMI     , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // DB EA
    {OF_FPU, 0xEBDB, 0x00, P_NONE, O_FUCOMI     , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // DB EB
    {OF_FPU, 0xECDB, 0x00, P_NONE, O_FUCOMI     , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // DB EC
    {OF_FPU, 0xEDDB, 0x00, P_NONE, O_FUCOMI     , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // DB ED
    {OF_FPU, 0xEEDB, 0x00, P_NONE, O_FUCOMI     , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // DB EE
    {OF_FPU, 0xEFDB, 0x00, P_NONE, O_FUCOMI     , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // DB EF

    {OF_FPU, 0xF0DB, 0x00, P_NONE, O_FCOMI      , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DB F0
    {OF_FPU, 0xF1DB, 0x00, P_NONE, O_FCOMI      , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // DB F1
    {OF_FPU, 0xF2DB, 0x00, P_NONE, O_FCOMI      , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // DB F2
    {OF_FPU, 0xF3DB, 0x00, P_NONE, O_FCOMI      , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // DB F3
    {OF_FPU, 0xF4DB, 0x00, P_NONE, O_FCOMI      , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // DB F4
    {OF_FPU, 0xF5DB, 0x00, P_NONE, O_FCOMI      , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // DB F5
    {OF_FPU, 0xF6DB, 0x00, P_NONE, O_FCOMI      , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // DB F6
    {OF_FPU, 0xF7DB, 0x00, P_NONE, O_FCOMI      , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // DB F7

    {OF_FPU, 0xF8DB, 0x00, P_NONE, UNKOP}       ,                                          // DB F8
    {OF_FPU, 0xF9DB, 0x00, P_NONE, UNKOP}       ,                                          // DB F9
    {OF_FPU, 0xFADB, 0x00, P_NONE, UNKOP}       ,                                          // DB FA
    {OF_FPU, 0xFBDB, 0x00, P_NONE, UNKOP}       ,                                          // DB FB
    {OF_FPU, 0xFCDB, 0x00, P_NONE, UNKOP}       ,                                          // DB FC
    {OF_FPU, 0xFDDB, 0x00, P_NONE, UNKOP}       ,                                          // DB FD
    {OF_FPU, 0xFEDB, 0x00, P_NONE, UNKOP}       ,                                          // DB FE
    {OF_FPU, 0xFFDB, 0x00, P_NONE, UNKOP}       ,                                          // DB FF

    {OF_FPU, 0xC0DC, 0x00, P_NONE, O_FADD       , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DC C0
    {OF_FPU, 0xC1DC, 0x00, P_NONE, O_FADD       , {MKREG(REG_ST1), MKREG(REG_ST0), NOOP}}, // DC C1
    {OF_FPU, 0xC2DC, 0x00, P_NONE, O_FADD       , {MKREG(REG_ST2), MKREG(REG_ST0), NOOP}}, // DC C2
    {OF_FPU, 0xC3DC, 0x00, P_NONE, O_FADD       , {MKREG(REG_ST3), MKREG(REG_ST0), NOOP}}, // DC C3
    {OF_FPU, 0xC4DC, 0x00, P_NONE, O_FADD       , {MKREG(REG_ST4), MKREG(REG_ST0), NOOP}}, // DC C4
    {OF_FPU, 0xC5DC, 0x00, P_NONE, O_FADD       , {MKREG(REG_ST5), MKREG(REG_ST0), NOOP}}, // DC C5
    {OF_FPU, 0xC6DC, 0x00, P_NONE, O_FADD       , {MKREG(REG_ST6), MKREG(REG_ST0), NOOP}}, // DC C6
    {OF_FPU, 0xC7DC, 0x00, P_NONE, O_FADD       , {MKREG(REG_ST7), MKREG(REG_ST0), NOOP}}, // DC C7

    {OF_FPU, 0xC8DC, 0x00, P_NONE, O_FMUL       , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DC C8
    {OF_FPU, 0xC9DC, 0x00, P_NONE, O_FMUL       , {MKREG(REG_ST1), MKREG(REG_ST0), NOOP}}, // DC C9
    {OF_FPU, 0xCADC, 0x00, P_NONE, O_FMUL       , {MKREG(REG_ST2), MKREG(REG_ST0), NOOP}}, // DC CA
    {OF_FPU, 0xCBDC, 0x00, P_NONE, O_FMUL       , {MKREG(REG_ST3), MKREG(REG_ST0), NOOP}}, // DC CB
    {OF_FPU, 0xCCDC, 0x00, P_NONE, O_FMUL       , {MKREG(REG_ST4), MKREG(REG_ST0), NOOP}}, // DC CC
    {OF_FPU, 0xCDDC, 0x00, P_NONE, O_FMUL       , {MKREG(REG_ST5), MKREG(REG_ST0), NOOP}}, // DC CD
    {OF_FPU, 0xCEDC, 0x00, P_NONE, O_FMUL       , {MKREG(REG_ST6), MKREG(REG_ST0), NOOP}}, // DC CE
    {OF_FPU, 0xCFDC, 0x00, P_NONE, O_FMUL       , {MKREG(REG_ST7), MKREG(REG_ST0), NOOP}}, // DC CF

    {OF_FPU, 0xD0DC, 0x00, P_NONE, UNKOP}       ,                                          // DC D0
    {OF_FPU, 0xD1DC, 0x00, P_NONE, UNKOP}       ,                                          // DC D1
    {OF_FPU, 0xD2DC, 0x00, P_NONE, UNKOP}       ,                                          // DC D2
    {OF_FPU, 0xD3DC, 0x00, P_NONE, UNKOP}       ,                                          // DC D3
    {OF_FPU, 0xD4DC, 0x00, P_NONE, UNKOP}       ,                                          // DC D4
    {OF_FPU, 0xD5DC, 0x00, P_NONE, UNKOP}       ,                                          // DC D5
    {OF_FPU, 0xD6DC, 0x00, P_NONE, UNKOP}       ,                                          // DC D6
    {OF_FPU, 0xD7DC, 0x00, P_NONE, UNKOP}       ,                                          // DC D7

    {OF_FPU, 0xD8DC, 0x00, P_NONE, UNKOP}       ,                                          // DC D8
    {OF_FPU, 0xD9DC, 0x00, P_NONE, UNKOP}       ,                                          // DC D9
    {OF_FPU, 0xDADC, 0x00, P_NONE, UNKOP}       ,                                          // DC DA
    {OF_FPU, 0xDBDC, 0x00, P_NONE, UNKOP}       ,                                          // DC DB
    {OF_FPU, 0xDCDC, 0x00, P_NONE, UNKOP}       ,                                          // DC DC
    {OF_FPU, 0xDDDC, 0x00, P_NONE, UNKOP}       ,                                          // DC DD
    {OF_FPU, 0xDEDC, 0x00, P_NONE, UNKOP}       ,                                          // DC DE
    {OF_FPU, 0xDFDC, 0x00, P_NONE, UNKOP}       ,                                          // DC DF

    {OF_FPU, 0xE0DC, 0x00, P_NONE, O_FSUB       , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DC E0
    {OF_FPU, 0xE1DC, 0x00, P_NONE, O_FSUB       , {MKREG(REG_ST1), MKREG(REG_ST0), NOOP}}, // DC E1
    {OF_FPU, 0xE2DC, 0x00, P_NONE, O_FSUB       , {MKREG(REG_ST2), MKREG(REG_ST0), NOOP}}, // DC E2
    {OF_FPU, 0xE3DC, 0x00, P_NONE, O_FSUB       , {MKREG(REG_ST3), MKREG(REG_ST0), NOOP}}, // DC E3
    {OF_FPU, 0xE4DC, 0x00, P_NONE, O_FSUB       , {MKREG(REG_ST4), MKREG(REG_ST0), NOOP}}, // DC E4
    {OF_FPU, 0xE5DC, 0x00, P_NONE, O_FSUB       , {MKREG(REG_ST5), MKREG(REG_ST0), NOOP}}, // DC E5
    {OF_FPU, 0xE6DC, 0x00, P_NONE, O_FSUB       , {MKREG(REG_ST6), MKREG(REG_ST0), NOOP}}, // DC E6
    {OF_FPU, 0xE7DC, 0x00, P_NONE, O_FSUB       , {MKREG(REG_ST7), MKREG(REG_ST0), NOOP}}, // DC E7

    {OF_FPU, 0xE8DC, 0x00, P_NONE, O_FSUBR      , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DC E8
    {OF_FPU, 0xE9DC, 0x00, P_NONE, O_FSUBR      , {MKREG(REG_ST1), MKREG(REG_ST0), NOOP}}, // DC E9
    {OF_FPU, 0xEADC, 0x00, P_NONE, O_FSUBR      , {MKREG(REG_ST2), MKREG(REG_ST0), NOOP}}, // DC EA
    {OF_FPU, 0xEBDC, 0x00, P_NONE, O_FSUBR      , {MKREG(REG_ST3), MKREG(REG_ST0), NOOP}}, // DC EB
    {OF_FPU, 0xECDC, 0x00, P_NONE, O_FSUBR      , {MKREG(REG_ST4), MKREG(REG_ST0), NOOP}}, // DC EC
    {OF_FPU, 0xEDDC, 0x00, P_NONE, O_FSUBR      , {MKREG(REG_ST5), MKREG(REG_ST0), NOOP}}, // DC ED
    {OF_FPU, 0xEEDC, 0x00, P_NONE, O_FSUBR      , {MKREG(REG_ST6), MKREG(REG_ST0), NOOP}}, // DC EE
    {OF_FPU, 0xEFDC, 0x00, P_NONE, O_FSUBR      , {MKREG(REG_ST7), MKREG(REG_ST0), NOOP}}, // DC EF

    {OF_FPU, 0xF0DC, 0x00, P_NONE, O_FDIVR      , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DC F0
    {OF_FPU, 0xF1DC, 0x00, P_NONE, O_FDIVR      , {MKREG(REG_ST1), MKREG(REG_ST0), NOOP}}, // DC F1
    {OF_FPU, 0xF2DC, 0x00, P_NONE, O_FDIVR      , {MKREG(REG_ST2), MKREG(REG_ST0), NOOP}}, // DC F2
    {OF_FPU, 0xF3DC, 0x00, P_NONE, O_FDIVR      , {MKREG(REG_ST3), MKREG(REG_ST0), NOOP}}, // DC F3
    {OF_FPU, 0xF4DC, 0x00, P_NONE, O_FDIVR      , {MKREG(REG_ST4), MKREG(REG_ST0), NOOP}}, // DC F4
    {OF_FPU, 0xF5DC, 0x00, P_NONE, O_FDIVR      , {MKREG(REG_ST5), MKREG(REG_ST0), NOOP}}, // DC F5
    {OF_FPU, 0xF6DC, 0x00, P_NONE, O_FDIVR      , {MKREG(REG_ST6), MKREG(REG_ST0), NOOP}}, // DC F6
    {OF_FPU, 0xF7DC, 0x00, P_NONE, O_FDIVR      , {MKREG(REG_ST7), MKREG(REG_ST0), NOOP}}, // DC F7

    {OF_FPU, 0xF8DC, 0x00, P_NONE, O_FDIV       , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DC F8
    {OF_FPU, 0xF9DC, 0x00, P_NONE, O_FDIV       , {MKREG(REG_ST1), MKREG(REG_ST0), NOOP}}, // DC F9
    {OF_FPU, 0xFADC, 0x00, P_NONE, O_FDIV       , {MKREG(REG_ST2), MKREG(REG_ST0), NOOP}}, // DC FA
    {OF_FPU, 0xFBDC, 0x00, P_NONE, O_FDIV       , {MKREG(REG_ST3), MKREG(REG_ST0), NOOP}}, // DC FB
    {OF_FPU, 0xFCDC, 0x00, P_NONE, O_FDIV       , {MKREG(REG_ST4), MKREG(REG_ST0), NOOP}}, // DC FC
    {OF_FPU, 0xFDDC, 0x00, P_NONE, O_FDIV       , {MKREG(REG_ST5), MKREG(REG_ST0), NOOP}}, // DC FD
    {OF_FPU, 0xFEDC, 0x00, P_NONE, O_FDIV       , {MKREG(REG_ST6), MKREG(REG_ST0), NOOP}}, // DC FE
    {OF_FPU, 0xFFDC, 0x00, P_NONE, O_FDIV       , {MKREG(REG_ST7), MKREG(REG_ST0), NOOP}}, // DC FF

    {OF_FPU, 0xC0DD, 0x00, P_NONE, O_FFREE      , {MKREG(REG_ST0), NOOP          , NOOP}}, // DD C0
    {OF_FPU, 0xC1DD, 0x00, P_NONE, O_FFREE      , {MKREG(REG_ST1), NOOP          , NOOP}}, // DD C1
    {OF_FPU, 0xC2DD, 0x00, P_NONE, O_FFREE      , {MKREG(REG_ST2), NOOP          , NOOP}}, // DD C2
    {OF_FPU, 0xC3DD, 0x00, P_NONE, O_FFREE      , {MKREG(REG_ST3), NOOP          , NOOP}}, // DD C3
    {OF_FPU, 0xC4DD, 0x00, P_NONE, O_FFREE      , {MKREG(REG_ST4), NOOP          , NOOP}}, // DD C4
    {OF_FPU, 0xC5DD, 0x00, P_NONE, O_FFREE      , {MKREG(REG_ST5), NOOP          , NOOP}}, // DD C5
    {OF_FPU, 0xC6DD, 0x00, P_NONE, O_FFREE      , {MKREG(REG_ST6), NOOP          , NOOP}}, // DD C6
    {OF_FPU, 0xC7DD, 0x00, P_NONE, O_FFREE      , {MKREG(REG_ST7), NOOP          , NOOP}}, // DD C7

    {OF_FPU, 0xC8DD, 0x00, P_NONE, UNKOP}       ,                                          // DD C8
    {OF_FPU, 0xC9DD, 0x00, P_NONE, UNKOP}       ,                                          // DD C9
    {OF_FPU, 0xCADD, 0x00, P_NONE, UNKOP}       ,                                          // DD CA
    {OF_FPU, 0xCBDD, 0x00, P_NONE, UNKOP}       ,                                          // DD CB
    {OF_FPU, 0xCCDD, 0x00, P_NONE, UNKOP}       ,                                          // DD CC
    {OF_FPU, 0xCDDD, 0x00, P_NONE, UNKOP}       ,                                          // DD CD
    {OF_FPU, 0xCEDD, 0x00, P_NONE, UNKOP}       ,                                          // DD CE
    {OF_FPU, 0xCFDD, 0x00, P_NONE, UNKOP}       ,                                          // DD CF

    {OF_FPU, 0xD0DD, 0x00, P_NONE, O_FST        , {MKREG(REG_ST0), NOOP          , NOOP}}, // DD D0
    {OF_FPU, 0xD1DD, 0x00, P_NONE, O_FST        , {MKREG(REG_ST1), NOOP          , NOOP}}, // DD D1
    {OF_FPU, 0xD2DD, 0x00, P_NONE, O_FST        , {MKREG(REG_ST2), NOOP          , NOOP}}, // DD D2
    {OF_FPU, 0xD3DD, 0x00, P_NONE, O_FST        , {MKREG(REG_ST3), NOOP          , NOOP}}, // DD D3
    {OF_FPU, 0xD4DD, 0x00, P_NONE, O_FST        , {MKREG(REG_ST4), NOOP          , NOOP}}, // DD D4
    {OF_FPU, 0xD5DD, 0x00, P_NONE, O_FST        , {MKREG(REG_ST5), NOOP          , NOOP}}, // DD D5
    {OF_FPU, 0xD6DD, 0x00, P_NONE, O_FST        , {MKREG(REG_ST6), NOOP          , NOOP}}, // DD D6
    {OF_FPU, 0xD7DD, 0x00, P_NONE, O_FST        , {MKREG(REG_ST7), NOOP          , NOOP}}, // DD D7

    {OF_FPU, 0xD8DD, 0x00, P_NONE, O_FSTP       , {MKREG(REG_ST0), NOOP          , NOOP}}, // DD D8
    {OF_FPU, 0xD9DD, 0x00, P_NONE, O_FSTP       , {MKREG(REG_ST1), NOOP          , NOOP}}, // DD D9
    {OF_FPU, 0xDADD, 0x00, P_NONE, O_FSTP       , {MKREG(REG_ST2), NOOP          , NOOP}}, // DD DA
    {OF_FPU, 0xDBDD, 0x00, P_NONE, O_FSTP       , {MKREG(REG_ST3), NOOP          , NOOP}}, // DD DB
    {OF_FPU, 0xDCDD, 0x00, P_NONE, O_FSTP       , {MKREG(REG_ST4), NOOP          , NOOP}}, // DD DC
    {OF_FPU, 0xDDDD, 0x00, P_NONE, O_FSTP       , {MKREG(REG_ST5), NOOP          , NOOP}}, // DD DD
    {OF_FPU, 0xDEDD, 0x00, P_NONE, O_FSTP       , {MKREG(REG_ST6), NOOP          , NOOP}}, // DD DE
    {OF_FPU, 0xDFDD, 0x00, P_NONE, O_FSTP       , {MKREG(REG_ST7), NOOP          , NOOP}}, // DD DF

    {OF_FPU, 0xE0DD, 0x00, P_NONE, O_FUCOM      , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DD E0
    {OF_FPU, 0xE1DD, 0x00, P_NONE, O_FUCOM      , {MKREG(REG_ST1), MKREG(REG_ST0), NOOP}}, // DD E1
    {OF_FPU, 0xE2DD, 0x00, P_NONE, O_FUCOM      , {MKREG(REG_ST2), MKREG(REG_ST0), NOOP}}, // DD E2
    {OF_FPU, 0xE3DD, 0x00, P_NONE, O_FUCOM      , {MKREG(REG_ST3), MKREG(REG_ST0), NOOP}}, // DD E3
    {OF_FPU, 0xE4DD, 0x00, P_NONE, O_FUCOM      , {MKREG(REG_ST4), MKREG(REG_ST0), NOOP}}, // DD E4
    {OF_FPU, 0xE5DD, 0x00, P_NONE, O_FUCOM      , {MKREG(REG_ST5), MKREG(REG_ST0), NOOP}}, // DD E5
    {OF_FPU, 0xE6DD, 0x00, P_NONE, O_FUCOM      , {MKREG(REG_ST6), MKREG(REG_ST0), NOOP}}, // DD E6
    {OF_FPU, 0xE7DD, 0x00, P_NONE, O_FUCOM      , {MKREG(REG_ST7), MKREG(REG_ST0), NOOP}}, // DD E7

    {OF_FPU, 0xE8DD, 0x00, P_NONE, O_FUCOMP     , {MKREG(REG_ST0), NOOP          , NOOP}}, // DD E8
    {OF_FPU, 0xE9DD, 0x00, P_NONE, O_FUCOMP     , {MKREG(REG_ST1), NOOP          , NOOP}}, // DD E9
    {OF_FPU, 0xEADD, 0x00, P_NONE, O_FUCOMP     , {MKREG(REG_ST2), NOOP          , NOOP}}, // DD EA
    {OF_FPU, 0xEBDD, 0x00, P_NONE, O_FUCOMP     , {MKREG(REG_ST3), NOOP          , NOOP}}, // DD EB
    {OF_FPU, 0xECDD, 0x00, P_NONE, O_FUCOMP     , {MKREG(REG_ST4), NOOP          , NOOP}}, // DD EC
    {OF_FPU, 0xEDDD, 0x00, P_NONE, O_FUCOMP     , {MKREG(REG_ST5), NOOP          , NOOP}}, // DD ED
    {OF_FPU, 0xEEDD, 0x00, P_NONE, O_FUCOMP     , {MKREG(REG_ST6), NOOP          , NOOP}}, // DD EE
    {OF_FPU, 0xEFDD, 0x00, P_NONE, O_FUCOMP     , {MKREG(REG_ST7), NOOP          , NOOP}}, // DD EF

    {OF_FPU, 0xF0DD, 0x00, P_NONE, UNKOP}       ,                                          // DD F8
    {OF_FPU, 0xF1DD, 0x00, P_NONE, UNKOP}       ,                                          // DD F9
    {OF_FPU, 0xF2DD, 0x00, P_NONE, UNKOP}       ,                                          // DD FA
    {OF_FPU, 0xF3DD, 0x00, P_NONE, UNKOP}       ,                                          // DD FB
    {OF_FPU, 0xF4DD, 0x00, P_NONE, UNKOP}       ,                                          // DD FC
    {OF_FPU, 0xF5DD, 0x00, P_NONE, UNKOP}       ,                                          // DD FD
    {OF_FPU, 0xF6DD, 0x00, P_NONE, UNKOP}       ,                                          // DD FE
    {OF_FPU, 0xF7DD, 0x00, P_NONE, UNKOP}       ,                                          // DD FF

    {OF_FPU, 0xF8DD, 0x00, P_NONE, UNKOP}       ,                                          // DD F8
    {OF_FPU, 0xF9DD, 0x00, P_NONE, UNKOP}       ,                                          // DD F9
    {OF_FPU, 0xFADD, 0x00, P_NONE, UNKOP}       ,                                          // DD FA
    {OF_FPU, 0xFBDD, 0x00, P_NONE, UNKOP}       ,                                          // DD FB
    {OF_FPU, 0xFCDD, 0x00, P_NONE, UNKOP}       ,                                          // DD FC
    {OF_FPU, 0xFDDD, 0x00, P_NONE, UNKOP}       ,                                          // DD FD
    {OF_FPU, 0xFEDD, 0x00, P_NONE, UNKOP}       ,                                          // DD FE
    {OF_FPU, 0xFFDD, 0x00, P_NONE, UNKOP}       ,                                          // DD FF

    {OF_FPU, 0xC0DE, 0x00, P_NONE, O_FADDP      , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DE C0
    {OF_FPU, 0xC1DE, 0x00, P_NONE, O_FADDP      , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // DE C1
    {OF_FPU, 0xC2DE, 0x00, P_NONE, O_FADDP      , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // DE C2
    {OF_FPU, 0xC3DE, 0x00, P_NONE, O_FADDP      , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // DE C3
    {OF_FPU, 0xC4DE, 0x00, P_NONE, O_FADDP      , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // DE C4
    {OF_FPU, 0xC5DE, 0x00, P_NONE, O_FADDP      , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // DE C5
    {OF_FPU, 0xC6DE, 0x00, P_NONE, O_FADDP      , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // DE C6
    {OF_FPU, 0xC7DE, 0x00, P_NONE, O_FADDP      , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // DE C7

    {OF_FPU, 0xC8DE, 0x00, P_NONE, O_FMULP      , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DE C8
    {OF_FPU, 0xC9DE, 0x00, P_NONE, O_FMULP      , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // DE C9
    {OF_FPU, 0xCADE, 0x00, P_NONE, O_FMULP      , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // DE CA
    {OF_FPU, 0xCBDE, 0x00, P_NONE, O_FMULP      , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // DE CB
    {OF_FPU, 0xCCDE, 0x00, P_NONE, O_FMULP      , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // DE CC
    {OF_FPU, 0xCDDE, 0x00, P_NONE, O_FMULP      , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // DE CD
    {OF_FPU, 0xCEDE, 0x00, P_NONE, O_FMULP      , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // DE CE
    {OF_FPU, 0xCFDE, 0x00, P_NONE, O_FMULP      , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // DE CF

    {OF_FPU, 0xD0DE, 0x00, P_NONE, UNKOP}       ,                                          // DE D0
    {OF_FPU, 0xD1DE, 0x00, P_NONE, UNKOP}       ,                                          // DE D1
    {OF_FPU, 0xD2DE, 0x00, P_NONE, UNKOP}       ,                                          // DE D2
    {OF_FPU, 0xD3DE, 0x00, P_NONE, UNKOP}       ,                                          // DE D3
    {OF_FPU, 0xD4DE, 0x00, P_NONE, UNKOP}       ,                                          // DE D4
    {OF_FPU, 0xD5DE, 0x00, P_NONE, UNKOP}       ,                                          // DE D5
    {OF_FPU, 0xD6DE, 0x00, P_NONE, UNKOP}       ,                                          // DE D6
    {OF_FPU, 0xD7DE, 0x00, P_NONE, UNKOP}       ,                                          // DE D7

    {OF_FPU, 0xD8DE, 0x00, P_NONE, UNKOP}       ,                                          // DE D8
    {OF_FPU, 0xD9DE, 0x00, P_NONE, O_FCOMPP     , {NOOP         , NOOP           , NOOP}}, // DE D9
    {OF_FPU, 0xDADE, 0x00, P_NONE, UNKOP}       ,                                          // DE DA
    {OF_FPU, 0xDBDE, 0x00, P_NONE, UNKOP}       ,                                          // DE DB
    {OF_FPU, 0xDCDE, 0x00, P_NONE, UNKOP}       ,                                          // DE DC
    {OF_FPU, 0xDDDE, 0x00, P_NONE, UNKOP}       ,                                          // DE DD
    {OF_FPU, 0xDEDE, 0x00, P_NONE, UNKOP}       ,                                          // DE DE
    {OF_FPU, 0xDFDE, 0x00, P_NONE, UNKOP}       ,                                          // DE DF

    {OF_FPU, 0xE0DE, 0x00, P_NONE, O_FSUBRP     , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DE E0
    {OF_FPU, 0xE1DE, 0x00, P_NONE, O_FSUBRP     , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // DE E1
    {OF_FPU, 0xE2DE, 0x00, P_NONE, O_FSUBRP     , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // DE E2
    {OF_FPU, 0xE3DE, 0x00, P_NONE, O_FSUBRP     , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // DE E3
    {OF_FPU, 0xE4DE, 0x00, P_NONE, O_FSUBRP     , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // DE E4
    {OF_FPU, 0xE5DE, 0x00, P_NONE, O_FSUBRP     , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // DE E5
    {OF_FPU, 0xE6DE, 0x00, P_NONE, O_FSUBRP     , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // DE E6
    {OF_FPU, 0xE7DE, 0x00, P_NONE, O_FSUBRP     , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // DE E7

    {OF_FPU, 0xE8DE, 0x00, P_NONE, O_FSUBP      , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DE E8
    {OF_FPU, 0xE9DE, 0x00, P_NONE, O_FSUBP      , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // DE E9
    {OF_FPU, 0xEADE, 0x00, P_NONE, O_FSUBP      , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // DE EA
    {OF_FPU, 0xEBDE, 0x00, P_NONE, O_FSUBP      , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // DE EB
    {OF_FPU, 0xECDE, 0x00, P_NONE, O_FSUBP      , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // DE EC
    {OF_FPU, 0xEDDE, 0x00, P_NONE, O_FSUBP      , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // DE ED
    {OF_FPU, 0xEEDE, 0x00, P_NONE, O_FSUBP      , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // DE EE
    {OF_FPU, 0xEFDE, 0x00, P_NONE, O_FSUBP      , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // DE EF

    {OF_FPU, 0xF0DE, 0x00, P_NONE, O_FDIVRP     , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DE F0
    {OF_FPU, 0xF1DE, 0x00, P_NONE, O_FDIVRP     , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // DE F1
    {OF_FPU, 0xF2DE, 0x00, P_NONE, O_FDIVRP     , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // DE F2
    {OF_FPU, 0xF3DE, 0x00, P_NONE, O_FDIVRP     , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // DE F3
    {OF_FPU, 0xF4DE, 0x00, P_NONE, O_FDIVRP     , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // DE F4
    {OF_FPU, 0xF5DE, 0x00, P_NONE, O_FDIVRP     , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // DE F5
    {OF_FPU, 0xF6DE, 0x00, P_NONE, O_FDIVRP     , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // DE F6
    {OF_FPU, 0xF7DE, 0x00, P_NONE, O_FDIVRP     , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // DE F7

    {OF_FPU, 0xF8DE, 0x00, P_NONE, O_FDIVP      , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DE F8
    {OF_FPU, 0xF9DE, 0x00, P_NONE, O_FDIVP      , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // DE F9
    {OF_FPU, 0xFADE, 0x00, P_NONE, O_FDIVP      , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // DE FA
    {OF_FPU, 0xFBDE, 0x00, P_NONE, O_FDIVP      , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // DE FB
    {OF_FPU, 0xFCDE, 0x00, P_NONE, O_FDIVP      , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // DE FC
    {OF_FPU, 0xFDDE, 0x00, P_NONE, O_FDIVP      , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // DE FD
    {OF_FPU, 0xFEDE, 0x00, P_NONE, O_FDIVP      , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // DE FE
    {OF_FPU, 0xFFDE, 0x00, P_NONE, O_FDIVP      , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // DE FF

    {OF_FPU, 0xC0DF, 0x00, P_NONE, UNKOP}       ,                                          // DF C0
    {OF_FPU, 0xC1DF, 0x00, P_NONE, UNKOP}       ,                                          // DF C1
    {OF_FPU, 0xC2DF, 0x00, P_NONE, UNKOP}       ,                                          // DF C2
    {OF_FPU, 0xC3DF, 0x00, P_NONE, UNKOP}       ,                                          // DF C3
    {OF_FPU, 0xC4DF, 0x00, P_NONE, UNKOP}       ,                                          // DF C4
    {OF_FPU, 0xC5DF, 0x00, P_NONE, UNKOP}       ,                                          // DF C5
    {OF_FPU, 0xC6DF, 0x00, P_NONE, UNKOP}       ,                                          // DF C6
    {OF_FPU, 0xC7DF, 0x00, P_NONE, UNKOP}       ,                                          // DF C7

    {OF_FPU, 0xC8DF, 0x00, P_NONE, UNKOP}       ,                                          // DF C8
    {OF_FPU, 0xC9DF, 0x00, P_NONE, UNKOP}       ,                                          // DF C9
    {OF_FPU, 0xCADF, 0x00, P_NONE, UNKOP}       ,                                          // DF CA
    {OF_FPU, 0xCBDF, 0x00, P_NONE, UNKOP}       ,                                          // DF CB
    {OF_FPU, 0xCCDF, 0x00, P_NONE, UNKOP}       ,                                          // DF CC
    {OF_FPU, 0xCDDF, 0x00, P_NONE, UNKOP}       ,                                          // DF CD
    {OF_FPU, 0xCEDF, 0x00, P_NONE, UNKOP}       ,                                          // DF CE
    {OF_FPU, 0xCFDF, 0x00, P_NONE, UNKOP}       ,                                          // DF CF

    {OF_FPU, 0xD0DF, 0x00, P_NONE, UNKOP}       ,                                          // DF D0
    {OF_FPU, 0xD1DF, 0x00, P_NONE, UNKOP}       ,                                          // DF D1
    {OF_FPU, 0xD2DF, 0x00, P_NONE, UNKOP}       ,                                          // DF D2
    {OF_FPU, 0xD3DF, 0x00, P_NONE, UNKOP}       ,                                          // DF D3
    {OF_FPU, 0xD4DF, 0x00, P_NONE, UNKOP}       ,                                          // DF D4
    {OF_FPU, 0xD5DF, 0x00, P_NONE, UNKOP}       ,                                          // DF D5
    {OF_FPU, 0xD6DF, 0x00, P_NONE, UNKOP}       ,                                          // DF D6
    {OF_FPU, 0xD7DF, 0x00, P_NONE, UNKOP}       ,                                          // DF D7

    {OF_FPU, 0xD8DF, 0x00, P_NONE, UNKOP}       ,                                          // DF D8
    {OF_FPU, 0xD9DF, 0x00, P_NONE, UNKOP}       ,                                          // DF D9
    {OF_FPU, 0xDADF, 0x00, P_NONE, UNKOP}       ,                                          // DF DA
    {OF_FPU, 0xDBDF, 0x00, P_NONE, UNKOP}       ,                                          // DF DB
    {OF_FPU, 0xDCDF, 0x00, P_NONE, UNKOP}       ,                                          // DF DC
    {OF_FPU, 0xDDDF, 0x00, P_NONE, UNKOP}       ,                                          // DF DD
    {OF_FPU, 0xDEDF, 0x00, P_NONE, UNKOP}       ,                                          // DF DE
    {OF_FPU, 0xDFDF, 0x00, P_NONE, UNKOP}       ,                                          // DF DF

    {OF_FPU, 0xE0DF, 0x00, P_NONE, O_FSTSW      , {MKREG(REG_AX) , NOOP          , NOOP}}, // DF E0
    {OF_FPU, 0xE1DF, 0x00, P_NONE, UNKOP}       ,                                          // DF E1
    {OF_FPU, 0xE2DF, 0x00, P_NONE, UNKOP}       ,                                          // DF E2
    {OF_FPU, 0xE3DF, 0x00, P_NONE, UNKOP}       ,                                          // DF E3
    {OF_FPU, 0xE4DF, 0x00, P_NONE, UNKOP}       ,                                          // DF E4
    {OF_FPU, 0xE5DF, 0x00, P_NONE, UNKOP}       ,                                          // DF E5
    {OF_FPU, 0xE6DF, 0x00, P_NONE, UNKOP}       ,                                          // DF E6
    {OF_FPU, 0xE7DF, 0x00, P_NONE, UNKOP}       ,                                          // DF E7

    {OF_FPU, 0xE8DF, 0x00, P_NONE, O_FUCOMIP    , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DF E8
    {OF_FPU, 0xE9DF, 0x00, P_NONE, O_FUCOMIP    , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // DF E9
    {OF_FPU, 0xEADF, 0x00, P_NONE, O_FUCOMIP    , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // DF EA
    {OF_FPU, 0xEBDF, 0x00, P_NONE, O_FUCOMIP    , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // DF EB
    {OF_FPU, 0xECDF, 0x00, P_NONE, O_FUCOMIP    , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // DF EC
    {OF_FPU, 0xEDDF, 0x00, P_NONE, O_FUCOMIP    , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // DF ED
    {OF_FPU, 0xEEDF, 0x00, P_NONE, O_FUCOMIP    , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // DF EE
    {OF_FPU, 0xEFDF, 0x00, P_NONE, O_FUCOMIP    , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // DF EF

    {OF_FPU, 0xF0DF, 0x00, P_NONE, O_FCOMIP     , {MKREG(REG_ST0), MKREG(REG_ST0), NOOP}}, // DF F0
    {OF_FPU, 0xF1DF, 0x00, P_NONE, O_FCOMIP     , {MKREG(REG_ST0), MKREG(REG_ST1), NOOP}}, // DF F1
    {OF_FPU, 0xF2DF, 0x00, P_NONE, O_FCOMIP     , {MKREG(REG_ST0), MKREG(REG_ST2), NOOP}}, // DF F2
    {OF_FPU, 0xF3DF, 0x00, P_NONE, O_FCOMIP     , {MKREG(REG_ST0), MKREG(REG_ST3), NOOP}}, // DF F3
    {OF_FPU, 0xF4DF, 0x00, P_NONE, O_FCOMIP     , {MKREG(REG_ST0), MKREG(REG_ST4), NOOP}}, // DF F4
    {OF_FPU, 0xF5DF, 0x00, P_NONE, O_FCOMIP     , {MKREG(REG_ST0), MKREG(REG_ST5), NOOP}}, // DF F5
    {OF_FPU, 0xF6DF, 0x00, P_NONE, O_FCOMIP     , {MKREG(REG_ST0), MKREG(REG_ST6), NOOP}}, // DF F6
    {OF_FPU, 0xF7DF, 0x00, P_NONE, O_FCOMIP     , {MKREG(REG_ST0), MKREG(REG_ST7), NOOP}}, // DF F7

    {OF_FPU, 0xF8DF, 0x00, P_NONE, UNKOP}       ,                                          // DF F8
    {OF_FPU, 0xF9DF, 0x00, P_NONE, UNKOP}       ,                                          // DF F9
    {OF_FPU, 0xFADF, 0x00, P_NONE, UNKOP}       ,                                          // DF FA
    {OF_FPU, 0xFBDF, 0x00, P_NONE, UNKOP}       ,                                          // DF FB
    {OF_FPU, 0xFCDF, 0x00, P_NONE, UNKOP}       ,                                          // DF FC
    {OF_FPU, 0xFDDF, 0x00, P_NONE, UNKOP}       ,                                          // DF FD
    {OF_FPU, 0xFEDF, 0x00, P_NONE, UNKOP}       ,                                          // DF FE
    {OF_FPU, 0xFFDF, 0x00, P_NONE, UNKOP}                                                  // DF FF
};

/// FPU opcode table for ModR/M > 0xBF length
extern const std::size_t FPUOpcodeTableHighLength = sizeof(FPUOpcodeTableHigh) / sizeof(Opcode);

}
