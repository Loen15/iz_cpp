#include <gtest/gtest.h>

extern "C" {
#include "../start/stakeholder.h"
}

TEST(Fib, TestBasics) {
EXPECT_EQ(1, fib(1));
EXPECT_EQ(1, fib(2));
}

TEST(Fib, Test10) {
EXPECT_EQ(55, fib(10));
}

//initialization
int start(char* name, size_t count);
stakeholder* read_data(char* name, stakeholder * stakeholders, size_t count);
char* read_string(FILE* file);
stakeholder read_stakeholder(FILE *file);
//client_part
void print_stakeholders(stakeholder * stakeholders, size_t count);
void print_stakeholder(stakeholder curr_stake);
stakeholder info_select();
char* info_read(char* buf);
int find_stakeholders(stakeholder * Stakeholders, stakeholder criter, size_t count);
