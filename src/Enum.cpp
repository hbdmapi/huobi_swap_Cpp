#include "HuobiSwap/Enums.h"

namespace HuobiSwap {

    CandlestickInterval CandlestickInterval::min1 = CandlestickInterval("1min");
    CandlestickInterval CandlestickInterval::min5 = CandlestickInterval("5min");
    CandlestickInterval CandlestickInterval::min15 = CandlestickInterval("15min");
    CandlestickInterval CandlestickInterval::min30 = CandlestickInterval("30min");
    CandlestickInterval CandlestickInterval::min60 = CandlestickInterval("60min");
    CandlestickInterval CandlestickInterval::hour4 = CandlestickInterval("4hour");
    CandlestickInterval CandlestickInterval::week1 = CandlestickInterval("1week");
    CandlestickInterval CandlestickInterval::day1 = CandlestickInterval("1day");
    CandlestickInterval CandlestickInterval::mon1 = CandlestickInterval("1mon");
    CandlestickInterval CandlestickInterval::SDK_NOTSUPPORT = CandlestickInterval("sdk_not_support_for_now");

    OrderSide OrderSide::buy = OrderSide("buy");
    OrderSide OrderSide::sell = OrderSide("sell");
    OrderSide OrderSide::SDK_NOTSUPPORT = OrderSide("sdk_not_support_for_now");

    TradeOffset TradeOffset::open = TradeOffset("open");
    TradeOffset TradeOffset::close = TradeOffset("close");
    TradeOffset TradeOffset::SDK_NOTSUPPORT = TradeOffset("sdk_not_support_for_now");

    OrderType OrderType::requested = OrderType("1");
    OrderType OrderType::canceled = OrderType("2");
    OrderType OrderType::liquidated = OrderType("3");
    OrderType OrderType::delivered = OrderType("4");
    OrderType OrderType::SDK_NOTSUPPORT = OrderType("sdk_not_support_for_now");


    OrderSource OrderSource::sys = OrderSource("sys");
    OrderSource OrderSource::web = OrderSource("web");
    OrderSource OrderSource::api = OrderSource("api");
    OrderSource OrderSource::app = OrderSource("app");
    OrderSource OrderSource::SDK_NOTSUPPORT = OrderSource("sdk_not_support_for_now");


    OrderStatus OrderStatus::submitting = OrderStatus("1");
    OrderStatus OrderStatus::seq_submitted = OrderStatus("2");
    OrderStatus OrderStatus::submitted = OrderStatus("3");
    OrderStatus OrderStatus::partial_filled = OrderStatus("4");
    OrderStatus OrderStatus::partial_canceled = OrderStatus("5");
    OrderStatus OrderStatus::filled = OrderStatus("6");
    OrderStatus OrderStatus::canceled = OrderStatus("7");
    OrderStatus OrderStatus::failed = OrderStatus("10");
    OrderStatus OrderStatus::cancelling = OrderStatus("11");
    OrderStatus OrderStatus::SDK_NOTSUPPORT = OrderStatus("sdk_not_support_for_now");

    OrderPriceType OrderPriceType::limit = OrderPriceType("limit");
    OrderPriceType OrderPriceType::opponent = OrderPriceType("opponent");
    OrderPriceType OrderPriceType::post_only = OrderPriceType("post_only");
    OrderPriceType OrderPriceType::SDK_NOTSUPPORT = OrderPriceType("sdk_not_support_for_now");

    DealRole DealRole::taker = DealRole("taker");
    DealRole DealRole::maker = DealRole("maker");
    DealRole DealRole::SDK_NOTSUPPORT = DealRole("sdk_not_support_for_now");

    DepthStep DepthStep::step0 = DepthStep("step0");
    DepthStep DepthStep::step1 = DepthStep("step1");
    DepthStep DepthStep::step2 = DepthStep("step2");
    DepthStep DepthStep::step3 = DepthStep("step3");
    DepthStep DepthStep::step4 = DepthStep("step4");
    DepthStep DepthStep::step5 = DepthStep("step5");
    DepthStep DepthStep::step6 = DepthStep("step6");
    DepthStep DepthStep::step7 = DepthStep("step7");
    DepthStep DepthStep::step8 = DepthStep("step8");
    DepthStep DepthStep::step9 = DepthStep("step9");
    DepthStep DepthStep::step10 = DepthStep("step10");
    DepthStep DepthStep::step11 = DepthStep("step11");
    DepthStep DepthStep::SDK_NOTSUPPORT = DepthStep("sdk_not_support_for_now");

    MBPLevel MBPLevel::LEVEL20 = MBPLevel("20");
    MBPLevel MBPLevel::LEVEL150 = MBPLevel("150");
    MBPLevel MBPLevel::SDK_NOTSUPPORT = MBPLevel("sdk_not_support_for_now");

    LiquidationType LiquidationType::non_liquidated = LiquidationType("0");
    LiquidationType LiquidationType::long_short_netting = LiquidationType("1");
    LiquidationType LiquidationType::partial_liquidated = LiquidationType("2");
    LiquidationType LiquidationType::full_liquidated = LiquidationType("3");

}

