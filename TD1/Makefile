# Compilateur
C++ = g++
C++FLAGS = -std=c++11 -Wall

# Dossier source
SRC_DIR = sources

# Fichiers sources
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Nom de l'exécutable
BIN = td1_winness

.PHONY: all clean

all:
	$(C++) $(C++FLAGS) -o $(BIN) $(SRCS)
clean:
	rm -f $(BIN)