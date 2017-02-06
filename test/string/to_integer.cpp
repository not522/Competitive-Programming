#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "string/to_integer.hpp"

BOOST_AUTO_TEST_SUITE(TO_INTEGER)
BOOST_AUTO_TEST_CASE(HAND) {
  BOOST_CHECK_EQUAL(toInteger<int>("123"), 123);
  BOOST_CHECK_EQUAL(toInteger<int>("-123"), -123);
  BOOST_CHECK_EQUAL(toInteger<int64_t>("1234567890123456789"), 1234567890123456789ll);
  BOOST_CHECK_EQUAL(toInteger<int64_t>("-1234567890123456789"), -1234567890123456789ll);
  BOOST_CHECK_EQUAL(toInteger<>("1234567890123456789"), 1234567890123456789ll);
  BOOST_CHECK_EQUAL(toInteger<>("-1234567890123456789"), -1234567890123456789ll);
  BOOST_CHECK_EQUAL(toInteger<int>("101", 2), 0b101);
  BOOST_CHECK_EQUAL(toInteger<int>("-101", 2), -0b101);
  BOOST_CHECK_EQUAL(toInteger<int>("123", 8), 0123);
  BOOST_CHECK_EQUAL(toInteger<int>("-123", 8), -0123);
  BOOST_CHECK_EQUAL(toInteger<int>("abc", 16), 0xabc);
  BOOST_CHECK_EQUAL(toInteger<int>("-abc", 16), -0xabc);
  BOOST_CHECK_EQUAL(toInteger<int64_t>("101010101010101010101010101010101010101010101010101010101010101", 2), 0b101010101010101010101010101010101010101010101010101010101010101ll);
  BOOST_CHECK_EQUAL(toInteger<int64_t>("-101010101010101010101010101010101010101010101010101010101010101", 2), -0b101010101010101010101010101010101010101010101010101010101010101ll);
  BOOST_CHECK_EQUAL(toInteger<int64_t>("1234567012345670", 8), 01234567012345670ll);
  BOOST_CHECK_EQUAL(toInteger<int64_t>("-1234567012345670", 8), -01234567012345670ll);
  BOOST_CHECK_EQUAL(toInteger<int64_t>("abcdef01", 16), 0xabcdef01ll);
  BOOST_CHECK_EQUAL(toInteger<int64_t>("-abcdef01", 16), -0xabcdef01ll);
}
BOOST_AUTO_TEST_SUITE_END()