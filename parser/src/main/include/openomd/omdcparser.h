#pragma once
#include "openomd/omdbaseparser.h"
#include <omdc_sbe/AddOddLotOrder.h>
#include <omdc_sbe/AddOrder.h>
#include <omdc_sbe/AggregateOrderBookUpdate.h>
#include <omdc_sbe/BrokerQueue.h>
#include <omdc_sbe/ClosingPrice.h>
#include <omdc_sbe/CurrencyRate.h>
#include <omdc_sbe/DeleteOddLotOrder.h>
#include <omdc_sbe/DeleteOrder.h>
#include <omdc_sbe/DisasterRecoverySignal.h>
#include <omdc_sbe/Heartbeat.h>
#include <omdc_sbe/IndexData.h>
#include <omdc_sbe/IndexDefinition.h>
#include <omdc_sbe/IndicativeEquilibriumPrice.h>
#include <omdc_sbe/LiquidityProvider.h>
#include <omdc_sbe/Logon.h>
#include <omdc_sbe/LogonResponse.h>
#include <omdc_sbe/MarketDefinition.h>
#include <omdc_sbe/ModifyOrder.h>
#include <omdc_sbe/NominalPrice.h>
#include <omdc_sbe/OrderImbalance.h>
#include <omdc_sbe/ReferencePrice.h>
#include <omdc_sbe/RefreshComplete.h>
#include <omdc_sbe/RetransmissionReq.h>
#include <omdc_sbe/RetransmissionResp.h>
#include <omdc_sbe/SecurityDefinition.h>
#include <omdc_sbe/SecurityStatus.h>
#include <omdc_sbe/SequenceReset.h>
#include <omdc_sbe/Trade.h>
#include <omdc_sbe/TradeCancel.h>
#include <omdc_sbe/TradeTicker.h>
#include <omdc_sbe/TradingSessionStatus.h>
#include <omdc_sbe/VCMTrigger.h>

namespace openomd
{
#define OMD_SWITCH_CASE(MESSAGE) case MESSAGE::sbeTemplateId(): process<MESSAGE>(pos, msgSize, callback, partition); break;

class OmdcParser : public OmdBaseParser
{
public:
    template <typename _Callback>
    static void parse(char* data, size_t bytesRecvd, _Callback& callback, int32_t partition)
    {
        using namespace omdc::sbe;
        parseHelper(data, bytesRecvd, callback, partition, 
            [](uint16_t type, char* pos, uint16_t msgSize, _Callback& callback, int32_t partition) {
            switch (type)
            {
                OMD_SWITCH_CASE(AddOddLotOrder);
                OMD_SWITCH_CASE(AddOrder);
                OMD_SWITCH_CASE(AggregateOrderBookUpdate);
                OMD_SWITCH_CASE(BrokerQueue);
                OMD_SWITCH_CASE(ClosingPrice);
                OMD_SWITCH_CASE(CurrencyRate);
                OMD_SWITCH_CASE(DeleteOddLotOrder);
                OMD_SWITCH_CASE(DeleteOrder);
                OMD_SWITCH_CASE(DisasterRecoverySignal);
                OMD_SWITCH_CASE(IndexData);
                OMD_SWITCH_CASE(IndexDefinition);
                OMD_SWITCH_CASE(IndicativeEquilibriumPrice);
                OMD_SWITCH_CASE(LiquidityProvider);
                OMD_SWITCH_CASE(Logon);
                OMD_SWITCH_CASE(LogonResponse);
                OMD_SWITCH_CASE(MarketDefinition);
                OMD_SWITCH_CASE(ModifyOrder);
                OMD_SWITCH_CASE(NominalPrice);
                OMD_SWITCH_CASE(OrderImbalance);
                OMD_SWITCH_CASE(ReferencePrice);
                OMD_SWITCH_CASE(RefreshComplete);
                OMD_SWITCH_CASE(RetransmissionReq);
                OMD_SWITCH_CASE(RetransmissionResp);
                OMD_SWITCH_CASE(SecurityDefinition);
                OMD_SWITCH_CASE(SecurityStatus);
                OMD_SWITCH_CASE(SequenceReset);
                OMD_SWITCH_CASE(Trade);
                OMD_SWITCH_CASE(TradeCancel);
                OMD_SWITCH_CASE(TradeTicker);
                OMD_SWITCH_CASE(TradingSessionStatus);
                OMD_SWITCH_CASE(VCMTrigger);
            default:
                callback.onUnknownMessage(type, msgSize);
                break;
            }
        });
    }
};
}
