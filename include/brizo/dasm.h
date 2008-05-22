/** @file dasm.h \brief Brizo default disassembler interface. */
// $Workfile: dasm.h $
//
// Brizo Disassembler by DEATH, 2003-2004
//
// Disassembler with default formatter header.
//
// $Author: Death $
// $Revision: 20 $
// $Date: 11/22/04 21:33 $
//
// $NoKeywords: $
//
#ifndef BRIZO_INC_DASM_H
#define BRIZO_INC_DASM_H

#include <cstddef>
#include <memory>
#include "brizo.h"
#include "decoder.h"

namespace Brizo_DE20041115
{

/// The Brizo default disassembler
class Disassembler : public Decoder
{
public:
    Disassembler();
    virtual ~Disassembler();

    /// Copy constructor
    Disassembler(const Disassembler & other);

    /// Assignment operator
    Disassembler & operator= (const Disassembler & rhs);

    /// Format the decoded instruction
    /// @param address The address where the instruction is supposed to be
    /// @see Decode()
    void Format(unsigned int address);

    /// Retrieve formatted instruction prefix
    /// @return A C string representation of the prefix
    /// @see Format()
    const char *GetFormattedPrefix() const;

    /// Retrieve formatted instruction opcode
    /// @return A C string representation of the opcode
    /// @see Format()
    const char *GetFormattedOpcode() const;

    /// Retrieve formatted instruction operand
    /// @param index The operand's index
    /// @return A C string representation of the operand
    /// @see Format()
    /// @see GetOperandCount()
    const char *GetFormattedOperand(std::size_t index) const;

    /// Retrieve number of operands in formatted instruction
    /// @return The number of operands
    /// @see Format()
    /// @see GetFormattedOperand()
    using Decoder::GetOperandCount;

private:
    struct Impl;
    friend Impl;
    std::auto_ptr<Impl> m_pimpl;
};

}

#endif // BRIZO_INC_DASM_H
