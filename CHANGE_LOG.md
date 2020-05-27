# Huobi Swap C++ Demo Change Log

This is Huobi Swap C++ Demo, This is a lightweight c++ library, you can import to your c++ project and use this Demo to query all market data, trading and manage your account.

The Demo supports both synchronous RESTful API invoking, and subscribe the market data from the Websocket connection.

## Table of Contents

- [Huobi Swap API C++ Demo version 1.0.0](#Huobi-Swap-API-Cpp-Demo-version-1.0.0)

## Huobi Swap API Cpp Demo version 1.0.0

***2020-05-27***

- First Version

- Add new API

  ```
  Query Swap Info  GET /swap-api/v1/swap_contract_info

  Query Account Info POST /swap-api/v1/swap_account_info

  Public websocket subscription of the candlestick data(market.$contract_code.kline.$period)
  
  Private websocket subscription of the order event(orders.$contract_code).
  
  ```