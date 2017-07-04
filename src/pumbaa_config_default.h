/**
 * @section License
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016-2017, Erik Moqvist
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * This file is part of the Pumbaa project.
 */

#ifndef __PUMBAA_CONFIG_DEFAULT_H__
#define __PUMBAA_CONFIG_DEFAULT_H__

/**
 * This is the default configuration of Pumbaa.
 */

#ifndef MICROPY_CPYTHON_COMPAT
#    define MICROPY_CPYTHON_COMPAT                        (1)
#endif

#ifndef MICROPY_OBJ_REPR
#    define MICROPY_OBJ_REPR             (MICROPY_OBJ_REPR_C)
#endif

#ifndef MICROPY_ALLOC_PATH_MAX
#    define MICROPY_ALLOC_PATH_MAX                      (128)
#endif

#ifndef MICROPY_ENABLE_GC
#    define MICROPY_ENABLE_GC                             (1)
#endif

#ifndef MICROPY_MALLOC_USES_ALLOCATED_SIZE
#    define MICROPY_MALLOC_USES_ALLOCATED_SIZE            (1)
#endif

#ifndef MICROPY_PY_MICROPYTHON_MEM_INFO
#    define MICROPY_PY_MICROPYTHON_MEM_INFO               (1)
#endif

#ifndef MICROPY_MEM_STATS
#    define MICROPY_MEM_STATS                             (1)
#endif

#ifndef MICROPY_DEBUG_PRINTERS
#    define MICROPY_DEBUG_PRINTERS                        (0)
#endif

#ifndef MICROPY_HELPER_REPL
#    define MICROPY_HELPER_REPL                           (1)
#endif

#ifndef MICROPY_HELPER_LEXER_UNIX
#    if defined(ARCH_LINUX)
#        define MICROPY_HELPER_LEXER_UNIX                 (1)
#    else
#        define MICROPY_HELPER_LEXER_UNIX                 (0)
#    endif
#endif

#ifndef MICROPY_LONGINT_IMPL
#    define MICROPY_LONGINT_IMPL   (MICROPY_LONGINT_IMPL_MPZ)
#endif

#ifndef MICROPY_ENABLE_SOURCE_LINE
#    define MICROPY_ENABLE_SOURCE_LINE                    (1)
#endif

#ifndef MICROPY_MODULE_WEAK_LINKS
#    define MICROPY_MODULE_WEAK_LINKS                     (1)
#endif

#ifndef MICROPY_FLOAT_IMPL
#    define MICROPY_FLOAT_IMPL       MICROPY_FLOAT_IMPL_FLOAT
#endif

#ifndef MICROPY_PY_BUILTINS_FLOAT
#    define MICROPY_PY_BUILTINS_FLOAT                     (1)
#endif

#ifndef MICROPY_PY_BUILTINS_FROZENSET
#    define MICROPY_PY_BUILTINS_FROZENSET                 (1)
#endif

#ifndef MICROPY_PY_SYS_EXIT
#    define MICROPY_PY_SYS_EXIT                           (1)
#endif

#ifndef MICROPY_PY_SYS_PLATFORM
#    define MICROPY_PY_SYS_PLATFORM                   "simba"
#endif

#ifndef MICROPY_PY_SYS_STDFILES
#    define MICROPY_PY_SYS_STDFILES                       (1)
#endif

#ifndef MICROPY_PY_UBINASCII
#    define MICROPY_PY_UBINASCII                          (1)
#endif

#ifndef MICROPY_PY_UBINASCII_CRC32
#    define MICROPY_PY_UBINASCII_CRC32                    (1)
#endif

#ifndef MICROPY_PY_COLLECTIONS_ORDEREDDICT
#    define MICROPY_PY_COLLECTIONS_ORDEREDDICT            (1)
#endif

#ifndef MICROPY_PY_CMATH
#    define MICROPY_PY_CMATH                              (1)
#endif

#ifndef MICROPY_PY_UHASHLIB
#    define MICROPY_PY_UHASHLIB                           (1)
#endif

