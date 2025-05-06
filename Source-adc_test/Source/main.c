/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

 #include "pico/stdlib.h"
 #include <stdio.h>
 #include "hardware/dma.h"
 #include "hardware/pio.h"
 #include "hardware/clocks.h"
 #include "hardware/irq.h"
 #include "ADC_captures.pio.h"
 #include <math.h>

 #define BUFFER_SIZE 2048

 PIO pio = pio0;
 uint sm = 0, dma_chan = 0, offset = 0;



 int main() {
	set_sys_clock_khz(250000, true);  //over lcock
	stdio_init_all();
	offset = pio_add_program(pio, &adc_captures_program); //add PIO program
	adc_captures_program_init(pio, sm, offset);
	uint32_t capture_buf[BUFFER_SIZE];
	hard_assert(capture_buf);

	pio_sm_set_enabled(pio, sm, false);
    pio_sm_clear_fifos(pio, sm);
    pio_sm_restart(pio, sm);
    dma_channel_config d = dma_channel_get_default_config(dma_chan);
    channel_config_set_read_increment(&d, false);
    channel_config_set_write_increment(&d, true);
    channel_config_set_dreq(&d, pio_get_dreq(pio, sm, false));
    dma_channel_configure(dma_chan, &d,
        &capture_buf,        // Destination pointer
        &pio->rxf[sm],       // Source pointer
        BUFFER_SIZE,         // Number of transfers
        true                 // Start immediately
    );

    pio_sm_set_enabled(pio, sm, true);
    dma_channel_wait_for_finish_blocking(dma_chan);


	while (true) {
		//Restart DMA-ADC
		hard_assert(capture_buf);
        dma_channel_config d = dma_channel_get_default_config(dma_chan);
        channel_config_set_read_increment(&d, false);
        channel_config_set_write_increment(&d, true);
        channel_config_set_dreq(&d, pio_get_dreq(pio, sm, false));
        dma_channel_configure(dma_chan, &d,
            &capture_buf,        // Destination pointer
            &pio->rxf[sm],       // Source pointer
            BUFFER_SIZE,         // Number of transfers
            true                 // Start immediately
        );
		gpio_put(25, 1); //LED
        pio_sm_set_enabled(pio, sm, true);
        dma_channel_wait_for_finish_blocking(dma_chan); //ADC read complete
		gpio_put(25, 0); //LED
		for(int i=0; i<=320; i++)
		{

		}
	}
 }
 