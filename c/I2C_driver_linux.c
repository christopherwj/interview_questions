//https://www.kernel.org/doc/html/latest/i2c/dev-interface.html#c-example

#include <linux/i2c-dev.h>
#include <i2c/smbus.h>

__u8 reg = 0x10; /* Device register to access */
__s32 res;
char buf[10];

/* Using SMBus commands */
res = i2c_smbus_read_word_data(file, reg);
if (res < 0) {
  /* ERROR HANDLING: I2C transaction failed */
} else {
  /* res contains the read word */
}

/*
 * Using I2C Write, equivalent of
 * i2c_smbus_write_word_data(file, reg, 0x6543)
 */
buf[0] = reg;
buf[1] = 0x43;
buf[2] = 0x65;
if (write(file, buf, 3) != 3) {
  /* ERROR HANDLING: I2C transaction failed */
}

/* Using I2C Read, equivalent of i2c_smbus_read_byte(file) */
if (read(file, buf, 1) != 1) {
  /* ERROR HANDLING: I2C transaction failed */
} else {
  /* buf[0] contains the read byte */
}
