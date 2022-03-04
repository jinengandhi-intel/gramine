/* SPDX-License-Identifier: LGPL-3.0-or-later */
/* Copyright (C) 2022 Integritee AG
 *                    Frieder Paape <frieder@integritee.network>
 */

/*
 * Implements timerfd_create, timerfd_settime and timerfd_gettime. These syscalls
 * are stubbed to always return success.
 *
 * This (dummy) functionality is required by Trinity fuzzer.
 */

#include "api.h"
#include "shim_table.h"
#include "shim_handle.h"

long shim_do_timerfd_create(int clockid, int flags) {
    return 0;
}

long shim_do_timerfd_settime(int fd, struct __kernel_itimerval* value,
                       struct __kernel_itimerval* ovalue) {
    struct shim_handle* hdl = get_fd_handle(fd, NULL, NULL);
    if (!hdl)
        return -EBADF;
    
    return 0;
}

long shim_do_timerfd_gettime(int fd, struct __kernel_itimerval* value) {
    struct shim_handle* hdl = get_fd_handle(fd, NULL, NULL);
    if (!hdl)
        return -EBADF;
    
    return 0;

}