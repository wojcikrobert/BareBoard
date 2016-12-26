TARGET = BareBoard

#obj dump
DUMP = arm-none-eabi-objdump
#dump flags
DUMPFLAGS = -S

# compiler
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
# compiling flags
ASFLAGS = -Wall -ggdb
CCFLAGS = -Wall -ggdb

#linker
LD = arm-none-eabi-gcc -o
#linker flags
LDFLAGS = -Wall -T stm32.ld

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
	
# compilation rules
$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CCFLAGS) -c $< -o $@
	$(CC) -MM $(CCFLAGS) $< > $(OBJDIR)/$*.d
	$(DUMP) $(DUMPFLAGS) $@  > $(LISDIR)/$*.lis
	@echo "Object created: " $@
	
$(OBJDIR)/%.o : $(SRCDIR)/%.s
	$(AS) $(ASFLAGS) -c $< -o $@
	$(AS) -MM $(ASFLAGS) $< > $(OBJDIR)/$*.d
	$(DUMP) $(DUMPFLAGS) $@  > $(LISDIR)/$*.lis
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