#ifndef MICROPY_PY_UJSON
#    define MICROPY_PY_UJSON                              (1)
#endif

#ifndef MICROPY_PY_URANDOM
#    define MICROPY_PY_URANDOM                            (1)
#endif

#ifndef MICROPY_PY_URANDOM_EXTRA_FUNCS
#    define MICROPY_PY_URANDOM_EXTRA_FUNCS                (1)
#endif

#ifndef MICROPY_PY_URE
#    define MICROPY_PY_URE                                (0)
#endif

#ifndef MICROPY_PY_THREAD
#    define MICROPY_PY_THREAD                             (1)
#endif

#ifndef MICROPY_PY_THREAD_GIL
#    define MICROPY_PY_THREAD_GIL                         (0)
#endif

#ifndef MICROPY_PY_UTIME
#    define MICROPY_PY_UTIME                              (1)
#endif

#ifndef MICROPY_PY_UZLIB
#    define MICROPY_PY_UZLIB                              (1)
#endif

#ifndef MICROPY_MODULE_FROZEN_STR
#    define MICROPY_MODULE_FROZEN_STR                     (0)
#endif

#ifndef MICROPY_MODULE_FROZEN_MPY
#    define MICROPY_MODULE_FROZEN_MPY                     (1)
#endif

#ifndef MICROPY_QSTR_EXTRA_POOL
#    if MICROPY_MODULE_FROZEN_MPY == 1
#        define MICROPY_QSTR_EXTRA_POOL mp_qstr_frozen_const_pool
#    endif
#endif

#ifndef MICROPY_MODULE_BUILTIN_INIT
#    define MICROPY_MODULE_BUILTIN_INIT                   (1)
#endif

#ifndef MPZ_DIG_SIZE
#    define MPZ_DIG_SIZE                                 (16)
#endif

#ifndef CONFIG_PUMBAA_MAIN_FRIENDLY_REPL
#    define CONFIG_PUMBAA_MAIN_FRIENDLY_REPL                1
#endif

#ifndef CONFIG_PUMBAA_MAIN_REBOOT_AT_EXIT
#    define CONFIG_PUMBAA_MAIN_REBOOT_AT_EXIT               1
#endif

#ifndef CONFIG_PUMBAA_HEAP_SIZE
#    if defined(ARCH_ESP)
#        define CONFIG_PUMBAA_HEAP_SIZE                 24576
#    elif defined(ARCH_ESP32)
#        define CONFIG_PUMBAA_HEAP_SIZE                 65536
#    elif defined(ARCH_LINUX)
#        define CONFIG_PUMBAA_HEAP_SIZE         (1024 * 1024)
#    else
#        define CONFIG_PUMBAA_HEAP_SIZE                 32768
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_BOARD
#    if defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_PUMBAA_CLASS_BOARD                   0
#    else
#        define CONFIG_PUMBAA_CLASS_BOARD                   1
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_DAC
#    if defined(CONFIG_MINIMAL_SYSTEM) || !defined(PORT_HAS_DAC) || defined(ARCH_ESP)
#        define CONFIG_PUMBAA_CLASS_DAC                     0
#    else
#        define CONFIG_PUMBAA_CLASS_DAC                     1
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_ADC
#    if defined(CONFIG_MINIMAL_SYSTEM) || !defined(PORT_HAS_ADC) || defined(ARCH_ESP)
#        define CONFIG_PUMBAA_CLASS_ADC                     0
#    else
#        define CONFIG_PUMBAA_CLASS_ADC                     1
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_EXTI
#    if defined(CONFIG_MINIMAL_SYSTEM) || !defined(PORT_HAS_EXTI)
#        define CONFIG_PUMBAA_CLASS_EXTI                    0
#    else
#        define CONFIG_PUMBAA_CLASS_EXTI                    1
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_EVENT
#    define CONFIG_PUMBAA_CLASS_EVENT                       1
#endif

