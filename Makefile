SRC_DIR = src
INC_DIR = inc

CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++20

BUILD_DIR = build

TARGET = LLM

SRCS = $(wildcard $(SRC_DIR)/*.cpp)

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

INCS = -I$(INC_DIR)

# 빌드 규칙
all: clean $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCS) -c $< -o $@

# 클린 규칙
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# 디펜던시 규칙
.PHONY: all clean
