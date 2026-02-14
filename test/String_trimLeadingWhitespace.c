#include "String.h"

#include <stdio.h>

#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

// Property: String_trimLeadingWhitespace(s = String(s)) -> s = String(t)

void property__String_trimLeadingWhitespace__sound(const char *s, const char *t) {
    String expected = String_createFromLiteral(t);
    String actual = String_createFromLiteral(s);

    String_trimLeadingWhitespace(actual);

    char message[1024];

    snprintf(message, 1024,
             "String_trimLeadingWhitespace(s = String(%s)) -> s = String(%s)", s, t);

    TEST_ASSERT_TRUE_MESSAGE(String_equals(expected, actual), message);

    String_destroy(expected);
    String_destroy(actual);
}

void test__string_trimLeadingWhitespace__sound__emptyString(void) {
    property__String_trimLeadingWhitespace__sound("", "");
}

void test__String_trimLeadingWhitespace__sound__helloWorldString(void) {
    property__String_trimLeadingWhitespace__sound("Hello world!", "Hello world!");
    property__String_trimLeadingWhitespace__sound("  Hello world!", "Hello world!");
    property__String_trimLeadingWhitespace__sound("Hello world!  ", "Hello world!  ");
    property__String_trimLeadingWhitespace__sound("  Hello world!  ", "Hello world!  ");
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test__string_trimLeadingWhitespace__sound__emptyString);
    RUN_TEST(test__String_trimLeadingWhitespace__sound__helloWorldString);

    return UNITY_END();
}
