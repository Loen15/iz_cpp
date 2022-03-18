#include <gtest/gtest.h>

extern "C" {
#include "../start/stakeholder.h"
}

TEST(start, correct) {
    std::string correct_str = "../tests/initData.txt";
    char *correct = new char[correct_str.length() + 1];
    strcpy(correct, correct_str.c_str());
    EXPECT_EQ(1, start(correct,7));
    delete [] correct;
}
TEST(start, incorrect) {
    std::string incorrect_str = "unitData.txt";
    char *incorrect = new char[incorrect_str.length() + 1];
    strcpy(incorrect, incorrect_str.c_str());
    EXPECT_EQ(0, start(incorrect,1));
    delete [] incorrect;
}

TEST (info_select,correct){
    std::string test_file = "../start/test.txt";
    char *correct = new char[test_file.length() + 1];
    strcpy(correct, test_file.c_str());
    char b='H';
    EXPECT_EQ(b,info_select(correct).influence_lvl);
}
TEST (info_select,incorrect){
    std::string task_file = "../start/task.txt";
    char *incor_task = new char[task_file.length() + 1];
    strcpy(incor_task, task_file.c_str());
    EXPECT_EQ(NULL,info_select(incor_task).role);
    std::string test_file = "../start/test_incor.txt";
    char *incorrect = new char[test_file.length() + 1];
    strcpy(incorrect, test_file.c_str());
    EXPECT_EQ(NULL,info_select(incorrect).role);
}
/*

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
*/
