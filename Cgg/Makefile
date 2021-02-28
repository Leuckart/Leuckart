
GO_FILES	=	adapter.go cpp.go debug.go dict.go gen.go	\
				header.go lex.go list.go main.go			\
				parse.go string.go							\
				util.go

TEST_BINS := $(patsubst %.cgg, %.bin, $(wildcard test/*.cgg))
CFLAGS=-Wall -std=gnu99 -g -I. -no-pie

cgg: $(GO_FILES)
	@GOOS=linux  GOARCH=amd64 go build -o cgg $(GO_FILES)
	@#@echo $(notdir $(TEST_BINS))
	@echo "Building..."

clean:
	@rm -rf cgg
	@rm -rf test/*.bin test/*.s test/*.o
	@echo "Cleaning..."

fmt:
	@go fmt *.go
	@echo "Formating..."

test: $(TEST_BINS) test.sh cgg
	@echo
	@for test in $(TEST_BINS); do \
		./$$test;                 \
	done
	./test.sh

test/%.bin: test/%.s test/util/util.o cgg
	@#echo "---------------------------------------------------"
	@#echo $@ $<
	@$(CC) $(CFLAGS) -o $@ $< test/util/util.o

test/%.s: test/%.cgg cgg
	@#echo "***************************************************"
	@#echo $< $@
	./cgg < $< > $@

.PHONEY: test
