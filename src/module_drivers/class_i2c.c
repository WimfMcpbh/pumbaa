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

#include "pumbaa.h"

#if CONFIG_PUMBAA_CLASS_I2C == 1

/**
 * Print the i2c soft object.
 */
static void class_i2c_print(const mp_print_t *print_p,
                            mp_obj_t self_in,
                            mp_print_kind_t kind)
{
    struct class_i2c_t *self_p;

    self_p = MP_OBJ_TO_PTR(self_in);
    mp_printf(print_p, "<0x%p>", self_p);
}

/**
 * Create a new I2C object associated with the id.
 */
static mp_obj_t class_i2c_make_new(const mp_obj_type_t *type_p,
                                   mp_uint_t n_args,
                                   mp_uint_t n_kw,
                                   const mp_obj_t *args_p)
{
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_device, MP_ARG_REQUIRED | MP_ARG_INT },
        { MP_QSTR_baudrate, MP_ARG_INT, { .u_int = I2C_BAUDRATE_100KBPS } },
        { MP_QSTR_address, MP_ARG_INT, { .u_int = -1 } },
    };
    struct class_i2c_t *self_p;
    mp_map_t kwargs;
    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    int device;
    int baudrate;
    int address;

    mp_arg_check_num(n_args, n_kw, 1, MP_OBJ_FUN_ARGS_MAX, true);

    /* Parse args. */
    mp_map_init(&kwargs, 0);
    mp_arg_parse_all(n_args,
                     args_p,
                     &kwargs,
                     MP_ARRAY_SIZE(allowed_args),
                     allowed_args,
                     args);

    /* Create a new i2c object. */
    self_p = m_new_obj(struct class_i2c_t);
    self_p->base.type = &module_drivers_class_i2c;

    /* Device argument. */
    device = args[0].u_int;

    if ((device < 0) || (device >= I2C_DEVICE_MAX)) {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError,
                                           "bad device"));
    }

    /* Baudrate argument. */
    baudrate = args[1].u_int;

    /* Address argument. */
    address = args[2].u_int;

    if (i2c_init(&self_p->drv,
                 &i2c_device[device],
                 baudrate,
                 address) != 0) {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_OSError,
                                           "i2c_init() failed"));
    }

    return (self_p);
}

/**
 * def start(self)
 */
static mp_obj_t class_i2c_start(mp_obj_t self_in)
{
    struct class_i2c_t *self_p;

    self_p = MP_OBJ_TO_PTR(self_in);
    i2c_start(&self_p->drv);

    return (mp_const_none);
}

/**
 * def stop(self)
 */
static mp_obj_t class_i2c_stop(mp_obj_t self_in)
{
    struct class_i2c_t *self_p;

    self_p = MP_OBJ_TO_PTR(self_in);
    i2c_stop(&self_p->drv);

    return (mp_const_none);
}

/**
 * def read(self, address, size)
 */
static mp_obj_t class_i2c_read(mp_obj_t self_in,
                               mp_obj_t address_in,
                               mp_obj_t size_in)
{
    struct class_i2c_t *self_p;
    vstr_t vstr;
    int address;
    ssize_t size;

    self_p = MP_OBJ_TO_PTR(self_in);
    address = mp_obj_get_int(address_in);
    size = mp_obj_get_int(size_in);

    vstr_init_len(&vstr, size);
    size = i2c_read(&self_p->drv, address, vstr.buf, size);

    if (size < 0) {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_OSError,
                                           "i2c_read() failed"));
    }

    vstr.len = size;

    return (mp_obj_new_str_from_vstr(&mp_type_bytes, &vstr));
}

/**
 * def read_into(self, address, buffer[, size])
 */
static mp_obj_t class_i2c_read_into(mp_uint_t n_args, const mp_obj_t *args_p)
{
    struct class_i2c_t *self_p;
    int address;
    mp_buffer_info_t buffer_info;
    ssize_t size;

    self_p = MP_OBJ_TO_PTR(args_p[0]);
    address = mp_obj_get_int(args_p[1]);
    mp_get_buffer_raise(MP_OBJ_TO_PTR(args_p[2]),
                        &buffer_info,
                        MP_BUFFER_WRITE);

    /* Get the size. */
    if (n_args == 4) {
        size = mp_obj_get_int(args_p[3]);

        if (buffer_info.len < size) {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError,
                                               "bad buffer length"));
        }
    } else {
        size = buffer_info.len;
    }

    size = i2c_read(&self_p->drv, address, buffer_info.buf, size);

    if (size < 0) {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_OSError,
                                           "i2c_read() failed"));
    }

    return (MP_OBJ_NEW_SMALL_INT(size));
}

