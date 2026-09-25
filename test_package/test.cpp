#include <cassert>
#include <iostream>

#include "nlp/lowercase.hpp"

int main() {
    assert(nlp::lowercase("HeLLo, WoRLD!") == "hello, world!");
    assert(nlp::lowercase("") == "");
    assert(nlp::lowercase("already lower 123 !@#") == "already lower 123 !@#");
    assert(nlp::lowercase("ABCXYZ") == "abcxyz");

    // Non-ASCII bytes pass through untouched.
    std::string utf8 = "CAF\xC3\x89"; // CAFÉ in UTF-8
    assert(nlp::lowercase(utf8) == "caf\xC3\x89");

    std::string s = "MiXeD CASE";
    nlp::lowercase_in_place(s);
    assert(s == "mixed case");

    std::cout << "nlp-lowercase OK" << std::endl;
    return 0;
}
