if(SB_CONFIG_BOOTLOADER_MCUBOOT)
  set_target_properties(${DEFAULT_IMAGE} PROPERTIES BOARD stm32h7s78_dk/stm32h7s7xx/extmem)
  set_target_properties(mcuboot PROPERTIES BOARD stm32h7s78_dk/stm32h7s7xx/mcuboot)
endif()