#ifndef CONFIG_PUMBAA_CLASS_PIN
#    if defined(CONFIG_MINIMAL_SYSTEM) || !defined(PORT_HAS_PIN)
#        define CONFIG_PUMBAA_CLASS_PIN                     0
#    else
#        define CONFIG_PUMBAA_CLASS_PIN                     1
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_SPI
#    if defined(CONFIG_MINIMAL_SYSTEM) || !defined(PORT_HAS_SPI)
#        define CONFIG_PUMBAA_CLASS_SPI                     0
#    else
#        define CONFIG_PUMBAA_CLASS_SPI                     1
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_SD
#    if defined(CONFIG_MINIMAL_SYSTEM) || !defined(PORT_HAS_SD)
#        define CONFIG_PUMBAA_CLASS_SD                      0
#    else
#        define CONFIG_PUMBAA_CLASS_SD                      1
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_I2C
#    if defined(CONFIG_MINIMAL_SYSTEM) || !defined(PORT_HAS_I2C)
#        define CONFIG_PUMBAA_CLASS_I2C                     0
#    else
#        define CONFIG_PUMBAA_CLASS_I2C                     1
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_I2C_SOFT
#    if defined(CONFIG_MINIMAL_SYSTEM) || !defined(PORT_HAS_I2C_SOFT)
#        define CONFIG_PUMBAA_CLASS_I2C_SOFT                0
#    else
#        define CONFIG_PUMBAA_CLASS_I2C_SOFT                1
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_EEPROM_I2C
#    if defined(CONFIG_MINIMAL_SYSTEM) || !defined(PORT_HAS_EEPROM_I2C)
#        define CONFIG_PUMBAA_CLASS_EEPROM_I2C              0
#    else
#        define CONFIG_PUMBAA_CLASS_EEPROM_I2C              1
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_ESP_WIFI
#    if defined(CONFIG_MINIMAL_SYSTEM) || !defined(PORT_HAS_ESP_WIFI)
#        define CONFIG_PUMBAA_CLASS_ESP_WIFI                0
#    else
#        define CONFIG_PUMBAA_CLASS_ESP_WIFI                1
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_OWI
#    if defined(CONFIG_MINIMAL_SYSTEM) || !defined(PORT_HAS_OWI)
#        define CONFIG_PUMBAA_CLASS_OWI                     0
#    else
#        define CONFIG_PUMBAA_CLASS_OWI                     1
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_DS18B20
#    if defined(CONFIG_MINIMAL_SYSTEM) || !defined(PORT_HAS_DS18B20)
#        define CONFIG_PUMBAA_CLASS_DS18B20                 0
#    else
#        define CONFIG_PUMBAA_CLASS_DS18B20                 1
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_CAN
#    if defined(CONFIG_MINIMAL_SYSTEM) || !defined(PORT_HAS_CAN)
#        define CONFIG_PUMBAA_CLASS_CAN                     0
#    else
#        define CONFIG_PUMBAA_CLASS_CAN                     1
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_UART
#    if defined(CONFIG_MINIMAL_SYSTEM) || !defined(PORT_HAS_UART)
#        define CONFIG_PUMBAA_CLASS_UART                    0
#    else
#        define CONFIG_PUMBAA_CLASS_UART                    1
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_FLASH
#    if defined(CONFIG_MINIMAL_SYSTEM) || !defined(PORT_HAS_FLASH)
#        define CONFIG_PUMBAA_CLASS_FLASH                   0
#    else
#        define CONFIG_PUMBAA_CLASS_FLASH                   1
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_WS2812
#    if defined(CONFIG_MINIMAL_SYSTEM) || !defined(PORT_HAS_WS2812)
#        define CONFIG_PUMBAA_CLASS_WS2812                  0
#    else
#        define CONFIG_PUMBAA_CLASS_WS2812                  1
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_QUEUE
#    define CONFIG_PUMBAA_CLASS_QUEUE                       1
#endif

#ifndef CONFIG_PUMBAA_CLASS_TIMER
#    define CONFIG_PUMBAA_CLASS_TIMER                       1
#endif

#ifndef CONFIG_PUMBAA_OS_SYSTEM
#    define CONFIG_PUMBAA_OS_SYSTEM                         1
#endif

