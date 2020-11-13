FILES=endiantest.c
CC=gcc
OUT=EndianTest

$(OUT): $(FILES)
	$(CC) $^ -o $@

clean:
	rm $(OUT)
