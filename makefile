TARGET = BareBoard

# compiler
CC = arm-none-eabi-gcc
# compiling flags
CCFLAGS = -Wall

#linker
LD = arm-none-eabi-gcc -o
#linker flags
LDFLAGS = -Wall

# directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

OBJECTS = $(OBJDIR)\main.o $(OBJDIR)\context_manager.o

rm       = rm -f

# compilation rules
all: $(OBJECTS)
	$(LD) $(BINDIR)\$(TARGET) $(LDFLAGS) $(OBJECTS)
	@echo "Linking complete!"
	
$(OBJDIR)\main.o : $(SRCDIR)\main.c
	$(CC) $(CCFLAGS)-c $< -o $@
	@echo "Object created: " $@ 
	
$(OBJDIR)\context_manager.o : $(SRCDIR)\context_manager.c $(SRCDIR)\context_manager.h
	$(CC) $(CCFLAGS) -c $< -o $@
	@echo "Object created: " $@ 

	
# build rules

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