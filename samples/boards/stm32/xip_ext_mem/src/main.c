/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/flash.h>
#include <cmsis_core.h>

__attribute((section("EXTMEM")))
void helper_function(){
    printk("This code is running from external memory!\n");
}


int main(void)
{
	const struct device *flash_dev = DEVICE_DT_GET(DT_ALIAS(spi_flash0));
    volatile uint32_t *ext_mem = ((volatile uint32_t *)(0xFFFFFFFE & (uint32_t)helper_function));

	if (!device_is_ready(flash_dev)) {
		printk("%s: device not ready.\n", flash_dev->name);
		return 0;
	}

    printk("Reading from address: 0x%x ...\n", (uint32_t)ext_mem);
    printk("Reading value: 0x%x\n", ext_mem[0]);

	helper_function();

	return 0;
}
