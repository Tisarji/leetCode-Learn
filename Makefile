# Variables
RED=\033[0;31m
GREEN=\033[0;32m
BOLD_GREEN=\033[1;32m
PINK=\033[0;95m
NORMAL=\033[0m

all: compile

compile:
	@if [ ! -f "$(file).c" ]; then \
		echo -e "${GREEN}Please provide a C source file path and name as an argument.${NORMAL}"; \
		echo -e "\t ${PINK}Usage -> make compile file=[path/to/file] ${NORMAL}"; \
		exit 1; \
	fi; \
	gcc -o "$(file)" "$(file).c"; \
	if [ $$? -ne 0 ]; then \
		echo -e "${RED}Error:${NORMAL} Compilation failed for '$(file).c'."; \
		exit 1; \
	fi; \
	echo; \
	echo -e "${BOLD_GREEN}** Compilation successful. **"; \
	echo "Executable created as '$(file)'."

clean:
	@rm -f $(file)

.PHONY: all compile clean
