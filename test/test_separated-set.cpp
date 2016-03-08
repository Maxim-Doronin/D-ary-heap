#include "gtest.h"
#include "separated-set.h"

TEST(SEPARATED_SET, can_create_set_with_actual_n)
{
	SeparatedSet *set;
	ASSERT_NO_THROW(set = new SeparatedSet(10));
}

TEST(SEPARATED_SET, throws_when_try_create_set_with_wrong_n)
{
	SeparatedSet *set;
	ASSERT_ANY_THROW(set = new SeparatedSet(-10));
}

TEST(SEPARATED_SET, can_create_singleton)
{
	SeparatedSet *set = new SeparatedSet(10);
	ASSERT_NO_THROW(set->singleton(5));
}

TEST(SEPARATED_SET, can_define_set)
{
	SeparatedSet *set = new SeparatedSet(10);
	set->singleton(5);
	ASSERT_NO_THROW(set->defineSet(5));
}

TEST(SEPARATED_SET, throws_when_try_define_with_negative_idx)
{
	SeparatedSet *set = new SeparatedSet(10);
	set->singleton(5);
	ASSERT_ANY_THROW(set->defineSet(-1));
}

TEST(SEPARATED_SET, throws_when_try_define_with_large_idx)
{
	SeparatedSet *set = new SeparatedSet(10);
	set->singleton(5);
	ASSERT_ANY_THROW(set->defineSet(15));
}

TEST(SEPARATED_SET, difining_is_correct)
{
	SeparatedSet *set = new SeparatedSet(10);
	set->singleton(0);
	set->singleton(4);
	set->association(4, 0);
	EXPECT_EQ(set->defineSet(0), 4);
}

TEST(SEPARATED_SET, difining_return_neg1_when_set_is_empty)
{
	SeparatedSet *set = new SeparatedSet(10);
	set->singleton(0);
	EXPECT_EQ(set->defineSet(5), -1);
}

TEST(SEPARATED_SET, singleton_has_equal_parent)
{
	SeparatedSet *set = new SeparatedSet(10);
	set->singleton(5);
	EXPECT_EQ(set->defineSet(5), 5);
}

TEST(SEPARATED_SET, throws_when_try_create_singleton_with_large_i)
{
	SeparatedSet *set = new SeparatedSet(10);
	ASSERT_ANY_THROW(set->singleton(11));
}

TEST(SEPARATED_SET, throws_when_try_create_singleton_with_neg_i)
{
	SeparatedSet *set = new SeparatedSet(10);
	ASSERT_ANY_THROW(set->singleton(-10));
}

TEST(SEPARATED_SET, can_associate_sets)
{
	SeparatedSet *set = new SeparatedSet(10);
	set->singleton(5);
	set->singleton(9);
	ASSERT_NO_THROW(set->association(5,9));
}

TEST(SEPARATED_SET, association_is_correct)
{
	SeparatedSet *set = new SeparatedSet(10);
	set->singleton(0);
	set->singleton(4);
	set->association(4, 0);
	set->singleton(7);
	set->singleton(9);
	set->association(7, 9);
	set->association(9, 0);
	set->singleton(2);
	set->singleton(5);
	set->singleton(1);
	set->association(1, 2);
	set->association(1, 5);
	
	set->association(7, 1);

	EXPECT_EQ(set->defineSet(1), 7);

}

TEST(SEPARATED_SET, throws_when_try_associate_large_idx)
{
	SeparatedSet *set = new SeparatedSet(10);
	set->singleton(0);
	set->singleton(4);
	ASSERT_ANY_THROW(set->association(0, 15));
}

TEST(SEPARATED_SET, throws_when_try_associate_negative_idx)
{
	SeparatedSet *set = new SeparatedSet(10);
	set->singleton(0);
	set->singleton(4);
	ASSERT_ANY_THROW(set->association(-5, 4));
}

TEST(SEPARATED_SET, throws_when_try_associate_empty_set)
{
	SeparatedSet *set = new SeparatedSet(10);
	set->singleton(0);
	set->singleton(4);
	ASSERT_ANY_THROW(set->association(0, 5));
}

TEST(SEPARATED_SET, getSetSize_is_correct)
{
	SeparatedSet *set = new SeparatedSet(10);
	set->singleton(0);
	set->singleton(4);
	set->association(4, 0);
	set->singleton(7);
	set->singleton(9);
	set->association(7, 9);
	set->association(9, 0);

	EXPECT_EQ(set->getSetSize(0), 4);
}