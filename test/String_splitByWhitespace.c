#include "String.h"

#include <stddef.h>
#include <stdio.h>

#include "List.h"

#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

// Property: l = String_splitByWhitespace(String(s)) -> l[i] = String(t[i]), 0 <= i <= n

void property__String_splitByWhitespace__sound(const char *s, const char **t,
                                               size_t n) {
    String string = String_createFromLiteral(s);
    List l = String_splitByWhitespace(string);

    char message[1024];

    snprintf(message, 1024, "length(l) (%zu) == n (%zu)", List_getLength(l), n);

    TEST_ASSERT_EQUAL_UINT_MESSAGE(n, List_getLength(l), message);

    for (size_t i = 0; i < n; i++) {
        String expected = String_createFromLiteral(t[i]);
        String actual = (String)List_getItemAtIndex(l, i);

        snprintf(message, 1024, "l[%zu] (%.*s) = String(t[%zu]) (%.*s)", i,
                 (unsigned)String_getLength(actual), String_getBuffer(actual), i,
                 (unsigned)String_getLength(expected), String_getBuffer(expected));

        TEST_ASSERT_TRUE_MESSAGE(String_equals(expected, actual), message);

        String_destroy(expected);
        String_destroy(actual);
    }

    String_destroy(string);
    List_destroy(l);
}

void test__String_splitByWhitespace__sound__emptyString(void) {
    const char **t = {};
    property__String_splitByWhitespace__sound("", t, 0);
}

void test__String_splitByWhitespace__sound__helloWorldString(void) {
    const char *t[2] = {"Hello", "world!"};
    property__String_splitByWhitespace__sound("Hello world!", t, 2);
}

void test__String_splitByWhitespace__sound__lipsumString(void) {
    const char *s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    const char *t[8] = {
        "Lorem", "ipsum", "dolor", "sit", "amet,", "consectetur", "adipiscing", "elit.",
    };

    property__String_splitByWhitespace__sound(s, t, 8);
}

void test__String_splitByWhitespace__sound__alphabetString(void) {
    const char *s = "a b c d e f g h i j k l m n o p q r s t u v w x y z";
    const char *t[26] = {
        "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
        "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
    };

    property__String_splitByWhitespace__sound(s, t, 26);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test__String_splitByWhitespace__sound__emptyString);
    RUN_TEST(test__String_splitByWhitespace__sound__helloWorldString);
    RUN_TEST(test__String_splitByWhitespace__sound__lipsumString);
    RUN_TEST(test__String_splitByWhitespace__sound__alphabetString);

    return UNITY_END();
}
