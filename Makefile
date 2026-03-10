# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LDFLAGS = 

# Директории
SRCDIR = src
BUILDDIR = build
TARGET = program

# Исходные файлы
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES))

# Цели
.PHONY: all clean run

all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	@echo "Сборка завершена: $(TARGET)"

# Компиляция .c в .o
$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Скомпилирован: $<"

# Создание директории build
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Запуск программы
run: $(TARGET)
	./$(TARGET)

# Очистка
clean:
	rm -rf $(BUILDDIR) $(TARGET)
	@echo " Проект очищен"

# Информация
info:
	@echo "Компилятор: $(CC)"
	@echo "Флаги: $(CFLAGS)"
	@echo "Исходники: $(SOURCES)"
	@echo "Объекты: $(OBJECTS)"

# Зависимости
$(BUILDDIR)/main.o: $(SRCDIR)/task1.h $(SRCDIR)/task2.h $(SRCDIR)/task3.h
$(BUILDDIR)/task1.o: $(SRCDIR)/task1.h
$(BUILDDIR)/task2.o: $(SRCDIR)/task2.h
$(BUILDDIR)/task3.o: $(SRCDIR)/task3.h
