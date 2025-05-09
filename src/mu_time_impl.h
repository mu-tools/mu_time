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
 * @file mu_time_impl.h
 * @brief Platform-specific definitions for mu_time module.
 *
 * This header selects the correct platform-specific implementation of mu_time types
 * and ensures portability across different environments.
 */

#ifndef _MU_TIME_IMPL_H_
#define _MU_TIME_IMPL_H_

// *****************************************************************************
// C++ Compatibility

#ifdef __cplusplus
extern "C" {
#endif

// *****************************************************************************
// Platform Selection

#if defined(__linux__) || defined(__APPLE__)
    #include "platform/mu_time_posix.h"
#elif defined(_WIN32)
    #include "platform/mu_time_windows.h"
#elif defined(ESP32)
    #include "platform/mu_time_esp32.h"
#else
    #error "Unsupported platform! Define your mu_time implementation."
#endif

// *****************************************************************************
// End of file

#ifdef __cplusplus
}
#endif

#endif /* #ifndef _MU_TIME_H_ */
