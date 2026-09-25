#pragma once

#include <string>
#include <string_view>

namespace nlp {

// Returns a lowercased copy of `text`.
// Only ASCII 'A'-'Z' are mapped to 'a'-'z'; every other byte (including
// multi-byte UTF-8 sequences) is passed through unchanged. The conversion is
// locale-independent so results are stable across platforms.
std::string lowercase(std::string_view text);

// Lowercases `text` in place (same ASCII-only, locale-independent rules).
void lowercase_in_place(std::string& text);

} // namespace nlp
