


#include <gmock/gmock.h>
#include <unity.h>
#include <stdio.h>

#include <ALGpio.h>

using ::testing::Return;
using ::testing::_;
using ::testing::Mock;


    class MockGpioPinSource: public ALGpioPinSource
    {
        public:
            MOCK_METHOD(void,     begin,         (),                     (override) );
            MOCK_METHOD(void,     setupInputPin, (int pin, bool pullUp), (override) );
            MOCK_METHOD(void,     setupOutputPin,(int pin),              (override) );
            MOCK_METHOD(void,     writeGPIO,     (uint32_t val),         (override) );
            MOCK_METHOD(uint32_t, readGPIO,      (),                     (override) );
    };

    MockGpioPinSource mockPinSource;
    ALGpio gpio = ALGpio(&mockPinSource);

    void setUp(void)
    {

    }

    void tearDown(void)
    {
        TEST_ASSERT_TRUE(!::testing::Test::HasFailure());
    }

    void testGpioEnums(void)
    {
//        TEST_ASSERT_EQUAL(12, LED_COUNT);
//        TEST_ASSERT_EQUAL(16, BUTTON_COUNT);

        /* Ensure all values in ALL_BUTTONS are unique */


        /* Ensure all values in ALL_LEDS are unique */

    }

    void testGpioBegin(void)
//    TEST(Gpio, Begin)
    {
        /* Given */
        TEST_MESSAGE("A");
    
        TEST_MESSAGE("B");
        EXPECT_CALL(mockPinSource, setupInputPin(_, _)).Times(201);
        EXPECT_CALL(mockPinSource, begin()).Times(0);
        // EXPECT_CALL(mockPinSource, setupOutputPin(_)).Times(12);
        // EXPECT_CALL(mockPinSource, writeGPIO(_)).Times(1);
        // EXPECT_CALL(mockPinSource, readGPIO()).Times(1);

        /* When */
        TEST_MESSAGE("c");
        gpio.begin();

        /* Then */
        TEST_MESSAGE("D");
        int a = Mock::VerifyAndClearExpectations(&mockPinSource);
        int b = Mock::VerifyAndClear(&mockPinSource);
        int c = ::testing::Test::HasFailure();
        char msg[64];
        sprintf(msg, "[%d][%d][%d]", a, b, c);
        TEST_MESSAGE(msg);
        //TEST_ASSERT_EQUAL(1, 2);



        TEST_MESSAGE("E");
        

    }

    // void testGpioProcess()
    // {
    //     /* Given */
    //     When(Method(mockPinSource, writeGPIO)).AlwaysReturn();
    //     When(Method(mockPinSource, readGPIO)).AlwaysReturn();

    //     /* When */
    //     gpio.process();

    //     /* Then write and read */
    //     Verify(Method(mockPinSource, writeGPIO) + Method(mockPinSource, readGPIO)).Once();

    // }

    // /*
    //  * Leds are set ON by turning off the bit, and OFF by turning on the bit.
    //  */
    // void testGpioSetLed(void)
    // {
    //     /* Given */
    //     static uint32_t outVal;
    //     When(Method(mockPinSource, writeGPIO)).AlwaysDo([](uint32_t val){ outVal = val; });
    //     When(Method(mockPinSource, readGPIO)).AlwaysReturn();
    //     gpio.process();
    //     uint32_t startingOutVal = outVal;
        

    //     /* When */
    //     gpio.setLed(LED_B1, false);
    //     gpio.process();

    //     /* Then */
    //     Verify(Method(mockPinSource, writeGPIO)).Exactly(2);
    //     Verify(Method(mockPinSource, readGPIO)).Exactly(2);
    //     TEST_ASSERT_NOT_EQUAL(startingOutVal, outVal);

    //     /* Also When */
    //     gpio.setLed(LED_B1, true);
    //     gpio.process();

    //     /* Also Then */
    //     Verify(Method(mockPinSource, writeGPIO)).Exactly(3);
    //     Verify(Method(mockPinSource, readGPIO)).Exactly(3);
    //     TEST_ASSERT_EQUAL(startingOutVal, outVal);

    // }

    // /*
    //  * Joysticks are pulled LOW when trigered, HIGH when released.
    //  */
    // void testGpioJoystick()
    // {
    //     /* Given */
    //     When(Method(mockPinSource, writeGPIO)).AlwaysReturn();
    //     When(Method(mockPinSource, readGPIO)).AlwaysReturn(0xFFFFFFFF);
        
    //     /* When */
    //     gpio.process();
    //     bool up = gpio.getJoystick(JOYSTICK_UP);
    //     bool down = gpio.getJoystick(JOYSTICK_DOWN);
    //     bool left = gpio.getJoystick(JOYSTICK_LEFT);
    //     bool right = gpio.getJoystick(JOYSTICK_RIGHT);

    //     /* Then */
    //     Verify(Method(mockPinSource, writeGPIO)).Once();
    //     Verify(Method(mockPinSource, readGPIO)).Once();
    //     TEST_ASSERT_EQUAL(false, up);
    //     TEST_ASSERT_EQUAL(false, down);
    //     TEST_ASSERT_EQUAL(false, left);
    //     TEST_ASSERT_EQUAL(false, right);

    //     /* Also Given */
    //     When(Method(mockPinSource, readGPIO)).AlwaysReturn(0);

    //     /* Also When */
    //     gpio.process();
    //     up = gpio.getJoystick(JOYSTICK_UP);
    //     down = gpio.getJoystick(JOYSTICK_DOWN);
    //     left = gpio.getJoystick(JOYSTICK_LEFT);
    //     right = gpio.getJoystick(JOYSTICK_RIGHT);

    //     /* Also Then */
    //     Verify(Method(mockPinSource, writeGPIO)).Twice();
    //     Verify(Method(mockPinSource, readGPIO)).Twice();
    //     TEST_ASSERT_EQUAL(true, up);
    //     TEST_ASSERT_EQUAL(true, down);
    //     TEST_ASSERT_EQUAL(true, left);
    //     TEST_ASSERT_EQUAL(true, right);
    // }


    // /*
    //  * Buttons are pulled HIGH when trigered, LOW when released.
    //  */
    // void testGpioButtons()
    // {
    //     /* Given */
    //     When(Method(mockPinSource, writeGPIO)).AlwaysReturn();
    //     When(Method(mockPinSource, readGPIO)).AlwaysReturn(0xFFFFFFFF);
        
    //     /* When */
    //     gpio.process();
    //     bool b1 = gpio.getButton(BUTTON_B1);
        
    //     /* Then */
    //     Verify(Method(mockPinSource, writeGPIO)).Once();
    //     Verify(Method(mockPinSource, readGPIO)).Once();
    //     TEST_ASSERT_EQUAL(true, b1);

    //     /* Also Given */
    //     When(Method(mockPinSource, readGPIO)).AlwaysReturn(0);

    //     /* Also When */
    //     gpio.process();
    //     b1 = gpio.getButton(BUTTON_B1);

    //     /* Also Then */
    //     Verify(Method(mockPinSource, writeGPIO)).Twice();
    //     Verify(Method(mockPinSource, readGPIO)).Twice();
    //     TEST_ASSERT_EQUAL(false, b1);
        
    // }




void runTests()
{
    // RUN_TEST(testGpioEnums);
    RUN_TEST(testGpioBegin);
    // RUN_TEST(testGpioProcess);
    // RUN_TEST(testGpioSetLed);
    // RUN_TEST(testGpioJoystick);
    // RUN_TEST(testGpioButtons);
}
