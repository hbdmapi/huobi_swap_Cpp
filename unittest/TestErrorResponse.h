#ifndef TESTERRORRESPONSE_H
#define TESTERRORRESPONSE_H

#include <gtest/gtest.h>
#include <../src/RestApiImpl.h>
#include <../src/RestApiInvoke.h>
#include "../src/Utils/JsonDocument.h"
#include "../include/HuobiSwap/Error.h"

using namespace HuobiSwap;

TEST(TestErrorResponse, Error) {
    std::string errorData = "{\n"
            "  \"ts\": 1550209202720,\n"
            "  \"status\": \"error\",\n"
            "  \"err-code\": \"invalid-parameter\",\n"
            "  \"err-msg\": \"invalid symbol\"\n"
            "}";
    JsonWrapper json = JsonDocument().parseFromString(errorData);
    EXPECT_THROW(RestApiInvoke::checkResponse(json), Error);
}

TEST(TestErrorResponse, unexpectedResponse) {
    std::string errorData_unexpected = "{\n"
            "  \"ts\": 1550209202720,\n"
            "  \"status\": \"abc\",\n"
            "  \"err-code\": \"invalid-parameter\",\n"
            "  \"err-msg\": \"invalid symbol\"\n"
            "}";
    JsonWrapper json = JsonDocument().parseFromString(errorData_unexpected);
    EXPECT_THROW(RestApiInvoke::checkResponse(json), Error);
}

TEST(TestErrorResponse, noStatusResponse) {
  std::string errorData_noStatus = "{\n"
      "  \"ts\": 1550209202720,\n"
      "  \"err-code\": \"invalid-parameter\",\n"
      "  \"err-msg\": \"invalid symbol\"\n"
      "}";
    JsonWrapper json = JsonDocument().parseFromString(errorData_noStatus);
    EXPECT_THROW(RestApiInvoke::checkResponse(json), Error);
}

#endif /* TESTERRORRESPONSE_H */

