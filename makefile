TARGET = BareBoard

#obj dump
DUMP = arm-none-eabi-objdump
#dump flags
DUMPFLAGS1 = -S
DUMPFLAGS2 = -t

#obj copy
COPY = arm-none-eabi-objcopy
#obj copy flags
COPYFLAGS = -O ihex

# compiler
CC = arm-none-eabi-gcc
AS = arm-none-eabi-gcc
# compiling flags
ASFLAGS = 
CCFLAGS = -mthumb -mcpu=cortex-m7 -Wall -ggdb

#linker
LD = arm-none-eabi-gcc -o
#linker flags
LDFLAGS = -Wall -nostdlib -nostartfiles -Wl,-Map=$(BINDIR)/$(TARGET).map -T stm32.ld

# directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin
LISDIR = listings

SRCA := $(wildcard $(SRCDIR)/*.s)
SRCC := $(wildcard $(SRCDIR)/*.c)
OBJECTSA := $(subst $(SRCDIR),$(OBJDIR),$(SRCA:%.s=%.o))
OBJECTSC := $(subst $(SRCDIR),$(OBJDIR),$(SRCC:%.c=%.o))
OBJECTS := $(OBJECTSA) $(OBJECTSC)

rm       = rm -f

# build rules
all:$(OBJECTS)
	$(LD) $(BINDIR)\$(TARGET) $(LDFLAGS) $(OBJECTS)
	@echo "Linking complete!"
	$(DUMP) $(DUMPFLAGS1) $(BINDIR)\$(TARGET) > $(LISDIR)/$(TARGET).lis
	@echo "Listing created!"
	$(DUMP) $(DUMPFLAGS2) $(BINDIR)\$(TARGET) > $(BINDIR)/$(TARGET).sym
	@echo "Symbols list created!"
	$(COPY) $(COPYFLAGS) $(BINDIR)/$(TARGET) $(BINDIR)/$(TARGET).hex
	@echo "Hex file created!"
	
# compilation rules
$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CCFLAGS) -c $< -o $@
	$(CC) -MM $(CCFLAGS) $< > $(OBJDIR)/$*.d
	$(DUMP) $(DUMPFLAGS1) $@  > $(LISDIR)/$*.lis
	@echo "Object created: " $@
	
$(OBJDIR)/%.o : $(SRCDIR)/%.s
	$(AS) $(ASFLAGS) -c $< -o $@
	$(AS) -MM $(ASFLAGS) $< > $(OBJDIR)/$*.d
	$(DUMP) $(DUMPFLAGS1) $@  > $(LISDIR)/$*.lis
	@echo "Object created: " $@ 

#clean up rules
.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

#remove rules
.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"