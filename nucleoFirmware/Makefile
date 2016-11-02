BUILDDIR = build

DEVICE = libraries/CMSIS/device/ST/STM32L0xx
CMSIS = libraries/CMSIS
LIBRARIES = libraries/STM32L0xx_HAL_Driver
SYSTEM = system
DRIVERS = drivers
UTILS = utils
CONFIG = config

SOURCES += main.c

SOURCES += $(LIBRARIES)/source/stm32l0xx_hal_gpio.c \
		   $(LIBRARIES)/source/stm32l0xx_hal_rcc.c \
		   $(LIBRARIES)/source/stm32l0xx_hal_rcc_ex.c \
		   $(LIBRARIES)/source/stm32l0xx_hal_cortex.c \
		   $(LIBRARIES)/source/stm32l0xx_hal.c \
		   $(LIBRARIES)/source/stm32l0xx_hal_rtc.c \
		   $(LIBRARIES)/source/stm32l0xx_hal_rtc_ex.c \
		   $(LIBRARIES)/source/stm32l0xx_hal_flash.c \
		   $(LIBRARIES)/source/stm32l0xx_hal_flash_ex.c \
		   $(LIBRARIES)/source/stm32l0xx_hal_i2c.c \
		   $(LIBRARIES)/source/stm32l0xx_hal_dma.c

SOURCES += $(SYSTEM)/startup_stm32l051xx.s \
		   $(SYSTEM)/stm32l0xx_hal_msp.c \
		   $(SYSTEM)/stm32l0xx_it.c \
		   $(SYSTEM)/system_stm32l0xx.c

SOURCES += $(DRIVERS)/usart.c \
		   $(DRIVERS)/console.c \
		   $(DRIVERS)/spi.c

SOURCES += $(UTILS)/buffer8.c \
		   $(UTILS)/newlib_hooks.c \
		   $(UTILS)/timerCallback.c \
		   $(UTILS)/misc.c

OBJECTS = $(addprefix $(BUILDDIR)/, $(addsuffix .o, $(basename $(SOURCES))))

INCLUDES += -I$(DEVICE)/include \
			-I$(LIBRARIES)/include \
			-I$(CMSIS)/include \
			-I$(SYSTEM) \
			-I$(DRIVERS) \
			-I$(UTILS) \
			-I$(CONFIG) \
			-I.

ELF = $(BUILDDIR)/program.elf
HEX = $(BUILDDIR)/program.hex
BIN = $(BUILDDIR)/program.bin

CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
AR = arm-none-eabi-ar
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

WARNINGS = -Wall -Werror
	
CFLAGS  = -Os -g \
   -mcpu=cortex-m0plus -mthumb \
   -mfloat-abi=soft \
   $(INCLUDES) -DUSE_STDPERIPH_DRIVER \
   -D STM32L051xx \
   $(WARNINGS)

LDSCRIPT = buildTools/stm32_flash.ld
LDFLAGS += -T$(LDSCRIPT) -mthumb -mcpu=cortex-m0plus -nostdlib -LbuildTools --specs=nano.specs

LDLIBS += -lc -lnosys

FLASH_SCRIPT = buildTools/flash.jlink

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex $< $@

$(ELF): $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)
	$(SIZE) $(ELF)

$(BUILDDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILDDIR)/%.o: %.s
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

flash: $(BIN)
	st-flash write $(BIN) 08000000

debug: $(ELF)
	arm-none-eabi-gdb $(ELF)

clean:
	rm -rf build
