#include "String.h"

#include <stdio.h>

#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

// Property: String_append(s = String(s1), String(s2)) -> s = String(s3)

void property__String_append__sound(const char *s1, const char *s2, const char *s3) {
    String string1 = String_createFromLiteral(s1);
    String string2 = String_createFromLiteral(s2);
    String string3 = String_createFromLiteral(s3);

    String_append(string1, string2);

    char message[1024];

    snprintf(message, 1024,
             "String_append(s = String(%s), String(%s)) -> s = String(%s)",
             s1, s2, s3);

    TEST_ASSERT_TRUE_MESSAGE(String_equals(string1, string3), message);

    String_destroy(string1);
    String_destroy(string2);
    String_destroy(string3);
}

void test__string_append__sound__emptyStrings(void) {
    property__String_append__sound("", "", "");
}

void test__String_append__sound__equalStrings(void) {
    property__String_append__sound("Hello", "Hello", "HelloHello");
}

void test__String_append__sound__unequalStrings(void) {
    property__String_append__sound("Hello", " world!", "Hello world!");
    property__String_append__sound("Hello ", "world!", "Hello world!");
    property__String_append__sound(" Hello ", " world! ", " Hello  world! ");
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test__string_append__sound__emptyStrings);
    RUN_TEST(test__String_append__sound__equalStrings);
    RUN_TEST(test__String_append__sound__unequalStrings);

    return UNITY_END();
}