#ifndef CONFIG_PUMBAA_OS_FORMAT
#    define CONFIG_PUMBAA_OS_FORMAT                         1
#endif

#ifndef CONFIG_PUMBAA_SYS_LOCK
#    define CONFIG_PUMBAA_SYS_LOCK                          1
#endif

#ifndef CONFIG_PUMBAA_SYS_REBOOT
#    define CONFIG_PUMBAA_SYS_REBOOT                        1
#endif

#ifndef CONFIG_PUMBAA_THRD
#    if MICROPY_PY_THREAD == 1
#        define CONFIG_PUMBAA_THRD                          1
#    else
#        define CONFIG_PUMBAA_THRD                          0
#    endif
#endif

#ifndef CONFIG_PUMBAA_PING
#    if defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_PUMBAA_PING                          0
#    else
#        define CONFIG_PUMBAA_PING                          1
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_HTTP_SERVER
#    if defined(CONFIG_MINIMAL_SYSTEM) || defined(ARCH_ARM) || defined(BOARD_ESP01)
#        define CONFIG_PUMBAA_CLASS_HTTP_SERVER             0
#    elif CONFIG_PUMBAA_THRD == 1
#        define CONFIG_PUMBAA_CLASS_HTTP_SERVER             1
#    else
#        define CONFIG_PUMBAA_CLASS_HTTP_SERVER             0
#    endif
#endif

#ifndef CONFIG_PUMBAA_CLASS_HTTP_SERVER_WEBSOCKET
#    if CONFIG_PUMBAA_CLASS_HTTP_SERVER == 1
#        define CONFIG_PUMBAA_CLASS_HTTP_SERVER_WEBSOCKET   1
#    else
#        define CONFIG_PUMBAA_CLASS_HTTP_SERVER_WEBSOCKET   0
#    endif
#endif

#ifndef CONFIG_PUMBAA_MODULE_SOCKET
#    if defined(CONFIG_MINIMAL_SYSTEM) || defined(ARCH_ARM)
#        define CONFIG_PUMBAA_MODULE_SOCKET                 0
#    else
#        define CONFIG_PUMBAA_MODULE_SOCKET                 1
#    endif
#endif

#ifndef CONFIG_PUMBAA_MODULE_SELECT
#    if defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_PUMBAA_MODULE_SELECT                 0
#    else
#        define CONFIG_PUMBAA_MODULE_SELECT                 1
#    endif
#endif

#ifndef CONFIG_PUMBAA_MODULE_SSL
#    if defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_PUMBAA_MODULE_SSL                    0
#    elif defined(ARCH_ESP32) || defined(ARCH_LINUX)
#        define CONFIG_PUMBAA_MODULE_SSL                    1
#    else
#        define CONFIG_PUMBAA_MODULE_SSL                    0
#    endif
#endif

#ifndef CONFIG_PUMBAA_EMACS
#    if defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_PUMBAA_EMACS                         0
#    elif defined(ARCH_LINUX) || defined(ARCH_ESP32)
#        define CONFIG_PUMBAA_EMACS                         1
#    else
#        define CONFIG_PUMBAA_EMACS                         0
#    endif
#endif

/**
 * Validate the configuration.
 */

#if CONFIG_PUMBAA_THRD == 1 && MICROPY_PY_THREAD == 0
#    error "MICROPY_PY_THREAD must be 1 when CONFIG_PUMBAA_THRD is 1."
#endif

#if CONFIG_PUMBAA_HTTP_SERVER == 1 && MICROPY_PY_THREAD == 0
#    error "MICROPY_PY_THREAD must be 1 when CONFIG_PUMBAA_HTTP_SERVER is 1."
#endif

#if CONFIG_PUMBAA_HTTP_SERVER_WEBSOCKET == 1 && CONFIG_PUMBAA_HTTP_SERVER == 0
#    error "CONFIG_PUMBAA_HTTP_SERVER must be 1 when CONFIG_PUMBAA_HTTP_SERVER_WEBSOCKET is 1."
#endif

