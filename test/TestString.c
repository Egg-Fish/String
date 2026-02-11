#include "String.h"

#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

// Property: s1 == s2 -> String_equals(s1, s2)

void property__String_equals__complete(const char *s1, const char *s2) {
    if (s1 == s2) {
        String string1 = String_createFromLiteral(s1);
        String string2 = String_createFromLiteral(s2);

        TEST_ASSERT_TRUE(String_equals(string1, string2));

        String_destroy(string1);
        String_destroy(string2);
    }
}

void test__string_equals__complete__emptyStrings(void) {
    property__String_equals__complete("", "");
}

void test__String_equals__complete__equalStrings(void) {
    property__String_equals__complete("Hello", "Hello");
}
void test__String_equals__complete__unequalStrings(void) {
    property__String_equals__complete("Hello", "world!");
}

// Property: String_equals(s, s)

void property__String_equals__reflexive(String s) {
    TEST_ASSERT_TRUE(String_equals(s, s));
}

void test__String_equals__reflexive__emptyString(void) {
    String s = String_createFromLiteral("");

    property__String_equals__reflexive(s);

    String_destroy(s);
}

void test__String_equals__reflexive__nonemptyString(void) {
    String s = String_createFromLiteral("Hello world!");

    property__String_equals__reflexive(s);

    String_destroy(s);
}

// Property: String_equals(s1, s2) <-> String_equals(s2, s1)

void property__String_equals__symmetric(String s1, String s2) {
    TEST_ASSERT_EQUAL(String_equals(s1, s2), String_equals(s2, s1));
}

void test__String_equals__symmetric__emptyStrings(void) {
    String s1 = String_createFromLiteral("");
    String s2 = String_createFromLiteral("");

    property__String_equals__symmetric(s1, s2);

    String_destroy(s1);
    String_destroy(s2);
}

void test__String_equals__symmetric__equalStrings(void) {
    String s1 = String_createFromLiteral("Hello");
    String s2 = String_createFromLiteral("Hello");

    property__String_equals__symmetric(s1, s2);

    String_destroy(s1);
    String_destroy(s2);
}

void test__String_equals__symmetric__unequalStrings(void) {
    String s1 = String_createFromLiteral("Hello");
    String s2 = String_createFromLiteral("world!");

    property__String_equals__symmetric(s1, s2);

    String_destroy(s1);
    String_destroy(s2);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test__string_equals__complete__emptyStrings);
    RUN_TEST(test__String_equals__complete__equalStrings);
    RUN_TEST(test__String_equals__complete__unequalStrings);

    RUN_TEST(test__String_equals__reflexive__emptyString);
    RUN_TEST(test__String_equals__reflexive__nonemptyString);

    RUN_TEST(test__String_equals__symmetric__emptyStrings);
    RUN_TEST(test__String_equals__symmetric__equalStrings);
    RUN_TEST(test__String_equals__symmetric__unequalStrings);

    return UNITY_END();
}
