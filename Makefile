ifndef VERBOSE
.SILENT:
endif

LLVM_VERSION := 12

all: clean build

out/bin/logger_test: ;@echo Building llvm-pass...
	cmake -S . -B out/build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
		-DCMAKE_CXX_COMPILER=clang++-$(LLVM_VERSION)
	cmake --build out/build
	echo Done!
	echo

.PHONY: build
build: clean out/bin/logger_test

.PHONY: format
format: ;
	find . -type f \( -name "*.h" -o -name "*.cpp" -o -name "*.c" -o -name "*.hpp" -o -name "*.proto" \) \
		-exec clang-format-$(LLVM_VERSION) -i {} +

.PHONY: clean
clean: ;@echo Cleaning...
	if [ -d out ]; then \
		rm -rf out; \
	fi
	rm -f *.log
	echo Done!
	echo