/**
 * def write(self, address, buffer[, size])
 */
static mp_obj_t class_i2c_write(mp_uint_t n_args, const mp_obj_t *args_p)
{
    struct class_i2c_t *self_p;
    mp_buffer_info_t buffer_info;
    int address;
    ssize_t size;

    self_p = MP_OBJ_TO_PTR(args_p[0]);
    address = mp_obj_get_int(args_p[1]);
    mp_get_buffer_raise(MP_OBJ_TO_PTR(args_p[2]),
                        &buffer_info,
                        MP_BUFFER_READ);

    /* Get the size. */
    if (n_args == 4) {
        size = mp_obj_get_int(args_p[3]);

        if (buffer_info.len < size) {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError,
                                               "bad buffer length"));
        }
    } else {
        size = buffer_info.len;
    }

    size = i2c_write(&self_p->drv, address, buffer_info.buf, size);

    if (size < 0) {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_OSError,
                                           "i2c_write() failed"));
    }

    return (MP_OBJ_NEW_SMALL_INT(size));
}

/**
 * def scan(self)
 */
static mp_obj_t class_i2c_scan(mp_obj_t self_in)
{
    struct class_i2c_t *self_p;
    mp_obj_t list;
    int address;

    self_p = MP_OBJ_TO_PTR(self_in);
    list = mp_obj_new_list(0, NULL);

    for (address = 0; address < 128; address++) {
        if (i2c_scan(&self_p->drv, address) == 1) {
            mp_obj_list_append(list, MP_OBJ_NEW_SMALL_INT(address));
        }
    }

    return (list);
}

static MP_DEFINE_CONST_FUN_OBJ_1(class_i2c_start_obj, class_i2c_start);
static MP_DEFINE_CONST_FUN_OBJ_1(class_i2c_stop_obj, class_i2c_stop);
static MP_DEFINE_CONST_FUN_OBJ_3(class_i2c_read_obj, class_i2c_read);
static MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(class_i2c_read_into_obj, 3, 4, class_i2c_read_into);
static MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(class_i2c_write_obj, 3, 4, class_i2c_write);
static MP_DEFINE_CONST_FUN_OBJ_1(class_i2c_scan_obj, class_i2c_scan);

static const mp_rom_map_elem_t class_i2c_locals_dict_table[] = {
    /* Instance methods. */
    { MP_ROM_QSTR(MP_QSTR_start), MP_ROM_PTR(&class_i2c_start_obj) },
    { MP_ROM_QSTR(MP_QSTR_stop), MP_ROM_PTR(&class_i2c_stop_obj) },
    { MP_ROM_QSTR(MP_QSTR_read), MP_ROM_PTR(&class_i2c_read_obj) },
    { MP_ROM_QSTR(MP_QSTR_read_into), MP_ROM_PTR(&class_i2c_read_into_obj) },
    { MP_ROM_QSTR(MP_QSTR_write), MP_ROM_PTR(&class_i2c_write_obj) },
    { MP_ROM_QSTR(MP_QSTR_scan), MP_ROM_PTR(&class_i2c_scan_obj) },

    /* Class constants. */
    { MP_ROM_QSTR(MP_QSTR_BAUDRATE_1MBPS), MP_ROM_INT(I2C_BAUDRATE_1MBPS) },
    { MP_ROM_QSTR(MP_QSTR_BAUDRATE_400KBPS), MP_ROM_INT(I2C_BAUDRATE_400KBPS) },
    { MP_ROM_QSTR(MP_QSTR_BAUDRATE_100KBPS), MP_ROM_INT(I2C_BAUDRATE_100KBPS) }
};

static MP_DEFINE_CONST_DICT(class_i2c_locals_dict, class_i2c_locals_dict_table);

/**
 * I2c class type.
 */
const mp_obj_type_t module_drivers_class_i2c = {
    { &mp_type_type },
    .name = MP_QSTR_I2C,
    .print = class_i2c_print,
    .make_new = class_i2c_make_new,
    .locals_dict = (mp_obj_t)&class_i2c_locals_dict,
};

#endif
