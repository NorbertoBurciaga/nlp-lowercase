#include "nlp/lowercase.hpp"

namespace nlp {

namespace {

constexpr char ascii_tolower(char c) noexcept {
    return (c >= 'A' && c <= 'Z') ? static_cast<char>(c + ('a' - 'A')) : c;
}

} // namespace

std::string lowercase(std::string_view text) {
    std::string out(text);
    lowercase_in_place(out);
    return out;
}

void lowercase_in_place(std::string& text) {
    for (char& c : text) {
        c = ascii_tolower(c);
    }
}

} // namespace nlp
