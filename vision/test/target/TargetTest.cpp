/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_TargetTest_init = false;
#include "/home/noah/Documents/code/c++/TheBrain/vision/test/target/TargetTest.h"

static TargetTest suite_TargetTest;

static CxxTest::List Tests_TargetTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TargetTest( "test/target/TargetTest.h", 15, "TargetTest", suite_TargetTest, Tests_TargetTest );

static class TestDescription_suite_TargetTest_testLoadImage : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TargetTest_testLoadImage() : CxxTest::RealTestDescription( Tests_TargetTest, suiteDescription_TargetTest, 17, "testLoadImage" ) {}
 void runTest() { suite_TargetTest.testLoadImage(); }
} testDescription_suite_TargetTest_testLoadImage;

static class TestDescription_suite_TargetTest_testHsvImage : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TargetTest_testHsvImage() : CxxTest::RealTestDescription( Tests_TargetTest, suiteDescription_TargetTest, 26, "testHsvImage" ) {}
 void runTest() { suite_TargetTest.testHsvImage(); }
} testDescription_suite_TargetTest_testHsvImage;

static class TestDescription_suite_TargetTest_testGetRectangles : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TargetTest_testGetRectangles() : CxxTest::RealTestDescription( Tests_TargetTest, suiteDescription_TargetTest, 31, "testGetRectangles" ) {}
 void runTest() { suite_TargetTest.testGetRectangles(); }
} testDescription_suite_TargetTest_testGetRectangles;

static class TestDescription_suite_TargetTest_testGetResults : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TargetTest_testGetResults() : CxxTest::RealTestDescription( Tests_TargetTest, suiteDescription_TargetTest, 36, "testGetResults" ) {}
 void runTest() { suite_TargetTest.testGetResults(); }
} testDescription_suite_TargetTest_testGetResults;

static class TestDescription_suite_TargetTest_testDistanceValues : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TargetTest_testDistanceValues() : CxxTest::RealTestDescription( Tests_TargetTest, suiteDescription_TargetTest, 41, "testDistanceValues" ) {}
 void runTest() { suite_TargetTest.testDistanceValues(); }
} testDescription_suite_TargetTest_testDistanceValues;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
