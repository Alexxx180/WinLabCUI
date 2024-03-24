# recursive file search
rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SHELL := powershell.exe
.SHELLFLAGS := -NoProfile -Command
CMD=powershell -NoProfile -Command

CC=cl
CFLAGS=/nologo /EHsc /I header
LINK=link
SYSTEM=CONSOLE

EXE=target.exe

BUILD=build
SRC=source
OBJ=artifacts
BIN=bin

CLOG=compile.log
LLOG=link.log

CFILES=$(call rwildcard,$(SRC),*.cpp) # search for *.cpp files
OFILES=$(CFILES:.cpp=.obj) # object file names 
LSOBJ := $(CMD) "(ls $(OBJ) -Recurse -Include *.obj | Resolve-Path -Relative) -join ' '"

DELOBJ=del $$PSItem.FullName -Recurse

.ONESHELL:
%.obj : %.cpp
	$(eval folder=$(subst $(SRC),$(OBJ),$(@D)))
	$(eval result=$(folder)/$(@F))
	@$(CMD) "if (-not (Test-Path $(folder))) { mkdir $(folder) > $(BUILD)/$(CLOG) }"
	@$(CC) $(CFLAGS) /Fo$(result) /c $<

compile : $(OFILES)
link :
	$(eval objects=$(shell $(LSOBJ)))
	@$(CMD) "if (-not (Test-Path $(BIN))) { mkdir $(BIN) > $(BUILD)/$(LLOG) }"
	$(LINK) $(objects) /nologo /OUT:$(BIN)/$(EXE) /SUBSYSTEM:$(SYSTEM)

build : compile link
clean :
	$(CMD) "del $(OBJ) -Recurse"
	$(CMD) "del $(BIN) -Recurse"

rebuild : clean build
