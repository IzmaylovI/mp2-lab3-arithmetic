// тесты для вычисления арифметических выражений

#include "arithmetic.h"
#include <gtest.h>

TEST(lexeme, сan_create_lexeme_with_positive_value)
{
	ASSERT_NO_THROW(lexeme(10));
}

TEST(lexeme, can_create_lexeme_with_negative_value)
{
	ASSERT_NO_THROW(lexeme(-10));
}

TEST(lexeme, can_create_lexeme_with_operator)
{
	string a = "+";

	ASSERT_NO_THROW(lexeme(a));
}

TEST(lexeme, can_show_the_value)
{
	lexeme a(100);

	EXPECT_EQ(100, a.getValue());
}

TEST(lexeme, can_show_the_operator)
{
	string q = "/";
	lexeme a(q);

	EXPECT_EQ("/", a.getOp());
}


TEST(lexeme, can_assign_operator)
{
	string a = "-";
	lexeme q = a;

	EXPECT_EQ("-", q.getOp());
}

TEST(lexeme, can_assign_value)
{
	lexeme q = 34.55;

	EXPECT_EQ(34.55, q.getValue());
}

TEST(lexeme, can_assign_lexeme)
{
	lexeme q = 34.55;
	lexeme w = q;

	EXPECT_EQ(q, w);
}

TEST(arithmetic, throw_when_expression_isnt_correct)
{
	string a("5*+2");

	arithmetic r;
	ASSERT_ANY_THROW(r.tokenizing_and_polish_notation(a));
}

TEST(arithmetic, throw_when_expression_isnt_correct_1)
{
	string a("24-5*");

	arithmetic r;
	ASSERT_ANY_THROW(r.tokenizing_and_polish_notation(a));
}

TEST(arithmetic, throw_when_expression_isnt_correct_2)
{
	string a("24-5*");

	arithmetic r;
	ASSERT_ANY_THROW(r.tokenizing_and_polish_notation(a));
}

TEST(arithmetic, throw_when_expression_isnt_correct_3)
{
	string a("2)+(5");

	arithmetic r;
	ASSERT_ANY_THROW(r.tokenizing_and_polish_notation(a));
}

TEST(arithmetic, throw_when_expression_isnt_correct_4)
{
	string a("2.5.6");

	arithmetic r;
	ASSERT_ANY_THROW(r.tokenizing_and_polish_notation(a));
}

TEST(arithmetic, throw_when_expression_ismt_correct5)
{
	string a("5+-4(");

	arithmetic r;
	ASSERT_ANY_THROW(r.tokenizing_and_polish_notation(a));
}

TEST(arithmetic, true_when_the_expression_is_correct)
{
	string a("2.5/8*---10");

	arithmetic r;
	ASSERT_NO_THROW(r.tokenizing_and_polish_notation(a));
}

TEST(arithmetic, can_calculating_the_correct_expression)
{
	string a("2/5*-20+145");

	arithmetic r;
	EXPECT_EQ(137, r.tokenizing_and_polish_notation(a));
}

TEST(arithmetic, can_calculating_the_correct_expression_2)
{
	string a("1+-----9/3-0.2");

	arithmetic r;
	EXPECT_EQ(-2.2, r.tokenizing_and_polish_notation(a) );
}