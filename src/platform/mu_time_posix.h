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
 * @file mu_time_posix.h
 *
 * @brief POSIX-specific definitions for mu_time module.
 */

#ifndef _MU_TIME_POSIX_H_
#define _MU_TIME_POSIX_H_

// *****************************************************************************
// C++ Compatibility

#ifdef __cplusplus
extern "C" {
#endif

// *****************************************************************************
// Includes

#include <stdint.h>
#include <time.h>

// *****************************************************************************
// Public types and definitions

/**
 * @brief Absolute time representation using POSIX timespec.
 */
typedef struct {
    time_t seconds;      ///< Seconds since Unix epoch
    long nanoseconds;    ///< Nanoseconds (0 - 999999999)
} mu_time_abs_t;

/**
 * @brief Relative time representation using signed integer nanoseconds.
 */
typedef int64_t mu_time_rel_t;

// *****************************************************************************
// Public declarations

// *****************************************************************************
// End of file

#ifdef __cplusplus
}
#endif

#endif /* #ifndef _MU_TIME_POSIX_H_ */
