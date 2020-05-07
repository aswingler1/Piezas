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

	ASSERT_TRUE(obj.pieceAt(0,0) == Blank);
	ASSERT_TRUE(obj.pieceAt(0,1) == Blank);
	ASSERT_TRUE(obj.pieceAt(0,2) == Blank);
	ASSERT_EQ(obj.pieceAt(0,3), Blank);


}

TEST(PiezasTest, dropPieceTest)
{

	Piezas obj;
	obj.reset();


	obj.dropPiece(0);
	obj.dropPiece(1);
	obj.dropPiece(2);
	obj.dropPiece(3);
	ASSERT_TRUE(obj.pieceAt(0,0) != Blank);
	ASSERT_TRUE(obj.pieceAt(0,1) != Blank);
	ASSERT_TRUE(obj.pieceAt(0,2) != Blank);
	ASSERT_TRUE(obj.pieceAt(0,3) != Blank);

	obj.dropPiece(0);
	obj.dropPiece(1);
	obj.dropPiece(2);
	obj.dropPiece(3);
	ASSERT_TRUE(obj.pieceAt(1,0) != Blank);
	ASSERT_TRUE(obj.pieceAt(1,1) != Blank);
	ASSERT_TRUE(obj.pieceAt(1,2) != Blank);
	ASSERT_TRUE(obj.pieceAt(1,3) != Blank);

	obj.dropPiece(0);
	obj.dropPiece(1);
	obj.dropPiece(2);
	obj.dropPiece(3);
	ASSERT_TRUE(obj.pieceAt(2,0) != Blank);
	ASSERT_TRUE(obj.pieceAt(2,1) != Blank);
	ASSERT_TRUE(obj.pieceAt(2,2) != Blank);
	ASSERT_TRUE(obj.pieceAt(2,3) != Blank);


	// out of bounds check
	ASSERT_TRUE(obj.pieceAt(5,0) == Invalid);
	ASSERT_TRUE(obj.pieceAt(0,5) == Invalid);
	ASSERT_TRUE(obj.pieceAt(5,5) == Invalid);

}
