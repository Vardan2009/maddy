/*
 * This project is licensed under the MIT license. For more information see the
 * LICENSE file.
 */
#pragma once

// -----------------------------------------------------------------------------

#include <regex>
#include <string>

#include "maddy/common.h"
#include "maddy/lineparser.h"

// -----------------------------------------------------------------------------

namespace maddy {

// -----------------------------------------------------------------------------

/**
 * InlineCodeParser
 *
 * @class
 */
class InlineCodeParser : public LineParser
{
public:
  /**
   * Parse
   *
   * From Markdown: `text `some code``
   *
   * To HTML: `text <code>some code</code>`
   *
   * @method
   * @param {std::string&} line The line to interpret
   * @return {void}
   */
  void Parse(std::string& line) override
  {
    static std::regex re("`([^`]*)`");
    std::smatch match;

    if (std::regex_search(line, match, re))
    {
      std::string replacement =
        "<code>" + common::escapeHTML(match[1].str()) + "</code>";

      line = match.prefix().str() + replacement + match.suffix().str();
    }
  }
}; // class InlineCodeParser

// -----------------------------------------------------------------------------

} // namespace maddy