extern const struct _mp_obj_module_t mp_module_uos;
extern const struct _mp_obj_module_t mp_module_utime;
extern const struct _mp_obj_module_t mp_module_usocket;
extern const struct _mp_obj_module_t mp_module_uselect;
extern const struct _mp_obj_module_t module_kernel;
extern const struct _mp_obj_module_t module_sync;
extern const struct _mp_obj_module_t module_drivers;
extern const struct _mp_obj_module_t module_inet;
extern const struct _mp_obj_module_t module_text;
extern const struct _mp_obj_module_t module_board;

#ifndef MICROPY_PORT_BUILTIN_MODULES_EXTRA
#    define MICROPY_PORT_BUILTIN_MODULES_EXTRA
#endif

#ifndef MICROPY_PORT_BUILTIN_MODULE_WEAK_LINKS_EXTRA
#    define MICROPY_PORT_BUILTIN_MODULE_WEAK_LINKS_EXTRA
#endif

#ifndef MICROPY_PORT_ROOT_POINTERS_EXTRA
#    define MICROPY_PORT_ROOT_POINTERS_EXTRA
#endif

#if CONFIG_PUMBAA_MODULE_SOCKET == 1
#    define PORT_BUILTIN_MODULE_SOCKET                                  \
    { MP_ROM_QSTR(MP_QSTR_usocket), MP_ROM_PTR(&mp_module_usocket) },
#    define PORT_BUILTIN_MODULE_WEAK_LINKS_SOCKET                       \
    { MP_OBJ_NEW_QSTR(MP_QSTR_socket), (mp_obj_t)&mp_module_usocket },
#else
#    define PORT_BUILTIN_MODULE_SOCKET
#    define PORT_BUILTIN_MODULE_WEAK_LINKS_SOCKET
#endif

#if CONFIG_PUMBAA_MODULE_SELECT == 1
#    define PORT_BUILTIN_MODULE_SELECT                                  \
    { MP_ROM_QSTR(MP_QSTR_uselect), MP_ROM_PTR(&mp_module_uselect) },
#    define PORT_BUILTIN_MODULE_WEAK_LINKS_SELECT                       \
    { MP_OBJ_NEW_QSTR(MP_QSTR_select), (mp_obj_t)&mp_module_uselect },
#else
#    define PORT_BUILTIN_MODULE_SELECT
#    define PORT_BUILTIN_MODULE_WEAK_LINKS_SELECT
#endif

#if CONFIG_PUMBAA_MODULE_SSL == 1
#    define PORT_BUILTIN_MODULE_SSL                             \
    { MP_ROM_QSTR(MP_QSTR_ussl), MP_ROM_PTR(&mp_module_ussl) },
#    define PORT_BUILTIN_MODULE_WEAK_LINKS_SSL                          \
    { MP_OBJ_NEW_QSTR(MP_QSTR_ssl), (mp_obj_t)&mp_module_ussl },
#else
#    define PORT_BUILTIN_MODULE_SSL
#    define PORT_BUILTIN_MODULE_WEAK_LINKS_SSL
#endif

#define MICROPY_PORT_BUILTIN_MODULES                                    \
    { MP_ROM_QSTR(MP_QSTR_uos), MP_ROM_PTR(&mp_module_uos) },           \
        PORT_BUILTIN_MODULE_SELECT                                      \
        PORT_BUILTIN_MODULE_SOCKET                                      \
        PORT_BUILTIN_MODULE_SSL                                         \
    { MP_ROM_QSTR(MP_QSTR_kernel), MP_ROM_PTR(&module_kernel) },        \
    { MP_ROM_QSTR(MP_QSTR_sync), MP_ROM_PTR(&module_sync) },            \
    { MP_ROM_QSTR(MP_QSTR_drivers), MP_ROM_PTR(&module_drivers) },      \
    { MP_ROM_QSTR(MP_QSTR_inet), MP_ROM_PTR(&module_inet) },            \
    { MP_ROM_QSTR(MP_QSTR_text), MP_ROM_PTR(&module_text) },            \
    { MP_ROM_QSTR(MP_QSTR_board), MP_ROM_PTR(&module_board) },          \
    { MP_ROM_QSTR(MP_QSTR_utime), MP_ROM_PTR(&mp_module_utime) },       \
        MICROPY_PORT_BUILTIN_MODULES_EXTRA

