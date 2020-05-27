/*******************************************************************************
* File name： Enums.h
* Description: HuobiSwap api client header files.
* Author: QiaoXiaofeng(andyjoe318@gmail.com)
* Version: 0.0.1
* Date： 2020-05-26
* History: 
*
*******************************************************************************/

#ifndef ENUMDEFINE_H
#define ENUMDEFINE_H

#include "stdio.h"
#include <string>
#include <map>
#include <math.h>

namespace HuobiSwap {

    template<class T>
    /**
     * All enums about HuobiSwap pack
     * 
     */
    class BaseEnumClass {
    public:

        BaseEnumClass() : m_value() {
        }

        const std::string &getValue() const {
            return m_value;
        }

        static T lookup(const std::string &value) {
            auto it = m_lookupMap.find(value);
            if (it != m_lookupMap.end()) {
                return *((T *) (it->second));
            }
            //  throw "error";
            auto notFound = m_lookupMap.rbegin();
            return *((T *) (notFound->second));
        }

        bool operator==(const BaseEnumClass &obj) const {
            return m_value == obj.m_value;
        }

        bool isNull() const {
            return m_value.empty();
        }
    protected:

        BaseEnumClass(const std::string &value) : m_value(value) {
        }

        std::string m_value;
    public:
        static std::map<std::string, void *> m_lookupMap;
    };

    template<class T>
    std::map<std::string, void *> BaseEnumClass<T>::m_lookupMap = {};


#define DEFINE_ENUM_CLASS(class_name) \
private: \
    class_name(const std::string& value) : BaseEnumClass(value) { m_lookupMap[value] = this; } \
public: \
    class_name() {} \
    class_name(const class_name& value) : BaseEnumClass(value.m_value) {} \
    bool operator == (const class_name& value) const { return this->m_value == value.m_value; } \
    bool operator != (const class_name& value) const { return !(*this == value); } \
    class_name& operator =(const class_name& value) { this->m_value = value.m_value; return *this; } \
private:

    /**
     * 1min, 5min, 15min, 30min, 60min, 1day, 1mon, 1week, 1year
     */
    class CandlestickInterval : public BaseEnumClass<CandlestickInterval> {
        DEFINE_ENUM_CLASS(CandlestickInterval);
    public:
        static CandlestickInterval min1;
        static CandlestickInterval min5;
        static CandlestickInterval min15;
        static CandlestickInterval min30;
        static CandlestickInterval min60;
        static CandlestickInterval hour4;
        static CandlestickInterval day1;
        static CandlestickInterval mon1;
        static CandlestickInterval week1;
        static CandlestickInterval year1;
        static CandlestickInterval SDK_NOTSUPPORT;
    };

    /**
     * buy, sell, both.
     */
    class OrderSide : public BaseEnumClass<OrderSide> {
        DEFINE_ENUM_CLASS(OrderSide);
    public:
        static OrderSide buy;
        static OrderSide sell;
        static OrderSide SDK_NOTSUPPORT;
    };

    /**
     * SPOT, MARGIN, OTC, POINT, UNKNOWN.
     */
    class AccountType : public BaseEnumClass<AccountType> {
        DEFINE_ENUM_CLASS(AccountType);
    public:
        static AccountType spot;
        static AccountType margin;
        static AccountType otc;
        static AccountType point;
        static AccountType minepool;
        static AccountType etf;
        static AccountType agency;
        static AccountType super_margin;
        static AccountType future;
        static AccountType swap;
        static AccountType SDK_NOTSUPPORT;
    };

    /**
     * limit, opponent, post_only, 
     */
    class OrderPriceType : public BaseEnumClass<OrderPriceType> {
        DEFINE_ENUM_CLASS(OrderPriceType);
    public:
        static OrderPriceType limit;
        static OrderPriceType opponent;
        static OrderPriceType post_only;
        static OrderPriceType SDK_NOTSUPPORT;
    };


    /**
     * sys, web, api, app.
     */
    class OrderSource : public BaseEnumClass<OrderSource> {
        DEFINE_ENUM_CLASS(OrderSource);
    public:
        static OrderSource sys;
        static OrderSource web;
        static OrderSource api;
        static OrderSource app;
        static OrderSource risk;
        static OrderSource SDK_NOTSUPPORT;
    };

    /**
     *  1. Requested orders; 2. Cancelled orders; 3. Liquidated orders; 4. Delivered orders  
     */
    class OrderType : public BaseEnumClass<OrderType> {
        DEFINE_ENUM_CLASS(OrderType);
    public:
        static OrderType requested;
        static OrderType canceled;
        static OrderType liquidated;
        static OrderType delivered;
        static OrderType SDK_NOTSUPPORT;
    };

    /**
     * Liquidation type: 0: Non-liquidated,1: Long and short netting,2: Partial liquidated,3: Full liquidated
     */
    class LiquidationType: public BaseEnumClass<LiquidationType> {
        DEFINE_ENUM_CLASS(LiquidationType);
    public:
        static LiquidationType non_liquidated;
        static LiquidationType long_short_netting;
        static LiquidationType partial_liquidated;
        static LiquidationType full_liquidated;
    };

    /**
     * SUBMITTED, PARTIALFILLED, CANCELLING. PARTIALCANCELED FILLED CANCELED
     */
    class OrderStatus : public BaseEnumClass<OrderStatus> {
        DEFINE_ENUM_CLASS(OrderStatus);
    public:
        static OrderStatus submitting;
        static OrderStatus seq_submitted;
        static OrderStatus submitted;
        static OrderStatus partial_filled;
        static OrderStatus cancelling;
        static OrderStatus partial_canceled;
        static OrderStatus filled;
        static OrderStatus canceled;
        static OrderStatus failed;
        static OrderStatus SDK_NOTSUPPORT;
    };

    /**
     * Tradeoffset: open, close
     */
    class TradeOffset : public BaseEnumClass<TradeOffset> {
        DEFINE_ENUM_CLASS(TradeOffset);
    public:
        static TradeOffset open;
        static TradeOffset close;
        static TradeOffset SDK_NOTSUPPORT;
    };

    class DealRole : public BaseEnumClass<DealRole> {
        DEFINE_ENUM_CLASS(DealRole);
    public:
        static DealRole taker;
        static DealRole maker;
        static DealRole SDK_NOTSUPPORT;
    };

    class DepthStep : public BaseEnumClass<DepthStep> {
        DEFINE_ENUM_CLASS(DepthStep);
    public:
        static DepthStep step0;
        static DepthStep step1;
        static DepthStep step2;
        static DepthStep step3;
        static DepthStep step4;
        static DepthStep step5;
        static DepthStep step6;
        static DepthStep step7;
        static DepthStep step8;
        static DepthStep step9;
        static DepthStep step10;
        static DepthStep step11;
        static DepthStep SDK_NOTSUPPORT;
    };

    class MBPLevel : public BaseEnumClass<MBPLevel> {
        DEFINE_ENUM_CLASS(MBPLevel);
    public:
        static MBPLevel LEVEL20;
        static MBPLevel LEVEL150;
        static MBPLevel SDK_NOTSUPPORT;
    };

}
#endif /* ENUMDEFINE_H */

