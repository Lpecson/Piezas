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

TEST(PiezasTest, dropPiece1)
{
	Piezas obj;
	Piece p = obj.dropPiece(1);
	bool ret;
	if ( p == X )
	{
		ret = true;
	}
	ASSERT_TRUE(ret);
}

TEST(PiezasTest, dropPiece2)
{
	Piezas obj;
	Piece p = obj.dropPiece(1);
	p = obj.dropPiece(1);
	bool ret;
	if ( p == O )
	{
		ret = true;
	}
	ASSERT_TRUE(ret);
}

TEST(PiezasTest, GameStateXWin)
{
	Piezas obj;
	p = obj.dropPiece(1);
	p = obj.dropPiece(2);
	p = obj.dropPiece(1);
	p = obj.dropPiece(2);
	p = obj.dropPiece(1);
	p = obj.gameState();
	if ( p == X )
	{
		ret = true;
	}
	ASSERT_TRUE(ret);
}