#define MICROPY_PORT_BUILTIN_MODULE_WEAK_LINKS                          \
    { MP_OBJ_NEW_QSTR(MP_QSTR_binascii), (mp_obj_t)&mp_module_ubinascii }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_collections), (mp_obj_t)&mp_module_collections }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_hashlib), (mp_obj_t)&mp_module_uhashlib }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_io), (mp_obj_t)&mp_module_io },           \
    { MP_OBJ_NEW_QSTR(MP_QSTR_json), (mp_obj_t)&mp_module_ujson },      \
    { MP_OBJ_NEW_QSTR(MP_QSTR_os), (mp_obj_t)&mp_module_uos },          \
    { MP_OBJ_NEW_QSTR(MP_QSTR_random), (mp_obj_t)&mp_module_urandom },  \
        PORT_BUILTIN_MODULE_WEAK_LINKS_SELECT                           \
        PORT_BUILTIN_MODULE_WEAK_LINKS_SOCKET                           \
        PORT_BUILTIN_MODULE_WEAK_LINKS_SSL                              \
    { MP_OBJ_NEW_QSTR(MP_QSTR_struct), (mp_obj_t)&mp_module_ustruct },  \
    { MP_OBJ_NEW_QSTR(MP_QSTR_time), (mp_obj_t)&mp_module_utime },      \
    { MP_OBJ_NEW_QSTR(MP_QSTR_zlib), (mp_obj_t)&mp_module_uzlib },      \
        MICROPY_PORT_BUILTIN_MODULE_WEAK_LINKS_EXTRA

/* Extra built in names to add to the global namespace. */
#define MICROPY_PORT_BUILTINS                                           \
    { MP_ROM_QSTR(MP_QSTR_help), MP_ROM_PTR(&mp_builtin_help_obj) },    \
    { MP_ROM_QSTR(MP_QSTR_input), MP_ROM_PTR(&mp_builtin_input_obj) },  \
    { MP_ROM_QSTR(MP_QSTR_open), MP_ROM_PTR(&mp_builtin_open_obj) },

#define MICROPY_PORT_ROOT_POINTERS \
    mp_obj_t keyboard_interrupt_obj; \
    const char *readline_hist[8]; \
    MICROPY_PORT_ROOT_POINTERS_EXTRA

//////////////////////////////////////////
// Do not change anything beyond this line
//////////////////////////////////////////

// Define to 1 to use undertested inefficient GC helper implementation
// (if more efficient arch-specific one is not available).
#ifndef MICROPY_GCREGS_SETJMP
    #ifdef __mips__
        #define MICROPY_GCREGS_SETJMP                     (1)
    #else
        #define MICROPY_GCREGS_SETJMP                     (0)
    #endif
#endif

// type definitions for the specific machine

#ifdef __LP64__
typedef long mp_int_t; // must be pointer size
typedef unsigned long mp_uint_t; // must be pointer size
#else
// These are definitions for machines where sizeof(int) == sizeof(void*),
// regardless for actual size.
typedef int mp_int_t; // must be pointer size
typedef unsigned int mp_uint_t; // must be pointer size
#endif

#define BYTES_PER_WORD sizeof(mp_int_t)

// Cannot include <sys/types.h>, as it may lead to symbol name clashes
#if _FILE_OFFSET_BITS == 64 && !defined(__LP64__)
typedef long long mp_off_t;
#else
typedef long mp_off_t;
#endif

#define mp_hal_pin_obj_t mp_obj_t

// We need to provide a declaration/definition of alloca()
#include <alloca.h>

#define MP_PLAT_PRINT_STRN(str, len) mp_hal_stdout_tx_strn_cooked(str, len)

#define MP_STATE_PORT MP_STATE_VM

#endif
