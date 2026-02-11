#include "String.h"

#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

// Property: String_startsWith(s1, s2) -> s1 starts with s2

void property__String_startsWith__sound(const char *s1, const char *s2) {
    String string1 = String_createFromLiteral(s1);
    String string2 = String_createFromLiteral(s2);

    if (String_startsWith(string1, string2)) {
        size_t s2Length = String_getLength(string2);

        if (s2Length == 0) {
            TEST_PASS();
        }

        const char *message = "String_startsWith(s1, s2) -> s1 starts with s2";
        TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(s1, s2, s2Length, message);
    }

    String_destroy(string1);
    String_destroy(string2);
}

// Property: s1 starts with s2 -> String_startsWith(s1, s2)

void property__String_startsWith__complete(const char *s1, const char *s2) {
    String string1 = String_createFromLiteral(s1);
    String string2 = String_createFromLiteral(s2);
    size_t s2Length = String_getLength(string2);

    int startsWith = 1;

    for (size_t i = 0; i < s2Length; i++) {
        if (s1[i] != s2[i]) {
            startsWith = 0;
            break;
        }
    }

    if (startsWith) {
        const char *message = "s1 starts with s2 -> String_startsWith(s1, s2)";
        TEST_ASSERT_TRUE_MESSAGE(String_startsWith(string1, string2), message);
    }

    String_destroy(string1);
    String_destroy(string2);
}

void test__string_startsWith__sound__emptyStrings(void) {
    property__String_startsWith__sound("", "");
}

void test__String_startsWith__sound__equalStrings(void) {
    property__String_startsWith__sound("Hello", "Hello");
}

void test__String_startsWith__sound__unequalStrings(void) {
    property__String_startsWith__sound("Hello", "world!");
}

void test__String_startsWith__sound__leftStartsWithRight(void) {
    property__String_startsWith__sound("Hello world!", "Hello");
}

void test__String_startsWith__sound__rightStartsWithLeft(void) {
    property__String_startsWith__sound("Hello", "Hello world!");
}

void test__string_startsWith__complete__emptyStrings(void) {
    property__String_startsWith__complete("", "");
}

void test__String_startsWith__complete__equalStrings(void) {
    property__String_startsWith__complete("Hello", "Hello");
}

void test__String_startsWith__complete__unequalStrings(void) {
    property__String_startsWith__complete("Hello", "world!");
}

void test__String_startsWith__complete__leftStartsWithRight(void) {
    property__String_startsWith__complete("Hello world!", "Hello");
}

void test__String_startsWith__complete__rightStartsWithLeft(void) {
    property__String_startsWith__complete("Hello", "Hello world!");
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test__string_startsWith__sound__emptyStrings);
    RUN_TEST(test__String_startsWith__sound__equalStrings);
    RUN_TEST(test__String_startsWith__sound__unequalStrings);
    RUN_TEST(test__String_startsWith__sound__leftStartsWithRight);
    RUN_TEST(test__String_startsWith__sound__rightStartsWithLeft);

    RUN_TEST(test__string_startsWith__complete__emptyStrings);
    RUN_TEST(test__String_startsWith__complete__equalStrings);
    RUN_TEST(test__String_startsWith__complete__unequalStrings);
    RUN_TEST(test__String_startsWith__complete__leftStartsWithRight);
    RUN_TEST(test__String_startsWith__complete__rightStartsWithLeft);

    return UNITY_END();
}
