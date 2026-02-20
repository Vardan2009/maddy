#pragma once

#include <string>

namespace maddy {

namespace common {

inline std::string escapeHTML(const std::string& input)
{
  std::string result;

  for (char c : input)
  {
    switch (c)
    {
      case '<':
        result += "&lt;";
        break;
      case '>':
        result += "&gt;";
        break;
      default:
        result += c;
    }
  }

  return result;
}

} // namespace common

} // namespace maddy
