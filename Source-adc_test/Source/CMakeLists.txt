add_executable(Soure main.c)
pico_generate_pio_header(Soure ${CMAKE_CURRENT_LIST_DIR}/ADC_captures.pio)
pico_generate_pio_header(Soure ${CMAKE_CURRENT_LIST_DIR}/LCD_SPI.pio)
target_sources(Soure PRIVATE LCD.c)
target_link_libraries(Soure PRIVATE 
    pico_stdlib
    hardware_dma
    hardware_pio
    hardware_clocks
    hardware_flash
    hardware_adc
    hardware_spi
    hardware_i2c
    pico_base_headers
    ${CYW_LIB}
    )

pico_add_extra_outputs(Soure)

