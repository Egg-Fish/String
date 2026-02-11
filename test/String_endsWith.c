#include "String.h"

#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

// Property: String_endsWith(s1, s2) -> s1 ends with s2

void property__String_endsWith__sound(const char *s1, const char *s2) {
    String string1 = String_createFromLiteral(s1);
    String string2 = String_createFromLiteral(s2);

    if (String_endsWith(string1, string2)) {
        size_t s1Length = String_getLength(string1);
        size_t s2Length = String_getLength(string2);

        if (s2Length == 0) {
            TEST_PASS();
        }

        size_t offset = s1Length - s2Length;

        const char *message = "String_endsWith(s1, s2) -> s1 ends with s2";
        TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(s1 + offset, s2, s2Length, message);
    }

    String_destroy(string1);
    String_destroy(string2);
}

// Property: s1 ends with s2 -> String_endsWith(s1, s2)

void property__String_endsWith__complete(const char *s1, const char *s2) {
    String string1 = String_createFromLiteral(s1);
    String string2 = String_createFromLiteral(s2);
    size_t s1Length = String_getLength(string1);
    size_t s2Length = String_getLength(string2);

    int endsWith = 1;

    for (size_t i = 0; i < s2Length; i++) {
        if (s1[s1Length - 1 - i] != s2[s2Length - 1 - i]) {
            endsWith = 0;
            break;
        }
    }

    if (endsWith) {
        const char *message = "s1 ends with s2 -> String_endsWith(s1, s2)";
        TEST_ASSERT_TRUE_MESSAGE(String_endsWith(string1, string2), message);
    }

    String_destroy(string1);
    String_destroy(string2);
}

void test__string_endsWith__sound__emptyStrings(void) {
    property__String_endsWith__sound("", "");
}

void test__String_endsWith__sound__equalStrings(void) {
    property__String_endsWith__sound("Hello", "Hello");
}

void test__String_endsWith__sound__unequalStrings(void) {
    property__String_endsWith__sound("Hello", "world!");
}

void test__String_endsWith__sound__leftEndsWithRight(void) {
    property__String_endsWith__sound("Hello world!", "world!");
}

void test__String_endsWith__sound__rightEndsWithLeft(void) {
    property__String_endsWith__sound("world!", "Hello world!");
}

void test__string_endsWith__complete__emptyStrings(void) {
    property__String_endsWith__complete("", "");
}

void test__String_endsWith__complete__equalStrings(void) {
    property__String_endsWith__complete("Hello", "Hello");
}

void test__String_endsWith__complete__unequalStrings(void) {
    property__String_endsWith__complete("Hello", "world!");
}

void test__String_endsWith__complete__leftEndsWithRight(void) {
    property__String_endsWith__complete("Hello world!", "world!");
}

void test__String_endsWith__complete__rightEndsWithLeft(void) {
    property__String_endsWith__complete("world!", "Hello world!");
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test__string_endsWith__sound__emptyStrings);
    RUN_TEST(test__String_endsWith__sound__equalStrings);
    RUN_TEST(test__String_endsWith__sound__unequalStrings);
    RUN_TEST(test__String_endsWith__sound__leftEndsWithRight);
    RUN_TEST(test__String_endsWith__sound__rightEndsWithLeft);

    RUN_TEST(test__string_endsWith__complete__emptyStrings);
    RUN_TEST(test__String_endsWith__complete__equalStrings);
    RUN_TEST(test__String_endsWith__complete__unequalStrings);
    RUN_TEST(test__String_endsWith__complete__leftEndsWithRight);
    RUN_TEST(test__String_endsWith__complete__rightEndsWithLeft);

    return UNITY_END();
}
