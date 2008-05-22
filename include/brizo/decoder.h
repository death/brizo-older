/** @file decoder.h \brief Brizo decoder interface. */
// $Workfile: decoder.h $
//
// Brizo Disassembler by DEATH, 2003-2004
//
// Decoder class header.
//
// $Author: Death $
// $Revision: 28 $
// $Date: 11/22/04 21:33 $
//
// $NoKeywords: $
//
#ifndef BRIZO_INC_DECODER_H
#define BRIZO_INC_DECODER_H

#include <cstddef>
#include <memory>
#include "brizo.h"
#include "types.h"

namespace Brizo_DE20041115
{

/// The Brizo instruction decoder
class Decoder
{
public:
    Decoder();
    virtual ~Decoder();

    /// Copy constructor
    Decoder(const Decoder & other);

    /// Assignment operator
    Decoder & operator= (const Decoder & rhs);

    /// Decode an instruction
    /// @param mem The memory buffer holding the instruction bytes
    /// @param length The buffer length
    /// @param dmDefaultAddress Default address size decoding mode
    /// @param dmDefaultOperand Default operand size decoding mode
    /// @return A signed integer
    /// @return If positive, represents the decoded instruction size in bytes
    /// If zero or negative, the decoder failed to decode the instruction
    /// and the absolute value is the number of bytes that were read before
    /// the decoding failed
    int Decode(const unsigned char *mem, std::size_t length, DecodeMode dmDefaultAddress = DM_32BIT, DecodeMode dmDefaultOperand = DM_32BIT);

protected:
    // Helper functions (for derived disassembler implementations)

    /// Determines if there's a decoded instruction ready for formatting
    /// @return true if there is a decoded instruction, false if there isn't
    /// @see Decode()
    bool CanFormat() const;

    /// Retrieves the decoded instruction's opcode type
    /// @return The opcode type
    /// @see Decode()
    /// @see OpcodeType
    OpcodeType GetOpcodeType() const;

    /// Retrieves number of operands in decoded instruction
    /// @return The number of operands
    /// @see Decode()
    /// @see GetOperandType()
    /// @see GetOperandValue()
    std::size_t GetOperandCount() const;

    /// Retrieves the decoded instruction's operand type
    /// @param index Index of the operand
    /// @return The operand type
    /// @see Decode()
    /// @see GetOperandCount()
    OperandType GetOperandType(std::size_t index) const;

    /// Retrieves the decoded instruction's operand size decode mode
    /// @return The operand size mode
    /// @see Decode()
    DecodeMode GetOperandDecodeMode() const;

    /// Retrieves the decoded instruction's address size decode mode
    /// @return The address size mode
    /// @see Decode()
    DecodeMode GetAddressDecodeMode() const;

    /// Retrieves a decoded instruction's operand's value
    /// @param index Index of the operand
    /// @return The operand's value
    /// @see Decode()
    /// @see GetOperandCount()
    const OperandValue & GetOperandValue(std::size_t index) const;

    /// Retrieves a decoded instruction's prefix
    /// @param index Index of the prefix
    /// @return The prefix
    /// @see Decode()
    /// @see GetPrefixCount()
    const Prefix & GetPrefix(std::size_t index) const;

    /// Retrieves number of prefixes in decoded instruction
    /// @return The number of prefixes
    /// @see Decode()
    /// @see GetPrefix()
    std::size_t GetPrefixCount() const;

    /// Retrieves instruction length
    /// @return Instruction length
    /// @see Decode()
    int GetInstructionLength() const;

private:
    struct Impl;
    friend Impl;
    std::auto_ptr<Impl> m_pimpl;
};

}

#endif // BRIZO_INC_DECODER_H
