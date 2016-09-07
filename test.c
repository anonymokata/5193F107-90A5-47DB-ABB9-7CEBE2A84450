#include <check.h>
#include <stdbool.h>
#include <stdlib.h>
#include "roman.h"

START_TEST(one_plus_one_is_two)
{
    ck_assert_str_eq(roman_add("I", "I"), "II");
}
END_TEST

START_TEST(one_plus_two_is_three)
{
    ck_assert_str_eq(roman_add("I", "II"), "III");
}
END_TEST

START_TEST(two_plus_two_is_four)
{
    ck_assert_str_eq(roman_add("II", "II"), "IV");
}
END_TEST

START_TEST(two_plus_three_is_five)
{
    ck_assert_str_eq(roman_add("II", "III"), "V");
}
END_TEST

START_TEST(three_plus_three_is_six)
{
    ck_assert_str_eq(roman_add("III", "III"), "VI");
}
END_TEST

START_TEST(four_plus_one_is_five)
{
    ck_assert_str_eq(roman_add("IV", "I"), "V");
}
END_TEST

START_TEST(one_plus_four_is_five)
{
    ck_assert_str_eq(roman_add("I", "IV"), "V");
}
END_TEST

START_TEST(fourteen_plus_one_is_fifteen)
{
    ck_assert_str_eq(roman_add("XIV", "I"), "XV");
}
END_TEST

START_TEST(one_plus_fourteen_is_fifteen)
{
    ck_assert_str_eq(roman_add("I", "XIV"), "XV");
}
END_TEST

START_TEST(fourteen_plus_fourteen_is_twenty_eight)
{
    ck_assert_str_eq(roman_add("XIV", "XIV"), "XXVIII");
}
END_TEST

START_TEST(nineteen_plus_nineteen_is_thirty_eight)
{
    ck_assert_str_eq(roman_add("XIX", "XIX"), "XXXVIII");
}
END_TEST

START_TEST(forty_plus_forty_is_eighty)
{
    ck_assert_str_eq(roman_add("XL", "XL"), "LXXX");
}
END_TEST

START_TEST(ninety_plus_ninety_is_one_hundred_eighty)
{
    ck_assert_str_eq(roman_add("XC", "XC"), "CLXXX");
}
END_TEST

START_TEST(four_hundred_plus_four_hundred_is_eight_hundred)
{
    ck_assert_str_eq(roman_add("CD", "CD"), "DCCC");
}
END_TEST

START_TEST(nine_hundred_plus_nine_hundred_is_one_thousand_eight_hundred)
{
    ck_assert_str_eq(roman_add("CM", "CM"), "MDCCC");
}
END_TEST

START_TEST(twenty_plus_twenty_is_forty)
{
    ck_assert_str_eq(roman_add("XX", "XX"), "XL");
}
END_TEST

START_TEST(two_hundred_plus_two_hundred_is_four_hundred)
{
    ck_assert_str_eq(roman_add("CC", "CC"), "CD");
}
END_TEST

START_TEST(five_plus_four_is_nine)
{
    ck_assert_str_eq(roman_add("V", "IV"), "IX");
}
END_TEST

START_TEST(fifty_plus_forty_is_ninety)
{
    ck_assert_str_eq(roman_add("L", "XL"), "XC");
}
END_TEST

START_TEST(five_hundred_plus_four_hundred_is_nine_hundred)
{
    ck_assert_str_eq(roman_add("D", "CD"), "CM");
}
END_TEST

////////////////////////////////////////////////////////////

START_TEST(two_minus_one_is_one)
{
    ck_assert_str_eq(roman_subtract("II", "I"), "I");
}
END_TEST

START_TEST(three_minus_two_is_one)
{
    ck_assert_str_eq(roman_subtract("III", "II"), "I");
}
END_TEST

START_TEST(five_minus_one_is_four)
{
    ck_assert_str_eq(roman_subtract("V", "I"), "IV");
}
END_TEST

START_TEST(ten_minus_one_is_nine)
{
    ck_assert_str_eq(roman_subtract("X", "I"), "IX");
}
END_TEST

START_TEST(fifty_minus_one_is_forty_nine)
{
    ck_assert_str_eq(roman_subtract("L", "I"), "XLIX");
}
END_TEST

START_TEST(one_hundred_minus_one_is_ninety_nine)
{
    ck_assert_str_eq(roman_subtract("C", "I"), "XCIX");
}
END_TEST

