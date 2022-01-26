// тесты для стека

#include "stack.h"
#include <gtest.h>

TEST(Stack, can_create_stack_with_positive_length) 
{
	ASSERT_NO_THROW(Stack<int> st(10));
}

TEST(Stack, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> st(-5));
}

TEST(Stack, can_create_copied_stack)
{
	Stack<int> st(5);

	ASSERT_NO_THROW(Stack<int> reuslt(st));
}

TEST(Stack, copied_stack_is_equal_to_source_one)
{
	Stack<int> first(5);
	first.push(7);

	Stack<int> second(first);

	EXPECT_EQ(first, second);
}

TEST(Stack, can_get_size)
{
	Stack<int> St(10);
    
	EXPECT_EQ(10, St.getSize());
}

TEST(Stack, can_get_count_of_elements)
{
	Stack<int> St(10);
	St.push(9);
	ASSERT_NO_THROW(St.count());
}

TEST(Stack, get_count_of_elements)
{
	Stack<int> St(10);
	St.push(9);
	St.push(10);
	EXPECT_EQ(2, St.count());
}

TEST(Stack, can_check_stack_for_emptiness)
{
	Stack<int> St(0);

	EXPECT_EQ(1, St.isEmpty());
}

TEST(Stack, can_push_element_in_stack)
{
	Stack<int> St(3);

	ASSERT_NO_THROW(St.push(9));
}

TEST(Stack, can_increase_memory_when_adding_an_item_to_the_full_stack)
{
	Stack<int> St(6);
	St.push(7);
	St.push(11);
	St.push(34);
	St.push(56);
	St.push(45);
	St.push(56);

	ASSERT_NO_THROW(St.push(7));
}

TEST(Stack, can_check_stack_for_completeness)
{
	Stack<int> St(3);
	St.push(1);
	St.push(2);
	St.push(3);

	EXPECT_EQ(1, St.isFull());
}

TEST(Stack, can_show_the_top_element_without_removing)
{
	Stack<int> St(4);
	St.push(1);
	St.push(2);
	St.push(3);
	St.push(4);

	EXPECT_EQ(4, St.peek());
	EXPECT_EQ(4, St.count());
}

TEST(Stack, can_remove_the_top_element_and_show_it)
{
	Stack<int> St(7);
	St.push(100);
	St.push(24);


	EXPECT_EQ(24, St.pop());
	EXPECT_EQ(1, St.count());
}

TEST(Stack, can_assign_stacks_to_each_other)
{
	Stack<int> St(9); 
	St.push(1);
	St.push(2);
	St.push(3);
	St.push(4);

	Stack<int> second = St;

	EXPECT_EQ(St, second);
	EXPECT_EQ(St.peek(), second.peek());
	EXPECT_EQ(St.getSize(), second.getSize());
}