#ifndef _TESTS_H_
#define _TESTS_H_

#include "PageTurnTest/PageTurnScene.h"
#include "ActionsTest/ActionsTest.h"
#include "MotionStreakTest/MotionStreak.h"

enum
{
    TEST_PAGETURN = 0,
	TEST_ACTIONS,
	TEST_MOTIONSTREAK,
	TEST_ACTIONS2,
	TEST_ACTIONS3,
	TEST_ACTIONS4,
	TEST_ACTIONS5,
	TEST_ACTIONS6,
	TEST_ACTIONS7,
	TEST_ACTIONS8,
	TEST_ACTIONS9,
	TESTS_COUNT
};

const std::string g_aTestNames[TESTS_COUNT] = {
	"PageturnTest",
	"ActionsTest",
	"MotionStreakTest",
	"TestNull",
	"TestNull",
	"TestNull",
	"TestNull",
	"TestNull",
	"TestNull",
	"TestNull",
	"TestNull"
	 
};

#endif
