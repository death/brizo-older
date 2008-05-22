/** @file prefix.h \brief Brizo instruction prefix declarations. */
// $Workfile: prefix.h $
//
// Brizo Disassembler by DEATH, 2003-2004
//
// Instruction prefix header.
//
// $Author: Death $
// $Revision: 12 $
// $Date: 11/22/04 21:33 $
//
// $NoKeywords: $
//
#ifndef BRIZO_INC_PREFIX_H
#define BRIZO_INC_PREFIX_H

#include "brizo.h"

namespace Brizo_DE20041115
{

/// Instruction prefix group
enum PrefixGroup
{
    PG_LOCK_REP = 1,            ///< Group 1 - Lock and repeat prefixes
    PG_SEG_BRANCH,              ///< Group 2 - Segment override prefixes and branch hints (only used in Jcc)
    PG_OP_OVERRIDE,             ///< Group 3 - Operand size override
    PG_ADDR_OVERRIDE            ///< Group 4 - Address size override
};

/// Prefix types
enum PrefixEnum
{
    P_NONE = 0x00,
    // Group 1 -- Lock and repeat prefixes
    P_LOCK = 0xF0,
    P_REPNE = 0xF2,
    P_REPE = 0xF3,
    // Group 2 -- Segment override prefixes and branch hints (only used in Jcc)
    P_SEG_CS = 0x2E,
    P_SEG_SS = 0x36,
    P_SEG_DS = 0x3E,
    P_SEG_ES = 0x26,
    P_SEG_FS = 0x64,
    P_SEG_GS = 0x65,
    P_BRANCH_NOT_TAKEN = 0x2E,
    P_BRANCH_TAKEN = 0x3E,
    // Group 3 -- Operand size override
    P_OVERRIDE_OP = 0x66,
    // Group 4 -- Address size override
    P_OVERRIDE_ADDR = 0x67
};

/// Prefix structure
struct Prefix
{
    // HACK: Index is here to ease use in formatter
    unsigned int index;         ///< Index in prefix table
    PrefixGroup group;          ///< The prefix group this prefix belongs to
    PrefixEnum code;            ///< The prefix type
};

}

#endif // BRIZO_INC_PREFIX_H
