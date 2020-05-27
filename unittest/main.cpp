/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <gtest/gtest.h>

#include "TestGetAccount.h"
#include "TestErrorResponse.h"
#include "TestDecimal.h"
#include "TestSubscribeOrderUpdateEvent.h"
int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
