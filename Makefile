CC = gcc
CFLAGS = -Wall -std=c99
ODIR = obj
LIBS = -lm

_OBJ = gaussian_elimination.o obtain_nullspace.o obtain_solution.o input_matrix.o divide_row.o swap_rows.o swap_cols.o subtract.o pivoting.o elimination.o print_matrix.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $^ $(CFLAGS)

compile_run: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)