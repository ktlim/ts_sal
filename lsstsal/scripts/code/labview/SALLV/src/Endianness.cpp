// ============================================================================
//
// = CONTEXT
//   SALLV Generic Client for LabVIEW
//
// = FILENAME
//   Endianness.cpp - CODE STOLEN FROM THE FABULOUS ACE FRAMEWORK
//
// = ORIGINAL AUTHORS
//   Aniruddha Gokhale <gokhale@cs.wustl.edu>
//   Carlos O'Ryan<coryan@cs.wustl.edu>
//   Jeff Parsons <parsons@cs.wustl.edu>
//   Istvan Buki	<istvan.buki@euronet.be>
//
// = HACKER
//   Nicolas Leclercq - SOLEIL : SAL adaptation : Dave Mills - LSST
//
// ============================================================================

//=============================================================================
// IMPL OPTION
//=============================================================================
#if !defined(DISABLE_POLYMORPHIC_IMPL)

//=============================================================================
// DEPENDENCIES
//=============================================================================
#include "StandardHeader.h"
#include "Endianness.h"

#if !defined (_LV_INLINE_)
  #include "Endianness.i"
#endif 

//=============================================================================
// BASE TYPE FOR POINTERS ARITH
//=============================================================================
typedef u_long ptr_arith_t;

//=============================================================================
// ALIGN_BINARY
//=============================================================================
#define ALIGN_BINARY(ptr, alignment) \
    ((ptr + ((ptr_arith_t)((alignment)-1))) & (~((ptr_arith_t)((alignment)-1))))

//=============================================================================
// PTR_ALIGN_BINARY
//=============================================================================
#define PTR_ALIGN_BINARY(ptr, alignment) \
        ((char *) ALIGN_BINARY (((ptr_arith_t) (ptr)), (alignment)))

//=============================================================================
// Endianness::swap_2_array
//=============================================================================
void Endianness::swap_2_array (const char* orig, char* target, size_t n)
{
  const char* const o4 = PTR_ALIGN_BINARY(orig, 4);
  // this is an _if_, not a _while_. The mistmatch can only be by 2.
  if (orig != o4)
    {
      Endianness::swap_2 (orig, target);
      orig += 2;
      target += 2;
      --n;
    }

  if (n == 0)
    return;

  const char* const end = orig + 2 * (n & (~3));

  if (target == PTR_ALIGN_BINARY(target, 4))
  {
    while (orig < end)
    {
#if (_TBFL_HAS_PENTIUM_ == 1)
# if defined(__GNUG__)
    unsigned int a = *reinterpret_cast<const unsigned int*>(orig);
    unsigned int b = *reinterpret_cast<const unsigned int*>(orig + 4);
    asm( "bswap %1"      : "=r" (a) : "0" (a) );
    asm( "bswap %1"      : "=r" (b) : "0" (b) );
    asm( "rol $16, %1"   : "=r" (a) : "0" (a) );
    asm( "rol $16, %1"   : "=r" (b) : "0" (b) );
    *reinterpret_cast<unsigned int*>(target) = a;
    *reinterpret_cast<unsigned int*>(target + 4) = b;
# elif defined(_MSC_VER)
    __asm mov ecx, orig;
    __asm mov edx, target;
    __asm mov eax, [ecx];
    __asm mov ebx, 4[ecx];
    __asm bswap eax;
    __asm bswap ebx;
    __asm rol eax, 16;
    __asm rol ebx, 16;
    __asm mov [edx], eax;
    __asm mov 4[edx], ebx;
# endif
#endif
      orig += 8;
      target += 8;
    }
  }
  else
  {
    // We're out of luck. We have to write in 2 byte chunks.
    while (orig < end)
    {
#if (_TBFL_HAS_PENTIUM_ == 1)
# if defined(__GNUG__)
    unsigned int a = *reinterpret_cast<const unsigned int*>(orig);
    unsigned int b = *reinterpret_cast<const unsigned int*>(orig + 4);
    asm( "bswap %1" : "=r" (a) : "0" (a) );
    asm( "bswap %1" : "=r" (b) : "0" (b) );
    // We're little endian.
    *reinterpret_cast<unsigned short*>(target + 2) = (unsigned short)(a & 0xffff);
    *reinterpret_cast<unsigned short*>(target + 6) = (unsigned short)(b & 0xffff);
    asm( "shrl $16, %1" : "=r" (a) : "0" (a) );
    asm( "shrl $16, %1" : "=r" (b) : "0" (b) );
    *reinterpret_cast<unsigned short*>(target + 0) = (unsigned short)(a & 0xffff);
    *reinterpret_cast<unsigned short*>(target + 4) = (unsigned short)(b & 0xffff);
# elif defined(_MSC_VER)
    __asm mov ecx, orig;
    __asm mov edx, target;
    __asm mov eax, [ecx];
    __asm mov ebx, 4[ecx];
    __asm bswap eax;
    __asm bswap ebx;
    // We're little endian.
    __asm mov 2[edx], ax;
    __asm mov 6[edx], bx;
    __asm shr eax, 16;
    __asm shr ebx, 16;
    __asm mov 0[edx], ax;
    __asm mov 4[edx], bx;
# endif
#endif
      orig += 8;
      target += 8;
    }
  }

  // (n & 3) == (n % 4).
  switch (n&3) 
  {
    case 3:
      Endianness::swap_2 (orig, target);
      orig += 2;
      target += 2;
    case 2:
      Endianness::swap_2 (orig, target);
      orig += 2;
      target += 2;
    case 1:
      Endianness::swap_2 (orig, target);
  }
}

