/**
 * MIT License
 *
 * Copyright (c) 2025 R. D. Poor & Assoc <rdpoor @ gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

// *****************************************************************************
// Includes

#include "mu_time.h"
#include "unity.h"
#include <stdio.h>

// *****************************************************************************
// Private types and definitions

// *****************************************************************************
// Private (static) storage

// *****************************************************************************
// Private (forward) declarations

void test_mu_time_now(void);
void test_mu_time_offset(void);
void test_mu_time_difference(void);
void test_mu_time_is_before(void);
void test_mu_time_is_after(void);

// *****************************************************************************
// Public code

void setUp(void) {}    // Called before each test, useful for setup.
void tearDown(void) {} // Called after each test, useful for cleanup.

void test_mu_time_now(void) {
    mu_time_abs_t t1 = mu_time_now();
    mu_time_abs_t t2 = mu_time_now();

    // Ensure timestamps are valid and increasing
    TEST_ASSERT_TRUE(t1.seconds > 0);
    TEST_ASSERT_TRUE(t1.nanoseconds >= 0 && t1.nanoseconds < 1000000000);
    TEST_ASSERT_TRUE(mu_time_is_before(t1, t2) || t1.seconds == t2.seconds);
}

void test_mu_time_rel_max(void) {
    mu_time_abs_t t1 = {0, 0};
    mu_time_abs_t t2 = mu_time_offset(t1, mu_time_rel_max());
    TEST_ASSERT_TRUE(mu_time_is_before(t1, t2));
    TEST_ASSERT_FALSE(mu_time_is_before(t2, t1));
}

void test_mu_time_offset(void) {
    mu_time_abs_t base = {1000, 500000000};  // 1000s + 500ms
    mu_time_rel_t delta = 1500000000;       // 1.5s in nanoseconds
    mu_time_abs_t result = mu_time_offset(base, delta);

    mu_time_abs_t expected = {1002, 0};  // Expected result (1002s + 0ns)
    TEST_ASSERT_EQUAL_UINT32(expected.seconds, result.seconds);
    TEST_ASSERT_EQUAL_UINT32(expected.nanoseconds, result.nanoseconds);
}

void test_mu_time_difference(void) {
    mu_time_abs_t a = {1000, 0};
    mu_time_abs_t b = {1002, 500000000};  // 2.5s later
    mu_time_rel_t diff = mu_time_difference(a, b);

    TEST_ASSERT_EQUAL_INT64(2500000000, diff);  // Should be 2.5s in nanoseconds
}

void test_mu_time_is_before(void) {
    mu_time_abs_t a = {1000, 0};
    mu_time_abs_t b = {1002, 500000000};  // 2.5s later
    TEST_ASSERT_TRUE(mu_time_is_before(a, b));
    TEST_ASSERT_FALSE(mu_time_is_before(b, a));
}

void test_mu_time_is_after(void) {
    mu_time_abs_t a = {1000, 0};
    mu_time_abs_t b = {1002, 500000000};  // 2.5s later
    TEST_ASSERT_TRUE(mu_time_is_after(b, a));
    TEST_ASSERT_FALSE(mu_time_is_after(a, b));
}

void test_mu_time_rel_from_seconds(void) {
    mu_time_rel_t t1 = mu_time_rel_from_seconds(1.5);
    mu_time_rel_t t2 = 1500000000;       // 1.5s in nanoseconds
    TEST_ASSERT_EQUAL(t1, t2);
}

void test_mu_time_rel_to_seconds(void) {
    float f1 = mu_time_rel_to_seconds(1500000000);
    float f2 = 1.5;
    TEST_ASSERT_EQUAL(f1, f2);
}

void test_mu_time_rel_from_millis(void) {
    mu_time_rel_t t1 = mu_time_rel_from_millis(1500);
    mu_time_rel_t t2 = 1500000000;       // 1.5
    TEST_ASSERT_EQUAL(t1, t2);
}

void test_mu_time_rel_to_millis(void) {
    uint32_t r1 = mu_time_rel_to_millis(1500000000);
    uint32_t r2 = 1500;
    TEST_ASSERT_EQUAL(r1, r2);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_mu_time_now);
    RUN_TEST(test_mu_time_rel_max);
    RUN_TEST(test_mu_time_offset);
    RUN_TEST(test_mu_time_difference);
    RUN_TEST(test_mu_time_is_before);
    RUN_TEST(test_mu_time_is_after);
    RUN_TEST(test_mu_time_rel_from_seconds);
    RUN_TEST(test_mu_time_rel_to_seconds);
    RUN_TEST(test_mu_time_rel_from_millis);
    RUN_TEST(test_mu_time_rel_to_millis);
    return UNITY_END();
}

// *****************************************************************************
// End of file
