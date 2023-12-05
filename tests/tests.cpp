#include <gtest/gtest.h>
#include <base64/base64.hpp>

TEST(base64tests, encode_rfc_test_vectors) {
    EXPECT_EQ(base64::encode(""), "");
    EXPECT_EQ(base64::encode("f"), "Zg==");
    EXPECT_EQ(base64::encode("fo"), "Zm8=");
    EXPECT_EQ(base64::encode("foo"), "Zm9v");
    EXPECT_EQ(base64::encode("foob"), "Zm9vYg==");
    EXPECT_EQ(base64::encode("fooba"), "Zm9vYmE=");
    EXPECT_EQ(base64::encode("foobar"), "Zm9vYmFy");
}

TEST(base64tests, decode_rfc_test_vectors) {
    EXPECT_EQ(base64::decode(""), "");
    EXPECT_EQ(base64::decode("Zg=="), "f");
    EXPECT_EQ(base64::decode("Zm8="), "fo");
    EXPECT_EQ(base64::decode("Zm9v"), "foo");
    EXPECT_EQ(base64::decode("Zm9vYg=="), "foob");
    EXPECT_EQ(base64::decode("Zm9vYmE="), "fooba");
    EXPECT_EQ(base64::decode("Zm9vYmFy"), "foobar");
}

TEST(base64tests, encode_custom_test_vectors) {
    EXPECT_EQ(base64::encode("Man"), "TWFu");
    EXPECT_EQ(base64::encode("Ma"), "TWE=");
    EXPECT_EQ(base64::encode("light work"), "bGlnaHQgd29yaw==");
    EXPECT_EQ(base64::encode("light work."), "bGlnaHQgd29yay4=");
    EXPECT_EQ(base64::encode("Many hands make light work."), "TWFueSBoYW5kcyBtYWtlIGxpZ2h0IHdvcmsu");
}

TEST(base64tests, decode_custom_test_vectors) {
    EXPECT_EQ(base64::decode("TWFu"), "Man");
    EXPECT_EQ(base64::decode("TWE="), "Ma");
    EXPECT_EQ(base64::decode("bGlnaHQgd29yaw=="), "light work");
    EXPECT_EQ(base64::decode("bGlnaHQgd29yay4="), "light work.");
    EXPECT_EQ(base64::decode("TWFueSBoYW5kcyBtYWtlIGxpZ2h0IHdvcmsu"), "Many hands make light work.");
}
TEST(base64test, encode_big_text) {
    EXPECT_EQ(base64::encode("Man is distinguished, not only by his reason, but by this singular passion from other animals, which is a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure."), "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlzIHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2YgdGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGludWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRoZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=");
}
TEST(base64test, decode_big_text) {
    EXPECT_EQ(base64::decode("TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlzIHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2YgdGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGludWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRoZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4="), "Man is distinguished, not only by his reason, but by this singular passion from other animals, which is a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure.");
}
