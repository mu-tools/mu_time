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

#include "../mu_time.h"
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

// *****************************************************************************
// Public code

mu_time_abs_t mu_time_now(void) {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return (mu_time_abs_t){.seconds = ts.tv_sec, .nanoseconds = ts.tv_nsec};
}

mu_time_rel_t mu_time_rel_max(void) {
    return INT64_MAX;
}

mu_time_abs_t mu_time_offset(mu_time_abs_t base, mu_time_rel_t delta) {
    mu_time_abs_t result;
    result.seconds = base.seconds + (delta / 1000000000);
    result.nanoseconds = base.nanoseconds + (delta % 1000000000);

    // Handle nanosecond overflow
    if (result.nanoseconds >= 1000000000) {
        result.seconds += 1;
        result.nanoseconds -= 1000000000;
    }

    return result;
}

mu_time_rel_t mu_time_difference(mu_time_abs_t a, mu_time_abs_t b) {
    return ((b.seconds - a.seconds) * 1000000000) + (b.nanoseconds - a.nanoseconds);
}

bool mu_time_is_before(mu_time_abs_t a, mu_time_abs_t b) {
    return (a.seconds < b.seconds) || (a.seconds == b.seconds && a.nanoseconds < b.nanoseconds);
}

bool mu_time_is_after(mu_time_abs_t a, mu_time_abs_t b) {
    return (a.seconds > b.seconds) || (a.seconds == b.seconds && a.nanoseconds > b.nanoseconds);
}

mu_time_rel_t mu_time_rel_from_seconds(float delta_t) {
    return (mu_time_rel_t)(delta_t * 1000000000);
}

float mu_time_rel_to_seconds(mu_time_rel_t delta_t) {
    return (float)delta_t / 1000000000.0f;
}

mu_time_rel_t mu_time_rel_from_millis(uint32_t milliseconds) {
    return (mu_time_rel_t)(milliseconds * 1000000);
}

uint32_t mu_time_rel_to_millis(mu_time_rel_t delta_t) {
    return (uint32_t)(delta_t / 1000000);
}

// *****************************************************************************
// End of file
