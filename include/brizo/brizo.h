/** @file brizo.h \brief Brizo general header. */
// $Workfile: brizo.h $
//
// Brizo Disassembler by DEATH, 2003-2004
//
// Namespace helper and other stuff.
//
// $Author: Death $
// $Revision: 2 $
// $Date: 11/22/04 21:33 $
//
// $NoKeywords: $
//
#ifndef BRIZO_INC_BRIZO_H
#define BRIZO_INC_BRIZO_H

// VC6 hack
#if defined(_MSC_VER) && (_MSC_VER < 1300)
namespace std
{
	typedef unsigned int size_t;
}
#endif

/// The namespace all Brizo public declarations go into
namespace Brizo_DE20041115
{
}

namespace Brizo = Brizo_DE20041115;

#endif // BRIZO_INC_BRIZO_H
