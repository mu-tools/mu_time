# -------------------------------------------------------------------
# Platform Support
# -------------------------------------------------------------------
PLATFORM ?= posix
SUPPORTED_PLATFORMS = posix esp32
ifeq ($(filter $(PLATFORM),$(SUPPORTED_PLATFORMS)),)
$(error Unsupported PLATFORM: $(PLATFORM). Supported: $(SUPPORTED_PLATFORMS))
endif

# -------------------------------------------------------------------
# Directories
# -------------------------------------------------------------------
BUILD_DIR := build
OBJ_DIR   := $(BUILD_DIR)/obj
BIN_DIR   := $(BUILD_DIR)/bin

# -------------------------------------------------------------------
# Toolchain and flags
# -------------------------------------------------------------------
CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -O0 -g --coverage \
		   -I.. \
		   -I../src \
		   -I../src/platform
LDFLAGS := --coverage

# -------------------------------------------------------------------
# Sources
# -------------------------------------------------------------------
PLAT_SRC := ../src/platform/mu_time_$(PLATFORM).c
TEST_SRC := unity.c test_mu_time_$(PLATFORM).c
ALL_SRC  := $(PLAT_SRC) $(TEST_SRC)

OBJ := $(patsubst ../src/platform/%.c,$(OBJ_DIR)/%.o,$(PLAT_SRC)) \
	   $(patsubst %.c,$(OBJ_DIR)/%.o,$(TEST_SRC))

TEST_EXE := $(BIN_DIR)/test_mu_time_$(PLATFORM)

# -------------------------------------------------------------------
# Phony targets
# -------------------------------------------------------------------
.PHONY: all test coverage clean

all: test

# -------------------------------------------------------------------
# Build & run
# -------------------------------------------------------------------
test: | clean $(TEST_EXE)
	@echo ">>> Running unit tests for $(PLATFORM)…"
	@./$(TEST_EXE)

# link the test runner into bin/, ensure bin dir exists first
$(TEST_EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ -o $@

# compile platform sources → build/obj/mu_time_$(PLATFORM).o
$(OBJ_DIR)/%.o: ../src/platform/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# compile test sources → build/obj/*.o
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ensure the obj/ dir exists
$(OBJ_DIR):
	mkdir -p $@

# ensure the bin/ dir exists
$(BIN_DIR):
	mkdir -p $@

# -------------------------------------------------------------------
# Coverage report
# -------------------------------------------------------------------
coverage: test
	@echo ">>> Capturing LCOV data..."
	@lcov --capture --directory $(BUILD_DIR) --directory ../src --output-file coverage.info
	@echo ">>> Generating HTML report..."
	@genhtml coverage.info --output-directory coverage_html
	@echo "open coverage_html/index.html"

# -------------------------------------------------------------------
# Clean
# -------------------------------------------------------------------
clean:
	@echo ">>> Removing build artifacts and coverage data"
	@rm -rf $(BUILD_DIR) coverage.info coverage_html
