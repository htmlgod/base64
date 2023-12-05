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

//TEST(base64tests, decode_rfc_test_vectors) {
    // TODO
//    EXPECT_EQ(base64::decode(""), "");
//    EXPECT_EQ(base64::decode("f"), "Zg==");
//    EXPECT_EQ(base64::decode("fo"), "Zm8=");
//    EXPECT_EQ(base64::decode("foo"), "Zm9v");
//    EXPECT_EQ(base64::decode("foob"), "Zm9vYg==");
//    EXPECT_EQ(base64::decode("fooba"), "Zm9vYmE=");
//    EXPECT_EQ(base64::decode("foobar"), "Zm9vYmFy");
//}

TEST(base64tests, encode_custom_test_vectors) {
    EXPECT_EQ("TWFu", base64::encode("Man"));
    EXPECT_EQ("TWE=", base64::encode("Ma"));
    EXPECT_EQ("bGlnaHQgd29yaw==", base64::encode("light work"));
    EXPECT_EQ("bGlnaHQgd29yay4=", base64::encode("light work."));
    EXPECT_EQ("TWFueSBoYW5kcyBtYWtlIGxpZ2h0IHdvcmsu", base64::encode("Many hands make light work."));
}
