#pragma once
#include <cassert>
#include <string_view>

namespace {
constexpr std::string_view BASE64_TABLE = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

constexpr auto PADDING = '=';

std::string decode_quadruplet(std::string in) {
    // TODO
}

struct base64_buf {
    base64_buf() : buf(0) {}
    uint32_t buf : 24;

};

std::string encode_triplet(std::string in) {
    if (in.empty())
        return in;
    uint32_t bit_pack = 0;
    size_t offset = 2;
    for (auto ch : in) {
        bit_pack = bit_pack | (static_cast<uint8_t>(ch) << 8*offset--);
    }
    base64_buf buf;
    buf.buf = bit_pack;

    std::string out;
    size_t pads = 3 - in.size();
    size_t amount = 4 - pads;
    for (size_t i = 0; i < amount; i++) {
        out.push_back(BASE64_TABLE[(buf.buf & (0b111111 << (3 - i)*6)) >> (3 - i)*6]);
    }
    for (size_t i = 0; i < pads; i++)
        out.push_back(PADDING);
    return out;
}

}

namespace base64 {

std::string encode(std::string in) {
    std::string result = "";

    size_t triplets = in.size() / 3 + 1;
    for (size_t i = 0; i < triplets; ++i) {
        result += encode_triplet(in.substr(i*3, 3));
    }

    return result;
}

std::string decode(std::string in) {
    // TODO
    std::string result = "";

    return result;
}

} // namespace base64
