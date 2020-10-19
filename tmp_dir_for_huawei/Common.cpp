#include "Common.hpp"

/**
 * @brief Get bits from word function
 * @tparam high - upper bound
 * @tparam low - lower bound (starts from 0)
 * @param word - word to get bits from.
 * @return Resulting bits as word.
 */
template <unsigned high, unsigned low>
constexpr Word GetBits( Word word )
{
    return (word >> low) & ((1 << (high - low + 1)) - 1);
} /* End of 'GetBits' function */

/**
 * @brief Signed extension function
 * @tparam old_size size of a number in bits
 * @tparam new_size new (extended) size of a number in bits
 * @param word number to extend
 * @return
 */
template <unsigned old_size, unsigned new_size>
constexpr Word SignExtend( Word word )
{
  Word mask = ((1 << (new_size - old_size)) - GetBits<old_size - 1, old_size - 1>(word)) << old_size;
  return GetBits<new_size - 1, 0>(mask | word);
} /* End of 'SignExtend' function */

// Useful function for debug
/*
void BitPrint( Word word, size_t size = sizeof(Word) * 8 )
{
  Word mask = 1 << (size -  1);
  for (size_t i = 0; i < size; ++i)
  {
    std::cout << ((word & mask) >> (size - 1 - i)) << " ";
    mask >>= 1;
  }
  std::cout << std::endl;
}
*/