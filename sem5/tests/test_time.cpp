#include "Time.hpp"
#include <gtest/gtest.h>

TEST(TimeTest, DefaultConstructor) {
    Time t;
    EXPECT_EQ(t.GetHours(), 0);
    EXPECT_EQ(t.GetMinutes(), 0);
    EXPECT_EQ(t.GetSeconds(), 0);
}

TEST(TimeTest, ParameterizedConstructor) {
    Time t(1, 61, 61); 
    EXPECT_EQ(t.GetHours(), 2);
    EXPECT_EQ(t.GetMinutes(), 2);
    EXPECT_EQ(t.GetSeconds(), 0);
}


TEST(TimeTest, CopyConstructor) {
    Time t1(1, 1, 1);
    Time t2 = t1;
    
    EXPECT_EQ(t2.GetHours(), t1.GetHours());
    EXPECT_EQ(t2.GetMinutes(), t1.GetMinutes());
    EXPECT_EQ(t2.GetSeconds(), t1.GetSeconds());
}


TEST(TimeTest, AssignmentOperator) {
    Time t1(2, 30, 45);
    Time t2;
    t2 = t1;

    EXPECT_EQ(t2.GetHours(), 2);
    EXPECT_EQ(t2.GetMinutes(), 30);
    EXPECT_EQ(t2.GetSeconds(), 45);
}

TEST(TimeTest, AddOperator) {
    Time t1(2, 30, 45);
    t1 += 15;
    EXPECT_EQ(t1.GetHours(), 2);
    EXPECT_EQ(t1.GetMinutes(), 31);
    EXPECT_EQ(t1.GetSeconds(), 0);
}

TEST(TimeTest, RemoveOperator) {
    Time t1(2, 30, 45);
    t1 -= 15;
    EXPECT_EQ(t1.GetHours(), 2);
    EXPECT_EQ(t1.GetMinutes(), 30);
    EXPECT_EQ(t1.GetSeconds(), 30);
}


TEST(TimeTest, NormalizeFunction) {
    Time t(1, 61, 61); 
    EXPECT_EQ(t.GetHours(), 2);
    EXPECT_EQ(t.GetMinutes(), 2);
    EXPECT_EQ(t.GetSeconds(), 0);
}

TEST(TimeTest, ToSec) {
    Time t(0, 2, 5); 
    EXPECT_EQ(t.ToSeconds(), 125);
}


TEST(TimeTest, FailingTest) {
    Time t(1, 2, 3);
    EXPECT_EQ(t.GetHours(), 1);
    EXPECT_EQ(t.GetMinutes(), 3);
}

