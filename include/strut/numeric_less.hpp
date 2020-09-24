#ifndef HEADER_SORT_HPP
#define HEADER_SORT_HPP

namespace strut {

/** Compare two strings according to their numeric value, similar to
    what 'sort -n' does. */
inline
bool numeric_less(const std::string& lhs, const std::string& rhs)
{
  std::string::size_type i = 0;
  std::string::size_type min_len = std::min(lhs.size(), rhs.size());

  while(i < min_len)
  {
    if (isdigit(lhs[i]) && isdigit(rhs[i]))
    {
      // have two digits, so check which number is smaller
      std::string::size_type li = i+1;
      std::string::size_type ri = i+1;

      // find the end of the number in both strings
      while(li < lhs.size() && isdigit(lhs[li])) { li += 1; }
      while(ri < rhs.size() && isdigit(rhs[ri])) { ri += 1; }

      if (li == ri)
      {
        // end is at the same point in both strings, so do a detail
        // comparism of the numbers
        for(std::string::size_type j = i; j < li; ++j)
        {
          if (lhs[j] != rhs[j])
          {
            return lhs[j] < rhs[j];
          }
        }

        // numbers are the same, so jump to the end of the number and compare
        i = li;
      }
      else
      {
        // numbers have different numbers of digits, so the number
        // with the least digits wins
        // FIXME: this doesn't deal with leading zero, i.e. "01" > "2"
        return li < ri;
      }
    }
    else
    {
      // do normal character comparism
      if (lhs[i] != rhs[i])
      {
        return lhs[i] < rhs[i];
      }
      else
      {
        // strings are the same so far, so continue
        i += 1;
      }
    }
  }

  return lhs.size() < rhs.size();
}

} // namespace strut

#endif

/* EOF */
