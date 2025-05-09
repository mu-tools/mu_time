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

/**
 * @file mu_time.h
 * @brief Generic API for handling absolute and relative time values.
 *
 * Provides platform-independent functions for reasoning about time, supporting
 * both rollover-safe timestamp calculations and relative durations.
 *
 * Note that the user must provide "mu_time_impl.h" and a companion
 * "mu_time_impl.c" that defines the implentation of these functions.
 */

#ifndef _MU_TIME_H_
#define _MU_TIME_H_

// *****************************************************************************
// C++ Compatibility

#ifdef __cplusplus
extern "C" {
#endif

// *****************************************************************************
// Includes

#include "mu_time_impl.h"  // define mu_time_abs_t and mu_time_rel_t
#include <stdbool.h>
#include <stdint.h>

// *****************************************************************************
// Public API Functions

/**
 * @brief Returns the current absolute time from the platform-specific
 * implementation.
 * @return Current time as an absolute timestamp.
 */
mu_time_abs_t mu_time_now(void);

/**
 * @brief Return the maximum relative time before "future" becomes "past"
 * @return The largest value that can be represented by mu_time_rel_t.
 */
mu_time_rel_t mu_time_rel_max(void);

/**
 * @brief Computes an offset from an absolute timestamp.
 * @param base The reference absolute time.
 * @param delta The relative time offset.
 * @return The new absolute time (base + delta).
 */
mu_time_abs_t mu_time_offset(mu_time_abs_t base, mu_time_rel_t delta);

/**
 * @brief Computes the difference between two absolute timestamps.
 * @param a First absolute timestamp.
 * @param b Second absolute timestamp.
 * @return The relative time difference (b - a).
 */
mu_time_rel_t mu_time_difference(mu_time_abs_t a, mu_time_abs_t b);

/**
 * @brief Determines if one time happens before another
 *
 * @param a A time value.
 * @param b Another time value
 * @return `true` if a happens before b, `false` otherwise.
 */
bool mu_time_is_before(mu_time_abs_t a, mu_time_abs_t b);

/**
 * @brief Determines if one time happens after another
 *
 * @param a A time value.
 * @param b Another time value
 * @return `true` if a is happens after b, `false` otherwise.
 */
bool mu_time_is_after(mu_time_abs_t a, mu_time_abs_t b);

/**
 * @brief Converts a floating-point time duration into a relative time
 * representation.
 * @param delta_t Time duration in floating-point format.
 * @return Relative time value.
 */
mu_time_rel_t mu_time_rel_from_seconds(float delta_t);

/**
 * @brief Converts a relative time representation into floating-point format.
 * @param delta_t Relative time value.
 * @return Time duration as a floating-point value.
 */
float mu_time_rel_to_seconds(mu_time_rel_t delta_t);

/**
 * @brief Comparison helpers for absolute timestamps.
 */

/**
 * @brief Converts milliseconds into a relative time representation.
 * @param milliseconds Time duration in milliseconds.
 * @return Relative time value.
 */
mu_time_rel_t mu_time_rel_from_millis(uint32_t milliseconds);

/**
 * @brief Converts a relative time representation into milliseconds.
 * @param delta_t Relative time value.
 * @return Time duration in milliseconds.
 */
uint32_t mu_time_rel_to_millis(mu_time_rel_t delta_t);

// *****************************************************************************
// End of file

#ifdef __cplusplus
}
#endif

#endif /* #ifndef _MU_TIME_H_ */