START_TEST(five_hundred_minus_one_is_four_hundred_ninety_nine)
{
    ck_assert_str_eq(roman_subtract("D", "I"), "CDXCIX");
}
END_TEST

START_TEST(one_thousand_minus_one_is_nine_hundred_ninety_nine)
{
    ck_assert_str_eq(roman_subtract("M", "I"), "CMXCIX");
}
END_TEST

START_TEST(can_subtract_five_from_all_larger_symbols)
{
    ck_assert_str_eq(roman_subtract("X", "V"), "V");
    ck_assert_str_eq(roman_subtract("L", "V"), "XLV");
    ck_assert_str_eq(roman_subtract("C", "V"), "XCV");
    ck_assert_str_eq(roman_subtract("D", "V"), "CDXCV");
    ck_assert_str_eq(roman_subtract("M", "V"), "CMXCV");
}
END_TEST

START_TEST(can_subtract_ten_from_all_larger_symbols)
{
    ck_assert_str_eq(roman_subtract("L", "X"), "XL");
    ck_assert_str_eq(roman_subtract("C", "X"), "XC");
    ck_assert_str_eq(roman_subtract("D", "X"), "CDXC");
    ck_assert_str_eq(roman_subtract("M", "X"), "CMXC");
}
END_TEST

START_TEST(can_subtract_fifty_from_all_larger_symbols)
{
    ck_assert_str_eq(roman_subtract("C", "L"), "L");
    ck_assert_str_eq(roman_subtract("D", "L"), "CDL");
    ck_assert_str_eq(roman_subtract("M", "L"), "CML");
}
END_TEST

///////////////////////////////////////////////////////////

Suite * roman_suite(void)
{
    Suite * s;
    TCase * tc;

    s = suite_create("roman");

    tc = tcase_create("roman_add");

    tcase_add_test(tc, one_plus_one_is_two);
    tcase_add_test(tc, one_plus_two_is_three);
    tcase_add_test(tc, two_plus_two_is_four);
    tcase_add_test(tc, two_plus_three_is_five);
    tcase_add_test(tc, three_plus_three_is_six);
    tcase_add_test(tc, four_plus_one_is_five);
    tcase_add_test(tc, one_plus_four_is_five);
    tcase_add_test(tc, fourteen_plus_one_is_fifteen);
    tcase_add_test(tc, one_plus_fourteen_is_fifteen);
    tcase_add_test(tc, fourteen_plus_fourteen_is_twenty_eight);
    tcase_add_test(tc, nineteen_plus_nineteen_is_thirty_eight);
    tcase_add_test(tc, forty_plus_forty_is_eighty);
    tcase_add_test(tc, ninety_plus_ninety_is_one_hundred_eighty);
    tcase_add_test(tc, four_hundred_plus_four_hundred_is_eight_hundred);
    tcase_add_test(tc, nine_hundred_plus_nine_hundred_is_one_thousand_eight_hundred);
    tcase_add_test(tc, twenty_plus_twenty_is_forty);
    tcase_add_test(tc, two_hundred_plus_two_hundred_is_four_hundred);
    tcase_add_test(tc, five_plus_four_is_nine);
    tcase_add_test(tc, fifty_plus_forty_is_ninety);
    tcase_add_test(tc, five_hundred_plus_four_hundred_is_nine_hundred);

    suite_add_tcase(s, tc);

    tc = tcase_create("roman_subtract");

    tcase_add_test(tc, two_minus_one_is_one);
    tcase_add_test(tc, three_minus_two_is_one);
    tcase_add_test(tc, five_minus_one_is_four);
    tcase_add_test(tc, ten_minus_one_is_nine);
    tcase_add_test(tc, fifty_minus_one_is_forty_nine);
    tcase_add_test(tc, one_hundred_minus_one_is_ninety_nine);
    tcase_add_test(tc, five_hundred_minus_one_is_four_hundred_ninety_nine);
    tcase_add_test(tc, one_thousand_minus_one_is_nine_hundred_ninety_nine);
    tcase_add_test(tc, can_subtract_five_from_all_larger_symbols);
    tcase_add_test(tc, can_subtract_ten_from_all_larger_symbols);
    tcase_add_test(tc, can_subtract_fifty_from_all_larger_symbols);

    suite_add_tcase(s, tc);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = roman_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
