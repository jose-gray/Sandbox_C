#include <stdio.h>
#include <assert.h>
#include "tests.h"
#include "maths.h"

typedef struct
{
    int a;
    int b;
    int expected;
    const char *testName;
} TestCase;

void assertWithPrint(int expected, int actual, const char *testName, int *failureCount)
{
    if (expected != actual)
    {
        printf("%s - Expected: %d, Actual: %d\n", testName, expected, actual);
        (*failureCount)++;
    }
    else
    {
        printf("%s passed.\n", testName);
    }
}

void testSum(TestCase testCase, int *failureCount)
{
    int result = sum(testCase.a, testCase.b);
    assertWithPrint(testCase.expected, result, testCase.testName, failureCount);
}

void TestRunner()
{
    TestCase testCases[] = {
        {2, 3, 5, "testPositiveIntegers"},
        {-4, -6, -10, "testNegativeIntegers"},
        {0, 8, 8, "testZeroAndPositiveInteger"},
        {0, -7, -7, "testZeroAndNegativeInteger"},
        {0, 0, 0, "testZeroAndZero"}};

    const int numTests = sizeof(testCases) / sizeof(testCases[0]);
    int failureCount = 0;

    for (int i = 0; i < numTests; i++)
    {
        printf("Running test %d...\n", i + 1);
        testSum(testCases[i], &failureCount);
        printf("\n");
    }

    if (failureCount == 0)
    {
        printf("All tests passed.\n");
    }
    else
    {
        printf("%d test(s) failed.\n", failureCount);
    }
}