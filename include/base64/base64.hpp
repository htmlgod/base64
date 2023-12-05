#pragma once
#include <cassert>
#include <string_view>
#include <bitset>

namespace {
constexpr inline std::string_view BASE64_TABLE = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

constexpr inline auto PADDING = '=';

struct base64_buf {
    base64_buf() : buf(0) {}
    uint32_t buf : 24;

};

inline int get_decoded_index(char in) {
    if (std::isupper(in)) 
        return static_cast<int>(in) - 65;
    if (std::islower(in)) 
        return static_cast<int>(in) - 97 + 26;
    if (std::isdigit(in)) 
        return static_cast<int>(in) - 48 + 52;
    if (in == '+')
        return 62;
    return 63;
}

std::string decode_quadruplet(const std::string& in) {
    base64_buf buf;
    char end = -1;
    size_t offset = in.size() - 1;
    for (auto ch : in) {
        if (ch == PADDING) {
            end++;
            continue;
        }
        buf.buf |= (get_decoded_index(ch) << 6*offset--);
    }
    int32_t tmp = buf.buf;
    char* reader = reinterpret_cast<char*>(&tmp);
    std::string result = "";
    for (char i = 2; i > end; --i)
        result.push_back(*(reader+i));
    return result;
}

std::string encode_triplet(const std::string& in) {
    if (in.empty())
        return in;
    uint32_t bit_pack = 0;
    size_t offset = 2;
    for (auto ch : in) {
        bit_pack = bit_pack | (static_cast<uint8_t>(ch) << 8*offset--);
    }
    base64_buf buf;
    buf.buf = bit_pack;

    size_t pads = 3 - in.size();
    size_t amount = 4 - pads;
    std::string out;
    for (size_t i = 0; i < amount; i++) {
        out.push_back(BASE64_TABLE[(buf.buf & (0b111111 << (3 - i)*6)) >> (3 - i)*6]);
    }
    for (size_t i = 0; i < pads; i++)
        out.push_back(PADDING);
    return out;
}

}

namespace base64 {

std::string encode(const std::string& in) {
    std::string result = "";

    size_t triplets = in.size() / 3 + 1;
    for (size_t i = 0; i < triplets; ++i)
        result += encode_triplet(in.substr(i*3, 3));

    return result;
}

std::string decode(const std::string& in) {
    if (in.empty())
        return in;
    std::string result = "";
    size_t quadruplets = in.size() / 4;
    for (size_t i = 0; i < quadruplets; ++i)
        result += decode_quadruplet(in.substr(i*4, 4));
    return result;
}

} // namespace base64
