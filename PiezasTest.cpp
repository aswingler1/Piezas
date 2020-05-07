/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}


// TEST(PiezasTest, reset_test)
// {
// 	Piezas obj;
// 	obj.reset();

// 	ASSERT_TRUE(board[1][1] == Blank);
// }


TEST(PiezasTest, pieceAtTest)
{
	Piezas obj;
	obj.reset();
	obj.dropPiece(1);
	ASSERT_TRUE(obj.pieceAt(0,1) != Blank);
}