//=============================================================================
// Endianness::swap_4_array
//=============================================================================
void Endianness::swap_4_array (const char* orig, char* target, size_t n)
{
  if (n == 0)
    return;

  // (n & (~3)) is the greatest multiple of 4 not bigger than n.
  // In the while loop, orig will move over the array by 16 byte
  // increments (4 elements of 4 bytes).
  // ends marks our barrier for not falling outside.
  const char* const end = orig + 4 * (n & (~3));

  while (orig < end)
  {
#if (_TBFL_HAS_PENTIUM_ == 1)
# if defined(__GNUG__)
    register unsigned int a = *reinterpret_cast<const unsigned int*>(orig);
    register unsigned int b = *reinterpret_cast<const unsigned int*>(orig + 4);
    register unsigned int c = *reinterpret_cast<const unsigned int*>(orig + 8);
    register unsigned int d = *reinterpret_cast<const unsigned int*>(orig + 12);
    asm ("bswap %1" : "=r" (a) : "0" (a));
    asm ("bswap %1" : "=r" (b) : "0" (b));
    asm ("bswap %1" : "=r" (c) : "0" (c));
    asm ("bswap %1" : "=r" (d) : "0" (d));
    *reinterpret_cast<unsigned int*>(target) = a;
    *reinterpret_cast<unsigned int*>(target + 4) = b;
    *reinterpret_cast<unsigned int*>(target + 8) = c;
    *reinterpret_cast<unsigned int*>(target + 12) = d;
# elif defined(_MSC_VER) 
    __asm mov eax, orig
    __asm mov esi, target
    __asm mov edx, [eax]
    __asm mov ecx, 4[eax]
    __asm mov ebx, 8[eax]
    __asm mov eax, 12[eax]
    __asm bswap edx
    __asm bswap ecx
    __asm bswap ebx
    __asm bswap eax
    __asm mov [esi], edx
    __asm mov 4[esi], ecx
    __asm mov 8[esi], ebx
    __asm mov 12[esi], eax
# endif
#endif
    orig += 16;
    target += 16;
  }

  // (n & 3) == (n % 4).
  switch (n&3) 
  {
    case 3:
      Endianness::swap_4 (orig, target);
      orig += 4;
      target += 4;
    case 2:
      Endianness::swap_4 (orig, target);
      orig += 4;
      target += 4;
    case 1:
      Endianness::swap_4 (orig, target);
  }
}

//=============================================================================
// Endianness::swap_8_array
//=============================================================================
void Endianness::swap_8_array (const char* orig, char* target, size_t n)
{
  if (n == 0)
    return;

  const char* const end = orig + 8 * n;

  while (orig < end)
  {
    Endianness::swap_8(orig, target);
    orig += 8;
    target += 8;
  }
}

//=============================================================================
// Endianness::swap_16_array
//=============================================================================
void Endianness::swap_16_array (const char* orig, char* target, size_t n)
{
  if (n == 0)
    return;

  const char* const end = orig + 16 * n;

  while (orig < end)
  {
    Endianness::swap_16(orig, target);
    orig += 16;
    target += 16;
  }
}

#endif //- DISABLE_POLYMORPHIC_IMPL

