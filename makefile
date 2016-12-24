TARGET = BareBoard

# compiler
CC = arm-none-eabi-gcc
# compiling flags
CCFLAGS = -Wall

#linker
LD = arm-none-eabi-gcc -o
#linker flags
LDFLAGS = -Wall -T stm32.ld

# directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

SRC := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(subst $(SRCDIR),$(OBJDIR),$(SRC:%.c=%.o))

rm       = rm -f

# build rules
all:$(OBJECTS)
	$(LD) $(BINDIR)\$(TARGET) $(LDFLAGS) $(OBJECTS)
	@echo "Linking complete!"
	
# compilation rules
$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CCFLAGS) -c $< -o $@
	$(CC) -MM $(CFLAGS) $< > $(OBJDIR)/$*.d
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