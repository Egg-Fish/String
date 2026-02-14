#include "String.h"

#include <stdio.h>

#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

// Property: String_substring(s = String(s), start, end) -> s = String(t)

void property__String_substring__sound(const char *s, size_t start, size_t end,
                                       const char *t) {
    String expected = String_createFromLiteral(t);
    String actual = String_createFromLiteral(s);

    String_substring(actual, start, end);

    char message[1024];

    snprintf(message, 1024,
             "String_substring(s = String(%s), %zu, %zu) -> s = String(%s)", s, start,
             end, t);

    TEST_ASSERT_TRUE_MESSAGE(String_equals(expected, actual), message);

    String_destroy(expected);
    String_destroy(actual);
}

void test__string_substring__sound__emptyString(void) {
    property__String_substring__sound("", 0, 0, "");
    property__String_substring__sound("", 1, 0, "");
    property__String_substring__sound("", 0, 1, "");
}

void test__String_substring__sound__helloWorldString(void) {
    property__String_substring__sound("Hello world!", 0, 5, "Hello");
    property__String_substring__sound("Hello world!", 6, 12, "world!");
    property__String_substring__sound("Hello world!", 11, 12, "!");
    property__String_substring__sound("Hello world!", 0, 12, "Hello world!");
    property__String_substring__sound("Hello world!", 0, 13, "Hello world!");
    property__String_substring__sound("Hello world!", 6, 20, "world!");
    property__String_substring__sound("Hello world!", 20, 0, "");
    property__String_substring__sound("Hello world!", 0, 0, "");
    property__String_substring__sound("Hello world!", 20, 26, "");
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test__string_substring__sound__emptyString);
    RUN_TEST(test__String_substring__sound__helloWorldString);

    return UNITY_END();
}
